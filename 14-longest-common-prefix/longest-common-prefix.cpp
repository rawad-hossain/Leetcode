class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        if (strs.size() == 1) {
            return strs[0];
        }
        if (strs[0] == strs[strs.size() - 1]) {
            return strs[0];
        }
        for (int i = 0; i < strs[0].length(); i++) {
            if (strs[strs.size() - 1][i] != strs[0][i]) {
                return strs[0].substr(0, i);
            }
        }
        return strs[0];
    }
};