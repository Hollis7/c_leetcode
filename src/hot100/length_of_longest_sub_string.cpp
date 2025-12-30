#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
/* ASCII 编码范围（十进制 0-127）,扩展 ASCII 编码（128-255）*/
#define CHAR_SIZE 256
int lengthOfLongestSubstring(string s)
{
    int maxLen = 0;
    size_t len = s.length();
    if (len <= 1)
        return len;

    /* 记录最近字符a,b,c的位置 */
    int cIndex[CHAR_SIZE];
    for (int i = 0; i < CHAR_SIZE; i++)
        cIndex[i] = -1;

    /* 滑动窗口 */
    for (int left = 0, right = 0; right < len; right++)
    {
        if (cIndex[s.at(right)] < left)
        {
            maxLen = max(right - left + 1, maxLen);
            cIndex[s.at(right)] = right;
        }
        else
        { /* 在left右边(包含left)含有相同的字符 */
            left = cIndex[s.at(right)] + 1;
            cIndex[s.at(right)] = right;
        }
    }
    return maxLen;
}
int main()
{
    string s = "  ";
    int maxLen = lengthOfLongestSubstring(s);
    cout << "maxlen: " << maxLen << endl;
}