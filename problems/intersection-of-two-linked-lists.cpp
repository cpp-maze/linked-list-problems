/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> visited;

        while (headA != NULL) {
            visited.insert(headA);
            headA = headA->next;
        }

        while (headB != NULL) {
            if (visited.find(headB) != visited.end()) return headB;
            headB = headB->next;
        }

        return NULL;
    }
};

// Approach 2
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        
        ListNode *cur = headA;
        while (cur != NULL) {
            cur = cur->next;
            lenA++;
        }

        cur = headB;
        while (cur != NULL) {
            cur = cur->next;
            lenB++;
        }

        while (lenA != lenB) {
            if (lenA > lenB) {
                headA = headA->next;
                lenA--;
            } else {
                headB = headB->next;
                lenB--;
            }
        }

        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};