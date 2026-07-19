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
    ListNode *detectCycle(ListNode *head) {
        ListNode *s=head,*f=head;
        bool found=false;
        while(s && f &&  f->next){
            s=s->next;
            f=f->next->next;
            if(s==f){
                found=true;
                break;
            }
        }
        if(!found)
            return nullptr;
        f=head;
        cout<<f->val<<" "<<s->val<<endl;
        while(s!=f){
            s=s->next;
            f=f->next;
        }
        return s;
    }
};