class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> map;
        int count = 0;
        for(int i = 0; i<tasks.size(); i++)
        {
            map[tasks[i]]++;
            count = max(count, map[tasks[i]]);
        }
        int ans = (count-1)*(n+1);
        for(auto i: map)
        {
            if(i.second == count)
                ans++;
        }
        int size = tasks.size();
        return max(size, ans);
    }
};