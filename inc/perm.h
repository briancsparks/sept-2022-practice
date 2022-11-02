//
// Created by brian on 11/2/2022.
//

#ifndef INC_2_BASIC_PERM_H
#define INC_2_BASIC_PERM_H

#include "comb.h"
#include "arrange.h"

namespace one {

  template <typename Tint>
  class perm {
  public:
    Tint * arr;
    int n, r;
    int count;
    comb<Tint> * combins;
    arrange<Tint> * arrangements;
    bool ares, cres;

    perm(int n, int r) : arr(nullptr), n(n), r(r), count(-1), combins(nullptr), arrangements(nullptr), ares(false), cres(false) {
      arr = new Tint[r];
      combins = new comb<Tint>(n, r);
      arrangements = new arrange<Tint>(r);

      cres = combins->next();
    }

    ~perm() {
      delete combins;
      delete arrangements;
      delete arr;
    }

    bool next()
    {
      count += 1;

      ares = arrangements->next();
      if (!ares) {
        cres = combins->next();
        if (!cres) {
          return false;
        }

        delete arrangements;
        arrangements = new arrange<Tint>(r);
        ares = arrangements->next();
      }

      for (int i = 0; i < r; ++i) {
        arr[i] = combins->arr[arrangements->arr[i]];
      }

      return true;
    }

  };
}


#endif //INC_2_BASIC_PERM_H
