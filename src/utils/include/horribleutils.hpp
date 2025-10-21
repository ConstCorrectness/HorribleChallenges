#ifndef HORRIBLE_UTILS_HPP_
#define HORRIBLE_UTILS_HPP_


#include <cstddef>

namespace horrible::utils
{

template<typename... Ts>
class Typelist {
  using size_type = size_t;
  static constexpr size_type const size = sizeof...(Ts);
};


// metafunctions

inline namespace metafunctions 
{

template<typename LIST> struct front;

template<typename Head, typename... Tail>
struct front<Typelist<Head, Tail...>> {
  using type = Head;
};



template<typename LIST> struct back;

template<typename T> struct back<Typelist<T>> {
  using type = T;
};

template<typename Head, typename... Tail>
struct back<Typelist<Head, Tail...>> {
  using type = typename back<Typelist<Tail...>>::type;
};


}               // end namespace horrible::utils::inline metafunctions

template<typename LIST>
using front_t = typename front<LIST>::type;

template<typename LIST>
using back_t = typename back<LIST>::type;

}               // end namespace horrible::utils


#endif          // HORRIBLE_UTILS_HPP_