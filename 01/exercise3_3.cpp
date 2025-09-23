#include <vector>
#include <limits>
#include <type_traits>
#include <stdexcept>
#include <cstddef>
#include <concepts>

// Accumulateur pour flottants : Neumaier (somme compensée)
template <std::floating_point T>
struct FloatAccumulator {
    long double sum = 0.0L;
    long double comp = 0.0L; // compensation

    void add(T x) noexcept {
        long double vx = static_cast<long double>(x);
        long double t = sum + vx;
        if (std::fabsl(sum) >= std::fabsl(vx)) {
            comp += (sum - t) + vx;
        } else {
            comp += (vx - t) + sum;
        }
        sum = t;
    }
    [[nodiscard]] long double value() const noexcept { return sum + comp; }
    void clear() noexcept { sum = 0.0L; comp = 0.0L; }
};

// Accumulateur pour entiers : accumulate en long double (simple, pas d’overflow machine)
template <std::integral T>
struct IntAccumulator {
    long double sum = 0.0L;
    void add(T x) noexcept { sum += static_cast<long double>(x); }
    [[nodiscard]] long double value() const noexcept { return sum; }
    void clear() noexcept { sum = 0.0L; }
};

// Si vous voulez une somme entière EXACTE pour int/long long, remplacez IntAccumulator par ceci (si GCC/Clang) :
// template <std::integral T>
// struct IntAccumulator {
//     __int128 sum = 0;
//     void add(T x) noexcept { sum += static_cast<__int128>(x); }
//     [[nodiscard]] long double value() const noexcept { return static_cast<long double>(sum); } // moyenne en long double
//     // Vous pouvez aussi exposer sum en __int128 si besoin.
//     void clear() noexcept { sum = 0; }
// };

template <typename T>
class Statistics {
public:
    using value_type = T;

    Statistics() = default;

    void reserve(std::size_t n) { data.reserve(n); }

    void add(T value) {
        if (count_ == 0) {
            min_value = value;
            max_value = value;
        } else {
            if (value < min_value) min_value = value;
            if (value > max_value) max_value = value;
        }
        data.push_back(value);
        acc.add(value);
        ++count_;
    }

    template <typename Range>
    void add_range(const Range& r) {
        for (const auto& v : r) add(static_cast<T>(v));
    }

    [[nodiscard]] std::size_t size() const noexcept { return count_; }
    [[nodiscard]] bool empty() const noexcept { return count_ == 0; }

    // Retour en long double pour maximiser la précision
    [[nodiscard]] long double average() const {
        if (empty()) {
            // au choix: throw, NaN, optional
            return std::numeric_limits<long double>::quiet_NaN();
        }
        return acc.value() / static_cast<long double>(count_);
    }

    [[nodiscard]] T min() const {
        if (empty()) throw std::runtime_error("Statistics::min() on empty set");
        return min_value;
    }

    [[nodiscard]] T max() const {
        if (empty()) throw std::runtime_error("Statistics::max() on empty set");
        return max_value;
    }

    void clear() {
        data.clear();
        acc.clear();
        count_ = 0;
        // min/max laissés indéfinis jusqu’au prochain add
    }

    // Accès aux données si vous en avez besoin
    [[nodiscard]] const std::vector<T>& values() const noexcept { return data; }

private:
    std::vector<T> data;

    // Choix d’accumulateur suivant T
    using Acc =
        std::conditional_t<std::is_floating_point_v<T>, FloatAccumulator<T>, IntAccumulator<T>>;
    Acc acc{};

    T min_value{};
    T max_value{};
    std::size_t count_ = 0;
};
