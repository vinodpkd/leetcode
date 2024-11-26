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

/*
/ for string delimiter
std::vector<std::string> split(std::string s, std::string delimiter) {
	//initialization of variables need not be in the end.
	//string.size() == string.length()
	/*
As per the documentation, these are just synonyms. size() is there to be consistent with other STL containers (like vector, 
map, etc.) and length() is to be consistent with most peoples' intuitive notion of character strings. People usually talk 
about a word, sentence or paragraph's length, not its size, so length() is there to make things more readable.
*/
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;
	/*
	That line of code searches for the first occurrence of a delimiter within a C++ string, starting from a specified 
position. Let's break it down:
    s.find(delimiter, pos_start): This part uses the find() method of the std::string class. It searches for the first 
occurrence of the delimiter string within the string s. The search begins at the index pos_start. 
pos_end = ...: This assigns the result of the find() operation to the variable pos_end.

The Result: The find() method returns the index (position) of the first character of the found delimiter. If the delimiter is 
not found, it returns std::string::npos, a special constant typically representing the maximum value of the size_t type.
	*/

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

int main() {
	
    std::string str = "adsf-+qwret-+nvfkbdsj-+orthdfjgh-+dfjrleih-+";
    std::string delimiter = "-+";
    std::vector<std::string> v = split (str, delimiter);

    for (auto i : v) std::cout << i << std::endl;

    return 0;
}
*/
