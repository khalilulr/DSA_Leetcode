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
    unordered_map<TreeNode*,int>dp;
public:
    int solve(TreeNode *root,int &maxi){
        if(!root)
            return 0;
        if(dp.find(root)!=dp.end())
            return dp[root];
        int notRob=0;
        if(root->left)
            notRob+=solve(root->left,maxi);
        if(root->right)
            notRob+=solve(root->right,maxi);

        int rob=root->val;
        if(root->left){
            if(root->left->left){
                rob+=solve(root->left->left,maxi);
            }
            if(root->left->right)
                rob+=solve(root->left->right,maxi);
        }
        if(root->right){
             if(root->right->left){
                rob+=solve(root->right->left,maxi);
            }
            if(root->right->right)
                rob+=solve(root->right->right,maxi);
        }

        maxi=max(rob,notRob);;
        return dp[root]=maxi;
    }
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int maxi=INT_MIN;
         solve(root,maxi);
        return maxi;
    }
};