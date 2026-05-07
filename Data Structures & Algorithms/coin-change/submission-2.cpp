class Solution {
public:
int res= INT_MAX;  
unordered_map<int,int> memo;
    int coinChange(vector<int>& coins, int amount)
    {
       int res= dfs(amount, coins);
       if(res==INT_MAX){return -1;}
       else{
        return res;
       }

    }
    int dfs(int amount, vector<int> coins)
    {
        if( amount<0){return INT_MAX;}
        if (amount ==0){return 0;}
        if(memo.count(amount)){return memo[amount];}
        int res=INT_MAX;
        for(int coin: coins)
        {
           int result= dfs(amount-coin,coins);  

           if(result!=INT_MAX){

           res=min(result+1,res);   
           }

        }
        memo[amount]=res;
        return res;

    }
};
