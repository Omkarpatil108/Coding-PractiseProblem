//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
         vector<int> ans;
        
        int i = 0, j = 0;
        while(j < m){
            ans.push_back(matrix[i][j++]);
        }
        
        if(n == 1) return (ans);
        
        i = 1, j = m-1;
        while(i < n){
            ans.push_back(matrix[i++][j]);
        }
        
        if(m == 1) return (ans);
        
        i = n-1,j = m-2;
        while(j >= 0){
            ans.push_back(matrix[i][j--]);
        }
        
        i = n-2, j = 0;
        while(i > 0){
            ans.push_back(matrix[i--][j]);
        }
        
        return (ans);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends