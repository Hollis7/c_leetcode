#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;
void getLeftHighest(vector<int> &height, vector<int> &dp, int size)
{
    dp[0] = height[0];
    for (int i = 1; i < size; i++)
    {
        if (height[i] < dp[i - 1])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = height[i];
        }
    }
}

void getRightHighest(vector<int> &height, vector<int> &dp, int size)
{
    dp[size - 1] = height[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        if (height[i] < dp[i + 1])
        {
            dp[i] = dp[i + 1];
        }
        else
        {
            dp[i] = height[i];
        }
    }
}
int trap(vector<int> &height)
{
    int waterArea = 0;
    int vecSize = height.size();
    /* size 必须大于3 */
    if (vecSize < 3)
        return waterArea;
    vector<int> leftHighest(vecSize, 0);
    vector<int> rightHighest(vecSize, 0);
    getLeftHighest(height, leftHighest, vecSize);
    getRightHighest(height, rightHighest, vecSize);
    for (int i = 1; i < vecSize - 1; i++)
    { /* 左右两边必须比中间高 */
        if (leftHighest[i] != height[i] && rightHighest[i] != height[i])
        {
            waterArea += min(leftHighest[i], rightHighest[i]) - height[i];
        }
    }
    return waterArea;
}
int main()
{
    vector<int> height = {4, 2, 0, 3, 2, 5};
    int waterArea = trap(height);
    cout << "final waterArea:" << waterArea << endl;
}