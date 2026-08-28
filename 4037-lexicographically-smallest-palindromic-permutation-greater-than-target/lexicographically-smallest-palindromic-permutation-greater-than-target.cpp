class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26);
        for (char c : s)
            cnt[c - 'a']++;

        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        vector<int> halfCnt(26);
        for (int i = 0; i < 26; i++)
            halfCnt[i] = cnt[i] / 2;

        auto build = [&](const string& h) {
            string res = h;

            if (n % 2)
                res += mid;

            for (int i = m - 1; i >= 0; i--)
                res += h[i];

            return res;
        };

        // Try the exact first half of target
        vector<int> rem = halfCnt;
        string h;
        bool possible = true;

        for (int i = 0; i < m; i++) {
            int x = target[i] - 'a';

            if (rem[x] == 0) {
                possible = false;
                break;
            }

            h += target[i];
            rem[x]--;
        }

        // If exact half is possible, the palindrome may already be > target
        if (possible) {
            string ans = build(h);
            if (ans > target)
                return ans;
        }

        // Find the smallest half strictly greater than target's first half
        for (int p = m - 1; p >= 0; p--) {
            rem = halfCnt;
            string prefix;
            bool ok = true;

            // Keep target[0..p-1] unchanged
            for (int i = 0; i < p; i++) {
                int x = target[i] - 'a';

                if (rem[x] == 0) {
                    ok = false;
                    break;
                }

                prefix += target[i];
                rem[x]--;
            }

            if (!ok)
                continue;

            int cur = target[p] - 'a';

            // Choose the smallest character greater than target[p]
            for (int c = cur + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string nh = prefix;
                nh += char('a' + c);
                rem[c]--;

                // Fill remaining half in lexicographically smallest order
                for (int x = 0; x < 26; x++) {
                    while (rem[x] > 0) {
                        nh += char('a' + x);
                        rem[x]--;
                    }
                }

                return build(nh);
            }
        }

        return "";
    }
};