#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
void moveZeroes(vector<int> &nums)
{
    int gap = 0;
    int i = 0;
    int numSize = nums.size();
    for (; i + gap < numSize; i++)
    {
        if (nums[i] != 0)
        {
            continue;
        }
        else
        {
            while (i + gap < numSize && nums[i + gap] == 0)
            {
                gap++;
            }
            if (i + gap >= numSize)
            {
                break;
            }
            nums[i] = nums[i + gap];
            nums[i + gap] = 0;
        }
    }
    for (; i < nums.size(); i++)
    {
        nums[i] = 0;
    }
}
/* 推荐，简洁 */
void moveZeroes2(vector<int> &nums)
{
    int low = 0;
    int fast = 0;
    int numSize = nums.size();
    for (; fast < numSize; fast++)
    {
        if (nums[fast] != 0)
        {
            nums[low++] = nums[fast];
        }
    }
    for (int i = low; i < numSize; i++)
    {
        nums[i] = 0;
    }
}
int main()
{
    vector<int> nums = {0};
    moveZeroes(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        printf("%d,", nums[i]);
    }
    printf("\n");
}