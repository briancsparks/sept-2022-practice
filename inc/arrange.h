//
// Created by brian on 11/2/2022.
//

#ifndef INC_2_BASIC_ARRANGE_H
#define INC_2_BASIC_ARRANGE_H

#include <cassert>

namespace one {

  template <typename Tint>
  class arrange {
  public:
    int * arr;
    int   r;
    int count;
    arrange(int r): arr(nullptr), r(r), count(-1) {}
    ~arrange() { delete arr; }

    bool init()
    {
      arr = new int[r];
      for (int i = 0; i < r; ++i) {
        arr[i] = i;
      }
      return true;
    }

    bool next(int * begin = nullptr, int rr = -1)
    {
      if (begin == nullptr) {
        count += 1;
      }

      if (arr == nullptr) {
        return init();
      }

      if (begin == nullptr) {
        begin = arr;
        rr = r;
      } else if (rr == 0) {
        return false;
      }

      int * end   = begin + rr;
      int * p     = begin;
      int * p2    = nullptr;

      // in: [1, 3, 5, 2, 4]
      //            ^
      // Look for max value from the left
      for (; p < end; ++p) {
        if (*p == rr-1) {
          break;
        }
      }
      assert(p <= end);

      if (p == begin) {
        return next(begin+1, rr-1);
      }

      // in:       [1, 3, 5, 2, 4]
      //                   <- <-
      //                  ----->
      // restored: [1, 3, 2, 4, 5]
      // Restore it -- copy everything past the r back one, and put the r at the end
      for (p2 = p; p2 < end - 1; ++p2) {
        *p2 = *(p2 + 1);
      }
      *p2 = rr-1;

      // [1, 3, 2, 4, 5]
      // [1, 4, 2, 3, 5]
      //     ^     ^
      // One item left and find next to swap
      p -= 1;
      for (p2 = p + 1; p2 < end; ++p2) {
        if (*p2 > *p) {
          int temp = *p;
          *p = *p2;
          *p2 = temp;

          break;
        }
      }

      return true;
    }

  };

} // one

#endif //INC_2_BASIC_ARRANGE_H
