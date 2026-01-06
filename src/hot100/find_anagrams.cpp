#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int low_letter_size = 26;

vector<int> findAnagrams(string s, string p)
{
    int s_len = s.length();
    int p_len = p.length();
    int diff_count = 0; /* 不同字母的种类数 */
    vector<int> ans;
    if (s_len < p_len)
    {
        return {};
    }

    int letter_count[low_letter_size];
    memset(letter_count, 0, sizeof(letter_count));

    for (int i = 0; i < p_len; i++)
    {
        letter_count[s[i] - 'a']++;
        letter_count[p[i] - 'a']--;
    }
    for (int i = 0; i < low_letter_size; i++)
    {
        if (letter_count[i] != 0)
            diff_count++;
    }

    if (diff_count == 0)
    {
        ans.emplace_back(0);
    }

    for (int i = 0; i < s_len - p_len; i++)
    {
        /* 左边出 */
        if (letter_count[s[i] - 'a'] == 1)
        {
            diff_count--;
        }
        else if (letter_count[s[i] - 'a'] == 0)
        {
            diff_count++;
        }
        letter_count[s[i] - 'a']--;

        /* 右边进 */

        if (letter_count[s[i + p_len] - 'a'] == -1)
        {
            diff_count--;
        }
        else if (letter_count[s[i + p_len] - 'a'] == 0)
        {
            diff_count++;
        }

        letter_count[s[i + p_len] - 'a']++;

        if (diff_count == 0)
        {
            ans.emplace_back(i + 1);
        }
    }

    return ans;
}
int main()
{
    string s = "bpaa";
    string p = "aa";
    vector<int> ans = findAnagrams(s, p);
    if (!ans.empty())
    {
        for (int a : ans)
        {
            cout << a << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "empty" << endl;
    }
}