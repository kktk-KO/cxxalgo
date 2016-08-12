#pragma once

#include <algorithm>

namespace cxxalgro { namespace sort {

template <class Iterator, class Compare>
void comb_sort (Iterator first, Iterator last, Compare const & comp) {
  auto size = std::distance(first, last);
  decltype(size) h = size * 10 / 13;

  bool flag = true;
  while (flag) {
    flag = false;
    for (decltype(size) i = 0; i < size - h; ++i) {
      if (!comp(first[i], first[i + h])) {
        std::swap(first[i], first[i + h]);
        flag = true;
      }
    }
    if (h != 1) {
      flag = true;
      h = h * 10 / 13;
    }
    
  }
}

template <class Iterator>
void comb_sort (Iterator first, Iterator last) {
  using value_type = decltype(*first);
  comb_sort(first, last, [] (value_type const & left, value_type const & right) {
    return left < right;
  }); 
}

}}
