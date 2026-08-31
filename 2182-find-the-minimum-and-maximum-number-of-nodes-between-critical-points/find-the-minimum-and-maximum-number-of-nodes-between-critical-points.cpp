class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> criticalPoints;
        
        ListNode* prev = head;
        ListNode* curr = head->next;
        
        int index = 1;
        
        while (curr != nullptr && curr->next != nullptr) {
            
            ListNode* next = curr->next;
            
            if (curr->val > prev->val && curr->val > next->val) {
                criticalPoints.push_back(index);
            }
            
            else if (curr->val < prev->val && curr->val < next->val) {
                criticalPoints.push_back(index);
            }
            
            prev = curr;
            curr = curr->next;
            index++;
        }
        
        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }
        
        int maxDist = criticalPoints.back() - criticalPoints.front();
        
        int minDist = INT_MAX;
        
        for (int i = 1; i < criticalPoints.size(); i++) {
            minDist = min(minDist,
                          criticalPoints[i] - criticalPoints[i - 1]);
        }
        
        return {minDist, maxDist};
    }
};