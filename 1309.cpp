//1309. Decrypt String from Alphabet to Integer Mapping
/*
You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:
    Characters ('a' to 'i') are represented by ('1' to '9') respectively.
    Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.
The test cases are generated so that a unique mapping will always exist.
*/
class Solution {
public:
    string freqAlphabets(string s) {
        std::map<char,char> ai{};
        ai.insert(std::make_pair('1','a'));
        ai.insert(std::make_pair('2','b'));
        ai.insert(std::make_pair('3','c'));
        ai.insert(std::make_pair('4','d'));
        ai.insert(std::make_pair('5','e'));
        ai.insert(std::make_pair('6','f'));
        ai.insert(std::make_pair('7','g'));
        ai.insert(std::make_pair('8','h'));
        ai.insert(std::make_pair('9','i'));

        std::map<std::string,char> jz{};
        jz.insert(std::make_pair("10#",'j'));
        jz.insert(std::make_pair("11#",'k'));
        jz.insert(std::make_pair("12#",'l'));
        jz.insert(std::make_pair("13#",'m'));
        jz.insert(std::make_pair("14#",'n'));
        jz.insert(std::make_pair("15#",'o'));
        jz.insert(std::make_pair("16#",'p'));
        jz.insert(std::make_pair("17#",'q'));
        jz.insert(std::make_pair("18#",'r'));
        jz.insert(std::make_pair("19#",'s'));
        jz.insert(std::make_pair("20#",'t'));
        jz.insert(std::make_pair("21#",'u'));
        jz.insert(std::make_pair("22#",'v'));
        jz.insert(std::make_pair("23#",'w'));
        jz.insert(std::make_pair("24#",'x'));
        jz.insert(std::make_pair("25#",'y'));
        jz.insert(std::make_pair("26#",'z'));
        std::string t{};
        int i = s.size()-1;
        while(i >= 0)
        {
            if(s[i] == '#')
            {
                std::string hash{};
                std::string s1{s[i-2]};
                std::string s2{s[i-1]};
                hash = s1 + s2 + "#";
                std::string s4{jz[hash]};
                std::cout << i << ' ' << hash << '\n';
                t.insert(0,s4);
                i = i - 3;
            }
            else
            {
                string s3{ai[s[i]]};
                std::cout << "else" << i << ' ' << s[i] << ' ' << s3 << '\n';
                t.insert(0,s3);
                i--;
            }
        }

        return t;
    }
};
