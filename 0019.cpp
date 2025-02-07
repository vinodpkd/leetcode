19. Remove Nth Node From End of List 100% beats in time.
//Given the head of a linked list, remove the nth node from the end of the list and return its head./**

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr && n == 1)
            return nullptr;
        ListNode* first = head;
	ListNode* second = head;
	
	int i = 0;
	
	while(i < n)
	{
		second = second->next;
		i++;
	}
	
	//std::cout << first->val << '\n';
	//std::cout << second->val << '\n';
	
	if(nullptr == second)
	{
		ListNode* temp = head;
		head = head->next;
		delete temp;
		return head;
	}
	
	while(second->next)
	{
		first = first->next;
		second = second->next;
	}
	
	//std::cout << first->val << '\n';
	ListNode* temp = first->next;
	first->next = first->next->next;
	delete temp;
	//printLL(n1);
    return head;
    }
};
/*
	I have made an alternate method to delete the Kth node from the end.
	I got the idea from the book. I implemented on my own.
	Key idea : Two pointers 
	Initially both first and second node point to head.
	Advance second node k times. 
	Now there will be k-1 node in between first and second.
	If second points to last node or second->next point to nullptr, 
	first points to the K+1 st node from the end.
	The node pointed by first->next has to be deleted.
	What if second points to nullptr?
	head has to be deleted.Why?
	Why?
	
	*/
----------
#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* createLL(int A[],int n)
{
    struct ListNode *temp , *last, *first;
    first = new ListNode();
	
    first->val = A[0];
    first->next = NULL;
    last = first;
    for (int i=1; i<n; i++)
    {
        temp = new ListNode();
        temp->val = A[i];
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
	
	return first;
}

void displayLL(struct ListNode* p)
{

    while(p != NULL)
    {
        std::cout << p->val << '\n';
        p = p->next;
    }
}

int count(struct ListNode* p)
{
	int i = 0;
    while(p != NULL)
    {
        i++;
        p = p->next;
    }
	
	return i;
}

ListNode* remove(struct ListNode* p,const int index)
{
	if(1 == index)
		return p->next;
	
	if(0 == index)
		return p;
	
	if(index < 0)
		return p;
	
	    //index = count(p) - index;

        if(count(p) == 1 && (0 == index))
            return NULL;

         if(0 == index && (count(p) == 2))
		   {
           return p->next;} 

           if(1 == index && (count(p) == 2))
		   {p->next = NULL;
           return p;} 

        if(1 == index)
		    return p->next;
	
	//std::cout << "index = " << index << '\n';
	
	struct ListNode* r = new ListNode();
	r = p;
	
	int i = 0;
    while(p != NULL)
    {
        i++;
        p = p->next;
		
		if(index == (i+1))
			break;
    }
	
	//std::cout << p->val << '\n';
	if(NULL != p->next)
		p->next = (p->next)->next;
	else{
		p = NULL;
	}

	return r;	
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;

    ListNode* dummy = new ListNode(0, head); // Add a dummy node to simplify head removal
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move fast pointer n+1 positions ahead
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
        if (fast == nullptr) {
            delete dummy; //Clean up dummy node if n exceeds list length
            return nullptr; // Or throw an exception: throw std::out_of_range("n exceeds list length");
        }
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr) {
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the node
    ListNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;

    ListNode* result = dummy->next;
    delete dummy; //Clean up dummy node
    return result;
}

int main()
{
	struct ListNode* head = new ListNode();
	
	//int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	
	//int arr[2] = {1,2};
	
	//int arr[3] = {1,2,3};
	
	int arr[2] = {1,2};
	
	head = createLL(arr,sizeof(arr)/sizeof(arr[0]));
	
	displayLL(head);
	
	int p = 2;
	
	int m = count(head);

	std::cout << m << '\n';
	
	std::cout << '\n';
	
	struct ListNode* temp = new ListNode();
	
	//temp = remove(head,m-p);
	temp = removeNthFromEnd(head, 1);
	
	displayLL(temp);
	
	return 0;
}

