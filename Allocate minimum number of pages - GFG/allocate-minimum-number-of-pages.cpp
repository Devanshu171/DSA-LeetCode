// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isValid(int a[],int n,int k,int mx){
        int student=1;
        int sum=0;
        for(int i=0;i<n;i++){
          
            
            if(sum+a[i]>mx){
                student++;
                sum=a[i];
            }
            else sum+=a[i];
           
        }
        return student<=k;
    }
    int findPages(int a[], int n, int k) 
    {
        //code here
        if(n<k) return -1;
        int sum=0,mx=INT_MIN;
        for(int i=0;i<n;i++){
            sum+=a[i];
            mx=max(mx,a[i]);
        }
        int start=mx,end=sum;
        
        int res=-1;
       while(start<=end){
            int mid=start+(end-start)/2;
            if(isValid(a,n,k,mid)){
                res=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }   
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends