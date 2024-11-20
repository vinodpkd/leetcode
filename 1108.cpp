//1108. Defanging an IP Address
/*
Given a valid (IPv4) IP address, return a defanged version of that IP address.
A defanged IP address replaces every period "." with "[.]".
*/

class Solution {
public:
    string defangIPaddr(string address) {
        
        string s{""};
        std::vector<std::string> nums{};

        for(int i = 0;i < address.size();i++)
        {
            if('.' != address[i])
            {
                s = s + address[i];
            }
            else
            {
                nums.push_back(s);
                s = "";
            }
        }

        nums.push_back(s);
       
        s = nums[0];

        for(int i = 1;i < 4; i++)
        {
            s = s + "[.]" + nums[i];
        }

        return s;

        return s;
    }
};
