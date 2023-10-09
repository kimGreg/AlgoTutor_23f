#include "algo.h"
#include <iostream>
#include <algorithm>
#include <new>
#include <string>

using namespace std;

void Algo::do_bubble_sort(long long * arr, int n) {
  /// TODO: implement bubble sort
}

void Algo::do_insert_sort(long long * arr, int n) {
  /// TODO: implement insert sort
}

void Algo::do_merge_sort(long long * arr, int n) {
  /// TODO: implement merge sort
}

void Algo::do_shell_sort(long long * arr, int n) {
  /// TODO: implement insert sort
}

void Algo::do_find_max_subarr_brute_force(int * arr, int n, int * ans){
  /// TODO: implement insert sort
}

void Algo::do_find_max_subarr_recursive(int * arr, int n, int * ans){
  /// TODO: implement insert sort
}

void Algo::do_build_max_heap_n(long long * arr, int n){
  /// TODO: implement build heap
}

void Algo::do_build_max_heap_nlogn(long long * arr, int n){
  /// TODO: implement build heap
}

/* You Do Not Need To Read These Code */

// for run algorithms
void Algo::run(TAlgo algo) {
  switch (algo){
    case bubble_sort:
    case insert_sort:
    case merge_sort:
    case shell_sort:
      _do_sort(algo);
      break;
    case find_max_subarr_brute_force:
    case find_max_subarr_recursive:
      
    default:
      cerr << "Not such algorithm number : " << algo << endl;
  }
}


TAlgo Algo::string_to_TAlgo(string str) {
  if(str == "bubble_sort") return bubble_sort;
  if(str == "insert_sort") return insert_sort;
  if(str == "merge_sort") return merge_sort;
  if(str == "shell_sort") return shell_sort;
  if(str == "find_max_subarr_brute_force") return find_max_subarr_brute_force;
  if(str == "find_max_subarr_recursive") return find_max_subarr_recursive;
  if(str == "build_max_heap_n") return build_max_heap_n;
  if(str == "build_max_haep_nlogn") return build_max_heap_nlogn;
  return none;
}

void Algo::_do_sort(TAlgo algo) {
  // initialize variables
  int n;
  long long *arr;
  
  // input
  cin >> n;
  arr = new long long[n+20];
  for(int i=0; i<n; i++) cin >> arr[i];

  // select sort algorithm
  switch (algo){
    case bubble_sort: do_bubble_sort(arr, n);   break;
    case insert_sort: do_insert_sort(arr, n);   break;
    case merge_sort:  do_merge_sort(arr, n);    break;
    case shell_sort:  do_shell_sort(arr, n);    break;
    default: break;
  }
  
  // output
  for(int i=0; i<n; i++) cout << arr[i] << " ";
  cout << "\n";

  // free variable
  delete arr;
}

void _do_find_max_subarray(TAlgo algo){
  int n, *arr;

  // input
  cin >> n;
  arr = new int[n+20];
  int ans[3];

  for(int i=0; i<n; i++) cin >> arr[i];
  switch (algo){
    case find_max_subarr_brute_force:
      Algo::do_find_max_subarr_brute_force(arr, n, ans); break;
    case find_max_subarr_recursive:
      Algo::do_find_max_subarr_recursive(arr, n, ans); break;
    default:
      break;
  }

  cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;

  delete arr;
}

void _do_build_max_heap(TAlgo algo){
  int n;
  long long *arr;

  // input
  cin >> n;
  arr = new long long[n+20];

  for(int i=0; i<n; i++) cin >> arr[i];

  switch (algo){
    case build_max_heap_n:
      Algo::do_build_max_heap_n(arr, n); break;
    case build_max_heap_nlogn:
      Algo::do_build_max_heap_nlogn(arr, n); break;
    default:
      break;
  }

  delete arr;
}