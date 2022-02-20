/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string s="";
        if(!root) return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp=q.front();
                q.pop();
               if(temp==NULL) s+=("#,");
                else 
                s+=(to_string(temp->val)+',');
                if(temp){
                    q.push(temp->left);
                    q.push(temp->right);
                }  
            }
        }
        cout<<s;
        return s;
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string str="";
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                cur->left=NULL;
            else{
                TreeNode* curleft=new TreeNode(stoi(str));
                cur->left=curleft;
                q.push(curleft);
            }
             getline(s,str,',');
            if(str=="#") 
                cur->right=NULL;
            else{
                TreeNode* curright=new TreeNode(stoi(str));
                cur->right=curright;
                q.push(curright);
            }
        }
        return root;
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));