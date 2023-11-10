//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return sum of upper and lower triangles of a matrix.
    vector<int> sumTriangles(const vector<vector<int> >& matrix, int n)
    {
        // code here
        int m=matrix[0].size();
        vector<int>uppertri;
        vector<int>lowertri;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==j){
                    uppertri.push_back(matrix[i][j]);
                    lowertri.push_back(matrix[i][j]);
                    
                }
                else if(j>i){
                    uppertri.push_back(matrix[i][j]);
                }
                else{
                    lowertri.push_back(matrix[i][j]);
                }
            }
        }
        vector<int>ans;
        int sum1=0,sum2=0;
        for(int i=0;i<uppertri.size();i++){
            sum1+=uppertri[i];
            sum2+=lowertri[i];
        }
        
        ans.push_back(sum1);
        ans.push_back(sum2);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }
        Solution ob;
        vector<int> result = ob.sumTriangles(matrix,n);
        for (int i = 0; i < result.size(); ++i)
            cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends