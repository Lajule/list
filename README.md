list
====

This code should compile everywhere and survive to all warning flags (*).

(*) Almost

## Build ##

To build the library:

	$ make

## Example ##

The following example shows how to use a simply linked list:

	#include "list.h"
	...
	typedef struct int_list_s {
		/* This must be first */
		struct int_list_s *next;
		int element;
	} int_list_t;
	...
	int_list_t *list, *node;
	...
	list = NULL;
	...
	node = calloc(1, sizeof(int_list_t));
	node->element = 0;
	list = (int_list_t *)l_push((list_t *)list, (list_t *)node);
	...
	assert(l_size((list_t *)list) == 1);
	list = (int_list_t *)l_free((list_t *)list, NULL);
	...
