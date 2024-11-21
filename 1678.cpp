//1678. Goal Parser Interpretation
/*
  You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command.
  */
class Solution {
public:
    string interpret(string command) {

std::string result{""};

        std::string temp{""};

        int i = 0;
        while (i < command.size())
        {
			temp = "";
            
            if('G' == command[i])
            {
                result += "G";
                i++;
				//std::cout << "'G' == command[i] " << result << '\n';
				//goto label;
                continue;
            }

            temp += command[i]; temp += command[i+1];
			
			//std::cout << " " << command[i] << " " << command[i+1] << " " << command[i] + command[i+1] << '\n';
			//std::cout << " temp = " << temp << '\n';
			//break;
			
            if("()" == temp)
            {
                result = result + "o";
                i = i + 2;
				//std::cout << "() == temp" << result << '\n';
				//goto label;
                continue;
            }

            if("(a" == temp)
            {
                result = result + "al";
                i = i + 4;
            }
			
			//label:
			//	1+2;
        }

        return result;
    }
};
