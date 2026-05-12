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

    int len(ListNode* head){
        int counter = 0;

        while(head != nullptr){
            counter++;
            head = head->next;
        }

        return counter;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int N = len(head);

        int group = N / k;

        ListNode* prevHead = nullptr;
        ListNode* currHead = head;

        ListNode* answer = nullptr;

        for(int i = 0 ; i < group ; i++){

            ListNode* prev = nullptr;
            ListNode* curr = currHead;
            ListNode* nextNode = nullptr;

            for(int j = 0 ; j < k ; j++){

                nextNode = curr->next;

                curr->next = prev;

                prev = curr;

                curr = nextNode;
            }

            // first group
            if(prevHead == nullptr){
                answer = prev;
            }
            else{
                prevHead->next = prev;
            }

            prevHead = currHead;
            currHead = curr;
        }

        prevHead->next = currHead;

        return answer;
    }
};