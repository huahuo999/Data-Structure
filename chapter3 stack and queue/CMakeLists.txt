cmake_minimum_required(VERSION 3.15)
project(chapter3_stack_and_queue)

set(CMAKE_CXX_STANDARD 14)

add_executable(chapter3_stack_and_queue main.cpp LiStack.h ShStack.h SqStack.h SqQueue.h LinkQueue.h)