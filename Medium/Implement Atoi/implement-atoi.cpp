//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
  bool _nan(char c){
        return (c<'0'||c>'9');
    }
    
    int genNum(int ini , string& s){
        int num=0;
        for(int i=ini;i<s.size();i++){
            if(_nan(s[i]))return -1;
            int n = (int)s[i]-'0';
            num = num*10+n;
        }
        return (ini==0)?num:-num;
    }
    /*You are required to complete this method */
    int atoi(string s) {
        return (s[0]=='-')?genNum(1,s):genNum(0,s);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends