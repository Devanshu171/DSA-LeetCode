// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        
        int i=0,j=0,ans=0;
        sort(a,a+n);
        sort(b,b+m);
        while(i<n && j<m){
            while(i<n-1 && a[i]==a[i+1]) i++;
            while(j<m-1 && b[j]==b[j+1]) j++;
            if(a[i]<b[j]){
                ans++;
                i++;
            }else if(a[i]>b[j]){
                ans++;
                j++;
            }else{
                ans++;
                i++;
                j++;
            }
            
           }
           while(i<n) {
               if(i<n-1 && a[i]==a[i+1]){
               i++;
               }else{
               i++;ans++;
               }
           }
           while(j<m){
               if(j,m-1 && b[j]==b[j+1])
               j++;
               else{
               j++;ans++;
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
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends