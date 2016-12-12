/* vi: set sw=4 ts=4: */
/*
 *  setconsole.c - redirect system console output
 *
 *  Copyright (C) 2004,2005  Enrik Berkhan <Enrik.Berkhan@inka.de>
 *  Copyright (C) 2008 Bernhard Reutner-Fischer
 *
 * Licensed under GPLv2 or later, see file LICENSE in this tarball for details.
 */

#include "libbb.h"

int setconsole_main(int argc, char **argv) MAIN_EXTERNALLY_VISIBLE;
int setconsole_main(int argc UNUSED_PARAM, char **argv)
{
	const char *device = CURRENT_TTY;
	bool reset;

#if ENABLE_FEATURE_SETCONSOLE_LONG_OPTIONS
	static const char setconsole_longopts[] ALIGN1 =
		"reset\0" No_argument "r"
		;
	applet_long_options = setconsole_longopts;
#endif
	/* at most one non-option argument */
	opt_complementary = "?1";
	reset = getopt32(argv, "r");

	argv += 1 + reset;
	if (*argv) {
		device = *argv;
	} else {
		if (reset)
			device = DEV_CONSOLE;
	}

	xioctl(xopen(device, O_RDONLY), TIOCCONS, NULL);
	return EXIT_SUCCESS;
}
