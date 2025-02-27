/* Configuration file should be placed in the core's firmware directory.
   Each core will have different requirements of the firmware, and by avoiding
   the parts not needed the ROM size can be kept to a minimum */

#ifndef CONFIG_H
#define CONFIG_H

/* PS/2 Mouse support */
#undef PS2_MOUSE
#undef PS2_WRITE

/* CDROM support - used by the TurboGrafx core */
#undef CONFIG_CD

/* Disk Image support - used for Save RAM on consoles as well as the
more obvious application of disk images on computer cores.  If not defined
here, the number of units defaults to 4. */
#undef CONFIG_DISKIMG
#undef CONFIG_DISKIMG_UNITS 4

/* Speed up file operations by "bookmarking" the file.
   (Undef to disable, or set to the number of desired bookmarks - a reasonable
   range would be between 4 and 16 */
#undef CONFIG_FILEBOOKMARKS 6

/* Keyboard-based Joystick emulation */
#define CONFIG_JOYKEYS

/* Send key events via the mist_io block. If the core can support
   a PS/2 keyboard directly then that's probably a better option. */
#undef CONFIG_SENDKEYS

/* Send joystick events using the "new" extended joystick protocol.
   This could support more buttons (if DeMiSTify itself supported them,
   which it currently doesn't) - but some cores still use the older protocol. */
#undef CONFIG_EXTJOYSTICK

#endif

