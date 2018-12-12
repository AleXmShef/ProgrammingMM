cmake_minimum_required(VERSION 3.12)
project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoublyLinkedList main.cpp Node.cpp Node.h DoublyLinkedList.cpp DoublyLinkedList.h Commands.h)