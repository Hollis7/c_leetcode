#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int maxSubArray(vector<int> &nums)
{
    size_t num_size = nums.size();
    if (num_size == 0)
        return 0;
    int pre_sum = nums[0];
    int max_sum = nums[0];
    for (int i = 1; i < num_size; i++)
    {
        if (pre_sum <= 0)
        {
            pre_sum = nums[i];
        }
        else
        {
            pre_sum += nums[i];
        }
        max_sum = max(max_sum, pre_sum);
    }
    return max_sum;
}

int main()
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "max sum: " << maxSubArray(nums) << endl;
}