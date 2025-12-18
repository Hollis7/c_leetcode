#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    int numSize = nums.size();

    /* 排序，方便定位 */
    sort(nums.begin(), nums.end());
    /* i,k,j*/
    for (int i = 0; i < numSize - 2; i++)
    {
        /* 第一位重复 */
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }

        int j = numSize - 1;

        int tmp = -nums[i];
        for (int k = i + 1; k < j; k++)
        { /* 第二位重复 */
            if (k > i + 1 && nums[k] == nums[k - 1])
            {
                continue;
            }
            while (k < j && nums[k] + nums[j] > tmp)
            {
                j--;
            }
            /* 没有符合的k,j 跳过循环 */
            if (j == k)
            {
                break;
            }
            /* 后续可能还有，继续循环 */
            if (nums[k] + nums[j] == tmp)
            {
                ans.emplace_back(vector<int>{nums[i], nums[k], nums[j]});
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {-6, -4, -2, -2, -2, 0, 2, 4, 6, 8};
    vector<vector<int>> res = threeSum(nums);

    // 简洁漂亮的打印
    if (res.empty())
    {
        cout << "没有找到三数之和为0的组合" << endl;
    }
    else
    {
        cout << "找到 " << res.size() << " 个组合：" << endl;
        for (int i = 0; i < res.size(); i++)
        {
            cout << "第" << i + 1 << "组: {"
                 << res[i][0] << ", " << res[i][1] << ", " << res[i][2]
                 << "}" << endl;
        }
    }
    return 0;
}