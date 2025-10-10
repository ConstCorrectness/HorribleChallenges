# 🔮 7. Type-level Query Language

Goal: Define a compile-time SQL-like query system over a type_list of structs.

```cpp
struct Song { std::string name; int plays; };
struct Album { std::string title; int year; };

using data = type_list<Song, Album>;

using q = select<fields<"name">>::from<Song>::where<greater_than<"plays", 1000>>;
using result = execute_t<q, data>;
```

💀 Challenge:

- Encode field access via decltype(&T::field).
- Validate queries at compile time.
- Return filtered and projected type lists.