// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    string chooseandswap(string a){
        // Code Here
       vector<int>freq(26,-1);
       int n=a.size();
       for(int i=0;i<n;i++){
           if(freq[a[i]-'a']==-1)
           freq[a[i]-'a']=i;
       }
       char ch1,ch2;
       bool flag=false;
       for(int i=0;i<n;i++){
           char x=a[i];
           for(int j=0;j<x-'a';j++){
               if(freq[j]>freq[x-'a']){
                   flag=true;
                   ch1=x;
                   ch2=(char)(j+'a');
                   break;
               }
           }
           if(flag)break;
       }
    //   cout<<ch1<<" "<<ch2;
       if(flag)
       for(int i=0;i<n;i++){
            // cout<<a[i]<<" ";
           if(a[i]==ch1){
               a[i]=ch2;
           }
           else if(a[i]==ch2){
               a[i]=ch1;
           }
       }
       
       return a;
    }
    
};


// { Driver Code Starts.

int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
  // } Driver Code Ends