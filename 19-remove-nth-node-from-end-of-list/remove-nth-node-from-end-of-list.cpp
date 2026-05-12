class Solution {
public:

    int length(ListNode* head){

        int counter = 0;

        while(head != nullptr){
            counter++;
            head = head->next;
        }

        return counter;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = length(head);

        int traverse = len - n;

        // deleting head
        if(traverse == 0){

            ListNode* temp = head;

            head = head->next;

            delete(temp);

            return head;
        }

        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(traverse--){

            prev = curr;

            curr = curr->next;
        }

        prev->next = curr->next;

        delete(curr);

        return head;
    }
};