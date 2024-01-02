//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
       long long maxi, sum = 0;
        set<long long>pq;
        vector<int>ans(k, 0);
        for(int i = 0; i < k; i++){
            sum += a[i];
            ans[i] = sum;
        }
        maxi = sum;
        pq.insert(0);
        for(int i = k; i < n; i++){
            maxi = max(maxi, sum - *pq.begin());
            sum += a[i];
            pq.insert(ans[(i - k)%k]);
            ans[(i - k)%k] = sum;
        }
        maxi = max(maxi, sum - *pq.begin());
        return maxi; 
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends