#include <iostream>

bool next(int * ii, int n, int r)
{
  int * begin = ii;
  int * end   = begin + r;
  int * p     = nullptr;

  // Init
  if (ii[0] == -1 || ii[r-1] == 0) {
    p = ii;
    for (int i = 0; i < r; ++i) {
      *p++ = i;
    }
    return true;
  }

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

  for (p += 1; p < end; ++p) {
    *p = (*(p-1)) + 1;
  }

  return true;
}

void init(int * ii, int r)
{
  int * p = ii;
  for (int i = 0; i < r; ++i) {
    *p++ = 0;
  }
}

int main() {
  int n = 5, r = 3;
  int arr[r];
  init(arr, r);

  std::cout << "Hello, World!" << std::endl;
  while (next(arr, n, r)) {
    for (int i = 0; i < r; ++i) {
      std::cout << arr[i]+1 << ", ";
    }
    std::cout << std::endl;
  }

  return 0;
}
