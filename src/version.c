#include <stdio.h>

#ifdef HAVE_CONFIG_H
#include "config.h"
#else
#define PACKAGE_STRING "list (UNVERSIONED)"
#endif

static void
version() {
	puts(PACKAGE_STRING);
}
