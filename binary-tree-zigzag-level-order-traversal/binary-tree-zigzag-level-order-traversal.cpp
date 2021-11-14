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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>>ans;
        if(!root)
            return ans;
        queue<TreeNode*>q;
        q.push(root);
        
        bool flag=true;
        while(!q.empty()){
            int n=q.size();
            
            vector<int>vec(n);
            
           for(int i=0;i<n;i++){
                TreeNode* t=q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
                if(flag)
                vec[i]=t->val;
                else
                    vec[n-i-1]=t->val;
            }
          
            ans.push_back(vec);
            flag=!flag;
        }
        return ans;
    }
};