//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        int dp[100001][2][2];
        int solve(vector<int>&price ,int i,int t,int k)
        {
            if(k==0 || i>=price.size())return 0;
            if(dp[i][t][k]!=-1)return dp[i][t][k];
            if(t)
            {
                return dp[i][t][k]=max(-price[i]+solve(price,i+1,0,k),solve(price,i+1,1,k));
            }
            else
            {
                return dp[i][t][k]=max(price[i]+solve(price,i+1,1,k-1),solve(price,i+1,0,k));
            }
        }
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            memset(dp,-1,sizeof(dp));
            return solve(price,0,1,2);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends