//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
         int operations =0 ;
        while(n>1){
            if(n%2 != 0){
                n-- ;
                operations ++ ;
            }
            if(n%2 == 0){
                n = n/2  ;
                operations ++ ;
            }
        }
        return operations+1 ;
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
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends