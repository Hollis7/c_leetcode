#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    /* 当前待合并的区间 */
    vector<int> cur_interval(2, 0);
    cur_interval[0] = intervals[0][0];
    cur_interval[1] = intervals[0][1];

    for (auto &interval : intervals)
    {
        /* 发生重合 */
        if (cur_interval[1] >= interval[0])
        {
            cur_interval[1] = max(cur_interval[1], interval[1]);
        }
        /* 没有重合 */
        else
        {
            ans.emplace_back(cur_interval);
            cur_interval[0] = interval[0];
            cur_interval[1] = interval[1];
        }
    }
    ans.emplace_back(cur_interval);

    return ans;
}
int main()
{
    vector<vector<int>> intervals{
        {4, 7},
        {1, 4},
        {8, 10},
        {15, 18}};
    vector<vector<int>> ans = merge(intervals);
    for (auto &an : ans)
    {
        cout << "[" << an[0] << "," << an[1] << "],";
    }
}
