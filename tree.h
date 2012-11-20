#ifndef TREE_H
#define TREE_H

#include <stddef.h>

/* Binary tree node. */
typedef struct tree_s {
	struct tree_s *left;
	struct tree_s *right;
} tree_t;

/* Add a node in tree using the given three-way comparison function. */
tree_t *t_put(tree_t *, tree_t *, int (*)(const tree_t *, const tree_t *));

/* Call the given function (if non-zero) on the node selected using the given
 * three-way comparison function before destroy it. */
tree_t *t_erase(tree_t *, tree_t *, int (*)(const tree_t *, const tree_t *),
		void (*)(tree_t *));

/* Call the given function (if non-zero) on each node before destroy them,
 * return zero. */
tree_t *t_free(tree_t *, void (*)(tree_t *));

/* Search a node in tree using the given three-way comparison function. */
tree_t *t_find(tree_t *, tree_t *, int (*)(const tree_t *, const tree_t *));

/* Balance a tree, return the new root node of tree. */
tree_t *t_balance(tree_t *);

/* Return the number of nodes in tree. */
size_t t_size(tree_t *);

/* Return the depth of tree. */
size_t t_depth(tree_t *);

/* Return the node at the given position. */
tree_t *t_node(tree_t *, size_t);

/* Walk through tree since pre-order, in-order or post-order given functions
 * (if non-zero) return zero. */
tree_t *t_iter(tree_t *, int (*)(tree_t *), int (*)(tree_t *),
		int (*)(tree_t *));

#endif
