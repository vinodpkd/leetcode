//382. Linked List Random Node
/*
Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.
Implement the Solution class:
Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.
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
    private:        
        ListNode* head;
public:

    Solution(ListNode* head) {
        this->head = head;
        length = getLength(head);
    }
    
    int getRandom() {
        int result = head->val;  // Initialize first node as result
        ListNode* current = head->next;
        int count = 2;  // Start counting from 2nd element
        
        // For each node, decide whether to replace the result with probability 1/count
        while (current != nullptr) {
            // Generate random number between 0 and count-1
            int randomIndex = rand() % count;
            
            // If random number is 0, replace result with current value
            if (randomIndex == 0) {
                result = current->val;
            }
            
            current = current->next;
            count++;
        }
        
        return result;

    }

    
};

---------------------
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
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
    private:
        int length = 0;
        ListNode* begin;
public:

    Solution(ListNode* head) {
        begin = head;
        length = getLength(head);
    }
    
    int getRandom() {
         const int range_from  = 0;
    const int range_to    = length;
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>  distr(range_from, range_to);

    int pos = distr(generator);

    int i = 1;
    ListNode* temp = begin;
    while(i < pos)
    {
        temp = temp->next;
        i++;
    }

    return temp->val;

    }

    int getLength(ListNode* node)
    {
        int i = 0;
        while(node)
        {
            node = node->next;
            i++;
        }
        return i;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
