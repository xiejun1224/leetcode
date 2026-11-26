// 438. 找到字符串中所有字母异位词
// 链接：https://leetcode.cn/problems/find-all-anagrams-in-a-string/
// 难度：中等
// 专题：滑动窗口（定长）
//
// 思路：
//   窗口长度固定为 p.size()，右指针进、左指针出，用两个 26 桶的频率表 + count 计数
//   判断"当前窗口内达标的字符个数"，count == p.size() 即为异位词。
//
// 复杂度：时间 O(n)  空间 O(1)（26 个桶）

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ret;
        int hashp[26] = {0};
        int hashs[26] = {0};
        for(auto e : p) {hashp[e - 'a']++;}
        for(int left = 0 , right = 0, count = 0; right < s.size(); right++)
        {
            char in = s[right];
            if(++hashs[in - 'a'] <= hashp[in - 'a']) {++count;}
            if(right - left + 1 > p.size())
            {
                char out = s[left++];
                if(hashs[out - 'a']-- <= hashp[out - 'a']){--count;}
            }
            if(count == p.size()) {ret.push_back(left);}
        }
        return ret;
    }
};
