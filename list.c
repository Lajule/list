#include <assert.h>
#include <stdlib.h>
#include "list.h"

static list_t *split(list_t *);
static list_t *merge(list_t *, list_t *, int (*)(const list_t *, const
list_t *));

list_t *
l_push(list_t *list, list_t *node) {
	assert(node);
	node->next = list;
	return node;
}

list_t *
l_pop(list_t *list, void (*f)(list_t *)) {
	list_t *next;

	if (!list)
		return NULL;
	next = list->next;
	if (f)
		f(list);
	free(list);
	return next;
}

list_t *
l_insert(list_t *list, size_t position, list_t *node) {
	list_t *cursor;
	size_t offset;

	if (!list || !position)
		return l_push(list, node);
	offset = 0;
	cursor = list;
	while (cursor->next && offset++ != position - 1)
		cursor = cursor->next;
	assert(node);
	node->next = cursor->next;
	cursor->next = node;
	return list;
}

list_t *
l_erase(list_t *list, size_t position, void (*f)(list_t *)) {
	list_t *previous, *cursor;
	size_t offset;

	if (!list || !position)
		return l_pop(list, f);
	offset = 0;
	cursor = list;
	previous = cursor;
	while (cursor && offset++ != position) {
		previous = cursor;
		cursor = cursor->next;
	}
	if (cursor) {
		previous->next = cursor->next;
		if (f)
			f(cursor);
		free(cursor);
	}
	return list;
}

list_t *
l_free(list_t *list, void (*f)(list_t *)) {
	list_t *next;

	while (list) {
		next = list->next;
		if (f)
			f(list);
		free(list);
		list = next;
	}
	return NULL;
}

size_t
l_size(list_t *list) {
	size_t size;

	for (size = 0; list; ++size)
		list = list->next;
	return size;
}

list_t *
l_node(list_t *list, size_t position) {
	size_t offset;

	for (offset = 0; list && offset != position; ++offset)
		list = list->next;
	return list;
}

list_t *
l_find(list_t *list, list_t *node, int (*f)(const list_t *, const list_t *)) {
	assert(f);
	while (list && f(node, list))
		list = list->next;
	return list;
}

list_t *
l_iter(list_t *list, int (*f)(list_t *)) {
	assert(f);
	while (list && !f(list))
		list = list->next;
	return list;
}

list_t *
l_rev(list_t *list) {
	list_t *head, *next;

	head = NULL;
	while (list) {
		next = list->next;
		list->next = head;
		head = list;
		list = next;
	}
	return head;
}

list_t *
l_cat(list_t *list1, list_t *list2) {
	list_t *cursor;

	if (!list1)
		return list2;
	cursor = list1;
	while (cursor && cursor->next)
		cursor = cursor->next;
	cursor->next = list2;
	return list1;
	
}

list_t *
l_insert_if(list_t *list, list_t *node,
	int (*f)(const list_t *, const list_t *)) {
	list_t *cursor;

	assert(f);
	assert(node);
	if (!list || f(node, list) <= 0)
		return l_push(list, node);
	cursor = list;
	while (cursor->next && f(node, cursor->next) > 0)
		cursor = cursor->next;
	node->next = cursor->next;
	cursor->next = node;
	return list;
}

list_t *
l_erase_if(list_t *list, list_t *node,
	int (*c)(const list_t *, const list_t *), void (*f)(list_t *)) {
	list_t *previous, *cursor;

	if (!list || c(node, list) == 0)
		return l_pop(list, f);
	cursor = list;
	previous = cursor;
	while (cursor && c(node, cursor->next) != 0) {
		previous = cursor;
		cursor = cursor->next;
	}
	if (cursor) {
		previous->next = cursor->next;
		if (f)
			f(cursor);
		free(cursor);
	}
	return list;
}

list_t *
l_sort(list_t *list, int (*f)(const list_t *, const list_t *)) {
	list_t *middle;

	assert(f);
	if (!list)
		return NULL;
	if (!list->next)
		return list;
	middle = split(list);
	return merge(l_sort(list, f), l_sort(middle, f), f);
}

static list_t *
split(list_t *list) {
	list_t *next;

	if (!list)
		return NULL;
	if (!list->next)
		return NULL;
	next = list->next;
	list->next = next->next;
	next->next = split(next->next);
	return next;
}

static list_t *
merge(list_t *list1, list_t *list2, int (*f)(const list_t *, const list_t *)) {
	if (!list1)
		return list2;
	if (!list2)
		return list1;
	if (f(list1, list2) <= 0) {
		list1->next = merge(list1->next, list2, f);
		return list1;
	} else {
		list2->next = merge(list1, list2->next, f);
		return list2;
	}
}