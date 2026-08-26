class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int minLen = INT_MAX;
        string ans = "";

        for (int i = 0; i < n; i++) {
            int ones = 0;

            for (int j = i; j < n; j++) {
                if (s[j] == '1')
                    ones++;

                if (ones == k) {
                    string sub = s.substr(i, j - i + 1);

                    if (sub.length() < minLen) {
                        minLen = sub.length();
                        ans = sub;
                    }
                    else if (sub.length() == minLen && sub < ans) {
                        ans = sub;
                    }

                    break; // longer substring won't be shortest for this i
                }
            }
        }

        return ans;
    }
};