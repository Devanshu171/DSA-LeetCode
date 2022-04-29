class Solution {
public:
    void solve(int ind,string s,string map[],vector<string>&ans,string temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return;
        }
        // cout<<"i was here"<<endl;
        string k=map[s[ind]-'0'];
        for(int i=0;i<k.size();i++){
            temp.push_back(k[i]);
            solve(ind+1,s,map,ans,temp);
            temp.pop_back();
        }
    
    }
    vector<string> letterCombinations(string s) {
        int n=s.size();
        
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(n==0)
            return ans;
        solve(0,s,map,ans,"");
        return ans;
    }
};