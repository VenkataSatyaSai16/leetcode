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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr){
            st.push(temp);
            temp=temp->next;
            count++;
        }
        ListNode *left = head , * right = nullptr;
        for(int c = 0 ; c < count/2 ; c++){
            right = st.top();
            st.pop();

            ListNode* nextLeft = left->next;

            left->next = right;
            right->next = nextLeft;
            left = nextLeft;
        }
        left->next = nullptr;
    }
};