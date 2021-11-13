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
    bool flag;
    int helper(TreeNode *root){
        if(root==NULL)
            return 0;
        int ls=helper(root->left);
        int rs=helper(root->right);
        if(abs(ls-rs)>1)
            flag=false;
        return 1+max(ls,rs);
    }
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        flag=true;
        helper(root);
        return flag;
        
        
    }
};