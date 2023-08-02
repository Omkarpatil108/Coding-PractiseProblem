//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
         if(A[0][0]==0 || A[X][Y]==0)
        return -1;
        pair<int, int> movement[4]={{1,0}, {0, 1}, {-1, 0}, {0, -1}};
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        vector<vector<int>> visited(N, vector<int>(M, 0));
        visited[0][0]=1;
        int steps=N*M;
        while(!q.empty())
        {
            int step=q.front().first;
            pair<int, int> temp=q.front().second;
            q.pop();
            if(temp.first==X && temp.second==Y)
                {
                    return step;
                }
                for(int k=0; k<4; k++)
                {
                    int i=temp.first+movement[k].first;
                    int j=temp.second+movement[k].second;
                    if(i<N && i>=0 && j<M && j>=0 && visited[i][j]==0 && A[i][j]==1)
                    {
                        q.push({step+1, {i, j}});
                        visited[i][j]=1;
                    }
                }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends