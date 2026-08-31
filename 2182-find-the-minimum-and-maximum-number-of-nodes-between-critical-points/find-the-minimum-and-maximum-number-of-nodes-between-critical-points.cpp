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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 2;

        int firstCritical = -1;
        int lastCritical = -1;
        int minDistance = INT_MAX;

        while (curr->next != nullptr) {

            // Check whether curr is a critical point
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {

                // First critical point
                if (firstCritical == -1) {
                    firstCritical = pos;
                }
                else {
                    // Distance from previous critical point
                    minDistance = min(minDistance, pos - lastCritical);
                }

                // Current becomes last critical point
                lastCritical = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Less than 2 critical points
        if (firstCritical == lastCritical) {
            return {-1, -1};
        }

        int maxDistance = lastCritical - firstCritical;

        return {minDistance, maxDistance};
    }
};