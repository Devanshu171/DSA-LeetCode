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
//     void solve(TreeNode* root,string &ans){
//         if(root!) return;
//         if(ans.empty()){
//             ans.push_back(root->val);
//         }else{
//             ans+="("+root->val;
//         }
//         if(!root=>left){
//             ans+="()";
//         }
//         solve(root->left,ans);
        
//     }
    
    string tree2str(TreeNode* root) {
            if(!root) return "";
            string ans=to_string(root->val)+"";
        string left=tree2str(root->left);
        string right=tree2str(root->right);
        
        if(left=="" && right=="") return ans;
        return ans+"("+left+")"+(right==""?"":"("+right+")");
    }
};