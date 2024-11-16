class StockSpanner {
public:
stack <pair<int,int>> s;
int ind =-1;

    StockSpanner() {ind=-1;
    while(!s.empty())
    s.pop();
        
    }
    
    int next(int price) {
        ind++;
        while(!s.empty()&&s.top().first<=price)
        s.pop();
        int m=s.empty()?-1:s.top().second;
        int ans=ind-m;
        s.push({price,ind});
        return ans;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */