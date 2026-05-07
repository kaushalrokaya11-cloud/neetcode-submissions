class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        unordered_map<char,string> hmap;
        fillHmap(hmap);
        vector<string> result;
        string curr;
        if(digits.length()==0){return {};}
        dfs(hmap, result, curr,digits,0);
        return result;
       
    }

    void dfs(unordered_map<char,string>&hmap,vector<string> &result,
    string &curr, string &digits,int i)
    {
        if(curr.length()==digits.length()){result.push_back(curr);return;}
        
            string s= hmap[digits[i]];
            for(char c:s)
            {
                curr=curr+c;
                dfs(hmap, result, curr, digits, i+1);
                curr.pop_back();
            }
        
    }

    void fillHmap(unordered_map<char,string>&hmap)
    {
        hmap['2']="abc";
        hmap['3']="def";
        hmap['4']="ghi";
        hmap['5']="jkl";
        hmap['6']="mno";
        hmap['7']="pqrs";
        hmap['8']="tuv";
        hmap['9']="wxyz";
    }
};
