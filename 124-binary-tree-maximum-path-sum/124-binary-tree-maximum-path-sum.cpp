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
    int maxPathSum(TreeNode* root) {
      int   maxpath=INT_MIN;
        helper(root,maxpath);
        return maxpath;
    }
    int helper(TreeNode* node,int &mx){
        if(!node) return 0;
        int lsum=max(0,helper(node->left,mx));
        int rsum=max(0,helper(node->right,mx));
        mx=max(mx,lsum+rsum+node->val);
        return max(lsum,rsum)+node->val;
    }
};