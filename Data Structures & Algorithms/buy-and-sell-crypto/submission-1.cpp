class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int left=0,right=0;
        int temp_profit, per_profit=0;

        while(right<=prices.size()-1)
        {
            temp_profit=prices[right]-prices[left];
            if ( temp_profit> per_profit) per_profit=temp_profit;


            if (prices[left]==prices[right]){
                right ++;
            }
            else if(prices[right]<prices[left])
            {
                left++;
            }
            else{
                right++;
            }

        }
        return per_profit;
        
    }
};
