/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*,Node*>mp; //og,cp

    Node * createNode(Node *node){
        Node *newNode=new Node(node->val);
        mp[node]=newNode;
        return newNode;
    }
public:
    Node* copyRandomList(Node* head) {
        Node *temp=new Node(-1);
        Node *cur=temp;
        Node *ptr=head;
        while(ptr){
            if(mp.find(ptr)==mp.end()){
               Node *newNode= createNode(ptr);
               cur->next=newNode;
               cur=newNode;
               Node *rNode=ptr->random;
               //random is already present
               if(rNode && mp.find(rNode)!=mp.end()){
                    newNode->random=mp[rNode];
               }else if(rNode){
                    //not present ill create it
                    Node *randomNode=createNode(rNode);
                    newNode->random=randomNode;
               }else if(!rNode)
                    newNode->random=nullptr;
            }else{
                Node *newNode=mp[ptr];
                cur->next=newNode;
                cur=newNode;
                Node *rNode=ptr->random;
                if(rNode && mp.find(rNode)!=mp.end()){
                    newNode->random=mp[rNode];
               }else if(rNode){
                    //not present ill create it
                    Node *randomNode=createNode(rNode);
                    newNode->random=randomNode;
               }else if(!rNode)
                    newNode->random=nullptr;
            }
            ptr=ptr->next;
        }
        Node *cpyHead=temp->next;
        delete(temp);
        return cpyHead;
    }
};