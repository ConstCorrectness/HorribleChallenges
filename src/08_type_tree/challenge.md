🔺 8. Type Deduction Tree Visualizer

Goal: Build a compile-time type tree printer using C++20 concepts and string literals.

template<typename T>
constexpr auto print_type_tree();

struct Foo { int a; double b; };
print_type_tree<Foo>();


Output (compile-time generated string):

Foo
 ├── int a
 └── double b


💀 Challenge:

Use fold expressions and constexpr strings to build a tree at compile time.

Encode indentation using template recursion.

No RTTI or reflection — just SFINAE and decltype.