203. Remove Linked List Elements
/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.
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
    ListNode* removeElements(ListNode* head, int val) {
        std::vector<int> v = ll2vec(head);
        std::erase_if(v,[val](int n){return n == val;});
        head = vec2ll(v);
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
