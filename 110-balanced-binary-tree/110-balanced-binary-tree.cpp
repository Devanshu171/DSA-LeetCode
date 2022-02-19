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
    int helper(TreeNode* node,bool &flag){
        if(!node) return 0;
         
        int rh=helper(node->right,flag);
        int lh=helper(node->left,flag);
        
        if(abs(rh-lh)>1) flag=false;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool flag=true;
            helper(root,flag);
        return flag;
    }
};