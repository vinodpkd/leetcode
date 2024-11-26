//2114. Maximum Number of Words Found in Sentences
/*
A sentence is a list of words that are separated by a single space with no leading or trailing spaces.
You are given an array of strings sentences, where each sentences[i] represents a single sentence.
Return the maximum number of words that appear in a single sentence.
*/

#include <bits/stdc++.h>
// for string delimiter
std::vector<std::string> split(std::string s, std::string delimiter) {
	
	std::vector<std::string> result;
	
	size_t pos_start = 0,len = delimiter.length(),pos_end;
	//Check the behaviour of pos_end when type is an integer abd size_t
	while((pos_end = s.find(delimiter,pos_start)) != std::string::npos)
	{
		std::string slice = s.substr(pos_start,pos_end - pos_start);
		result.push_back(slice);
		pos_start = pos_end + len;
	}
	
	result.push_back(s.substr(pos_start,s.length()));
	
	return result;
	
}

int sentence_length(std::string s, std::string delimiter) {
	
	int slen {0};
	
	int pos_start = 0,len = delimiter.length(),pos_end;
	//Check the behaviour of pos_end when type is an integer abd size_t
	//(pos_end = s.find(delimiter,pos_start)) != -1 and (pos_end = s.find(delimiter,pos_start)) != std::string::npos
	//are equivalent
	while((pos_end = s.find(delimiter,pos_start)) != -1)//std::string::npos
	{
		std::string slice = s.substr(pos_start,pos_end - pos_start);
		slen++;
		pos_start = pos_end + len;
	}
	
	if(!s.substr(pos_start,s.length()).empty())
		slen++;
	
	return slen;
	
}

int main() {
	
    std::string str = "adsf-+qwret-+nvfkbdsj-+orthdfjgh-+dfjrleih-+";
    std::string delimiter = "-+";
    std::vector<std::string> v = split(str, delimiter);
	
	size_t len = sentence_length(str, delimiter);
	
	std::cout << len << '\n';

    for (auto i : v) std::cout << i << std::endl;

    return 0;
}
