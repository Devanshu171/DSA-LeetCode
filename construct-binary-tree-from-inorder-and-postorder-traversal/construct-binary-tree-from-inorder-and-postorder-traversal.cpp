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
    TreeNode* helper(vector<int>&post,vector<int>& in,int &indx,int left,int right,unordered_map<int,int>&mpp){
       
        if( indx<0 || left>right) return NULL;
        
        
        TreeNode *root=new TreeNode(post[indx]);
        int pivot=mpp[post[indx]];
        indx--;
        
        root->right=helper(post,in,indx,pivot+1,right,mpp);
        root->left=helper(post,in,indx,left,pivot-1,mpp);
        
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int indx=post.size()-1;
                unordered_map<int,int>mpp;
        for(int i=0;i<in.size();i++)
            mpp[in[i]]=i;
        return helper(post,in,indx,0,in.size()-1,mpp);
    }
};