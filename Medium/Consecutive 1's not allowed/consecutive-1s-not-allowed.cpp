//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	     if (n == 1) return 2;
        int mod = (int)1e9+7;
        long f = 1;
        long s = 2;
        for (int i = 2; i <= n; i++) {
            long temp = (f % mod + s % mod) % mod;
            f = s;
            s = temp;
        }
        
        return s;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends