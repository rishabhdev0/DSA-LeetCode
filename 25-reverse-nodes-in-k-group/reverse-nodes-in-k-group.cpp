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
    ListNode* Kreverse(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                return head; 
            }
            temp = temp->next;
        }

       //reversing the first k nodes 
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* forward = nullptr;
        int count = 0;

        while (curr != nullptr && count < k) {
            forward = curr->next; 
            curr->next = prev;    
            prev = curr;         
            curr = forward;       
            count++;
        }
        //  now connect the head t this using recursion call
        if (forward != nullptr) {
            head->next = Kreverse(forward, k);
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return Kreverse(head, k);
    }
};