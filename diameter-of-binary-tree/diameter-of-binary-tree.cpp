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
 int hx=0;
    int maxheight(TreeNode* root){
        if(!root) return 0;
        int ls=maxheight(root->left);
        int rs=maxheight(root->right);
        hx=max(hx,ls+rs);
         return 1+max(ls,rs);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
     maxheight(root);
        return hx;
    }
};