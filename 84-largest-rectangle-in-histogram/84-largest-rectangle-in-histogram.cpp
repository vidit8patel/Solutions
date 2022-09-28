class Solution
{
    public:
        int largestRectangleArea(vector<int> &heights)
        {
            stack<int> st;
            int n = heights.size();
            int ans = 0;
            for (int i = 0; i <= n; i++)
            {
                while (!st.empty() && (i == n || heights[i] <= heights[st.top()]))
                {
                    int height = heights[st.top()];
                    st.pop();
                    int width = 0;
                    if (st.empty())
                        width = i;
                    else width = i - st.top() - 1;
                    ans = max(ans, height *width);
                }
                st.push(i);
            }
            return ans;
        }
};