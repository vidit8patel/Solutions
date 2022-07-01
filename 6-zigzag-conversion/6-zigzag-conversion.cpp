class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        int jumps = 2*(numRows-1);
        string ans = "";
        for(int i = 0; i<numRows; i++)
        {
            for(int j = 0; i+j<s.length(); j+=jumps)
            {
                ans+= s[i+j];
                if(i != 0 && i != numRows-1 && j+jumps-i<s.length())
                    ans+=s[j+jumps-i];
            }
        }
        return ans;
    }
};