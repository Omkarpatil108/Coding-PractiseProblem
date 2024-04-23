//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        int a = 1;
        int b = 1;
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 1;
        }
        for (int i=2;i<n;i++)
        {
            int c = (a+b)%1000000007;
            a = b;
            b = c;
        }
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends