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
    bool hasCycle(ListNode *head) {
        if (head==NULL)
            return false;
        if (head->next==NULL)
            return false;
        if (head->next==head)
            return true;
        
        ListNode *fast, *slow;
        fast=slow=head;
        do
        {
            fast=fast->next;
            if (fast==NULL)
                return false;
            if (fast==slow)
                return true;
            fast=fast->next;
            slow=slow->next;
        }while (fast && slow && fast!=slow);
        if (!fast || !slow)
            return false;
        return true;
    }
};
