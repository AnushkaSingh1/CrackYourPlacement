class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
       
        int min_ = INT_MAX;
        int profit = 0;
        
        for(int i=0;i<n;i++){
		// Storing minimum element till current index
            min_ = min(min_, prices[i]);
        // Storing maximum profit till current idx
            profit = max(profit,prices[i]-min_ );
        }
        return profit;
    }
};







class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int buyPrice = prices[0], maxProfit = 0, curProfit = 0;
        
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < buyPrice) buyPrice = prices[i];
            else {
				curProfit = prices[i] - buyPrice;
				maxProfit = max(curProfit, maxProfit);
			}
        }
        return maxProfit;
    }
};
