#include "algo.h"
#include <iostream>
#include <algorithm>
#include <new>
#include <string>

using namespace std;

void Algo::do_bubble_sort(long long * arr, int n) {
  for(int i=n-1; i>=0; i--){
    for(int j=0; j<i; j++){
      if(arr[j] > arr[j+1]){ // swap(arr[j], arr[j+1])
        long long tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }
}

void Algo::do_insert_sort(long long * arr, int n) {
  for(int i=1; i<n; i++){
    long long key = arr[i];
    int j;
    for(j=i-1; j>=0 && arr[j]>key; j--){
      arr[j+1] = arr[j];
    }
    arr[j+1] = key;
  }
}

void do_merge_sort_recursive(int s, int e, long long * tmp, long long * arr){
  // base condition
  if(s >= e) return;

  // recursive call
  int m = (s + e)/2;
  do_merge_sort_recursive(s, m, tmp, arr);
  do_merge_sort_recursive(m+1, e, tmp, arr);
  
  //merge
  for(int i=s, t1 = s, t2 = m+1; i <= e; i++){
    if(t2 > e || (t1 <= m && arr[t1] < arr[t2]) ) tmp[i] = arr[t1++];
    else tmp[i] = arr[t2++];
  }
  for(int i=s; i<=e; i++) arr[i] = tmp[i];
}

void Algo::do_merge_sort(long long * arr, int n) {
  long long * tmp;
  tmp = new long long[n];
  do_merge_sort_recursive(0, n-1, tmp, arr);
  delete tmp;
}


// insertion sort with gap
void inc_insertion_sort(long long * arr, int first, int last, int gap){
  for(int i = first+gap; i <= last; i = i+gap){
    long long key = arr[i];
    int j;
    for(j=i-gap; j>=first && arr[j]>key; j=j-gap){
      arr[j+gap] = arr[j];
    }
    arr[j+gap] = key;
  }
}

void Algo::do_shell_sort(long long * arr, int n) {
  for(int gap=n/2; gap>0; gap=gap/2){
    // gap should be odd
    if((gap%2) == 0) gap++;

    for(int i=0; i<gap; i++)
      inc_insertion_sort(arr, i, n-1, gap);
  }
}

void do_quick_sort_recursive(int s, int e, long long * arr){
  // base condition
  if(s >= e) return;

  // partition
  int l = s,  h = e + 1;

  /// TODO: think 'worst case' of this implementation??
  long long pivot = arr[s]; 
 

  do{
    do l++;
    while (l<=e && arr[l]<pivot);

    do h--;
    while (h>=s && arr[h]>pivot);
    
    if(l<h) swap(arr[l], arr[h]);
  } while (l<h);

  swap(arr[s], arr[h]);


  // recursive call
  do_quick_sort_recursive(s, h-1, arr);
  do_quick_sort_recursive(h+1, e, arr);
}

void Algo::do_quick_sort(long long * arr, int n) {
  do_quick_sort_recursive(0, n-1, arr);
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
    case quick_sort:
      _do_sort(algo);
      break;
    case find_max_subarr_brute_force:
    case find_max_subarr_recursive:
      _do_find_max_subarray(algo);
      break;
    case build_max_heap_n:
    case build_max_heap_nlogn:
      _do_build_max_heap(algo);
      break;
      
    default:
      cerr << "Not such algorithm number : " << algo << endl;
  }
}


TAlgo Algo::string_to_TAlgo(string str) {
  if(str == "bubble_sort") return bubble_sort;
  if(str == "insert_sort") return insert_sort;
  if(str == "merge_sort") return merge_sort;
  if(str == "shell_sort") return shell_sort;
  if(str == "quick_sort") return quick_sort;
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
    case quick_sort:  do_quick_sort(arr, n);    break;
    default: break;
  }
  
  // output
  for(int i=0; i<n; i++) cout << arr[i] << " ";
  cout << "\n";

  // free variable
  delete arr;
}

void Algo::_do_find_max_subarray(TAlgo algo){
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

void Algo::_do_build_max_heap(TAlgo algo){
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