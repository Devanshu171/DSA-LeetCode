class Solution {
public:
    bool check(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>arr[(i+1)%arr.size()])
                ans++;
        }
        return (ans<=1);
    }
};