//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string A) {
        //code here
        vector<vector<int>> dp(A.length() + 1, vector<int>(A.length() + 1, -1));
        return solve(0, 0, A, string(A.rbegin(), A.rend()), dp);
    }
    private:
    int solve(int i, int j, const string& A, const string& B, vector<vector<int>>& dp) {
        if (i == A.length() || j == B.length()) {
            dp[i][j] = 0;
            return dp[i][j];
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        if (A[i] == B[j]) {
            dp[i][j] = 1 + solve(i + 1, j + 1, A, B, dp);
            return dp[i][j];
        }

        dp[i][j] = max(solve(i + 1, j, A, B, dp), solve(i, j + 1, A, B, dp));
        return dp[i][j];
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends