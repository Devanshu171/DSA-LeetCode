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
    
    TreeNode* helper(vector<int>&pre,vector<int>& in,int &indx,int left,int right,unordered_map<int,int>&mpp){
        if(left>right) return NULL;
        
        int pivot=mpp[pre[indx]];
        TreeNode *root=new TreeNode(in[pivot]);
        indx++;
        root->left=helper(pre,in,indx,left,pivot-1,mpp);
        root->right=helper(pre,in,indx,pivot+1,right,mpp);
        return root;
    }
    
    
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int indx=0;
                unordered_map<int,int>mpp;
        for(int i=0;i<in.size();i++)
            mpp[in[i]]=i;
        return helper(pre,in,indx,0,in.size()-1,mpp);
    }
};