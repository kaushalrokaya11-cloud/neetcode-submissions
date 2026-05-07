class Solution {
public:

vector<string> result;
    vector<string> generateParenthesis(int n) {
       
        string curr="";
         dfs(n, 0,0,curr);
        return result;    
    }
    void dfs(int n , int openN, int closeN, string curr){
       
       if(openN==closeN && closeN==n){
        result.push_back(curr);
        return;
       }
       
        if(openN < n){
            curr=curr+'(';
            dfs(n, openN+1, closeN, curr);
            curr.pop_back();
        }

        if(closeN<openN){
            curr=curr+')';
            dfs(n,openN,closeN+1, curr);
            // curr.pop_back();
        }
    }
};
