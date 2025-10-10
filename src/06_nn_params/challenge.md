# 🧬 6. Compile-time Neural Network Topology Evaluator

Goal: Represent a neural network structure and compute the number of parameters (weights + biases) at compile time.

```cpp
using net = network<
  layer<64, 128>,
  layer<128, 32>,
  layer<32, 10>
>;

static_assert(param_count<net> == (64*128 + 128) + (128*32 + 32) + (32*10 + 10));
```

💀 Challenge:

- Encode everything in templates (no constexpr lambdas).
- Use fold expressions and variadic packs elegantly.
- Bonus: Add static shape validation.