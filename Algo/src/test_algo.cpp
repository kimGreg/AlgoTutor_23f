#include <iostream>
#include "algo.h"

using namespace std;

int main(int argc, char ** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  
  if (argc != 2) {
    cerr << "arg# should be 1";
    return 1;
  }

  string algo_str(argv[1]);

  TAlgo algo = Algo::string_to_TAlgo(algo_str);
  Algo::run(algo);

  return 0;
}