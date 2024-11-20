//3280. Convert Date to Binary
/*
You are given a string date representing a Gregorian calendar date in the yyyy-mm-dd format.
date can be written in its binary representation obtained by converting year, month, and day to their binary representations without any leading zeroes and writing them down in year-month-day format.
Return the binary representation of date.
*/
class Solution {
public:
    string convertDateToBinary(string date) {
        //std::stoi( str )
        string s{""};
        int i = 0;
        for(int i = 0;i < 4;i++)
        {
           s = s + date[i];
        }

        int y = std::stoi(s);
        i++;
        s = "";

        for(i = 5;i < 7;i++)
        {
           s = s + date[i];
        }

        //std::cout << "m = " << s << '\n';
        int m = std::stoi(s);
        i++;
        s = "";

        for(;i < date.size();i++)
        {
           s = s + date[i];
        }
        int d = std::stoi(s);

        std::string yb = std::bitset<16>(y).to_string();
        std::string mb = std::bitset<4>(m).to_string();
        std::string db = std::bitset<8>(d).to_string();

        //std::cout << y << '-' << m << '-' << d << '\n';

        return remove_lead_zeros(yb) + '-' + remove_lead_zeros(mb) + '-' + remove_lead_zeros(db);
    }

    string remove_lead_zeros(string s)
    {
        
        for(auto it = s.begin();it != s.end();it++)
        {
            if('1' == *it)
            {
                string t(it,s.end());
                return t;
            }
        }

        return s;
    }
};
