//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.length();
	    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,str,str,dp);
		}
    
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp)
    {
        //base case
        if(i==s1.length() or j==s2.length())
        return 0;
        
        //memo check - is ans already calculated
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        //recursive calls
        //small calculation
        if(s1[i]==s2[j] and i!=j)
        return dp[i][j]=1+solve(i+1, j+1, s1, s2, dp);
        
        int a=solve(i+1, j, s1, s2, dp);
        int b=solve(i, j+1, s1, s2, dp);
        
        return dp[i][j]=max(a,b);
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends