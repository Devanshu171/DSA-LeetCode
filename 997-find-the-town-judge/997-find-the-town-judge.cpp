class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int>outdegre(n+1,0),indegree(n+1,0);
        for(auto it:trust){
            outdegre[it[0]]++;
            indegree[it[1]]++;
            cout<<outdegre[it[0]]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            cout<<outdegre[i]<<" ";
            if(outdegre[i]==0 && indegree[i]==n-1) return i;
        }
        return -1;
    }
};