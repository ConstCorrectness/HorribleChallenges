# ⚔️ 9. Metafunction Compiler

Goal: Write a mini “compiler” that takes metafunction definitions and produces executable constexpr results.

```cpp
template <auto Expr>
constexpr auto meta_eval = compile<Expr>::value;

constexpr auto result = meta_eval<"(x + y) * 2", x = 3, y = 4>; // -> 14
```

💀 Challenge:

- Parse symbols, constants, and operators.
- Store symbol bindings in compile-time maps.
- Perform arithmetic entirely in type-space.