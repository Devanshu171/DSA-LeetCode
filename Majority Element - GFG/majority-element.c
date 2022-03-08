// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdbool.h>


 // } Driver Code Ends
//User function Template for C

// Function to find majority element in the array
// a: input array
// size: size of input array
int majorityElement(int a[], int n)
{
        
        int count=1;
        int res=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[res]) count++;
            else count--;
            if(count==0) {
                count=1;
                res=i;
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]==a[res]) cnt++;
        }
        return cnt>n/2? a[res]:-1;
    // your code here
        
}

// { Driver Code Starts.

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        
        for(int i = 0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", majorityElement(arr, n));
    }

    return 0;
}
  // } Driver Code Ends