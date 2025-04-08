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
    int lenghtofList(ListNode*head){
        int length = 0;
        while(head!=0){
            length++;
            head=head->next;
        }
        return length;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      int L = lenghtofList(head);
      // case where we have to delete the head;
      if(n==L){
        ListNode* temp = head->next;
        delete(head);
        return temp;
      }
      int Travel_front = L-n;
      ListNode* curr = head;
      ListNode* prev = nullptr;
      while(Travel_front--){
          prev = curr;
          curr = curr->next;
      }
      prev->next = curr->next;
      delete(curr);
      return head;
    }
};