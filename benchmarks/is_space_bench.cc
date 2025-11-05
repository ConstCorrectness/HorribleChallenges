#include <benchmark/benchmark.h>
#include <array>
#include <algorithm>
#include <string>

#include "horribleJSON.hpp"


namespace h = horrible::utils;

namespace {

template <typename CharT>
std::basic_string<CharT> make_data(std::size_t n) {
  std::basic_string<CharT> s;
  s.resize(n);
  for (std::size_t i = 0; i < n; ++i) {
        CharT ch = static_cast<CharT>((i % 7 == 0) ? U'\x20'
                        : (i % 13 == 0) ? U'\x09'
                        : U'a' + (i % 26));
        s[i] = ch;
  }
  
  return s;
}

}     // end unnamed namespace

template <typename CharT>
static void BM_is_space_find(benchmark::State& st) {
    auto data = make_data<CharT>(static_cast<std::size_t>(st.range(0)));
    for (auto _ : st) {
        std::size_t count = 0;
        for (CharT c : data) {
            benchmark::DoNotOptimize(count += h::is_space(c));
        }
        benchmark::ClobberMemory();
    }
    st.SetBytesProcessed(st.iterations() * st.range(0) * sizeof(CharT));
}

template <typename CharT>
static void BM_is_space_traits(benchmark::State& st) {
    auto data = make_data<CharT>(static_cast<std::size_t>(st.range(0)));
    for (auto _ : st) {
        std::size_t count = 0;
        for (CharT c : data) {
            benchmark::DoNotOptimize(count += h::is_space_traits<CharT>(c));
        }
        benchmark::ClobberMemory();
    }
    st.SetBytesProcessed(st.iterations() * st.range(0) * sizeof(CharT));
}

BENCHMARK_TEMPLATE(BM_is_space_find, char)->Range(1<<10, 1<<20);
BENCHMARK_TEMPLATE(BM_is_space_traits, char)->Range(1<<10, 1<<20);

#ifdef __cpp_char8_t
BENCHMARK_TEMPLATE(BM_is_space_find, char8_t)->Range(1<<10, 1<<20);
BENCHMARK_TEMPLATE(BM_is_space_traits, char8_t)->Range(1<<10, 1<<20);
#endif

BENCHMARK_TEMPLATE(BM_is_space_find, char16_t)->Range(1<<10, 1<<20);
BENCHMARK_TEMPLATE(BM_is_space_traits, char16_t)->Range(1<<10, 1<<20);

BENCHMARK_TEMPLATE(BM_is_space_find, char32_t)->Range(1<<10, 1<<20);
BENCHMARK_TEMPLATE(BM_is_space_traits, char32_t)->Range(1<<10, 1<<20);

// Optionally wchar_t (size varies by platform)
BENCHMARK_TEMPLATE(BM_is_space_find, wchar_t)->Range(1<<10, 1<<20);
BENCHMARK_TEMPLATE(BM_is_space_traits, wchar_t)->Range(1<<10, 1<<20);

BENCHMARK_MAIN();

