class Solution {
public:
bool checkPalin(string s,int i,int j){
	// cout<<s<<endl;
	while(i<=j){
		if(s[i++]!=s[j--]) return false;
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
	for(int i=ind;i<=s.size();i++){
		if(checkPalin(s,ind,i)){
            temp.push_back(s.substr(ind,i-ind+1));
			if(solve(i+1,s,temp,ans));
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