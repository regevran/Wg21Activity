#include <concepts> 

template <typename T, typename... Us>
concept same_as_any_of = (std::same_as<T, Us> || ...);

template <typename T, typename... Us>
concept converible_to_any_of = (std::convertible_to<T, Us> || ...);

template <typename T, typename... Us>
concept converible_to_all_of = (std::convertible_to<T, Us> && ...);

namespace impl{
    template <typename T, typename... Us> 
    struct convertible_counter{
        constexpr static std::size_t counter_ = ((std::convertible_to<T, Us> ? 1 : 0) + ...);
    };
}

template <typename T, typename... Us>
concept converible_to_one_of = impl::convertible_counter<T, Us...>::counter_ == 1;


