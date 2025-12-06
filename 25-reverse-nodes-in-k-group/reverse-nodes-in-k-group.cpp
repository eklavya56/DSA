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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head|| k== 1)return head;

        ListNode*curr=head;
        int count =0;

        while(curr &&count < k) {
            curr= curr->next;
            count++;
        }
        if (count <k)return head;

        curr =head;
        ListNode*prev = NULL;
        ListNode*next = NULL;
        count = 0;

        while (curr&& count < k) {
            next =curr->next;
            curr->next = prev;
            prev =curr;
            curr = next;
            count++;
        }
        if(next)
         head->next = reverseKGroup(next, k);

        return prev;
    }
};
