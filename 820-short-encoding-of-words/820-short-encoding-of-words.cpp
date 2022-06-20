class Solution {
public:
    struct Node{
      Node *links[26];
      bool flag=false;
        
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;
    }
    Node *get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
        
    };
    
    class Trie{
        private: Node *root;
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
            node->setEnd();
        }
        
        void solve(Node *node,string temp,int &ans,int level){
            if(!node) return;
            if(node->flag==true)temp.push_back('#');
            if(temp.size()>0 && node->flag==true && temp.size()==level){
                ans=min(ans,level);
                return;
            }
            
            
            for(char i='a';i<='z';i++){
                if(node->containsKey(i)){
                    solve(node->get(i),temp+i,ans,level+1);
                }
            }
            
        } 
        
        int getEncode(){
            Node *node=root;
            int ans=INT_MAX;
            solve(node,"",ans,0);
            return ans;
            
        }
    };
    int minimumLengthEncoding(vector<string>& words) {
       unordered_set<string>st(words.begin(),words.end());
        for(auto s:st){
            for(int i=1;i<s.size();i++){
                if(st.count(s.substr(i))){
                    st.erase(s.substr(i));
                }
            }
        }
        int ans=0;
        for(auto it:st){
            ans+=it.size()+1;
        }
        return ans;
        
    }
};