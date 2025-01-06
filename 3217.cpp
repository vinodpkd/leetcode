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
---------------------------
ListNode* removeNode(ListNode* head, int val)
{
	while(head && head->val == val)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
	}

	ListNode* current = head;
	while(current && current->next)
	{
		if(current->next->val == val)
		{
			ListNode* temp = current->next;
			current->next = current->next->next;
			delete temp;
		}
		else
		{
			current = current->next;
		}
	}

	return head;
}


int main()
{
	//std::vector<int> arr = {5,1,2, 5,5, 8, 7,5,5};
	//std::vector<int> arr = {5,0,5};
    // Create a linked list with the values from the vector
	
	std::vector<int> arr = {1,2,3,4,5};
	ListNode* head = new ListNode(arr[0]);
	head->next = new ListNode(arr[1]);
    head->next->next = new ListNode(arr[2]);	
    head->next->next->next = new ListNode(arr[3]);
	head->next->next->next->next = new ListNode(arr[4]);
	
	std::vector<int> nums = {1,2,3};
	
	for(int& x : nums)
	{
		head = removeNode(head,x);
	}
	
	printLL_1(head);
	
	/*
    Node* head = new Node(arr[0]);
	head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);	
    head->next->next->next = new Node(arr[3]);
	head->next->next->next->next = new Node(arr[4]);
	head->next->next->next->next->next = new Node(arr[5]);
	head->next->next->next->next->next->next = new Node(arr[6]);
	head->next->next->next->next->next->next->next = new Node(arr[7]);
	head->next->next->next->next->next->next->next->next = new Node(arr[8]);
	*/
	
	//head = deleteAllOccurences(head,5);	
	
	//printLL(head);
	
	return 0;
}
