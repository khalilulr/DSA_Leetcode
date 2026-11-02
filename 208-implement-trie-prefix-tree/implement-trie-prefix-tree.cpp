class TrieNode{
    public:
        vector<TrieNode*>children;
        bool isEnd;
    TrieNode(){
        this->children=vector<TrieNode*>(26,nullptr);
        this->isEnd=false;
    }
};

class Trie {
    TrieNode * node;
public:
    Trie() {
        node=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * root=node;
        for(auto ch:word){
            int idx=ch-'a';
            if(!root->children[idx])
                root->children[idx]=new TrieNode();

            root=root->children[idx];
        }

        root->isEnd=true;;
    }
    
    bool search(string word) {
        TrieNode * root=node;

        for(auto ch:word){
            int idx=ch-'a';

            if(!root->children[idx])
                return false;

            root=root->children[idx];
        }


        return root->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode * root=node;

        for(auto ch:prefix){
            int idx=ch-'a';

            if(!root->children[idx])
                return false;

            root=root->children[idx];
        }


        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */