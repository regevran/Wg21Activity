

/*
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
        I1 first1, S1 last1, I2 first2, S2 last2, Comp comp = {}, Proj1 = {}, Proj2 = {}
    ) -> std::common_comparison_category_t<
                decltype(comp(*first1, *first2)), std::strong_ordering>;

template <
    class I1, class S1
    class I2, class S2,
    class Comp
>
constexpr auto
    ranges::lexicographical_compare_three_way( 
        I1 first1, S1 last1, 
        I2 first2, S2 last2, 
        Comp comp)
{
}

*/



int main()
{
    return 0;
}
