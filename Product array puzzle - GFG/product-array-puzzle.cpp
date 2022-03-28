// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    #define ll long long
    vector<long long int> productExceptSelf(vector<long long int>& arr, int n) {
       
        
        vector<ll>ans(n,0);
        int countZero=0;
        ll product=1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                countZero++;
            }else{
                product*=arr[i];
            }
        }
        
        if(countZero==0){
            for(int i=0;i<n;i++){
                ans[i]=product/arr[i];
            }
        }else if(countZero==1){
            for(int i=0;i<n;i++){
                if(arr[i]==0){
                    ans[i]=product;
                    break;
                }
            }
        }
        return ans;
        
    
        
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends