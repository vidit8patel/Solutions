class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(256, 0);
        for(auto i: t)
            map[i]++;
        int count = t.size(), begin = 0, end = 0, len = INT_MAX, start= 0;
        while(end < s.size())
        {
            if(map[s[end]]>0)
            {
                count--;
            }
            map[s[end]]--;
            end++;
            while(count == 0)
            {
                if(len > end - begin)
                {
                    len = end-begin;
                    start = begin;
                }
                if(map[s[begin]] == 0)
                {
                    count++;
                }
                map[s[begin]]++;
                begin++;
            }
        }
        return len == INT_MAX ? "" : s.substr(start,len);
    }
};