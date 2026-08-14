class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> freq_t, freq_window;

        int l = 0;
        int r = 0;
        int n = s.length();

        int in_com = 0;
        int best_length = INT_MAX;
        int best_index = 0;

        // Build frequency map for t
        for (int i = 0; i < t.length(); i++) {
            if (freq_t[t[i]] == 0) {
                in_com++;
            }

            freq_t[t[i]]++;
        }

        // Sliding window
        while (r < n) {
            freq_window[s[r]]++;

            if (freq_window[s[r]] == freq_t[s[r]]) {
                in_com--;
            }

            // Try to shrink the window while it remains valid
            while (in_com == 0) {
                if (r - l + 1 < best_length) {
                    best_length = r - l + 1;
                    best_index = l;
                }

                freq_window[s[l]]--;

                if (freq_window[s[l]] == freq_t[s[l]] - 1) {
                    in_com++;
                }

                l++;
            }

            r++;
        }

        // No valid window found
        if (best_length == INT_MAX) {
            return "";
        }

        return s.substr(best_index, best_length);
    }
};