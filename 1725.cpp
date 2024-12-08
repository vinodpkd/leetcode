//1725. Number Of Rectangles That Can Form The Largest Square
/*
You are given an array rectangles where rectangles[i] = [li, wi] represents the ith rectangle of length li and width wi.

You can cut the ith rectangle to form a square with a side length of k if both k <= li and k <= wi. For example, if you have a rectangle [4,6], you can cut it to get a square with a side length of at most 4.

Let maxLen be the side length of the largest square you can obtain from any of the given rectangles.

Return the number of rectangles that can make a square with a side length of maxLen.
*/
class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        std::vector<int> minSides;
    for (const auto& rectangle : rectangles) {
        minSides.push_back(std::min(rectangle[0], rectangle[1]));
    }
    int maxLen = *std::max_element(minSides.begin(), minSides.end());
    return std::count(minSides.begin(), minSides.end(), maxLen);
    }
};
