cmake_minimum_required(VERSION 3.19)
project(DataStructure)

set(CMAKE_CXX_STANDARD 14)

add_executable(DataStructure main.cpp sort/SortUtils.cpp sort/SortUtils.h tree/rbt/RedBlackTree.cpp tree/rbt/RedBlackTree.h tree/rbt/RBTNode.h tree/rbt/RBTNode.cpp Comparable.h tree/bst/BinarySearchTree.cpp tree/bst/BinarySearchTree.h tree/binary_tree/BinaryNode.cpp tree/binary_tree/BinaryNode.h tree/binary_tree/BinaryTree.cpp tree/binary_tree/BinaryTree.h search/SearchUtils.cpp search/SearchUtils.h list/ListNode.cpp list/ListNode.h exception/IndexOutOfBoundException.h list/List.h base/DS.cpp base/DS.h utils/StrUtils.cpp utils/StrUtils.h exception/IndexOutOfBoundException.cpp)