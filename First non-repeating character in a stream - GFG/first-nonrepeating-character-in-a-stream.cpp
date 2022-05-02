// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    queue<int>q;
		    int count[26]={0};
		    for(int i=0;i<s.size();i++){
		        count[s[i]-'a']++;
		        if(count[s[i]-'a']==1)
		        q.push(s[i]);
		        while(!q.empty() && count[q.front()-'a']!=1)
		        q.pop();
		        if(q.empty())
		        s[i]='#';
		        else
		        s[i]=q.front();
		    }
		    return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends