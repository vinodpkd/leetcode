//2974. Minimum Number Game
/*
You are given a 0-indexed integer array nums of even length and there is also an empty array arr. Alice and Bob decided to play a game where in every round Alice and Bob will do one move. The rules of the game are as follows:
Every round, first Alice will remove the minimum element from nums, and then Bob does the same.
    Now, first Bob will append the removed element in the array arr, and then Alice does the same.
    The game continues until nums becomes empty.
*/
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        std::multiset<int, std::greater<int> > mset(nums.begin(),nums.end());
        std::stack<int> st(mset.begin(),mset.end());
        nums.clear();
        while(!st.empty())
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            nums.push_back(b);
            nums.push_back(a);

        }

        return nums;
    }
};
