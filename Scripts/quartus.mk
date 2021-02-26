BOARD=none
PROJECT=none
PROJECTDIR=../../
MANIFEST=../../project_files.rtl
SCRIPTSDIR=../../DeMiSTify/Scripts

SOF=$(PROJECT)_$(BOARD).sof
QSF=$(PROJECT)_$(BOARD).qsf

all: init compile

.PHONY init:
init: $(QSF)

.PHONY compile:
compile: $(SOF)

$(PROJECT)_$(BOARD)_files.tcl: $(MANIFEST)
	@bash $(SCRIPTSDIR)/expandtemplate_quartus.sh $+ >$@

%.qsf: $(PROJECT)_$(BOARD)_files.tcl
	@echo -n "Making project file for $(PROJECT) on $(BOARD)... "
	$(TOOLPATH)/quartus_sh >init.log -t $(SCRIPTSDIR)/mkproject.tcl -project $(PROJECT) -board $(BOARD) && echo "Success" || grep Error init.log

%.sof: %.qsf
	@echo -n "Compiling $(PROJECT) for $(BOARD)... "
	$(TOOLPATH)/quartus_sh >compile.log -t $(SCRIPTSDIR)/compile.tcl -project $(PROJECT) -board $(BOARD) && echo "Success" || grep Error compile.log

clean:
	-rm $(SOF)
	-rm $(QSF)


