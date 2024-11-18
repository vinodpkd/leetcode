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
    std::vector<int> ll2Vec(ListNode* l1)
    {
        std::vector<int> num{};
        ListNode* t = new ListNode();
        while(t != NULL)
        {
            num.push_back(t->val);
            t = t->next;
        }
        
        return num;
    }
	
	
	ListNode* vec2ll(std::vector<int>& num)
    {
        
        ListNode* t = new ListNode();
		ListNode* s = new ListNode();
		s = t;
		int i = 0;
        while(i < num.size())
        {            
			ListNode* u = new ListNode(num[i]);
            t->next = u;
			t = u;
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
