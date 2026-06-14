class Solution {
public:
    int pairSum(ListNode* head) {

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr)
        {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Find maximum twin sum
        int maxi = 0;

        ListNode* first = head;
        ListNode* second = prev;

        while(second)
        {
            maxi = max(maxi, first->val + second->val);

            first = first->next;
            second = second->next;
        }

        return maxi;
    }
};