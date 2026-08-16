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
    ListNode *reverse_node(ListNode *start,ListNode *end){
        ListNode *prev=nullptr,*cur=start,*next=nullptr;

        while(cur && cur!=end){
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *ptr=head;
        ListNode *prev=nullptr;
        while(ptr){
            ListNode *start=ptr;
            ListNode *end=ptr;

            for(int i=1;i<k && end;i++)
                end=end->next;

            if(!end)
                break;

            ListNode *nextN=end->next;
            ListNode *revH=reverse_node(start,nextN);

            if(!prev)
                head=revH;
            else
                prev->next=revH;
                
            start->next=nextN;
            
            ptr=ptr->next;
            prev=start;
        }
        return head;
    }
};