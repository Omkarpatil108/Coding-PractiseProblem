//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
     int nofmaxsubarray( int arr[], int mid,int N)
    {
         int count=1;
         int sum=0;
         for(int i=0;i<N;i++)
         {
             if(sum+arr[i]>mid)
             {
                  count++;
                 sum=arr[i];
                
             }
             else 
               sum=sum+arr[i];
             
         }
         
         return count;
    }
    int splitArray(int arr[] ,int N, int K) {
        // code here
        
        // Leanr the logic of Binary Search usign the code by Alisha 
        
    int* max = max_element(arr, arr + N);
    int low = *max; 
    int high=0;
        for( int i=0;i<N;i++)
        { 
            high+=arr[i];
           
        }
        
        // now using the binary search logic -->
        int ans=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // make a function to count the noofmaxsubarrypresent ;
            
            int n=nofmaxsubarray(arr,mid,N);
            
            if(n>K) // ye batayega minimum value ko jo ki humse nhi chye
            {
                low=mid+1;
            }
            
            else
            {
                ans=mid;
                high=mid-1;
            }
        }
        
        return ans;
        
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends