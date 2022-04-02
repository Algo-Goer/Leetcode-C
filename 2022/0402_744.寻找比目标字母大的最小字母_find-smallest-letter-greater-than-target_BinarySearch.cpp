/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

// @lc code=start
// 对已经排序好的数组直接二分查找
class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int l = 0, r = letters.size() - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (letters[mid] <= target)
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return letters[l % letters.size()]; // 如果没有比target大的，就返回第一个
    }
};
// @lc code=end
