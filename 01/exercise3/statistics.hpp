#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

template <typename T>
struct Statistics {
  using sum_type =
      std::conditional_t<std::is_integral_v<T>, long long, long double>;
  private: 
    std::vector<T> data;
    T max_value = 0; 
    T min_value = std::numeric_limits<T>::min();

    /**
     * Don't forget to call this method everytime you
     * modify data.
     */
    void update_statistics(T value) {
        min_value = std::min(min_value, value);
        max_value = std::max(max_value, value);
    }

  public: 
    void add(T value) { 
        data.push_back(value); 
        update_statistics(value);
    }

    double average() const {
        if (data.size() == 0) return 0;
        auto sum = std::accumulate(data.begin(), data.end(), sum_type(0));
        return static_cast<double>(sum) / data.size();
    }
    auto min() const {
        return min_value;
    }
    auto max() const {
        return max_value;
    }
};
