# list

Play with linked lists and binary trees easily !

This library provides a basic set of functions for both structures. There's
only one rule for use it, you have to declare your structure like this:

```
struct list {
  struct list *next;
  ...
};
```

You also have to do the same for binary trees, take a look to *list.h* and
*tree.h* for more details.

## build

```
mkdir build
cd build
cmake ..
make
```
