# HorribleChallenges
Horrible C++ Challenges

---

A collection of advanced C++ template/metaprogramming challenges designed to exercise compile-time techniques (C++20). Each challenge lives under `src/` and includes a short spec (`challenge.md`), a minimal test harness and an `include/` folder for your implementation.

## Quick Links


- [CMakeLists.txt](CMakeLists.txt)
- [LICENSE](LICENSE)
- Challenges:
  - [01_type_list](src/01_type_list/challenge.md)
  - [02_expr_eval](src/02_expr_eval/challenge.md)
  - [03_pattern_match](src/03_pattern_match/challenge.md)
  - [04_json_validator](src/04_json_validator/challenge.md)
  - [05_lambda_calc](src/05_lambda_calc/challenge.md)
  - [06_nn_params](src/06_nn_params/challenge.md)
  - [07_type_query](src/07_type_query/challenge.md)
  - [08_type_tree](src/08_type_tree/challenge.md)
  - [09_metafunc_compiler](src/09_metafunc_compiler/challenge.md)
  - [10_reflection_system](src/10_reflection_system/challenge.md)


## Build & Run Tests

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build
```


