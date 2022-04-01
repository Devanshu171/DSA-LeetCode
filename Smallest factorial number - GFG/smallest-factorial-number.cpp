// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    int countZeros(int n){
        //  cout<<n<<endl;
        int count=0;
        while(n>0){
            count+=(n/5);
            n/=5;
        }
        return count;
    }
    public:
        int findNum(int n)
        {
        //complete the function here
       int low=1,high=n*5;
       int ans=-1;
       while(low<=high){
           int mid=low+(high-low)/2;
           if(countZeros(mid)>=n){
               ans=mid;
               high=mid-1;
           }else{
               low=mid+1;
           }
       }
       return ans;
       
    }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends