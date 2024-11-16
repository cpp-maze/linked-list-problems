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
    int listLen(ListNode *head) {
        int len = 0;

        while (head) {
            ++len;
            head = head->next;
        }

        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *tail;
        vector<ListNode*> ans(k, nullptr);
        int len = listLen(head);
        int minNodes = len / k, extraNodes = len % k;

        for (int i = 0; head; ++i) {
            ans[i] = head;
            tail = head;

            int iterateCount = minNodes;

            if (extraNodes > 0) {
                iterateCount++;
                --extraNodes;
            }

            iterateCount--;

            while (iterateCount > 0 && tail->next) {
                tail = tail->next;
                iterateCount--;
            }

            head = tail->next;
            tail->next = nullptr;
        }

        return ans;
    }
};