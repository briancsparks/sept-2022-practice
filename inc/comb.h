//
// Created by Brian Sparks on 11/1/22.
//

#ifndef INC_2_BASIC_COMB_H
#define INC_2_BASIC_COMB_H

namespace one {

  template <typename Tint>
  bool nextComb0(Tint * ii, Tint n, Tint r) {
    int * begin = ii;
    int * end   = begin + r;
    int * p     = nullptr;

    // Init
    if (ii[0] == -1 || ii[r-1] <= 0) {
      p = begin;
      *p = 0;

    } else {

      int pmax = n;
      for (p = end - 1; p >= begin; --p, --pmax) {
        *p += 1;
        if (*p < pmax) {
          break;
        }
      }
      if (p < begin) {
        return false;
      }
    }


    for (p += 1; p < end; ++p) {
      *p = (*(p-1)) + 1;
    }

    return true;
  }

  template <typename Tint>
  void init(Tint * ii, Tint r)
  {
    int * p = ii;
    for (int i = 0; i < r; ++i) {
      *p++ = -1;
    }
  }

  template <typename Tint>
  bool spring(Tint * ii, Tint n, Tint r, Tint * p, Tint pval)
  {
    for (; p < ii + r; ++p) {
      *p = pval++;
    }
    return true;
  }

  template <typename Tint>
  bool spring0(Tint * ii, Tint n, Tint r, Tint * p, Tint pval)
  {
    *p = pval;
    for (++p; p < ii + r; ++p) {
      *p = 0;
    }
    return true;
  }

  template <typename Tint>
  bool nextComb1(Tint * ii, Tint n, Tint r) {
    int * begin = ii;
    int * last  = begin + r - 1;
    int * p     = nullptr;

    // Init
    if (ii[0] == -1 || ii[r-1] <= 0) {
      return spring(ii, n, r, ii, 0);
    }

    for (p = last; p >= begin; --p) {
      int revcolnum = (last - p);
      *p += 1;
      int max = n - revcolnum;      // -----
      if (*p < n - revcolnum) {                    // n - revcolnum is the max for the column
        return spring(ii, n, r, p, *p);
      }
    }

    return false;
  }

  template <typename Tint>
  bool nextComb2(Tint * ii, Tint n, Tint r) {
    int * last  = ii + r - 1;

    // Init
    if (ii[0] == -1 || ii[r-1] <= 0) {
      return spring(ii, n, r, ii, 0);
    }

    int reverseColNum = 0;
    for (int * p = last; p >= ii; --p, ++reverseColNum) {
      *p += 1;
      int max = n - reverseColNum;      // -----
      if (*p < n - reverseColNum) {                    // n - reverseColNum is the max for the column
        return spring(ii, n, r, p, *p);
      }
    }

    return false;
  }

  template <typename Tint>
  bool nextComb(Tint * ii, Tint n, Tint r) {
    return nextComb2(ii, n, r);
  }

  template <typename Tint>
  class comb {
  public:
    Tint * arr;
    Tint n, r;
    comb(Tint n, Tint r) : arr(nullptr), n(n), r(r) {}

    ~comb()
    {
      delete arr;
    }

    bool init()
    {
      arr = new Tint[r];
      return spring(arr, n, r, arr, 0);
    }

    bool next()
    {
      if (arr == nullptr) {
        return init();
      }

      int * last  = arr + r - 1;

      int max = n;
      for (int * p = last; p >= arr; --p, --max) {
        *p += 1;
        if (*p < max) {
          return spring(arr, n, r, p, *p);
        }
      }

      return false;
    }
  };

//  template <typename Tint>
//  class perm {
//  public:
//    Tint * arr;
//    Tint n, r;
//    perm(Tint n, Tint r) : arr(nullptr), n(n), r(r) {}
//
//    ~perm()
//    {
//      delete arr;
//    }
//
//    bool init()
//    {
//      arr = new Tint[r];
//      return spring0(arr, n, r, arr, 0);
//    }
//
//    bool next()
//    {
//      if (arr == nullptr) {
//        return init();
//      }
//
//      int * last  = arr + r - 1;
//
//      int max = n;
//      for (int * p = last; p >= arr; --p, --max) {
//        *p += 1;
//        if (*p < max) {
//          return spring0(arr, n, r, p, *p);
//        }
//      }
//
//      return false;
//    }
//  };

}


#endif //INC_2_BASIC_COMB_H
