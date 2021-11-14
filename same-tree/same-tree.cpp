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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            TreeNode* t1=que.front();
            que.pop();
            TreeNode *t2=que.front();
            que.pop();
            
            if(!t1 && !t2) continue;
            if(!t1 || !t2) return false;
            if(t1->val!=t2->val) return false;
            
            que.push(t1->left);
            que.push(t2->left);
             que.push(t1->right);
            que.push(t2->right);
            
                
        }
        return true;
    }
};