// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <string.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

int isPalindrome(char S[])
{
    // int n=sizeof(S)/sizeof(S[i]);
    int len=0;
    while(S[len]!='\0')len++;
    for(int i=0;i<len;i++){
        if(S[i]!=S[len-i-1])
        return 0;
    }
    return  1;
}

// { Driver Code Starts.

int main() 
{
   	int t;
   	scanf("%d", &t);
   	while(t--)
   	{
   		char s[100000];
   		scanf("%s", s);


   		printf("%d\n", isPalindrome(s));
   	}

    return 0;
}  // } Driver Code Ends