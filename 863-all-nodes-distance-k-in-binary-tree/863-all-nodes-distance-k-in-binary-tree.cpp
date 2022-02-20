/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mpp;
    unordered_set<TreeNode*>vis;
    void connectWithParent(TreeNode * root,TreeNode* parent){
        if(!root) return;
        mpp[root]=parent;
        connectWithParent(root->left,root);
        connectWithParent(root->right,root);
        
    }
    void dfs(TreeNode* target,int k,vector<int>&res){
        if(!target) return;
        if(vis.count(target)) return;
        vis.insert(target);
        if(k==0) res.push_back(target->val);
        dfs(target->left,k-1,res);
        dfs(target->right,k-1,res);
        dfs(mpp[target],k-1,res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(!root) return res;
        connectWithParent(root,NULL);
        dfs(target,k,res);
        return res;
        
    }
};