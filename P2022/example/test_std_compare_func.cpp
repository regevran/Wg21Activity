
#include <compare>
#include <vector>
#include <string>

struct tree {};

// two trees are never ordered
std::partial_ordering cmp_tree(tree&, tree&)
{
    return std::partial_ordering::unordered;
}

struct apple_tree //: tree
{
    int row;
    int colum;
};

// apple trees are strongly ordered
//    1 2 3 4 5 6
// 1: # # # # # #
// 2: # a # # # #
// 3: # # b # # c
// 4: # # # # # #
// cmp(a,a) --> equal
// cmp(a,b) --> less (a's row smaller)
// cmp(c,b) --> greater (b's colum smaller)
std::strong_ordering cmp_apple_tree(apple_tree& a, apple_tree& b)
{
    return a.row < b.row ? 
                std::strong_ordering::less :
                a.row > b.row ?
                    std::strong_ordering::greater :
                    a.colum < b.colum ?
                        std::strong_ordering::less :
                            a.colum > b.colum ?
                                std::strong_ordering::greater :
                                std::strong_ordering::equal; 
}


int main()
{
    std::vector<tree> forest1(10), forest2(10);

    auto ret1 = std::lexicographical_compare_three_way(
            forest1.begin(), forest1.end(),
            forest2.begin(), forest2.end(),
            cmp_tree );

    static_assert(std::is_same<decltype(ret1), std::partial_ordering>::value);

    std::vector<apple_tree> area_a
    {
        {1,1},{1,2},{1,3},{1,4},
        {2,1},{2,2},{2,3},{2,4},
        {3,1},{3,2},{3,3},{3,4}
    };



    return 0;
}
