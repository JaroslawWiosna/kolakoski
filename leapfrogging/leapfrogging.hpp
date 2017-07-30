/**
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */


#ifndef LEAPFROGGING_HPP
#define LEAPFROGGING_HPP

#include <iostream>
#include <vector>

std::vector<std::size_t> kolakoskiLeapfrogging
    (std::vector<std::size_t> input = {1}) {
  std::size_t sumOfElemInputSeq{};
  for (const auto& i : input) {
    sumOfElemInputSeq += i;
  }
  std::vector<std::size_t> output;
  output.reserve(sumOfElemInputSeq + 1);
  output.emplace_back(1);

  std::size_t j{1};
  std::size_t pos{};
  for (const auto& i : input) {
    pos += i;
    while (j++ != pos) {
      output.emplace_back(output.back());
    }
      if (output.back() == 1){
        output.emplace_back(2); //change (toggle)
      } else {
        output.emplace_back(1); //change (toggle)
      }
  }
  return output;
}

#endif // LEAPFROGGING_HPP
