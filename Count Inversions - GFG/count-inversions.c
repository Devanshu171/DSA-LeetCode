// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long merge(long long a[],long long s ,long long mid,long long e){
    long long int i=s;
    long long int j=mid;
    long long int k=0;
    long long int b[e-s+1];
    long long int count=0;
    while(i<mid && j<=e){
        if(a[i]<=a[j]){
            b[k++]=a[i++];
        }else{
            count+=mid-i;
            b[k++]=a[j++];
        }
    }
    while(i<mid){
        b[k++]=a[i++];
    }
    while(j<=e){
        b[k++]=a[j++];
    }
    k=0;
    for(int p=s;p<=e;p++){
        a[p]=b[k++];
    }
    return count;
    
}
long long msort(long long a[],long long s,long long e){
    
    if(s>=e) return 0;
        long long int mid=s+(e-s)/2;
     long long int x=msort(a,s,mid);
       long long int y=msort(a,mid+1,e);
        long long int z=merge(a,s,mid+1,e);
    
    return x+y+z;
}
long long int inversionCount(long long a[], long long n)
{
    // Your Code Here
    long long int c= msort(a,0,n-1);
    return c;
    
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends