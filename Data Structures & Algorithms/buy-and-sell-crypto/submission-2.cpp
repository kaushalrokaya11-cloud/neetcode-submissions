class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit =0;
        int best_day = 0;
        for(int i =0;i<prices.size();i++){
            int temp_profit = prices[i]-prices[best_day];
            if(temp_profit<0){best_day =i;}
            profit= max(profit,temp_profit);
        }
        return profit;
    }
};
