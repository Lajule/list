list
====

This code should compile everywhere and survive to all warning flags (*).

(*) Almost

## Build ##

To build the library:

	$ make

## Example ##

How to declare a a simply linked list:

	#include "list.h"

	typedef struct person_s {
	  struct person_s *next; /* This must be first */
	  int id;
	} person_t;

	person_t *list = NULL;   /* Always initialize a list to NULL */

How to manipulate the previous list:

	person_t *person = calloc(1, sizeof(person_t));
	person->id = 0;
	list = (person_t *)l_push((list_t *)list, (list_t *)person);
	
	assert(l_size((list_t *)list) == 1);
	list = (person_t *)l_free((list_t *)list, NULL);
