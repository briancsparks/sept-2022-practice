
#include <iostream>
#include <cassert>

#include "inc/comb.h"
#include "inc/arrangements.h"

using namespace one;

void init(int * ii, int r)
{
  int * p = ii;
  for (int i = 0; i < r; ++i) {
    *p++ = 0;
  }
}

void assertN3(int * ii, int a, int b, int c) {
  assert(ii[0] == a);
  assert(ii[1] == b);
  assert(ii[2] == c);
}

// 5c3:
// 0:  [0, 1, 2]                            [0, 1, 2]
// 1:  [0, 1, 3]                            [0, 1, 3]
// 2:  [0, 1, 4]                            [0, 1, 4]
// 3:  [0, 2, 3]                       <--   !!! [0, 1, 5]
// 4:  [0, 2, 4]                            [0, 2, 4]
// 5:  [0, 3, 4]                       <--   !!! [0, 2, 5]
// 6:  [1, 2, 3]  <--   !!! [0, 4, 5]  <--   !!! [0, 3, 5]
// 7:  [1, 2, 4]                            [1, 2, 4]
// 8:  [1, 3, 4]                       <--   !!! [1, 2, 5]
// 9:  [2, 3, 4]  <--   !!! [1, 4, 5]  <--   !!! [1, 3, 5]

// 3Permus
// 0:  [0, 1, 2]
// 1:  [0, 2, 1]
// 2:  [1, 0, 2]
// 3:  [1, 2, 0]
// 4:  [2, 0, 1]
// 5:  [2, 1, 0]

int test0();

int main()
{
//  test0();

  int n = 5, r = 3;
  auto combins = comb<int>(n, r);

  int cCombins = 0;
  int cPermus  = 0;

  std::cout << "Hello, World!" << std::endl;
  while (combins.next()) {
    cCombins += 1;

    auto permus = arrangements<int>(r);
    while (permus.next()) {
      cPermus += 1;
      for (int i = 0; i < r; ++i) {
        std::cout << combins.arr[permus.arr[i]] /*+1*/ << ", ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
//    break;
  }

  std::cout << "Combins: " << cCombins << ", Permus: " << cPermus << std::endl;
}

int test0() {
  int n = 5, r = 3;
  auto combins = comb<int>(n, r);

  assert(combins.next());        // 0
  assertN3(combins.arr, 0,1,2);
  assert(combins.next());        // 1
  assert(combins.next());        // 2
  assert(combins.next());        // 3
  assertN3(combins.arr, 0,2,3);
  assert(combins.next());        // 4
  assert(combins.next());        // 5
  assert(combins.next());        // 6
  assertN3(combins.arr, 1,2,3);
  assert(combins.next());        // 7
  assert(combins.next());        // 8
  assert(combins.next());        // 9
  assertN3(combins.arr, 2,3,4);
  assert(!combins.next());        // 10


  // 0:  [0, 1, 2]
  // 1:  [0, 2, 1]
  // 2:  [1, 0, 2]
  // 3:  [1, 2, 0]
  // 4:  [2, 0, 1]
  // 5:  [2, 1, 0]

  auto permus = arrangements<int>(r);

  assert(permus.next());        // 0
  assertN3(permus.arr, 0, 1, 2);
  assert(permus.next());        // 1
  assertN3(permus.arr, 0, 2, 1);
  assert(permus.next());        // 2
  assertN3(permus.arr, 1,0,2);
  assert(permus.next());        // 3
  assertN3(permus.arr, 1,2,0);
  assert(permus.next());        // 4
  assertN3(permus.arr, 2,0,1);
  assert(permus.next());        // 5
  assertN3(permus.arr, 2,1,0);
  assert(!permus.next());        // 6


//  int arr[r];
//
//  init(arr, r);
//  assert(nextComb(arr, n, r));        // 0
//  assertN3(arr, 0,1,2);
//  assert(nextComb(arr, n, r));        // 1
//  assert(nextComb(arr, n, r));        // 2
//  assert(nextComb(arr, n, r));        // 3
//  assertN3(arr, 0,2,3);
//  assert(nextComb(arr, n, r));        // 4
//  assert(nextComb(arr, n, r));        // 5
//  assert(nextComb(arr, n, r));        // 6
//  assertN3(arr, 1,2,3);
//  assert(nextComb(arr, n, r));        // 7
//  assert(nextComb(arr, n, r));        // 8
//  assert(nextComb(arr, n, r));        // 9
//  assertN3(arr, 2,3,4);
//  assert(!nextComb(arr, n, r));        // 10

//  init(arr, r);
//
//  std::cout << "Hello, World!" << std::endl;
//  while (nextComb(arr, n, r)) {
//    for (int i = 0; i < r; ++i) {
//      std::cout << arr[i] /*+1*/ << ", ";
//    }
//    std::cout << std::endl;
//  }

  return 0;
}
