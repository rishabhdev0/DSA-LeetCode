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

    int getLen(ListNode* head){
        int len = 0;

        while(head != nullptr){
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode* swapNodes(ListNode* head, int k) {

        int len = getLen(head);

        ListNode* first = head;
        ListNode* second = head;

        // kth node from beginning
        for(int i = 1; i < k; i++){
            first = first->next;
        }

        // kth node from end
        for(int i = 1; i < len - k + 1; i++){
            second = second->next;
        }

        // swap values
        swap(first->val, second->val);

        return head;
    }
};