#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int maxArea(vector<int> &height)
{
    int res = 0;
    int curArea = 0;
    int left = 0;
    int right = height.size() - 1;
    int lowerHeight = 0;
    int width = 1;
    while (left < right)
    {
        lowerHeight = min(height[left], height[right]);
        width = right - left;
        curArea = width * lowerHeight;
        res = max(curArea, res);
        if (height[left] == lowerHeight)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return res;
}