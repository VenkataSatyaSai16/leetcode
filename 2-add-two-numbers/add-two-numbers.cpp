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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp1 = l1, *temp2 = l2;
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *temp = dummy;
        while(temp1!=nullptr && temp2!=nullptr){
            int sum = temp1->val + temp2->val + carry;
            if(sum>9){
                ListNode *node = new ListNode(sum%10);
                temp->next = node;
                carry = 1;
            }
            else{
                ListNode *node = new ListNode(sum);
                carry = 0;
                temp->next = node;
            }
            
            temp1 = temp1->next;
            temp2 = temp2->next;
            temp = temp->next;
        }

        while(temp1!=nullptr){
            int sum = temp1->val + carry;
            if(sum>9){
                ListNode *node = new ListNode(sum%10);
                temp->next = node;
                carry = 1;
            }
            else{
                ListNode *node = new ListNode(sum);
                temp->next = node;
                carry = 0;
            }
            temp1 = temp1->next;
            temp = temp->next;
        }

        while(temp2!=nullptr){
            int sum = temp2->val + carry;
            if(sum>9){
                ListNode *node = new ListNode(sum%10);
                temp->next = node;
                carry = 1;
            }
            else{
                ListNode *node = new ListNode(sum);
                temp->next = node;
                carry = 0;
            }
            temp2 = temp2->next;
            temp = temp->next;
        }
        if(carry==1){
            temp->next = new ListNode(carry);
        }
        return dummy->next;
    }
};