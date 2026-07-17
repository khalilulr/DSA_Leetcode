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
        ListNode *node=new ListNode(-1);
        ListNode *cur=node;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<>>pq;
        for(auto list:lists){
            if(list)
             pq.push({list->val,list});
        }
        while(!pq.empty()){
            auto [val,node]=pq.top();pq.pop();
            cur->next=node;
            cur=node;
            if(node->next)
                pq.push({node->next->val,node->next});
        }
        ListNode *head=node->next;
        delete(node);
        return head;
    }
};