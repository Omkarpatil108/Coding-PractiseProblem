//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        // vector<int>ans;
        // long long sum=0;
        // int low=1;
        // for(int i=1;i<=n;i++)
        // {
            
        //     if(arr[i]<=s)
        //     {
        //         sum+=arr[i];
                
        //     }
        //     if(sum>s)
        //     {
        //         sum-=arr[low];
        //         low++;
        //     }
        //     return {low,i};
         vector<int>ans;
        ans.push_back(-1);
        long long sum=0;
        int st=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>s && st<i){
                sum-=arr[st];
                st++;
                
            }
            if(sum==s){
                ans[0]=st+1;
                ans.push_back(1+i);
                break;
                
            }
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
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends