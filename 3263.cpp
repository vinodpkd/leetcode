//3263. Convert Doubly Linked List to Array I description
#include <bits/stdc++.h>

//3263. Convert Doubly Linked List to Array I description

struct node{
	int val;
	node* next;
	node* prev;
	node()
	{
		next = nullptr;
		prev = nullptr;
	}
	node(int v)
	{
		val = v;
		next = nullptr;
		prev = nullptr;
	}
	
	node(node* n,node* p,int v):next(n),prev(p),val(v)
	{
	}
};

int main()
{
	node* head = new node(0);
	
	node* temp;
	
	for(int i = 1;i < 5;i++)
	{
		if(i == 1)
		{
			temp = new node(i);
			head->next = temp;
			temp->prev = head;
		}
		else
		{
			temp->next = new node(i);
			temp->next->prev = temp;
			temp = temp->next;
		}	
		
	}
	
	std::vector<int> vec{};
	temp = head;
	
	while(temp != nullptr)
	{
		vec.push_back(temp->val);
		temp = temp->next;
	}
	
	for(int x : vec)
		std::cout << x << ' ';
	
	std::cout << '\n';
	
	return 0;
}
