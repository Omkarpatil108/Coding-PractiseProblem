//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
void calculateisland(vector<vector<int>>& grid, vector<vector<int>>& divideparts, int i, int j, int actualisland, unordered_map<int, int>& islandsizes, int& maxsize){
    queue<pair<int, int>> q;
    q.push({i, j});
    int size=0;
    while(!q.empty()){
        pair<int, int> p=q.front();
        q.pop();
        if (p.first<0 || p.first>=grid.size() || p.second<0 || p.second>=grid[0].size() || divideparts[p.first][p.second]!=0 || grid[p.first][p.second]==0){
            continue;
        }
        divideparts[p.first][p.second]=actualisland;
        size++;
        q.push({p.first+1, p.second});
        q.push({p.first-1, p.second});
        q.push({p.first, p.second+1});
        q.push({p.first, p.second-1});
    }
    islandsizes[actualisland]=size;
    maxsize=max(maxsize, size);
}
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int maxsize=0;
    int actualisland=1;
    unordered_map<int, int> islandsizes;
    vector<vector<int>> divideparts(grid.size(), vector<int>(grid[0].size(), 0));
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if (divideparts[i][j]==0 && grid[i][j]==1){
                calculateisland(grid, divideparts, i, j, actualisland, islandsizes, maxsize);
                actualisland++;
            }
        }
    }
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==0){
                int possiblesize=1;
                set<int> s;
                if(i-1>=0 && divideparts[i-1][j]!=0 && s.find(divideparts[i-1][j])==s.end()){
                    possiblesize+=islandsizes[divideparts[i-1][j]];
                    s.insert(divideparts[i-1][j]);
                }
                if(i+1<grid.size() && divideparts[i+1][j]!=0 && s.find(divideparts[i+1][j])==s.end()){
                    possiblesize+=islandsizes[divideparts[i+1][j]];
                    s.insert(divideparts[i+1][j]);
                }
                if(j-1>=0 && divideparts[i][j-1]!=0 && s.find(divideparts[i][j-1])==s.end()){
                    possiblesize+=islandsizes[divideparts[i][j-1]];
                    s.insert(divideparts[i][j-1]);
                }
                if(j+1<grid[0].size() && divideparts[i][j+1]!=0 && s.find(divideparts[i][j+1])==s.end()){
                    possiblesize+=islandsizes[divideparts[i][j+1]];
                    s.insert(divideparts[i][j+1]);
                }
                maxsize=max(maxsize, possiblesize);
            }
        }
    }
    return maxsize;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends