//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        vector<int> ans;
        for(int i=0;i<q;i++){
            int a =  queries[i][0];
            int b =  queries[i][1];
            int c =  queries[i][2];
            int sum = 0;
            //loop1 for up and down
            for(int j=-a;j<=a;j++){
                    int x = b+a; 
                    int z = b-a;
                    int y = c+ j;
                    if(x>=0 && x<n && y>=0 && y<m ){
                        sum += mat[x][y];
                    }
                    if(z>=0 && z<n && y>=0 && y<m ){
                        sum += mat[z][y];
                    }
            }
            //loop for left and right but excluding two from top //and two from bottom as it is included previously
             for(int j=-a+1;j<=a-1;j++){
                    int y = c+a; 
                    int z = c-a;
                    int x = b+ j;
                    if(x>=0 && x<n && y>=0 && y<m ){
                        sum += mat[x][y];
                    }
                    if(x>=0 && x<n && z>=0 && z<m ){
                        sum += mat[x][z];
                    }
            }
           
            ans.push_back(sum);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends