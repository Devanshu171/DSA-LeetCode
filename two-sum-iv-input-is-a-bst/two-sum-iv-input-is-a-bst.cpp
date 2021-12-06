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

class BSTIterator {
public:
      stack<TreeNode*>st;
    bool reverse=true;
    BSTIterator(TreeNode* root,bool isreverse) {
        reverse=isreverse;
        pushall(root);
    }
    void pushall(TreeNode* root){
        TreeNode *p=root;
        while(p){
                st.push(p);
            if(!reverse)
                p=p->left; 
            else
                p=p->right;
        }
    }
    int next() {
        TreeNode* top=st.top();
       st.pop();
        
        if(!reverse)
            pushall(top->right); 
         else pushall(top->left);
        return top->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:

    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        
        BSTIterator l(root,false);
        BSTIterator r(root,right);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j){
            
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        
          return false;  
        
    }
};