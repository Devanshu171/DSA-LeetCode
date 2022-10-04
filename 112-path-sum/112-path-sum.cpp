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
    bool solve(TreeNode* root, int targetSum){
                     cout<<targetSum<<endl;

         if(!root && targetSum==0) return true;
        if(!root) return false;
        targetSum-=root->val;
        int left=false,right=false;
        if(root->left){
           left= hasPathSum(root->left,targetSum);
        }
        if(root->right){
           right= hasPathSum(root->right,targetSum); 
        }
         if(!root->left && !root->right && targetSum==0) return true;
        return (right || left);
       

    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
       if(!root) return false;
        return solve(root,targetSum);
    }
};