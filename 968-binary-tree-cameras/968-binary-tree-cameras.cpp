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
    int solve(TreeNode *root,int &ans){
    if(!root) return 0;
    
   int left= solve(root->left,ans);
   int right= solve(root->right,ans);
   if(left==1 || right==1){
       ans++;
       return 2;
   }
   if(left==2 || right==2){
       return 0;
   }
  
       return 1;
   
   
}
    int minCameraCover(TreeNode* root) {
        int ans=0;
        int state=solve(root,ans);
        if(state==1) ans++;
        return ans;
    }
};