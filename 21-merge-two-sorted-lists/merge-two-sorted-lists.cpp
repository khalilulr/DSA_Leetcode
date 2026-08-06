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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *temp=new ListNode(-1);
        ListNode *cur=temp;

        ListNode *ptr=list1,*ptr2=list2;

        while(ptr || ptr2){
            if(ptr && ptr2 && ptr->val < ptr2->val){
                cur->next=ptr;
                cur=ptr;
                ptr=ptr->next;
            }
            else if(ptr && ptr2 && ptr->val >= ptr2->val){
                cur->next=ptr2;
                cur=ptr2;
                ptr2=ptr2->next;
            }
            else if(ptr){
                cur->next=ptr;
                cur=cur->next;
                ptr=ptr->next;
            }
            else if(ptr2){
                cur->next=ptr2;
                cur=cur->next;
                ptr2=ptr2->next;
            }
        }

        return temp->next;
    }
};