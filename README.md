list
====

This code should compile everywhere and survive to all warning flags (*).

## How to build ##

You need to invoke `make' binary to build the library.

### Goals ###

* all (default) : Build static/dynamic library.
* clean         : Delete object files. 
* realclean     : Delete object files and targets.

### Variables ###

* CC            : Compiler (default `cc').
* AR            : Archiver (default `ar').
* LD            : Linker (default `ld').
* CFLAGS        : Compiler flags.
* ARFLAGS       : Archiver flags (default `rv').
* LDFLAGS       : Linker flags.
* RM            : Binary used to delete files (default `rm').

## How to use ##

To use this code, give your compiler access to this directory and link your binary with the library.

### Example of use ###

  #include "list.h"
	...
	typedef struct int_list_s {
    /* this must be fisrt */
    struct int_list_s *next;
    int element;
  } int_list_t;
  ...
	int_list_t *list, *node;
  ...
  node = calloc(1, sizeof(int_list_t));
  node->element = 0;
  list = (int_list_t *)l_push((list_t *)list, (list_t *)node);
	assert(l_size((list_t *)list) == 1);
	list = (int_list_t *)l_free((list_t *)list, NULL);
	...





(*) Almost
