/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void createGraph(TreeNode *root,unordered_map<TreeNode*,vector<TreeNode*>>&adj,TreeNode *&startNode,int start){
        if(!root)
            return;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();q.pop();
            if(node->val==start)
                startNode=node;
            if(node->left){
                q.push(node->left);
                adj[node].push_back(node->left);
                adj[node->left].push_back(node);
            }
            if(node->right){
                q.push(node->right);
                adj[node].push_back(node->right);
                adj[node->right].push_back(node);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,vector<TreeNode*>>adj;
        TreeNode *startNode=nullptr;
        createGraph(root,adj,startNode,start);
        if(!startNode)
            return 0;
        int time=0;

        queue<pair<int,TreeNode*>>q;
        unordered_set<TreeNode*>vis;
        q.push({0,startNode});
        vis.insert(startNode);

        while(!q.empty()){
            auto [curT,node]=q.front();q.pop();
            time=curT;
            for(auto ne:adj[node]){
                if(vis.find(ne)==vis.end()){
                    q.push({curT+1,ne});
                    vis.insert(ne);
                }
            }
        }
        return time;
    }
};