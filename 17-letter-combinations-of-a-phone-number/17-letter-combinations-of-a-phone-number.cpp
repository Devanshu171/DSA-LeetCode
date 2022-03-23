class Solution {
public:
    void solve(int indx,string s,string temp,string map[],vector<string>&ans){
        if(indx==s.size()){
            ans.push_back(temp);
            return;
        }
        int number=s[indx]-'0';
        string value=map[number];
        for(int i=0;i<value.size();i++){
            temp.push_back(value[i]);
            solve(indx+1,s,temp,map,ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
        
vector<string>ans;
        if(s.empty())
            return ans;
        string map[10]={"", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,s,"",map,ans);
        return ans;
    }
};

