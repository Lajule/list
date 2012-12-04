#ifndef LIST_H
#define LIST_H

#include <stddef.h>

/* Linked list node. */
typedef struct list_s {
	struct list_s *next;
} list_t;

/* Adds a node before the first one, returns the new head of list. */
list_t *l_push(list_t *, list_t *);

/* Calls the given function (if non-zero) on the first node before destroy it,
 * returns the new head of list. */
list_t *l_pop(list_t *, void (*)(list_t *));

/* Inserts a node at the given position, returns the head of list. */
list_t *l_insert(list_t *, size_t, list_t *);

/* Calls the given function (if non-zero) on the node at the given position
 * before destroy it, returns the head of list. */
list_t *l_erase(list_t *, size_t, void (*)(list_t *));

/* Calls the given function (if non-zero) on each node before destroy them,
 * returns zero. */
list_t *l_free(list_t *, void (*)(list_t *));

/* Returns the number of nodes in list. */
size_t l_size(list_t *);

/* Returns the node at the given position. */
list_t *l_node(list_t *, size_t);

/* Searches a node in list using the given three-way comparison function. */
list_t *l_find(list_t *, list_t *, int (*)(const list_t *, const list_t *));

/* Walks through list since the given function returns zero. */
list_t *l_iter(list_t *, int (*)(list_t *));

/* Reverses a list, returns the new head of list. */
list_t *l_rev(list_t *);

/* Appends two lists. */
list_t *l_cat(list_t *, list_t *);

/* Inserts a node at the position selected by the given three-way comparison
 * function. */
list_t *l_insert_if(list_t *, list_t *,
	int (*)(const list_t *, const list_t *));

/* Calls the given function (if non-zero) on the node at the position selected
 * by the given three-way comparison function before destroy it, returns
 * the head of list. */
list_t *l_erase_if(list_t *, list_t *,
	int (*)(const list_t *, const list_t *), void (*)(list_t *));

/* Sorts (merge algorithm) the list using the given three-way comparison
 * function, returns the head of list. */
list_t *l_sort(list_t *, int (*)(const list_t *, const list_t *));

#endif
