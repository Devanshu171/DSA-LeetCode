// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
void reverse(vector<int>&arr,int i,int j){
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}
    vector<int> nextPermutation(int n, vector<int> arr){
        // code here
        int indx1=-1,indx2;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                indx1=i;
                break;
            }
        }
        if(indx1!=-1){
            for(int i=n-1;i>=0;i--){
                if(arr[i]>arr[indx1]){
                    indx2=i;
                    break;
                }
            }
            swap(arr[indx1],arr[indx2]);
        }
        reverse(arr,indx1+1,n-1);
        return arr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends