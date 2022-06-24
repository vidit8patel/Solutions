class Solution {
public:
    unordered_map<string, int> map;
    bool isScramble(string a, string b) {
        if(a.length() != b.length())
            return false;
        if(a.length() == 0)
            return true;
        if(a == b)
            return true;
        string key = a + "$" + b;
        if(map.find(key) != map.end())
            return map[key];
        int n = a.length();
        bool ans = false;
        for(int i = 1; i<=n-1; i++)
        {
            if((isScramble(a.substr(0, i), b.substr(n-i, i)) && isScramble(a.substr(i, n-i), b.substr(0, n-i))) || (isScramble(a.substr(0, i), b.substr(0, i)) && isScramble(a.substr(i, n-i), b.substr(i, n-i))))
            {
                ans = true;
                break;
            }
        }
        return map[key] = ans;
    }
};