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
    int helper(TreeNode* node){
        if(!node) return 0;
         
        int rh=helper(node->right);
        int lh=helper(node->left);
        if(lh==-1 || rh==-1) return -1;
        if(abs(rh-lh)>1) return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        bool flag=true;
            int x=helper(root);
        return x!=-1;
    }
};