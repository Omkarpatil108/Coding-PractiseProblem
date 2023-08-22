//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int sum = 0, maxRowSum = INT_MIN, maxColSum = INT_MIN;
        for (int i = 0; i < n; i++) {
        int rowSum = 0,colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];  //for computing row sum 
            colSum += matrix[j][i];   // for computing col sum
            sum += matrix[i][j];       //for computing sum of all elements 
        }
        if (rowSum > maxRowSum)  maxRowSum = rowSum;
        if (colSum > maxColSum) maxColSum = colSum;
    }
   
    
    int res = max(maxColSum,maxRowSum);
    return res*n-sum;
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
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends