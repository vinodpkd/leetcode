//82. Remove Duplicates from Sorted List II
/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
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
    ListNode* deleteDuplicates(ListNode* head) {
        std::vector<int> vec = ll2Vec(head);
        //auto last = std::unique(vec.begin(),vec.end());
        //vec.erase(last,vec.end());
        std::multiset<int> mset(vec.begin(),vec.end());
        std::set<int> set1(vec.begin(),vec.end());
        std::vector<int> diff{};
        std::set_difference(mset.begin(),mset.end(),set1.begin(),set1.end(),std::back_inserter(diff));
        std::vector<int> diff2{};
        std::set_difference(set1.begin(),set1.end(),diff.begin(),diff.end(),std::back_inserter(diff2));
        head = vec2ll(diff2);
        return head;
    }

     std::vector<int> ll2Vec(ListNode* l1)
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
