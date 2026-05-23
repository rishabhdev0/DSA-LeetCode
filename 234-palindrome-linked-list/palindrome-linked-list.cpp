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
    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast  = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }

    ListNode* reverse(ListNode* head){
       ListNode* prev = nullptr;
       ListNode* curr = head;
       while(curr != nullptr){
          ListNode* forward = curr -> next;
          curr -> next = prev;
          prev = curr;
          curr = forward;
       }
       return prev;
    }


    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return true;
        ListNode* start = head;
        ListNode* middle = getMiddle(head);
        ListNode* end = reverse(middle);
        while(start != nullptr  && end != nullptr){
            if(start -> val != end -> val){
                return false;
            }
            start = start -> next;
            end = end -> next;
        }
        return true;
    }
};