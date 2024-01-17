//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void solve(vector<int> &nums, int ind, int n, set<vector<int>> &s) {
        if(ind == n) {
            s.insert(nums);
            return;
        }
        
        for(int i = ind; i < n; i++) {
            swap(nums[ind], nums[i]);
            solve(nums, ind + 1, n, s);
            swap(nums[ind], nums[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        vector<vector<int>> res;
        set<vector<int>> s;
        solve(arr, 0, n, s);
        
        for(auto i: s)
            res.push_back(i);
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends