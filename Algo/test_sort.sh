#!/bin/bash


echo -e "test bubble sort\n============================"

echo -n "[sort_integer_small] : "
../testcase/test.sh bubble_sort ./test_algo ../testcase/sort_integer_small

echo -e "\ntest insert sort\n============================"

echo -n "[sort_integer_small] : "
../testcase/test.sh  insert_sort ./test_algo ../testcase/sort_integer_small

echo -e "\ntest merge sort\n============================"

echo -n "[sort_integer_small] : "
../testcase/test.sh  merge_sort ./test_algo ../testcase/sort_integer_small
echo -n "[sort_integer_large] : "
../testcase/test.sh  merge_sort ./test_algo ../testcase/sort_integer_large


echo -e "\ntest shell sort\n============================"

echo -n "[sort_integer_small] : "
../testcase/test.sh  shell_sort ./test_algo ../testcase/sort_integer_small