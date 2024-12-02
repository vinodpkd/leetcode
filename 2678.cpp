//2678. Number of Senior Citizens
/*
You are given a 0-indexed array of strings details. Each element of details provides information about a given passenger compressed into a string of length 15. The system is such that:
    The first ten characters consist of the phone number of passengers.
    The next character denotes the gender of the person.
    The following two characters are used to indicate the age of the person.
    The last two characters determine the seat allotted to that person.
Return the number of passengers who are strictly more than 60 years old.
*/
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count{0};
        for(int i = 0;i < details.size();i++)
        {
            std::string s1{details[i][11]};
            std::string s2{details[i][12]};
            std::string agestr = s1 + s2;
            int age = std::stoi(agestr);
            if(age > 60)
                count++;
        }
        return count;
    }
};
