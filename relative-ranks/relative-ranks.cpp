class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int,int>>pq;
        
        int n=score.size();
        vector<string>ans(n);
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        string first="Gold Medal";
        string second="Silver Medal";
        string third="Bronze Medal";
        
    for(int i=1;i<=n;i++){
        
        if(i==1){
            ans[pq.top().second]=(first);
            pq.pop();
        }
        else if(i==2){
            ans[pq.top().second]=(second);
            pq.pop();
        }
        else if(i==3){
            ans[pq.top().second]=(third);
            pq.pop();
        }
        else{
            ans[pq.top().second]=(to_string(i));
             pq.pop();
        } 
    }
        return ans;
    }
};