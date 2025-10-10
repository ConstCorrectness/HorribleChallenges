# 🧱 3. Static Pattern Matching Engine

Goal: Build a compile-time regular-expression-like pattern matcher for std::integer_sequence.

```cpp
using seq = std::integer_sequence<int, 1, 2, 3, 4, 5>;

template <auto... Pattern>
struct pattern {};

static_assert(matches<seq, pattern<1, _, 3, _, _>>); // true
static_assert(!matches<seq, pattern<_, 2, 2>>);      // false
```

💀 Challenge:

- Implement _ as a wildcard.
- Allow repetition operators like * and +.
- Purely template recursion — no constexpr runtime logic.