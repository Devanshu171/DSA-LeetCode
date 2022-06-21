class Solution {
public:
      struct Node{
     Node *links[26]={NULL};
          string word;
        bool flag=false;
        
        bool containsKey(char ch){
            return (links[ch-'a']!=NULL);
        }
        Node *get(char ch){
            return links[ch-'a'];
        }
        void put(char ch,Node *node){
            links[ch-'a']=node;
        }
        void setEnd(){
            flag=true;
        }
    };
    
    
    class Trie{
      private:Node *root;
      
      public:
        
        Trie(){
            root=new Node();
        }
        
       void insert(string s){
            Node *node=root;
            
            for(int i=0;i<s.size();i++){
                char ch=s[i];
                if(!node->containsKey(ch)){
                    node->put(ch,new Node());
                }
                node=node->get(ch);
            }
           node->word=s;
            node->setEnd();
        }
     

        
        void solve(int x,int y,int n,int m,Node *node,vector<vector<char>>& board,vector<string>&ans){
          
            
            if(x<0 || y<0 || x>=n || y>=m || board[x][y]=='#'|| !node->containsKey(board[x][y]))
                return ;
            node=node->get(board[x][y]);
            if(node->flag==true){
                node->flag=false;
                    ans.push_back(node->word);
                }
            
            int dx[]={0,0,-1,1};
            int dy[]={1,-1,0,0};
            
            char ch=board[x][y];
            board[x][y]='#';
            for(int i=0;i<4;i++){
                solve(x+dx[i],y+dy[i],n,m,node,board,ans);
            }
            board[x][y]=ch;
            
        }       
        
        vector<string> getWords(vector<vector<char>>& board){
            int n=board.size();
            int m=board[0].size();
            vector<string>ans;
            Node* node=root;
            
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                solve(i,j,n,m,node,board,ans);
                
            
            return ans;
         }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(auto word:words)t.insert(word);
        return t.getWords(board);
        
    }
};