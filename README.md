# list

Play with linked lists and binary trees easily !

This library provides a basic set of functions for both structures. There's
only one rule to use it, you have to declare your structure like this:

```c
struct list {
  struct list *next;
  ...
};
```

You also have to do the same for binary trees, take a look at *list.h* and
*tree.h* for more details.

## build

```sh
mkdir build
cd build
cmake ..
make
```
