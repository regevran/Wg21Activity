#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "3way.hpp"


struct BadComp
{
    template<typename T, typename U = T>
    auto operator()(T t, U u) -> bool
    {
        return 5 > 6;
    }
};

TEST_CASE("compilation error")
{
    std::vector<int> v1{ 0, 1, 2, 3 };
    std::vector<int> v2{ 0, 1, 2, 3 };

    // open the followinf section to make sure
    // Comp doesn't compile correctly
    
    /*auto res =
        std::ranges::lexicographical_compare_three_way(v1, v2, BadComp{});*/
    
}