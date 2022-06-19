// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

int countDistinctSubstring(string s);

int main()
{
 int t,l,i,j;
 int temp;
    cin>>t;
 while(t--){
 string s;
  cin>>s;
  cout<<countDistinctSubstring(s)<<endl;

 }
}

// } Driver Code Ends


/*You are required to complete this method */
struct Node{
        
        Node *links[26];
        bool flag=false;
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
    
    int insert(string word,int j) {
        Node *node=root;
        int count=0;
        for(int i=j;i<word.size();i++){
            if(!node->containsKey(word[i])){
                count++;
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            
            }
        node->setEnd();
        return count;
    }


};


int countDistinctSubstring(string s)
{
    //Your code here
    Trie t;

    int ans=0;
    for(int i=0;i<s.size();i++){
        ans+=t.insert(s,i);
    }
    return ans+1;
    
}