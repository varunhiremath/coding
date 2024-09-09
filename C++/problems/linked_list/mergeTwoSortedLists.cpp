/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        else if (!l2) return l1;

        ListNode* start;
        ListNode* previous;

        if (l1->val <= l2->val)
        {
            start = l1;
            l1 = l1->next;
        }
        else
        {
            start = l2;
            l2 = l2->next;
        }
        previous = start;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                ListNode* tmp = l1->next;
                previous->next = l1;
                l1 = tmp;
            }
            else
            {
                ListNode* tmp = l2->next;
                previous->next = l2;
                l2 = tmp;
            }
            previous = previous->next;
        }

        if (!l1)
            previous->next = l2;
        else
            previous->next = l1;

        return start;

    }
};
