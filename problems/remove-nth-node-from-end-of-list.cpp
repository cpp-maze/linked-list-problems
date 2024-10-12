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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *prv = nullptr, 
                 *toRemove = head, 
                 *cur = head;
        int dist = 0;
        
        while (cur) {
            if (dist == n) {
                prv = toRemove;
                toRemove = toRemove->next;
            } else {
                dist++;
            }

            cur = cur->next;
        }

        if (prv == nullptr) {
            head = head->next;
        } else {
            prv->next = toRemove->next;
        }

        return head;
    }
};