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
  
int sum=INT_MIN;
    int maxsum(TreeNode*root){
                    
        if(!root) return 0;
        
        int lsum=max(0,maxsum(root->left));
       int rsum= max(maxsum(root->right),0);
        
        sum=max(root->val+lsum+rsum,sum);
        
        return root->val+max(lsum,rsum);
    
    }
    int maxPathSum(TreeNode* root) {
       
       
        maxsum(root);
        return sum;
    }
};