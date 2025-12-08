#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>
using namespace std;
/* O(nlogn) */
int longestConsecutive(vector<int> &nums)
{
    if (nums.size() <= 1)
    {
        return nums.size();
    }
    sort(nums.begin(), nums.end());
    int maxLen = 1;
    int currentLen = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        // 处理重复元素：跳过但不重置
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        // 连续
        else if (nums[i] == nums[i - 1] + 1)
        {
            currentLen++;
            maxLen = max(maxLen, currentLen);
        }
        // 不连续
        else
        {
            currentLen = 1;
        }
    }
    return maxLen;
}
/* O(n) */
int longestConsecutive2(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    unordered_set<int> numSet(nums.begin(), nums.end());
    int maxLen = 0;
    for (int num : numSet)
    { /* num是起点 */
        if (numSet.find(num - 1) == numSet.end())
        {
            int curNum = num;
            int curLen = 1;
            while (numSet.find(curNum + 1) != numSet.end())
            {
                curLen++;
                curNum++;
            }
            maxLen = max(curLen, maxLen);
        }
    }
    return maxLen;
}
int main()
{
    vector<int> nums = {0, 1, 1, 2};
    printf("maxlen:%d\n", longestConsecutive2(nums));
}