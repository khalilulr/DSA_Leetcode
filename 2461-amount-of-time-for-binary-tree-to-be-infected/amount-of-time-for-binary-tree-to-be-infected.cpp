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
    void createGraph(TreeNode *root,unordered_map<TreeNode*,vector<TreeNode*>>&mp,TreeNode *&sNode,int start){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode *node=q.front();q.pop();
            if(node->val==start)
                sNode=node;
            if(node->left){
                q.push(node->left);
                mp[node].push_back(node->left);
                mp[node->left].push_back(node);
            }
            if(node->right){
                q.push(node->right);
                mp[node].push_back(node->right);
                mp[node->right].push_back(node);
            }
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,vector<TreeNode*>>mp;
        TreeNode *sNode;
        createGraph(root,mp,sNode,start); 
        unordered_set<TreeNode*>vis;
        queue<pair<int,TreeNode*>>q;
        q.push({0,sNode});
        vis.insert(sNode);
        int ans=0;
        while(!q.empty()){
            auto [time,node]=q.front();q.pop();
            ans=max(ans,time);
            for(auto nei:mp[node]){
                if(vis.find(nei)==vis.end()){
                    q.push({time+1,nei});
                    vis.insert(nei);
                }
            }
        } 
        return ans;
    }
};