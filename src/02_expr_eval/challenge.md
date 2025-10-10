# 🧮 2. Compile-time Expression Evaluator

Goal: Parse and evaluate arithmetic expressions entirely in templates, no runtime parsing.

```cpp
// Example usage:
constexpr auto val = eval<expr<"((2+3)*4)-5">>();
static_assert(val == 15);
```


💀 Challenge:

- Implement recursive-descent parsing using templates and constexpr string views.
- Handle parentheses, operator precedence, and unary minus.
- No constexpr if for branching logic — use partial specialization instead.