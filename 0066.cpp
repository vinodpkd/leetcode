//66. Plus One
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        std::set<int> set1 (digits.begin(),digits.end());
        auto elem = set1.begin();
        if(set1.size() == 1 && 9 == *elem)
        {
            for(int i = 0;i < digits.size();i++)
                digits[i] = 0;
            digits.insert(digits.begin(),1);
            return digits;
        }

        int carry = 0;
        for(auto it = digits.rbegin();it != digits.rend();it++)
        {
            if(it == digits.rbegin())
            {
                *it = *it + 1;
                if(*it > 9)
                {
                    carry = 1;
                    *it = *it - 10;
                    if(1 == digits.size())
                    {
                        digits.insert(digits.begin(),carry);
                        break;
                    }
                       
                }
                else
                {
                   return digits;
                }
            }
            else
            {
                *it = *it + carry;
                if(*it > 9)
                {
                    carry = 1;
                    *it = *it - 10;
                    
                }
                else
                {
                    carry = 0;
                }
            }
        }

        return digits;
    }
};
