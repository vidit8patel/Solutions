class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>map;
        int sum=0;
        for(auto i:s)
            map[i]++;
        for(auto i:t)
            map[i]--;
        for(auto it:map)
        {
            if(it.second<0)
                sum += it.second;
        }
        return abs(sum);
    }
};