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

