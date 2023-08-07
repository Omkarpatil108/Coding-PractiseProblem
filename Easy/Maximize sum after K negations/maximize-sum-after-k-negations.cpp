//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        
    //     int sum = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (a[i] < 0 && k > 0)
    //     {
    //         a[i] = -a[i];
    //         k--;
    //     }
    //     sum += a[i];
    // }

    // if (k % 2 == 1)
    // {
    //     // Find the smallest element in the array
    //     long long int mini = LLONG_MAX;
    //     for (int i = 0; i < n; i++)
    //     {
    //         mini = min(mini, a[i]);
    //     }
    //     sum -= 2 * mini;
    // }

    // return sum;
    
      long long int ans=0;
       sort(a,a+n);
       int i=0;
       while(k--){
           if(a[i]<0){
               a[i]=(-1)*a[i];
               i++;
           }
           else{
               break;
           }
       }
       if(k%2==0 && a[i]!=0){
           sort(a,a+n);
           a[0]=(-1)*a[0];
       }
       for(int i=0;i<n;i++){
           ans=ans+a[i];
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends