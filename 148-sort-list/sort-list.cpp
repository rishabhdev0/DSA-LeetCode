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
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != nullptr && fast->next != nullptr) {  
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* lefthead, ListNode* righthead) {
        ListNode* dummy_node = new ListNode(-1);
        ListNode* temp = dummy_node;  
        while(lefthead != nullptr && righthead != nullptr) { 
            if(lefthead->val < righthead->val) {
                temp->next = lefthead;
                lefthead = lefthead->next;  
            } else {
                temp->next = righthead;
                righthead = righthead->next; 
            }
            temp = temp->next;
        }
        if(lefthead) temp->next = lefthead;
        else temp->next = righthead;
        ListNode* head = dummy_node->next;
        delete(dummy_node);
        return head;
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {  
            return head;
        } 
        ListNode* mid = middle(head); 
        ListNode* lefthead = head;
        ListNode* righthead = mid->next;
        mid->next = nullptr;
        lefthead = sortList(lefthead); 
        righthead = sortList(righthead); 
        return merge(lefthead, righthead); 
    }
};