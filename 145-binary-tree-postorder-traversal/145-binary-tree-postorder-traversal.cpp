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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>pre,in,post;
        if(!root)return post;
        stack<pair<TreeNode*,int>>st;
        st.push({root,1});
        while(!st.empty()){
            TreeNode* cur=st.top().first;
            int n=st.top().second;
            st.pop();
            if(n==1){
                pre.push_back(cur->val);
                st.push({cur,n+1});
                if(cur->left) st.push({cur->left,1});
            }
            else if(n==2){
                in.push_back(cur->val);
                st.push({cur,n+1});
                if(cur->right) st.push({cur->right,1});
            }
            else{
                post.push_back(cur->val);
            }
        
        }
        
        return post;
        
    }
};