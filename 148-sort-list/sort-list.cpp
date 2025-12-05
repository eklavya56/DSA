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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) slow = slow->next, fast = fast->next->next;
        ListNode* mid = slow->next;
        slow->next = nullptr;

        ListNode* l = sortList(head);
        ListNode* r = sortList(mid);

        return merge(l, r);
    }

    ListNode* merge(ListNode* a, ListNode* b) {
        if (!a || !b) return a ? a : b;
        if (a->val < b->val) {
            a->next = merge(a->next, b);
            return a;
        }
        b->next = merge(a, b->next);
        return b;
    }
};
