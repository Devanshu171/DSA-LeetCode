// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string convertToRoman(int num) {
        // code here
        string ones[]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string tens[]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string hund[]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string thus[]={"","M","MM","MMM"};
       
        string ans="";
        int place=0;
        while(num){
            if(num%10==0){
                while(num%10==0) {
                    place++;
                    num/=10;
            }   
         }else{
                 if(place==0){
                ans=ones[num%10]+ans;
            }else if(place==1){
                ans=tens[num%10]+ans;
            }else if(place==2){
                ans=hund[num%10]+ans;
            }else{
                ans=thus[num%10]+ans;
            }
                  num/=10;
                place++;
            }
          
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}  // } Driver Code Ends