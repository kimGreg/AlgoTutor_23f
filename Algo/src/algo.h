#ifndef IMPL_H 
#define IMPL_H

#include <vector>
#include <algorithm>
#include <map>

using namespace std;

enum TAlgo{
  none = 0,
  bubble_sort,
  insert_sort,
  merge_sort,
  shell_sort,
};

namespace Algo{
  TAlgo string_to_TAlgo(string str);
  void run(TAlgo algo);

  // for core implimentation
  void do_bubble_sort(long long * arr, int n);
  void do_insert_sort(long long * arr, int n);
  void do_merge_sort(long long * arr, int n);
  void do_shell_sort(long long * arr, int n);

  // for total operation
  void _do_sort(TAlgo algo);
}

#endif