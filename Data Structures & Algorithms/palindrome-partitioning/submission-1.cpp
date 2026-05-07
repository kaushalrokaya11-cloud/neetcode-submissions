class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> curr;
        vector<vector<string>> result;
        int start = 0;
        cout << "[DEBUG] Starting partition on string: " << s << endl;
        dfs(result, curr, s, start);
        return result;
    }

    void dfs(vector<vector<string>> &result, vector<string> &curr,
             string &s, int boundary)
    {
        cout << "[DEBUG] Enter DFS with boundary = " << boundary << ", current path = ";
        for (auto &str : curr) cout << str << " ";
        cout << endl;

        if (boundary >= s.length()) {
            cout << "[DEBUG] Reached end, pushing current path to result" << endl;
            result.push_back(curr);
            return;
        }

        for (int i = boundary + 1; i <= s.length(); i++)
        {
            bool isPalindrome = palindromeChecker(boundary, i, s);
            cout << "[DEBUG] Checking substring s[" << boundary << ":" << i << "] = "
                 << s.substr(boundary, i - boundary)
                 << ", isPalindrome = " << isPalindrome << endl;

            if (isPalindrome) {
                curr.push_back(s.substr(boundary, i - boundary));
            } else {
                continue;
            }

            dfs(result, curr, s, i);

            cout << "[DEBUG] Backtracking from substring " << s.substr(boundary, i - boundary) << endl;
            curr.pop_back();
        }
    }

    bool palindromeChecker(int left, int right, string s) {
        right = right - 1;
        cout << "[DEBUG] palindromeChecker called on indices " << left << " to " << right << endl;
        while (left < right) {
            cout << "[DEBUG] Comparing s[" << left << "] = " << s[left]
                 << " and s[" << right << "] = " << s[right] << endl;
            if (s[left] != s[right]) {
                cout << "[DEBUG] Mismatch found" << endl;
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
