/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <bits/stdc++.h>

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
/* class Solution {
public: */
	/*
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    
        std::vector<int> vec1 = ll2Vec(l1);
        std::vector<int> vec2 = ll2Vec(l2);
        
        int n1 = vec2num(vec1);
        int n2 = vec2num(vec2);
        
        n1 = n1 + n2;
		
		std::vector<int> vecsum = num2vec(n1);
		
		ListNode* t = vec2ll(vecsum);
		
		return t;
        
    }
	*/
    std::vector<int> ll2vec(ListNode* l1)
    {
        std::vector<int> num{};
        ListNode* t = l1;
        while(t != nullptr)
        {
            num.push_back(t->val);
            t = t->next;
        }
        
        return num;
    }

    ListNode* vec2ll(std::vector<int>& num)
    {
	    if(num.empty())
            	return nullptr;
        
        ListNode* t = new ListNode(num[0]);
		ListNode* s = new ListNode();
		s = t;
		int i = 1;
        while(i < num.size())
        {            
			ListNode* u = new ListNode(num[i]);            
			t->next = u;
            t = t->next;
			i++;
        }
        
        return s;
    }
	
    int vec2num(std::vector<int>& num)
    {
        int n = 0;
        int i = 1;
        for(auto it = num.rbegin();it != num.rend();it++)
        {
            n += (*it)  *  i;
            i = i*10;
        }
        return n;
          
    }
	
	std::vector<int> num2vec(int num)
	{
		std::vector<int> vec{};
		
		if(0 == num)
		{
			vec = {0};
			return vec;
		}
		
		while(num != 0)
		{
			int r = num % 10;
			vec.insert(vec.begin(),r);
			num = (num - r)/10;
			//std::cout << num << ' ' << r << '\n';
		}
		return vec;
	}

//};

int main()
{
	std::vector<int> nums1{1,2,3};
		
	ListNode* lone = vec2ll(nums1);
	
	std::vector<int> nums2{4,5,6};
		
	ListNode* ltwo = vec2ll(nums2);
	
	std::vector<int> a = num2vec(123);
	
	for(auto& x: a)
		std::cout << x << ' ';
	
	std::cout << '\n';
	
	int n = vec2num(a);
	std::cout << n << '\n';
	
	std::cout << '\n';
	
	//Solution soln;
		
	return 0;
}

std::multiset<int> list_to_set(struct ListNode *first)
{
	std::multiset<int> set;
    //struct ListNode *p  = (struct ListNode *)malloc(sizeof(struct ListNode));
    ListNode *p  = new ListNode();
    p = first;
    while(p != NULL)
    {
        //std::cout << p->val << '\n';
		set.insert(p->val);
        p = p->next;
    }
	
	return set;	
}

struct ListNode* createLL_from_set(std::multiset<int>& A)
{
    struct ListNode *temp , *last;
    struct ListNode *one;
    //one = (struct ListNode *)malloc(sizeof(struct ListNode));
    one = new ListNode();
	auto it = A.begin();
    one->val = *it;
    one->next = NULL;
    last = one;
    //std::cout << one->val << '\n';
    for (it = std::next(A.begin());it != A.end();it++)
    {
        //temp = (struct ListNode *)malloc(sizeof(struct ListNode));
        temp = new ListNode();
        temp->val = *it;
        temp->next = NULL;
        last->next = temp;
        last = temp;
        //std::cout << last->val << '\n';
    }

    return one;
}
//Reverse a linked list
//https://www.interviewbit.com/blog/reverse-a-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !(head->next))  return head;
    auto res = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return res;
        
    }
};
//Iterative method
ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur=head, *tmp;
        while(cur){
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
   }
//split the string considering consecutive delimiters as one
std::vector<std::string> split(std::string s, std::string delimiter) {
    std::vector<std::string> res;
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    
    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        // Only add non-empty tokens
        if (pos_end > pos_start) {
            res.push_back(s.substr(pos_start, pos_end - pos_start));
        }
        pos_start = pos_end + delim_len;
    }
    
    // Add the last token if it's not empty
    if (pos_start < s.length()) {
        res.push_back(s.substr(pos_start));
    }
    
    return res;
}
};
//Longest subarray (Two pointers)
#include <bits/stdc++.h>

int main()
{
	std::vector<int> arr{16,4,2,1,6,3,1,9,8};
	int k = 15;
	int left = 0, right = 0;
	int r = 0, l = 0;
	int maxLen{0};
	int sum = 0;
	
	while(r < arr.size())
	{		
		sum += arr[r];
		
		while(sum > k)
		{
			sum = sum - arr[l];//Remove elements from left until sum <= k
			l++;
		}
		
		if(sum <= k)
		{
			if(maxLen < r-l+1)
			{//maxLen = std::max(maxLen,r-l+1);
				maxLen = r-l+1;
				left = l, right = r;
			}
		}
		r++;
	}
	
	std::cout << "max len = " << maxLen << " left = " << left << " right = " << right << '\n';
	
	return 0;
}
/*
//Brute force approach
std::vector<int> arr{3,4,2,1,6,3,1,9,8};
	int k = 15;
	int left = 0, right = 0;
	int maxLen{0};
	
	for(int i = 0;i < arr.size();i++)
	{
		int sum = arr[i];
		
		int j = i;
		
		do
		{
			
			if(sum <= k)
			{
				int len = j-i+1;
				if(len > maxLen)
				{
					maxLen = len;
					right = j;
					left = i;
				}
			}
			j++;
			sum += arr[j];
			
		}
		while(j < arr.size());
	}
	
	std::cout << "max len = " << maxLen << " left = " << left << " right = " << right << '\n';
	
	return 0;
}
*/

//Leetcode 560. Subarray Sum Equals K , Brute force
/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
*/
/*
class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int count{0};
	
	for(int i = 0;i < arr.size();i++)
	{
        int sum = arr[i];
		for(int j = i;j < arr.size();j++)
		{
			//int sum = std::accumulate(arr.begin()+i,arr.begin()+j+1,0);
			if(sum == k)
			{
				count++;
			}
            if(j+1 == arr.size())
                break;
            sum += arr[j+1];
		}
	}
    return count;
    }
};
*/
//Constant window (Two pointers)
#include <bits/stdc++.h>

int main()
{
	std::vector<int> arr{3,-4,2,-1,6,3,1,-9,-8};
	int k = 4;
	int l = 0, r = k, sum, maxSum;
	int left = l,right = r;
	
	sum = std::accumulate(arr.begin(),arr.begin()+k,0);
	maxSum = sum;
	
	std::cout << "l = " << l << " sum = " << sum << '\n';
	
	while(r < arr.size())
	{		
		r++;
		sum = sum + arr[r] - arr[l];
		l++;
		
		std::cout << "sum = " << sum << '\n';
		
		if(maxSum < sum)
		{
			maxSum = sum;
			left = l;
			right = r;
		}
	}
	
	std::cout << "max sum = " << maxSum << " left = " << left << " right = " << right << '\n';
	
}

//Delete all occurences of a value from a linked list
ode* deleteValue(Node* head, int value) {
	while (head && head->data == value) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	Node* current = head;
	while (current && current->next) {//What is this for?
		if (current->next->data == value) {
			Node* temp = current->next;
			current->next = current->next->next;
			delete temp;
		} else {
			current = current->next;
		}
	}
	
	return head;
}

int generateRandomInteger(int minm,int maxm)
{
	//int min = 0;
    //int max = freq[target].size()-1;

    // Initialize a random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(minm, maxm);

    // Generate random number in the integer range [minm, maxm]
    int randomIndex = distrib(gen);
	return randomIndex;
}

-----------------
	Two pointer problem get the indices such that sum of indices is minimum
	#include<bits/stdc++.h>

bool covered(std::vector<std::vector<int>>& indices,int low,int high)
{
	for(int i = 0;i < indices.size();i++)
	{
		if(indices[i][0] == low && indices[i][1] == high)
			return true;
	}
	
	return false;
}

int main()
{
	std::vector<int> arr{1,3,7,9,13,21,34,26};
	int low = 0;
	int high = arr.size()-1;
	int sum = 47;
	int minIndex = INT_MAX;
	std::vector<std::vector<int>> indices{};
	
	while(low < high)
	{
		if(covered(indices,low,high))
		{
			low = 0;
			high = arr.size()-1;
			continue;
		}
		
		if(arr[low] + arr[high] == sum)
		{
			if(low + high < minIndex)
			{
				minIndex = low + high;
			}
			arr[low] = sum + 1; arr[high] = sum + 1;
			std::cout << low << ' ' << high << ' ' << minIndex << '\n';
			//break;
			//low++;
			indices.push_back({low,high});
			low = 0;
			high = arr.size()-1;
		}
		else if(arr[low] + arr[high] > sum)
		{
			high--;
		}
		else
		{
			low++;
		}
	}
	
	return 0;
}
