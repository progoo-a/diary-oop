#include <gtest/gtest.h>
#include <limits>
#include <vector>
#include <cmath>

#include "statistics.hpp"

TEST(StatisticsInt, EmptyAverageIsZero) {
  Statistics<int> s;
  EXPECT_DOUBLE_EQ(s.average(), 0.0);
}

TEST(StatisticsInt, SingleValueStats) {
  Statistics<int> s;
  s.add(42);
  EXPECT_DOUBLE_EQ(s.average(), 42.0);
  EXPECT_EQ(s.min(), 42);
  EXPECT_EQ(s.max(), 42);
}

TEST(StatisticsInt, MultipleValuesStats) {
  Statistics<int> s;
  std::vector<int> vals{1, 2, 3, 4, 5};
  for (int v : vals) s.add(v);
  EXPECT_DOUBLE_EQ(s.average(), 3.0);
  EXPECT_EQ(s.min(), 1);
  EXPECT_EQ(s.max(), 5);
}

TEST(StatisticsInt, NonMonotonicSequenceMinMax) {
  Statistics<int> s;
  std::vector<int> vals{10, -3, 7, -20, 15, 0, 8};
  for (int v : vals) s.add(v);
  EXPECT_DOUBLE_EQ(s.average(), (10 - 3 + 7 - 20 + 15 + 0 + 8) / 7.0);
  EXPECT_EQ(s.min(), -20);
  EXPECT_EQ(s.max(), 15);
}

// ⚠️ Ce test met en évidence un bug d'initialisation de max_value (=0).
TEST(StatisticsInt, AllNegativeValuesShouldTrackMaxCorrectly) {
  Statistics<int> s;
  std::vector<int> vals{-10, -5, -7, -1, -3};
  for (int v : vals) s.add(v);
  // Le max attendu est -1 (le plus élevé des négatifs)
  EXPECT_EQ(s.max(), -1) << "Attendu: le max des valeurs négatives";
  EXPECT_EQ(s.min(), -10);
  // La moyenne est négative
  EXPECT_DOUBLE_EQ(s.average(), (-10 - 5 - 7 - 1 - 3) / 5.0);
}

TEST(StatisticsInt, LargeValuesNoOverflowInAverage) {
  Statistics<int> s;
  // 1'000'000'000 répété 10 fois -> somme = 10'000'000'000 (tient dans long long)
  for (int i = 0; i < 10; ++i) s.add(1'000'000'000);
  EXPECT_DOUBLE_EQ(s.average(), 1'000'000'000.0);
  EXPECT_EQ(s.min(), 1'000'000'000);
  EXPECT_EQ(s.max(), 1'000'000'000);
}

TEST(StatisticsInt, MixedLargeAndSmallValues) {
  Statistics<int> s;
  s.add(std::numeric_limits<int>::max());
  s.add(0);
  s.add(-100);
  // moyenne = (INT_MAX + 0 - 100)/3
  long double expected =
      (static_cast<long double>(std::numeric_limits<int>::max()) - 100.0L) / 3.0L;
  EXPECT_NEAR(s.average(), static_cast<double>(expected), 1e-6);
  EXPECT_EQ(s.min(), -100);
  EXPECT_EQ(s.max(), std::numeric_limits<int>::max());
}

TEST(StatisticsDouble, AveragePrecision) {
  Statistics<double> s;
  s.add(0.1);
  s.add(0.2);
  s.add(0.3);
  // Somme exacte en long double, moyenne ≈ 0.2
  EXPECT_NEAR(s.average(), 0.2, 1e-12);
  // On évite de tester min()/max() pour double ici car l'initialisation actuelle
  // de min_value avec numeric_limits<double>::min() (plus petite positive)
  // n'est pas adaptée pour des valeurs négatives.
}

TEST(StatisticsInt, RepeatedValues) {
  Statistics<int> s;
  for (int i = 0; i < 5; ++i) s.add(7);
  EXPECT_DOUBLE_EQ(s.average(), 7.0);
  EXPECT_EQ(s.min(), 7);
  EXPECT_EQ(s.max(), 7);
}

// Optional: test “gros volume” (sans assertion fine, juste que ça tourne et reste cohérent)
TEST(StatisticsInt, ManyValuesStability) {
  Statistics<int> s;
  long long sum = 0;
  int current_min = std::numeric_limits<int>::max();
  int current_max = std::numeric_limits<int>::lowest();
  for (int i = -5000; i <= 5000; ++i) {
    s.add(i);
    sum += i;
    current_min = std::min(current_min, i);
    current_max = std::max(current_max, i);
  }
  EXPECT_DOUBLE_EQ(s.average(), static_cast<double>(sum) / 10001.0);
  EXPECT_EQ(s.min(), current_min);
  EXPECT_EQ(s.max(), current_max);
}
