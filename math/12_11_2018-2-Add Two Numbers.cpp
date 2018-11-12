
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* num1=l1, *num2=l2, *sum, *ptr, *temp=NULL;
        while(num1&&num2)
        {
            ptr=(ListNode*)malloc(sizeof(ListNode));
            if (temp)
                temp->next=ptr;
            else
                sum=ptr;
            ptr->next=NULL;
            ptr->val=(num1->val+num2->val+carry)%10;
            carry=(num1->val+num2->val+carry)/10;
            temp=ptr;
            ptr=ptr->next;
            num1=num1->next;
            num2=num2->next;
        }
        
        while(num1)
        {
            ptr=(ListNode*)malloc(sizeof(ListNode));
            temp->next=ptr;
            ptr->next=NULL;
            ptr->val=(num1->val+carry)%10;
            carry=(num1->val+carry)/10;
            temp=ptr;
            ptr=ptr->next;
            num1=num1->next;
        }
        while(num2)
        {
            ptr=(ListNode*)malloc(sizeof(ListNode));
            temp->next=ptr;
            ptr->next=NULL;
            ptr->val=(num2->val+carry)%10;
            carry=(num2->val+carry)/10;
            temp=ptr;
            ptr=ptr->next;
            num2=num2->next;
        }
        if (carry!=0) //Beaware of this corner case!!!
        {
            ptr=(ListNode*)malloc(sizeof(ListNode));
            temp->next=ptr;
            ptr->next=NULL;
            ptr->val=1;
        }
        return sum;
    }
};
