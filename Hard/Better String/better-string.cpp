//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  vector<int> dp;
    
    int help(string s)
    {
        int n = s.length();
        dp.resize(n+1, 0);
        dp[0] = 1; // for null subsequence
        
        unordered_map<char, int> mp; // int -> index of the character
        for(int i=1; i<=n; i++)
        {
            char ch = s[i-1];
            dp[i] = dp[i-1]*2;
            
            if(mp.find(ch) != mp.end())  dp[i] = dp[i] - dp[mp[ch] - 1];
            
            mp[ch] = i;
        }
        return dp[n];
    }
    string betterString(string str1, string str2) {
        // code here
        return help(str1)>=help(str2) ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends