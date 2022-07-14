class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> map;
        for(auto num: nums2)
        {
            while(s.size() && s.top() < num)
            {
                map[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> ans;
        for(auto num: nums1)
        {
            if(map.count(num))
                ans.push_back(map[num]);
            else ans.push_back(-1);
        }
        return ans;
    }
};