class Node{
    public:
        Node *prev,*next;
        int value;
        int key;
        Node(int value,int key){
            this->value=value;
            this->key=key;
            this->prev=nullptr;
            this->next=nullptr;
        }
};

class LRUCache {
    Node *head,*tail;
    unordered_map<int,Node*>mp;
    int capacity;

    void removeNode(Node *node){
        Node *prevNode=node->prev;
        Node *nxtNode=node->next;

        prevNode->next=nxtNode;
        nxtNode->prev=prevNode;
    }

    void removeNodeEnd(){
        Node *endNode=tail->prev;
        if(endNode==head)
            return;

        mp.erase(endNode->key);

        Node *prevEndNode=endNode->prev;
        prevEndNode->next=tail;
        tail->prev=prevEndNode;

        delete(endNode);
    }

    void addNodeStart(Node *node){
        Node *headNext=head->next;
        head->next=node;
        node->prev=head;

        node->next=headNext;
        headNext->prev=node;
    }
public:
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);

        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
            return -1;
        
        Node *node=mp[key];

        removeNode(node);
        addNodeStart(node);

        return node->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node *node=mp[key];
            node->value=value;
            node->key=key;

            removeNode(node);
            addNodeStart(node);
        }else{
            Node *node=new Node(value,key);
            if(mp.size()==capacity){
                removeNodeEnd();
                mp[key]=node;
                addNodeStart(node);
            }else{
                mp[key]=node;
                addNodeStart(node);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */