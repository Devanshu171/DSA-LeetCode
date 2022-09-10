class Solution {
public:
    bool checkPalin(string s){
	// cout<<s<<endl;
	for(int i=0;i<s.size();i++){
		if(s[i]!=s[s.size()-i-1]) return false;
	}
	// cout<<s<<endl;
	return true;
}
// string anss;
bool solve(int ind,string s,vector<string>temp,vector<vector<string>>&ans){
	// cout<<ind<<endl;
	if(ind==s.size()){
		ans.push_back(temp);
		return true;
	}
	for(int i=1;i<=s.size()-ind;i++){
		if(checkPalin(s.substr(ind,i))){
            temp.push_back(s.substr(ind,i));
			if(solve(ind+i,s,temp,ans));
            temp.pop_back();
		}
	}
	return false;
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>temp;
        solve(0,s,temp,ans);
        return ans;
    }
};