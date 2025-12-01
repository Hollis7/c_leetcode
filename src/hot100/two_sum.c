#include <stdio.h>
#include <stdlib.h>
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *res = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                res[0] = i;
                res[1] = j;
                *returnSize = 2;
                return res;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
int main()
{
    int nums[4] = {2, 7, 11, 15};
    int target = 9;
    int returnSize = 0;
    int *res = twoSum(nums, sizeof(nums) / sizeof(int), target, &returnSize);
    if (returnSize == 2)
    {
        printf("idx: %d,idx:%d\n", res[0], res[1]);
        free(res);
    }
    else
    {
        printf("no matched\n");
    }
    return 0;
}