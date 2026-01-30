#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
 * count_lack记录差异数，右指针会增加符合t的字符，左指针会减少符合t的字符
 * count_lack大于0，移动右指针;
 * count_lack等于0，移动左指针，缩小子窗口，直到count_lack再次大于0
 */
string minWindow(string s, string t)
{
    int t_len = t.length();
    int s_len = s.length();
    int left = 0;
    int right = t_len;
    unordered_map<char, int> t_window;
    unordered_map<char, int> s_window;

    int count_lack = 0; /* s中还缺少字符的种类,对应字符数量需要大于等于t中的 */
    bool has_sub_window = false;
    int position[2];
    position[0] = 0;
    position[1] = s_len;

    if (t_len > s_len)
    {
        return "";
    }

    for (int i = 0; i < t_len; i++)
    {
        t_window[t[i]]++;
    }
    /* 只记录t中需要的 */
    for (int i = 0; i < t_len; i++)
    {
        if (t_window.find(s[i]) != t_window.end())
        {
            s_window[s[i]]++;
        }
    }
    for (auto &t_w : t_window)
    {
        if (s_window.find(t_w.first) == s_window.end() || s_window[t_w.first] < t_w.second)
            count_lack++;
    }
    /* 第一个就是 */
    if (count_lack == 0)
    {
        return s.substr(0, t_len);
    }
    while (right <= s_len)
    {
        if (count_lack > 0)
        {
            if (right < s_len && t_window.find(s[right]) != t_window.end())
            {
                s_window[s[right]]++;
                if (s_window[s[right]] == t_window[s[right]])
                {
                    count_lack--;
                }
            }
            right++;
        }
        else
        {
            has_sub_window = true;
            while (count_lack == 0)
            {
                if ((position[1] - position[0]) >= (right - left))
                {
                    position[0] = left;
                    position[1] = right;
                }
                if (t_window.find(s[left]) != t_window.end())
                {
                    s_window[s[left]]--;
                    if (s_window[s[left]] == t_window[s[left]] - 1)
                    {
                        count_lack++;
                    }
                }
                left++;
            }
        }
    }
    if (has_sub_window)
    {
        return s.substr(position[0], position[1] - position[0]);
    }
    else
    {
        return "";
    }
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << "ans: " << minWindow(s, t) << endl;
}
