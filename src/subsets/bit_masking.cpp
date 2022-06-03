#include "assignment/subsets/bit_masking.hpp"

#include <cassert>  // assert

#include "assignment/bits.hpp"  // is_bit_set

namespace assignment {

  std::vector<std::vector<int>> SubsetsBitMasking::generate(const std::vector<int>& set) const {
    assert(set.size() <= 16);

    const auto num_elems = static_cast<int>(set.size());  // N
    const int num_subsets = 1 << num_elems;               // 2^N

    // выделяем память
    auto subsets = std::vector<std::vector<int>>(num_subsets);

    for(int mask = 0; mask < num_subsets; mask++){
      for(int pos = 0; pos < num_elems; pos++) {
        if (is_bit_set(mask, pos)) {
          subsets[mask].push_back(pos);
        }
      }
    }

    return subsets;
  }

}  // namespace assignment