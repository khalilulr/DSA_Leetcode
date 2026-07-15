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
        ListNode *root=new ListNode(-1);
        ListNode *cur=root;
        ListNode *ptr1=l1,*ptr2=l2;
        int carry=0;
        while(ptr1 || ptr2){
            int curSum=carry;
            if(ptr1){
                curSum+=ptr1->val;
                ptr1=ptr1->next;
            }
            if(ptr2){
                curSum+=ptr2->val;
                ptr2=ptr2->next;
            }
            if(curSum>=10){
                carry=curSum/10;
                curSum=curSum%10;
            }else carry=0;
            ListNode *node=new ListNode(curSum);
            cur->next=node;
            cur=node;
        }
        if(carry){
            ListNode *node=new ListNode(carry);
            cur->next=node;
            cur=node;
        }
        return root->next;
    }
};