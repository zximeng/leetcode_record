class StockPrice {
public:
    unordered_map<int,int> timeToPrice;
    priority_queue<pair<int,int>>maxPrice;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>minPrice;
    // since timestamp start at 1 
    int currentTime = 0;
    int currentPrice = 0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        timeToPrice[timestamp] = price;
        if (timestamp >= currentTime) {
            currentPrice = price;
            currentTime = timestamp;
        }
        maxPrice.push({price, timestamp});
        minPrice.push({price, timestamp}); 
    }
    
    int current() {
        return currentPrice;
    }
    
    int maximum() {
        // check whether the price is still valid
        while(timeToPrice[maxPrice.top().second] != maxPrice.top().first)
        {
            maxPrice.pop();
        }
        return maxPrice.top().first;

    }
    
    int minimum() {
        // check whether the price is still valid
        while(timeToPrice[minPrice.top().second] != minPrice.top().first)
        {
            minPrice.pop();
        }
        return minPrice.top().first;
        
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */