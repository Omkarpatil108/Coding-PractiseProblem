//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
    unordered_map<string, bool> mp;
    
    bool isPrefix(string dicWord, string s) {
        return s.find(dicWord) == 0;
    }
    
    bool func(int n, string s, vector<string> &dictionary) {
        
        if(s == "") return true;
        if(mp.count(s) > 0) return mp[s];
        
        for(int i = 0; i < n; i++) {
            bool isPre = isPrefix(dictionary[i], s);
            if(isPre) {
                string remStr = s.substr(dictionary[i].length());
                bool retVal = func(n, remStr, dictionary);
                if(retVal) return mp[s] = true;
            }
            
        }
        return mp[s] = false;
        
    }
public:
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        mp.clear();
        return func(n, s, dictionary);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends