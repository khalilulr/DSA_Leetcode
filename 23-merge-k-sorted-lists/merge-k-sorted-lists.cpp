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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>>pq;

        for(auto list:lists){
            if(list)
            pq.push({list->val,list});
        }

        ListNode *head=new ListNode(-1);
        ListNode *ptr=head;
        while(!pq.empty()){
            ListNode *node=pq.top().second;
            ptr->next=node;
            pq.pop();
            if(node->next)
                 pq.push({node->next->val,node->next});
            ptr=ptr->next;
        }


        return head->next;
    }
};