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
    int solve(TreeNode* root,unordered_map<int,int>&mpp){
        if(!root) return 0;
         mpp[root->val]++;
        if(!root->right && !root->left){
            int cnt=0;
            for(auto it:mpp){
                if(it.second%2!=0) cnt++;
                if(cnt>1) break;
            }
                        cout<<" vdfhsd"<<endl;
             mpp[root->val]--;
            return cnt<=1;
            // cout<<" vdfhsd"<<endl;
        }
        
       
      int left=  solve(root->left,mpp);
        int right=solve(root->right,mpp);
        mpp[root->val]--;
        return left+right;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int>mpp;
        return solve(root,mpp);
        // queue<TreeNode*>q;
//         q.push(root);
//         while(!q.empty()){
            
//         }
        
    }
};