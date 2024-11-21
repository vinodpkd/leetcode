//3285. Find Indices of Stable Mountains
/*
There are n mountains in a row, and each mountain has a height. You are given an integer array height where height[i] represents the height of mountain i, and an integer threshold.
A mountain is called stable if the mountain just before it (if it exists) has a height strictly greater than threshold. Note that mountain 0 is not stable.
Return an array containing the indices of all stable mountains in any order.
*/
class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {
        std::vector<int> stable{};
        for(int i = 1;i < height.size();i++)
        {
            if(height[i-1] > threshold)
                stable.push_back(i);
        }
        return stable;
    }
};
