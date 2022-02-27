// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>>ds;
        for(int i=0;i<n;i++){
            ds.push_back({end[i],start[i]});
        }
        sort(ds.begin(),ds.end());
        int lastEnd=ds[0].first;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(ds[i].second>lastEnd){
                cnt++;
                lastEnd=ds[i].first;
            }
        }
        return cnt;
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends