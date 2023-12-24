
// Author : Pooja Vishwakarma
// Date : 24/12/2023
// Problem : Buy Maximum Stocks if i stocks can be bought on i-th day
// Difficulty : Medium
// Problem Link : https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1



class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        vector<pair<int, int>> stocks; // Store price and day as pairs
        for (int i = 0; i < n; ++i) {
            stocks.push_back(make_pair(price[i], i + 1)); // Store price and day
        }
        
        sort(stocks.begin(), stocks.end()); // Sort by price
        
        int stocksBought = 0;
        for (int i = 0; i < n; ++i) {
            int pricePerStock = stocks[i].first;
            int availableStocks = stocks[i].second;

            int canBuy = min(availableStocks, k / pricePerStock);
            stocksBought += canBuy;
            k -= canBuy * pricePerStock;
        }
        
        return stocksBought;
    }
};
