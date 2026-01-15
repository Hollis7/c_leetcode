#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
/* O(n^2)*/
// int subarraySum(vector<int> &nums, int k)
// {
//     size_t nums_size = nums.size();
//     int tmp_sum = 0;
//     int ans = 0;
//     if (nums_size == 0)
//         return 0;
//     /* 前i个数的和 */
//     vector<int> dp(nums_size + 1, 0);
//     dp[0] = 0;
//     for (int i = 0; i < nums_size; i++)
//     {
//         dp[i + 1] = dp[i] + nums[i];
//     }
//     for (int i = 0; i < nums_size; i++)
//     {
//         for (int j = i + 1; j <= nums_size; j++)
//         {
//             tmp_sum = dp[j] - dp[i];
//             if (k == tmp_sum)
//             {
//                 ans++;
//             }
//         }
//     }
//     return ans;
// }
/* pre[j] = pre[i] + k,i<j */
int subarraySum(vector<int> &nums, int k)
{
    unordered_map<int, int> map;
    int pre = 0;
    int ans = 0;
    map[0] = 1;          /* 当前pre==k，算一种情况 */
    for (auto &x : nums) /* 避免不必要的拷贝，以及不同类型的nums都可适用 */
    {
        pre += x;
        if (map.find(pre - k) != map.end())
        {
            ans += map[pre - k];
        }
        map[pre]++;
    }
    return ans;
}
int main()
{
    vector<int> nums = {6, 4, 3, 1};
    int k = 10;
    cout << "ans: " << subarraySum(nums, k) << endl;
}