class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        queue<pair<string,int>>q;
        q.push({start,0});
        vector<int>vis(bank.size(),0);
        while(!q.empty()){
            string cur=q.front().first;
            int num=q.front().second;
            q.pop();
            if(cur==end) return num;
           
            for(int i=0;i<bank.size();i++){
                 int cnt=0;
                for(int j=0;j<bank[i].size();j++){
                    if(bank[i][j]!=cur[j])cnt++;
                }
                if(cnt==1 && vis[i]==0){
                    q.push({bank[i],num+1});
                    vis[i]=1;
                }
            }
        }
        return -1;
    }
};