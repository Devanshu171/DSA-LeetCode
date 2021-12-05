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
    int findmin(TreeNode* root){
        // if(!root) return root;
        int min=root->val;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur->val<min)
                min=cur->val;
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        
        return min;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        
        else if(root->val > key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            
            if(!root->right && !root->left){
                delete root;
                root=NULL;
               
            }
            else if(root->right==NULL){
                TreeNode *temp=root;
                root=root->left;
                delete temp;
            }
            
             else if(root->left==NULL){
                TreeNode *temp=root;
              root=root->right;
                delete temp;
                
            }
            else{
               
                root->val= findmin(root->right);
                root->right=deleteNode(root->right,root->val);
            }
        }
        return root;
    }
};