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
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        
        while (even && even->next) {
            // Connect current odd to next odd
            odd->next = odd->next->next;
            // Connect current even to next even
            even->next = even->next->next;
            
            // Move pointers forward
            odd = odd->next;
            even = even->next;
        }
        // Connect end of odd list to head of even list
        odd->next = evenHead;
        
        return head;
    }
};