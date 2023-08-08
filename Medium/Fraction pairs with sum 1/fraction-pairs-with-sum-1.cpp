//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countFractions(int n, int numerator[], int denominator[])
    {
        unordered_map<double,int>map;
        int count = 0;
        for(int i = 0;i < n;i++) {
            
            int gcd = __gcd(numerator[i],denominator[i]);
            
            int nm = numerator[i]/gcd;
            int dm = denominator[i]/gcd;
            
            double x = (double)(dm - nm) / dm;
            double y = (double)nm / dm;
            if(map[x] > 0) {
                count = count + map[x];
            }
            map[y]++;
        }
        

        return count;
        
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
        int numerator[n],denominator[n];
        for(int i=0;i<n;i++)
            cin>>numerator[i];
        for(int i=0;i<n;i++)
            cin>>denominator[i];
        Solution ob;
        int ans=ob.countFractions(n,numerator,denominator);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends