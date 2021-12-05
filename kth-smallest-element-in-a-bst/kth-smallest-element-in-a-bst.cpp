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
    int count=0;
    void helper(TreeNode* root,int k,int &s){
        if(!root) return;
        
        helper(root->left,k,s);
        count++;
        cout<<root->val<<" ";
        if(count==k) s=root->val;
        helper(root->right,k,s);
    }
    int kthSmallest(TreeNode* root, int k) {
        int s=0;
        helper(root,k,s);
        return s;
    }
};