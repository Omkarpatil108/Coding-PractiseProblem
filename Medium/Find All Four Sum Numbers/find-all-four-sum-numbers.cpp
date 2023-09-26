//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        vector<vector<int>> ans;
        int n = arr.size();
        set<vector<int>> s;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++) {
                int l = j+1,r = n-1;
                int sum = arr[i]+arr[j];
                int targetSum = k - sum;
                while(l<r) {
                    if(arr[l]+arr[r] == targetSum)
                    {   vector<int>quad = {arr[i],arr[j],arr[l],arr[r]};
                        s.insert(quad);
                        l++; r--;
                    }
                    else if(arr[l]+arr[r] < targetSum)
                    l++;
                    else
                    r--;
                }
            }
        }
        for(auto x:s)
        ans.push_back(x);
        
        return ans;// Your code goes here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends