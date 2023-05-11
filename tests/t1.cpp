#include "../catch.hpp"

#include "../3way.hpp"


TEST_CASE("t1")
{
    std::vector<int> v1{ 0, 1, 2, 3 };
    std::vector<int> v2{ 0, 1, 2, 4 };

    auto res =
        std::ranges::lexicographical_compare_three_way(v1, v2);

    CHECK(res == std::strong_ordering::less);
}
