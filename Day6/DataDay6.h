#pragma once

//#define USE_TEST_DATA
#define PART1

#ifdef USE_TEST_DATA
constexpr int s_TimeData[] = { 7, 15, 30 };
constexpr int s_DistanceData[] = { 9, 40, 200 };
#else
#ifdef PART1
constexpr int s_TimeData[] = { 54, 81, 70, 88 };
constexpr int s_DistanceData[] = { 446, 1292, 1035, 1007 };
#else
constexpr unsigned long long s_TimeData[] = { 54817088 };
constexpr unsigned long long s_DistanceData[] = { 446129210351007 };
#endif // PART1
#endif // USE_TEST_DATA