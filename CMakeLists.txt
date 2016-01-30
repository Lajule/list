cmake_minimum_required(VERSION 3.4)

project(list)

add_library(list SHARED list.c tree.c)

install(TARGETS list DESTINATION lib)
install(FILES list.h tree.h DESTINATION include)
