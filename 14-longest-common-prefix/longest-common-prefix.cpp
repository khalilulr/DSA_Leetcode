class TrieNode{
    public:
        vector<TrieNode*>children;
        bool isEnd;
    TrieNode(){
        this->children=vector<TrieNode*>(26,nullptr);
        this->isEnd=false;
    }
};

class Tri{
    TrieNode *root;
public:
    Tri(){
        root=new TrieNode();
    }

    void insert(string word){
        TrieNode *ptr=root;

        for(auto ch:word){
            int idx=ch-'a';
            if(!ptr->children[idx])
                ptr->children[idx]=new TrieNode();
            ptr=ptr->children[idx];
        }

        ptr->isEnd=true;
    }

    int getLCP(){
        TrieNode *ptr=root;
        int size=0;
        while(ptr){
            int cnt=0,idx=-1;
            for(int i=0;i<26;i++){
                if(ptr->children[i]){
                    cnt++;
                    idx=i;
                    if(cnt>1)
                        return size;
                }
            }
            if (ptr->isEnd)
            return size;

        // No child
        if (idx == -1)
            return size;

        ptr = ptr->children[idx];
        size++;
        }

        return size;
    }


};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Tri *node=new Tri();

        for(auto word:strs)
            node->insert(word);

        int size=node->getLCP();

        return strs[0].substr(0,size);
    }
};