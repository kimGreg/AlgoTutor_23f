#!/bin/bash


echo -e "test bubble sort\n============================"

echo -n "[sort_integer_small] : "
python3 ../testcase/test.py --path ../testcase/sort_integer_small --cmd "./test_algo bubble_sort" --timeout 2

echo -e "\ntest insert sort\n============================"

echo -n "[sort_integer_small] : "
python3 ../testcase/test.py --path ../testcase/sort_integer_small --cmd "./test_algo insert_sort" --timeout 2

echo -e "\ntest merge sort\n============================"

echo -n "[sort_integer_small] : "
python3 ../testcase/test.py --path ../testcase/sort_integer_small --cmd "./test_algo merge_sort" --timeout 2
echo -n "[sort_integer_large] : "
python3 ../testcase/test.py --path ../testcase/sort_integer_large --cmd "./test_algo merge_sort" --timeout 3


echo -e "\ntest shell sort\n============================"

echo -n "[sort_integer_small] : "
python3 ../testcase/test.py --path ../testcase/sort_integer_small --cmd "./test_algo shell_sort" --timeout 2