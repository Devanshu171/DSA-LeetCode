class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>vec;
        
        for(int i=0;i<s.size();i++){
            if(vec.size()==0 || vec.back().first!=s[i]){
                vec.push_back({s[i],1});
            }else{
                vec.back().second+=1;
                if(vec.back().second==k){
                    vec.pop_back();
                }
            }
        }
        string ans;
        for(int i=0;i<vec.size();i++){
            while(vec[i].second--)
            ans.push_back(vec[i].first);
        }
        return ans;
        
    }
};