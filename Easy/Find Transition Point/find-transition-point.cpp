//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:    
    
    int transitionPoint(int arr[], int n) {
        // code here
         int i=0;
        int j = n;
        int mid;
        while(i<j){
            mid=(i+j)/2;
            if(arr[mid]==0 && arr[mid+1]==1)return mid+1;
            if(arr[mid]==1 && arr[mid-1]==0)return mid;
            if(arr[mid+1]==0){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int transitionPoint(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], i;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.transitionPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends