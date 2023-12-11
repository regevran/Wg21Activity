
#include "3way.hpp"
#include "catch2/catch_all.hpp"

struct CharIntComp
{
    template<typename T, typename U = T>
    constexpr auto operator()(T t, U u) -> std::partial_ordering
    {
        static_assert(std::same_as<T,int>);
        static_assert(std::same_as<U,char>);

        int char_as_int = static_cast<int>(u);
        if (char_as_int < 10)
        {
            return char_as_int <=> t;
        }
        else
        {
            return std::partial_ordering::unordered;
        }
    }
};
    
TEST_CASE("unordered")
{
    std::vector<int> v1{0, 1, 2, 3};
    std::vector<char> v2{'a', 'b'};

    auto res = 
        std::ranges::lexicographical_compare_three_way(
            std::ranges::begin(v1), std::ranges::end(v1),
            std::ranges::begin(v2), std::ranges::end(v2),
            CharIntComp{}
        );

    CHECK(res == std::partial_ordering::unordered);

    res = 
        std::ranges::lexicographical_compare_three_way(
            v1, v2, CharIntComp{}
        );

    CHECK(res == std::partial_ordering::unordered);
}

TEST_CASE("constexpr unordered")
{
    constexpr std::array<int,4> v1{0, 1, 2, 3};
    constexpr std::array<char,2> v2{'a', 'b'};

    constexpr auto res = 
        std::ranges::lexicographical_compare_three_way(
            std::ranges::begin(v1), std::ranges::end(v1),
            std::ranges::begin(v2), std::ranges::end(v2),
            CharIntComp{}
        );

    static_assert(res == std::partial_ordering::unordered); 
}

