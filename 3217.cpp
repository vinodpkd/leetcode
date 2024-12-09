//3217. Delete Nodes From Linked List Present in Array
/*
You are given an array of integers nums and the head of a linked list. Return the head of the modified linked list after removing all nodes from the linked list that have a value that exists in nums.
*/
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::vector<int> vec = ll2vec(head);
        std::set<int> set2(vec.begin(),vec.end());
        if(1 == set2.size())
        {
            int c = std::count(nums.begin(),nums.end(),vec[0]);
            if (1 >= c)
            {
                ListNode* temp;
                return temp;
            }

        }
        //std::set<int> set1(vec.begin(),vec.end());
        //std::vector<int> diff{};
        //std::set_difference(set1.begin(),set1.end(),nums.begin(),nums.end(),std::back_inserter(diff));
        for(int i = 0;i < nums.size();i++)
        {
            vec.erase(std::remove(vec.begin(),vec.end(),nums[i]),vec.end());
        }
        head = vec2ll(vec);
        return head;
    }

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
};
