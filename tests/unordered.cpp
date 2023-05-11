#include "../catch.hpp"

#include "../3way.hpp"


struct CharIntComp
{
    template<typename T, typename U = T>
    auto operator()(T t, U u) -> std::partial_ordering
    {
        static_assert(std::same_as<T, int>);
        static_assert(std::same_as<U, char>);

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
    std::vector<int> v1{ 0, 1, 2, 3 };
    std::vector<char> v2{ 'a', 'b' };

    auto res =
        std::ranges::lexicographical_compare_three_way(v1, v2, CharIntComp{});

    CHECK(res == std::partial_ordering::unordered);
}
