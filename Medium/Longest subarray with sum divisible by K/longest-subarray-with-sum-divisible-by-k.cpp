//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the 
	    unordered_map<int, int> mp;
	    int sum = 0;
	    int ans = 0;
	    mp[0] = 0;
	    for(int i = 0; i < n; i++)
	    {
	       sum += arr[i];
	       int rem = sum % k;
	       rem = (rem + k) % k;
	       if(mp.find(rem) != mp.end())
	       {
	           ans = max(ans, i - mp[rem] + 1);
	       }
	       else 
	        mp[rem] = i + 1;
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
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends