#include <assert.h>
#include <stdlib.h>
#include "tree.h"

static tree_t *join(tree_t *, tree_t *);
static tree_t *split(tree_t *, size_t);

tree_t *
t_put(tree_t *root, tree_t *node, int (*f)(const tree_t *, const tree_t *)) {
	assert(node && f);
	if (root) {
		if (f(root, node) <= 0) {
			root->left = t_put(root->left, node, f);
		} else {
			root->right = t_put(root->right, node, f);
		}
		return root;
	}
	return node;
}

tree_t *
t_erase(tree_t *root, tree_t *node, int (*c)(const tree_t *, const tree_t *),
	void (*f)(tree_t *)) {
	tree_t *tmp;
	int compare;

	assert(node && c);
	if (root) {
		compare = c(root, node);
		if (!compare) {
			tmp = root;
			root = join(root->left, root->right);
			if (f)
				f(tmp);
			free(tmp);
		} else if (compare < 0) {
			root->left = t_erase(root->left, node, c, f);
		} else {
			root->right = t_erase(root->right, node, c, f);
		}
		return root;
	}
	return NULL;
}

tree_t *
t_free(tree_t *root, void (*f)(tree_t *)) {
	if (root) {
		root->left = t_free(root->left, f);
		root->right = t_free(root->right, f);
		if (f)
			f(root);
		free(root);
	}
	return NULL;
}

tree_t *
t_find(tree_t *root, tree_t *node, int (*f)(const tree_t *, const tree_t *)) {
	int compare;

	assert(node && f);
	if (root) {
		compare = f(root, node);
		if (!compare)
			return root;
		if (compare < 0) {
			return t_find(root->left, node, f);
		} else {
			return t_find(root->right, node, f);
		}
	}
	return NULL;
}

tree_t *
t_balance(tree_t *root) {
	size_t size;

	size = t_size(root);
	if (size >= 2) {
		root = split(root, size / 2);
		root->left = t_balance(root->left);
		root->right = t_balance(root->right);
	}
	return root;
}

size_t
t_size(tree_t *root) {
	if (root)
		return 1 + t_size(root->left) + t_size(root->right);
	return 0;
}

size_t
t_depth(tree_t *root) {
	size_t left, right;

	if (root) {
		left = 1 + t_depth(root->left);
		right = 1 + t_depth(root->right);
		if (left > right) {
			return left;
		} else {
			return right;
		}
	}
	return 0;
}

tree_t *
t_node(tree_t *root, size_t position) {
	size_t size;

	if (root) {
		size = t_size(root->left);
		if (size > position)
			return t_node(root->left, position);
		if (size < position)
			return t_node(root->right, position - size - 1);
		return root;
	}
	return NULL;
}

tree_t *
t_iter(tree_t *root,
	int (*pre)(tree_t *), int (*in)(tree_t *), int (*post)(tree_t *)) {
	tree_t *node;

	if (root) {
		if (pre && pre(root))
			return root;
		if ((node = t_iter(root->left, pre, in, post)) != NULL)
			return node;
		if (in && in(root))
			return root;
		if ((node = t_iter(root->right, pre, in, post)) != NULL)
			return node;
		if (post && post(root))
			return root;
	}
	return NULL;
}

static tree_t *
join(tree_t *root1, tree_t *root2) {
	if (root2) {
		root2 = split(root2, 0);
		root2->left = root1;
		return root2;
	}
	return root1;
}

static tree_t *
split(tree_t *root, size_t position) {
	tree_t *node;
	size_t size;

	if (root) {
		size = t_size(root->left);
		if (size > position) {
			root->left = split(root->left, position);
			node = root->left;
			root->left = node->right;
			node->right = root;
			root = node;
		}
		if (size < position) {
			root->right = split(root->right, position - size - 1);
			node = root->right;
			root->right = node->left;
			node->left = root;
			root = node;
		}
		return root;
	}
	return NULL;
}
