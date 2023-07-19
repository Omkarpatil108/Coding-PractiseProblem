//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int A[], int N, int X)
    {
        // code here
         sort(A,A+N);
        int c=INT_MIN;
        int abso=INT_MAX;
        int i=0; int j=1; int k=N-1;
        while(i<j && j<k){
            while(j<k){
                int sum=A[i]+A[j]+A[k];
                if(sum==X) return X;
                if(abs(sum-X)<abso ){
                    abso=abs(sum-X);
                    c=sum;
                    j++;
                }
                else if(abs(sum-X)==abso && sum>c) {
                    c=sum;
                }
                if(sum<X) j++;
                else k--;
            }
            i++; j=i+1; k=N-1;
        }
        
        return c;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends