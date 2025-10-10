# 🪞 10. C++ Template Reflection System (Pre-C++26 Style)

Goal: Build a “reflection” system before official reflection exists.

```cpp
struct User { std::string name; int id; };

constexpr auto fields = reflect<User>();
// fields -> type_list<field<"name", std::string>, field<"id", int>>
```

💀 Challenge:

- Use SFINAE to probe members via detection idiom.
- Build type metadata tables at compile time.
- Bonus: Make it interoperable with constexpr JSON serializers.