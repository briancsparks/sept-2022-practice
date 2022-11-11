//
// Created by brian on 11/8/2022.
//

#ifndef INC_2_BASIC_MAXMINIFICATOR_H
#define INC_2_BASIC_MAXMINIFICATOR_H

#include <climits>
#include <limits>
#include <iostream>

namespace one {

  using namespace std;

  template <typename t>
  class maxminificator_tt {
  public:
    int max;
    int min;
    long lmax;
    long lmin;
    float fmax;
    float fmin;
    float fsmall;
    float finf;
    double dmax;
    double dmin;
    double dsmall;
    double dinf;

    maxminificator_tt()
    : max(INT_MAX),
      min(INT_MIN),
      lmax(LONG_MAX),
      lmin(LONG_MIN),
      fmax(std::numeric_limits<float>::max()),
      fmin(std::numeric_limits<float>::min()),
      fsmall(std::numeric_limits<float>::lowest()),
      finf(std::numeric_limits<float>::infinity())
    {

    }

    static void show()
    {
      cout << "CHAR_MIN : " << CHAR_MIN << endl;
      cout << "CHAR_MAX : " << CHAR_MAX << endl;
      cout << "SHRT_MIN : " << SHRT_MIN << endl;
      cout << "SHRT_MAX : " << SHRT_MAX << endl;
      cout << "USHRT_MAX : " << USHRT_MAX << endl;
      cout << "INT_MIN : " << INT_MIN << endl;
      cout << "INT_MAX : " << INT_MAX << endl;
      cout << "UINT_MAX : " << UINT_MAX << endl;
      cout << "LONG_MIN : " << LONG_MIN << endl;
      cout << "LONG_MAX : " << LONG_MAX << endl;
      cout << "ULONG_MAX : " << ULONG_MAX << endl;
      cout << "LLONG_MIN : " << LLONG_MIN << endl;
      cout << "LLONG_MAX : " << LLONG_MAX << endl;
      cout << "ULLONG_MAX : " << ULLONG_MAX << endl;

      cout << endl;

      cout << "fmax : " << std::numeric_limits<float>::max() << endl;
      cout << "fmin : " << std::numeric_limits<float>::lowest() << endl;
      cout << "fsmall : " << std::numeric_limits<float>::min() << endl;
      cout << "finf : " << std::numeric_limits<float>::infinity() << endl;
    }

  };

  typedef maxminificator_tt<int> maxminificator;

} // one

#endif //INC_2_BASIC_MAXMINIFICATOR_H
