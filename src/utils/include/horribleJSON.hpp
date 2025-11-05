#ifndef HORRIBLE_JSON_HPP_
#define HORRIBLE_JSON_HPP_

#include <concepts>
#include <type_traits>
#include <string>
#include <array>
#include <utility>
#include <algorithm>

namespace horrible::utils {


template<typename T>
struct is_character_type : public std::false_type { };

template<> struct is_character_type<char>          : public std::true_type { };
template<> struct is_character_type<wchar_t>       : public std::true_type { };
template<> struct is_character_type<char8_t>       : public std::true_type { };
template<> struct is_character_type<char16_t>      : public std::true_type { };
template<> struct is_character_type<char32_t>      : public std::true_type { };
template<> struct is_character_type<unsigned char> : public std::true_type { };
template<> struct is_character_type<signed char>   : public std::true_type { };


template<typename T> 
concept CharacterType = is_character_type<T>::value;


template<CharacterType CharT>
constexpr bool is_space(CharT c) {
  constexpr std::array ws { 
    static_cast<CharT>(U'\x20'),         // SP
    static_cast<CharT>(U'\x09'),         // TAB
    static_cast<CharT>(U'\x0B'),         // VTAB
    static_cast<CharT>(U'\x0C'),         // FF
    static_cast<CharT>(U'\x0D'),         // CR
    static_cast<CharT>(U'\x0A')          // LF
  };

  return std::find(ws.begin(), ws.end(), c) != ws.cend();
}

template<CharacterType CharT, typename Traits = std::char_traits<CharT>>
constexpr bool is_space_traits(CharT c) {
    constexpr std::array<CharT, 6> ws{
        static_cast<CharT>(U'\x20'),
        static_cast<CharT>(U'\x09'),
        static_cast<CharT>(U'\x0B'),
        static_cast<CharT>(U'\x0C'),
        static_cast<CharT>(U'\x0D'),
        static_cast<CharT>(U'\x0A')
    };
    return Traits::find(ws.data(), ws.size(), c) != nullptr;
}

}             // end namespace horrible::utils


#endif        // HORRIBLE_JSON_HPP_