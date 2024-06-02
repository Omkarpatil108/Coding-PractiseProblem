//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        // code here
        int val = 0,cal=0;
        vector<int>arr = {0};
        vector<int>temp;
        vector<pair<int,int>>qu;
     
        for(int i = 0;i<q;i++){
             if(queries[i][0] == 1){
                 val = val^queries[i][1];
                 arr.push_back(-1);
             }else{
                 arr.push_back(queries[i][1]);
             }
        }
        arr[0] = arr[0]^ val;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]==-1){
                 val = val^ queries[i-1][1];
            }else{
                 arr[i] = val^arr[i];
            }
        }
        vector<int>ans;
        for(int i = 0;i<arr.size();i++){
             if(arr[i] == -1){
                  
             }else{
                  ans.push_back(arr[i]);
             }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int q;
        scanf("%d", &q);

        vector<vector<int>> queries(q, vector<int>(2));
        Matrix::input(queries, q, 2);

        Solution obj;
        vector<int> res = obj.constructList(q, queries);

        Array::print(res);
    }
}

// } Driver Code Ends