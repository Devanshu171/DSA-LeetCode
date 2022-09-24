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
    
    
    void solve(TreeNode* root,int targetSum,vector<int>temp,vector<vector<int>>&ans ){
        if( !root->left && !root->right){
             if( (root && targetSum==root->val)){
                 temp.push_back(root->val);
            ans.push_back(temp);
        }
            return;
        }        
       
        temp.push_back(root->val);
      if(root->left)  solve(root->left,targetSum-root->val,temp,ans);
       if(root->right) solve(root->right,targetSum-root->val,temp,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        if(!root) return ans;
        solve(root,targetSum,{},ans);
        return ans;
    }
};