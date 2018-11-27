class Solution {
public:
   
    int maxProfit(vector<int>& prices) {

        int days=prices.size();
        if (days==0)
            return 0;
        if (days==1)
            return 0;
        
         vector<int> buy(days,0);
         vector<int> sell(days,0);
        
        buy[0]=-prices[0];
        buy[1]=max(-prices[0],-prices[1]);
 
        sell[0]=0;
        sell[1]=max(sell[0],buy[0]+prices[1]);
        
        for (int i=2; i<days; i++)
        {
            buy[i]=max(buy[i-1],sell[i-2]-prices[i]);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
        }
        
        return sell[days-1];
    }
};
