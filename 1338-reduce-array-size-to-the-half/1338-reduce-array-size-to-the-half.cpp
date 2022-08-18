class Solution {
public:
    int minSetSize(vector<int>& arr) {
      
//             int n=arr.size();
//         sort(begin(arr),end(arr));
//         vector<pair<int,int>>vec;
//         for(int i=0;i<n;i++){
//             int cnt=1;
//             while(i<n-1 && arr[i]==arr[i+1]){
//                 cnt++;
//                 i++;
//             }
//                 vec.push_back({cnt,arr[i]});
            
//         }
//         sort(begin(vec),end(vec));
//         int ans=0;
//         int sum=0;
//         for(int i=vec.size()-1;i>=0;i--){
//             ans++;
//             cout<<vec[i].first<<endl;
//             sum+=vec[i].first;
//             if(sum>=n/2){
//                 return ans;
//             }
//         }
//         return ans;
        unordered_map<int,int>mpp;
        int n=arr.size();
        priority_queue<int>pq;
        for(auto it:arr) mpp[it]++;
        for(auto it:mpp){
            pq.push(it.second);
        }
        
        int sum=0,ans=0;
        while(sum<n/2){
            ans++;
            sum+=pq.top();
            pq.pop();
        }
        return ans;
        
    }
};