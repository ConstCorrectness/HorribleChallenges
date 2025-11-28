# 👯‍♀️ Compile-Time Byte-Pair Encoding (BPE) — Template Metaprogramming Challenge

Goal:  
Implement a minimal **Byte-Pair Encoding (BPE)** system entirely using **C++ template metaprogramming**.  
All logic must execute at **compile time**: vocabulary construction, pair-frequency computation, best-pair selection, and token merging.

This is conceptually parallel to a compile-time neural-network parameter counter, but more involved.

---

## 📦 1. Input Representation

Represent the input text using a type-level sequence:

```cpp
using input = str<'l','o','w','e','r',' ','l','o','w','e','r'>;
```

Characters are template parameters.  
Tokens produced by merges should be represented as:

```cpp
template<char... Cs>
struct token {};
```

Adjacent character pairs:

```cpp
template<char A, char B>
struct pair {};
```

---

## 🧠 2. Requirements

### 2.1 Initial Vocabulary  
Build an initial vocabulary containing all unique characters in the input text.

### 2.2 Pair Enumeration  
From the input sequence, enumerate all adjacent pairs:

```
(l,o), (o,w), (w,e), (e,r), (r,' '), (' ',l) ...
```

Represent these as types.

### 2.3 Frequency Counting  
Count the frequency of each distinct pair using **template recursion**, **partial specialization**, and **variadic packs**.

No `constexpr` lambdas, no runtime loops.

### 2.4 Best-Pair Selection  
Select the **most frequent adjacent pair** at compile time.

### 2.5 Merging  
Given the most frequent pair `P`, merge every non-overlapping occurrence in the sequence.

For example:

```
l o w e r l o w e r
```

If merging `l o`:

```
(l o) w e r (l o) w e r
```

Use `token<'l','o'>` as a new vocabulary entry.

### 2.6 Recursion  
Perform `N` merge steps:

```cpp
using result = bpe<input, 4>;
```

Each step updates both:

- the tokenized sequence
- the vocabulary

---

## 🧾 3. Expected Interface

### Entry point

```cpp
template<typename Str, std::size_t N>
struct bpe;
```

The result must define:

```cpp
using encoded = typename result::encoded;
using vocab   = typename result::vocab;
```

### Example checks  
Your implementation should satisfy assertions like:

```cpp
// tokens created during merges
static_assert(contains<result::vocab, token<'l','o'>>);
static_assert(contains<result::vocab, token<'e','r'>>);

// structure of the encoded output
static_assert(std::is_same_v<
    result::encoded,
    str<
        token<'l','o'>,
        token<'w','e','r'>,
        token<' '>,
        token<'l','o'>,
        token<'w','e','r'>
    >
>);
```

(These are structural examples; the exact output depends on your implementation.)

---

## 💀 4. Constraints

1. **Absolutely no runtime logic**.  
   Only templates, type recursion, and fold expressions.

2. **No `constexpr` lambdas**, no `std::string`, no mutable runtime state.

3. **No external preprocessing**.

4. **No compiler extensions** (GCC/Clang/MSVC must all work).

---

## ⭐ Bonus Challenges

1. Static validation for invalid characters.  
2. Unicode support with `char32_t`.  
3. Pretty-printing by mapping the resulting token types back into a runtime string.  
4. Vocabulary deduplication with template sets.  
5. Overlapping-pair correctness.

---

## ✔ Deliverable

A pure-template TMP implementation of BPE that:

- accepts a type-level character sequence,  
- performs `N` BPE merges,  
- outputs the final encoded token sequence,  
- outputs the vocabulary,  
++

