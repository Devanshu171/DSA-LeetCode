class Solution {
public:
    struct Node{
        
        Node *links[26];
        bool flag=false;
        int cnt=0;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
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

class Trie {
    
    private:Node *root;
    
public:
    
    Trie() {
        
        root=new Node();
        
    }
    
    void insert(string word) {
        Node *node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                
                node->put(word[i],new Node());
            }
            node->cnt++;
            node=node->get(word[i]);
            
            }
         node->cnt++;
        node->setEnd();
        
    }
    
    int search(string word) {
        Node *node=root;
        int count=0;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])) return false;
                node=node->get(word[i]);  
             count+=node->cnt; 
        }
         // count+=node->cnt;
        return count;
    }
    
    
};
    vector<int> sumPrefixScores(vector<string>& words) {
     Trie t;
        for(int i=0;i<words.size();i++){
            t.insert(words[i]);
        }
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            int cnt=t.search(words[i]);
            
            ans.push_back(cnt);
        }
        return ans;
    }
};