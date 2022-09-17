#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> um;
        int ret = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (um.count(s[i])) ret = max(ret, i - um[s[i]] - 1);
            else um[s[i]] = i;
        }
        return ret;
    }
};