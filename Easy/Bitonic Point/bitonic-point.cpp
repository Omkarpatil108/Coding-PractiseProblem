//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	   // int maxi=0;
	   // for(int i=0;i<n;i++)
	   // {
	   //     if(arr[i]>arr[maxi])
	   //     {
	   //         maxi=i;
	   //     }
	        
	   // }return maxi;
	   
	   int low=0;
	   int high=n-1;
	   int maxi=0;
	   while(low<=high)
	   {
	       int mid=(low+high)/2;
	       if(arr[mid]>arr[mid+1])
	       {
	           maxi=max(maxi,arr[mid]);
	           high=mid-1;
	       }
	       else if(arr[mid]<arr[mid+1])
	       {
	           maxi=max(maxi,arr[mid]);
	           low=mid+1;
	       }
	   }
	   return maxi;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends