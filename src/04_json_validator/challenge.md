# ⚗️ 4. Compile-time JSON Type Validator

Goal: Given a C++ type and a JSON type schema encoded as a template, verify compatibility at compile time.

```cpp
template<typename T>
struct json_schema;

struct Person { std::string name; int age; };

using schema = json_obj<
  json_pair<"name", json_string>,
  json_pair<"age", json_number>
>;

static_assert(validate_json<Person, schema>);
```

💀 Challenge:

- Use reflection-like tricks (requires, decltype, etc.) to map struct members to schema fields.
- Handle nested structs and arrays.
- Compile-time diagnostics for mismatches.