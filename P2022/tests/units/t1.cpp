

#include "3way.hpp"
#include "catch2/catch_all.hpp"

TEST_CASE("t1")
{
    std::vector<int> v1{0, 1, 2, 3};
    std::vector<int> v2{0, 1, 2, 4};

    auto res = 
        std::ranges::lexicographical_compare_three_way(
            std::ranges::begin(v1), std::ranges::end(v1),
            std::ranges::begin(v2), std::ranges::end(v2)
        );

    CHECK(res == std::strong_ordering::less);
}

TEST_CASE("constexpr t1")
{
    constexpr std::array<int,4> v1{0, 1, 2, 3};
    constexpr std::array<int,4> v2{0, 1, 2, 4};

    constexpr auto res = 
        std::ranges::lexicographical_compare_three_way(
            std::ranges::begin(v1), std::ranges::end(v1),
            std::ranges::begin(v2), std::ranges::end(v2)
        );

    static_assert(!(res != std::strong_ordering::less));
}
