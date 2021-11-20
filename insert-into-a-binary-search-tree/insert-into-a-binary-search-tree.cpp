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
    TreeNode* insertIntoBST(TreeNode* root, int key) {
       
        TreeNode *r,*t=root,*temp=new TreeNode(key);
        if(root==NULL)
            return temp;
        while(t){
            r=t;
           if(key>t->val)
               t=t->right;
            else
                t=t->left;
        }
        if(r->val<key) r->right=temp;
        else r->left=temp;
        
        
         return root;
    }
   
};