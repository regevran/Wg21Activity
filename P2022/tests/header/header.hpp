

#include <concept>

namespace std
{

template<
    input_iterator I1, sentinel_for<I1> S1,
    input_iterator I2, sentinel_for<I2> S2,
    class Proj1 = identity, 
    class Proj2 = identity,
    class Comp = compare_three_way
>
requires
    three_way_comparable_with< 
        projected<I1,Proj1>, projected<I2,Proj2> 
    >
constexpr auto
    ranges::lexicographical_compare_three_way( 
        I1 first1, 
        S1 last1, 
        I2 first2, 
        S2 last2, 
        Comp comp = {}, 
        Proj1 = {}, 
        Proj2 = {}
    ) -> std::common_comparison_category_t<
                decltype(
                        comp(Proj1(I1), Proj2(I2))), 
                        strong_ordering
                >
{
    return strong_ordering::equal;
}

}
