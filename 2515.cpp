//2515. Shortest Distance to Target String in a Circular Array

/*
*/
#include <bits/stdc++.h>


int closetTarget(std::vector<std::string>& words, std::string target, int startIndex) {
        std::vector<int> d{};
        for(int i = 0;i < words.size();i++)
        {
            if(words[i] == target)
            {
                d.push_back(abs(i-startIndex));
                int k = words.size() - 1 - (i-startIndex);
                d.push_back(abs(k));
            }
        }

        int dist = *std::min_element(d.begin(),d.end());
        return dist;
    }


int main()
{	
	
	std::vector<std::string> words{"hello","i","am","leetcode","hello"};
	std::string target{"hello"};
	
	int startIndex = 1;
	
	int k = closetTarget(words,target,startIndex);
	
	std::cout << k << '\n';
	
	return 0;
}

/*
print(v);
	
	std::cout << "Next element to be removed : " << 2 << '\n';
	
	auto it = std::remove_if(v.begin(),v.end(),[](int a){return (a % 2) == 0;});
	
	v.erase(std::remove_if(v.begin(), 
                              v.end(),
                              [](int a){return (a % 2) == 0;}),
               v.end());
	
	v.resize(it - v.begin());
	
	//v.erase(it,v.end());
	
	print(v);

	int nextel = v[0];
	
	std::cout << "Next element to be removed : " << nextel << '\n';
	
	v.erase(std::remove_if(v.begin(), 
                              v.end(),
                              [nextel](int a){return (a % nextel) == 0;}),
               v.end());
	

	
	print(v);
	
	nextel = v[0];
	std::cout << "Next element to be removed : " << nextel << '\n';
	
	it = std::remove_if(v.begin(),v.end(),[nextel](int a){return (a % nextel) == 0;});
	
	v.erase(it,v.end());
	
	print(v);
	
	nextel = v[0];
	
	std::cout << "Next element to be removed : " << nextel << '\n';
	
	it = std::remove_if(v.begin(),v.end(),[nextel](int a){return (a % nextel) == 0;});
	
	v.erase(it,v.end());
	
	print(v);
	
	------------------------
	nextel = v[0];
	
	std::cout << "Next element to be removed : " << nextel << '\n';
	
	v.erase(std::remove_if(v.begin(), 
                              v.end(),
                              [nextel](int a){return (a % nextel) == 0;}),
               v.end());
	
	print(v);
	
	nextel = v[0];
	
	std::cout << "Next element to be removed : " << nextel << '\n';
	
	v.erase(std::remove_if(v.begin(), 
                              v.end(),
                              [nextel](int a){return (a % nextel) == 0;}),
               v.end());
	
	print(v);
	
	nextel = v[0];
	
	std::cout << "Next element to be removed : " << nextel << '\n';
	
	v.erase(std::remove_if(v.begin(), 
                              v.end(),
                              [nextel](int a){return (a % nextel) == 0;}),
               v.end());
	
	print(v);
*/


