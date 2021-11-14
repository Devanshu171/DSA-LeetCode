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
    int up=0;
    int helper(TreeNode* root){
        if(!root)
            return 0;
        int ls=helper(root->left);
        int rs=helper(root->right);
        
        if(root->left)
           ls= root->val==root->left->val ? ls+1:0;
               if(root->right)
                   rs=root->val==root->right->val?rs+1:0;
        
        up=max(up,ls+rs);
    
        return max(rs,ls);
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        helper(root);
        return up;
    }
};