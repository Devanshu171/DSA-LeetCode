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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth==1){
            TreeNode *temp=new TreeNode(val);
            temp->left=root;
            return temp;
            
        }
        queue<TreeNode*>q;
        int level=1;
        q.push(root);
        while(!q.empty()){
            level++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                if(level==depth){
                    TreeNode* left=new TreeNode(val);
                    TreeNode* right=new TreeNode(val);
                    left->left=temp->left;
                    right->right=temp->right;
                    temp->left=left;
                    temp->right=right;
                }else{
                
               if(temp->left) q.push(temp->left);
                if(temp->right)   q.push(temp->right);
                }
            }
            // if(level>depth){
            //     return root;
            // }
            
        }
        return root;
    }
};