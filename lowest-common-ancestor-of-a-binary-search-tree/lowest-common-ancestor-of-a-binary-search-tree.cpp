/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      
        while(root){
            int key=root->val, x=p->val,y=q->val;
            
            if(x<key && y<key) root=root->left;
            else if(x>key && y>key) root=root->right;
            else return root;
        }
        return NULL;
    }
};