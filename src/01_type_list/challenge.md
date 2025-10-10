# 🧩 1. Type Sequence Algebra

Goal: Implement a type_list class template and define compile-time set operations.


```cpp
// Example usage:
using list1 = type_list<int, double, char>;
using list2 = type_list<char, float, int>;

static_assert(std::is_same_v<union_t<list1, list2>, type_list<int, double, char, float>>);
static_assert(std::is_same_v<intersect_t<list1, list2>, type_list<int, char>>);
static_assert(std::is_same_v<difference_t<list1, list2>, type_list<double>>);
```

💀 Challenge:

- Must support arbitrary length.
- Must deduplicate while preserving order.
- Must be done entirely at compile time, no constexpr functions.