cmake_minimum_required(VERSION 3.7)
project(TemplateTraining)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp MyMap.h BinaryTree.h MyQueue.h ListQueue.h BufferQueue.h LinkedList.h)
add_executable(TemplateTraining ${SOURCE_FILES})