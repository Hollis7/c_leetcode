#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
/* 超时了 */
vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    size_t nums_size = nums.size();
    deque<int> maxTwo;
    vector<int> cur_window(nums.begin(), nums.begin() + k);
    vector<int> ans;
    if (k == 1 || nums_size == 1)
        return nums;
    if (nums_size < k)
    {
        return {};
    }
    sort(cur_window.begin(), cur_window.end(), [](int a, int b)
         { return a > b; }); /* 降序排序 */
    maxTwo.push_back(cur_window[0]);
    maxTwo.push_back(cur_window[1]);
    ans.emplace_back(maxTwo.front());

    for (int i = 0; i < nums_size - k; i++)
    {
        /* 新加入的值更大 */
        if (nums[i + k] > maxTwo.front())
        {
            maxTwo.pop_back();
            maxTwo.push_front(nums[i + k]);
        }
        /* 窗口删除的值是最大值或者次最大值，重新排序 */
        if (nums[i] == maxTwo.front() || nums[i] == maxTwo.back())
        {
            cur_window.assign(nums.begin() + i + 1, nums.begin() + i + 1 + k);
            sort(cur_window.begin(), cur_window.end(), [](int a, int b)
                 { return a > b; }); /* 降序排序 */
            maxTwo.clear();
            maxTwo.push_back(cur_window[0]);
            maxTwo.push_back(cur_window[1]);
        }
        ans.emplace_back(maxTwo.front());
    }
    return ans;
}
/* 法二 */
vector<int> maxSlidingWindow2(vector<int> &nums, int k)
{
    size_t nums_size = nums.size();
    deque<int> q;
    for (int i = 0; i < k; ++i)
    {
        while (!q.empty() && nums[i] >= nums[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};
    for (int i = k; i < nums_size; ++i)
    {
        while (!q.empty() && nums[i] >= nums[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
        if (q.front() <= i - k)
        {
            q.pop_front();
        }
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1};
    int k = 1;
    vector<int> ans = maxSlidingWindow(nums, k);
    if (!ans.empty())
    {
        for (auto &x : ans)
        {
            cout << x << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "error" << endl;
    }
}