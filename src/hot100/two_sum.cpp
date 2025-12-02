#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> hashTable;
    for (int i = 0; i < nums.size(); i++)
    {
        auto ht = hashTable.find(target - nums[i]);
        if (ht != hashTable.end())
        {
            return {ht->second, i};
        }
        hashTable[nums[i]] = i;
    }
    return {};
}

int main()
{
    // 测试用例1：题目示例
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    vector<int> result1 = twoSum(nums1, target1);
    cout << "测试用例1: nums = [2,7,11,15], target = 9" << endl;
    cout << "结果: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "验证: nums[" << result1[0] << "] + nums[" << result1[1] << "] = "
         << nums1[result1[0]] << " + " << nums1[result1[1]] << " = " << target1 << endl;
    cout << endl;

    // 测试用例2
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> result2 = twoSum(nums2, target2);
    cout << "测试用例2: nums = [3,2,4], target = 6" << endl;
    cout << "结果: [" << result2[0] << ", " << result2[1] << "]" << endl;
    cout << "验证: nums[" << result2[0] << "] + nums[" << result2[1] << "] = "
         << nums2[result2[0]] << " + " << nums2[result2[1]] << " = " << target2 << endl;
    cout << endl;

    // 测试用例3
    vector<int> nums3 = {3, 3};
    int target3 = 6;
    vector<int> result3 = twoSum(nums3, target3);
    cout << "测试用例3: nums = [3,3], target = 6" << endl;
    cout << "结果: [" << result3[0] << ", " << result3[1] << "]" << endl;
    cout << "验证: nums[" << result3[0] << "] + nums[" << result3[1] << "] = "
         << nums3[result3[0]] << " + " << nums3[result3[1]] << " = " << target3 << endl;
    cout << endl;

    // 测试用例4：无解情况
    vector<int> nums4 = {1, 2, 3, 4};
    int target4 = 10;
    vector<int> result4 = twoSum(nums4, target4);
    cout << "测试用例4: nums = [1,2,3,4], target = 10" << endl;
    cout << "结果: [";
    if (!result4.empty())
    {
        cout << result4[0] << ", " << result4[1];
    }
    else
    {
        cout << "无解";
    }
    cout << "]" << endl;
    cout << endl;

    return 0;
}