#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<string> curr;
        vector<vector<string>> result;
        int start = 0;
        dfs(result, curr, s, start);
        return result;
    }

    void dfs(vector<vector<string>> &result, vector<string> &curr,
             string &s, int boundary)
    {
        if (boundary >= s.length()) {
            result.push_back(curr);
            return;
        }

        for (int i = boundary; i <s.length(); i++)
        {
            bool isPalindrome = palindromeChecker(boundary, i, s);

            if (isPalindrome) {
                curr.push_back(s.substr(boundary, i - boundary+1));
            } else {
                continue;
            }

            dfs(result, curr, s, i+1);
            curr.pop_back();
        }
    }

    bool palindromeChecker(int left, int right, string s) {
        
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};