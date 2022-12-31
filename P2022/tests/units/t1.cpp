

#include "3way.hpp"
#include "catch2/catch_all.hpp"

TEST_CASE("t1")
{
    auto const v1{0, 1, 2, 3};
    auto const v2{0, 1, 2, 4};

    auto res = 
        std::ranges::lexicographical_compare_three_way_KKK(
            std::ranges::begin(v1), std::ranges::end(v1),
            std::ranges::begin(v1), std::ranges::end(v1)
        );

    CHECK(res == std::strong_ordering::less);
}


