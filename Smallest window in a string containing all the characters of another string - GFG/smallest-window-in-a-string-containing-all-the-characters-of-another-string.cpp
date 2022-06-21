// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        unordered_map<char, int> map;
        for(auto ch: p)
        {
            map[ch]++;
        }
        int count = map.size();
        int i = 0, j = 0;
        int start, end = s.length();
        int n = s.length();
        while(j<n)
        {
            if(map.find(s[j]) != map.end())
            {
                map[s[j]]--;
                if(map[s[j]] == 0)
                    count--;
            }
            while(count == 0)
            {
                if(end > j - i + 1)
                {
                    end = j- i + 1;
                    start = i;
                }
                if(map.find(s[i]) != map.end())
                {
                    map[s[i]]++;
                    if(map[s[i]] == 1)
                        count++;
                }
                i++;
            }
            j++;
        }
        if(end == n)
            return "-1";
        return s.substr(start, end);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends