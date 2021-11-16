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
    bool paths(TreeNode *root,vector<TreeNode*>&vec,TreeNode* x){
        if(!root) return false;
        
        vec.push_back(root);
        if(root==x)
            return true;
        
        if(paths(root->left,vec,x) || paths(root->right,vec,x))
            return true;
        vec.pop_back();
        return false;

        }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>p1;
        vector<TreeNode*>p2;
        paths(root,p1,p);
        paths(root,p2,q);
        int n=p1.size();
        int m=p2.size();
        int i=0,j=0;
        TreeNode* ans;
        while(i<n && j<m){
            if(p1[i]==p2[j])
                ans=p1[i];
            i++;j++;
        }
        return ans;
        
    }
};