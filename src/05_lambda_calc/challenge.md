# 🧠 5. Type-level λ-Calculus Interpreter

Goal: Represent lambda calculus expressions and perform β-reduction at compile time.

```cpp
// Example encoding
using expr = apply<
  lambda<"x", apply<lambda<"y", var<"y">>, var<"x">>>,
  int
>;

using result = normalize_t<expr>; // Should yield `int`
```

💀 Challenge:

- Implement substitution safely (avoid variable capture).
- Perform β-reduction via partial specialization.
- Represent variable bindings using compile-time symbol tables.