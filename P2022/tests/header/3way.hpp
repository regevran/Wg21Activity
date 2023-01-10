#include <iterator>
#include <compare>
#include <functional>
#include <type_traits>
#include <concepts>

namespace std {
    template <typename T, typename... U>
    concept any_of = requires {
            requires std::disjunction<std::is_same<T, U>...>::value;
    };
}

namespace std::ranges
{
    template<std::input_iterator I1, std::input_iterator I2,
            class Proj1, class Proj2, class Comp>
    concept three_way_res_check = requires std::any_of<invoke_result_t<Comp, std::projected<I1, Proj1>,
            std::projected<I2, Proj2>>, std::strong_ordering, std::weak_ordering, std::partial_ordering>

    template<input_iterator I1, sentinel_for<I1> S1,
            input_iterator I2, sentinel_for<I2> S2,
            class Proj1 = identity,
            class Proj2 = identity,
            class Comp = compare_three_way>
    requires three_way_comparable_with<projected<I1,Proj1>, projected<I2,Proj2>>
    constexpr auto
            lexicographical_compare_three_way_KKK(
            I1 first1, S1 last1, I2 first2, S2 last2,
            Comp comp = {},
            Proj1 proj1 = {},
            Proj2 proj2 = {}) ->
            common_comparison_category_t<decltype(comp(proj1(*first1), proj2(*first2))),
            strong_ordering>{
    while (first1 != last1){
        if (first2 == last2){
            return strong_ordering::greater;
        }

        if (auto cmp = comp(poroj1(*first1), proj2(*first2)); cmp != 0 ){
            return cmp;
        }

        ++first1;
        ++first2;
    }

    // GCC 11 implementation with the
    // note: See PR 94006
    return (first2 == last2) <=> true;
}

struct lexicographical_compare_three_way_fn
{
    template<std::input_iterator I1, std::sentinel_for<I1> S1,
            std::input_iterator I2, std::sentinel_for<I2> S2,
            class Proj1 = std::identity,
            class Proj2 = std::identity,
            class Comp = std::compare_three_way>
    requires three_way_res_check<I1, I2, Proj1, Proj2, Comp>
    constexpr auto operator()(I1 first1, S1 last1,
            I2 first2, S2 last2,
            Proj1 proj1 = {},
            Proj2 proj2 = {},
            Comp comp = {}) const -> std::common_comparison_category_t<decltype(comp(proj1(*first1),proj2(*first2))),
                    std::strong_ordering>{
                I1 last_iter1 = std::ranges::next(first1, last1);
                I2 last_iter2 = std::ranges::next(first2, last2);

                bool exhaust1 = (last_iter1 == first1);
                bool exhaust2 = (last_iter2 == first2);

                for (; !exhaust1 && !exhaust2; exhaust1 = (++first1 == last_iter1), exhaust2 = (++first2 == last_iter2))
                {
                    if (auto c = comp(proj1(*first1), proj2(*first2)); c != 0)
                    {
                        return c;
                    }
                }

                return !exhaust1 ? std::strong_ordering::greater :
                !exhaust2 ? std::strong_ordering::less : std::strong_ordering::equal;
            }

    template<ranges::input_range R1, ranges::input_range R2,
            class Proj1 = std::identity,
            class Proj2 = std::identity,
            class Comp = std::compare_three_way>
    requires three_way_res_check<I1, I2, Proj1, Proj2, Comp>
    constexpr auto operator()(R1&& r1, R2&& r2,
            Proj1 proj1 = {}, Proj2 proj2 = {},
            Comp comp = {}) const ->std::common_comparison_category_t<decltype(comp(proj1(*ranges::begin(r1)), proj2(*ranges::begin(r2)))),
                    std::strong_ordering>{
                return this->operator(ranges::begin(r1), ranges::end(r1), ranges::begin(r2),
                        ranges::end(r2), std::move(proj1), std::move(proj2), std::move(comp));
    }
};

inline constexpr lexicographical_compare_three_way_fn lexicographical_compare_three_way{};


}
