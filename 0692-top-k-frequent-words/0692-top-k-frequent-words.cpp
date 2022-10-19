class cmp{
    public:
    bool operator()(pair<int,string>&a,pair<int,string>&b) const{
        return a.first!=b.first ? a.first>b.first:a.second<b.second;
        // if(a.first<b.first) return true;
        // else if(a.first==b.first && a.second>b.second) return true;
        // return false;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mpp;
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        
        for(auto it:words){
            mpp[it]++;
        }
        
        for(auto it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k) pq.pop();
        }
        vector<string>ans;
        
        while(!pq.empty()){
            cout<<pq.top().second<<" "<<pq.top().first<<endl;
            ans.push_back(pq.top().second);
            pq.pop();
        
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};