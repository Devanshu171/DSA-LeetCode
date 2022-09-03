class Solution {
public:
    void solve(int n,int k,vector<int>&ans,string temp){
        if(temp.size()==n){
            ans.push_back(stoi(temp));
            return;
        }
        
        for(int i=0;i<=9;i++){
            // cout<<temp<<endl;
            if((temp.empty() && i!=0) ){
                temp.push_back(i+'0');
                solve(n,k,ans,temp);
                temp.pop_back();
            }
          else if( abs((temp.back()-'0')-i)==k){
                temp.push_back(i+'0');
                solve(n,k,ans,temp);
               temp.pop_back();
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int>ans;
        solve(n,k,ans,"");
        return ans;
    }
};