#include <vector>
#include <iostream>

int maxProfit(std::vector<int>& prices)
{
    int n = prices.size();
    if (n <= 1)
    {
        return 0;
    }

    std::vector<int> forwardProfit(n, 0);
    std::vector<int> backwardProfit(n, 0);

    int minPrice = prices[0];
    for (int i = 1; i < n; i++)
    {
        minPrice = std::min(minPrice, prices[i]);
        forwardProfit[i] = std::max(forwardProfit[i - 1], prices[i] - minPrice);
    }

    int maxPrice = prices[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxPrice = std::max(maxPrice, prices[i]);
        backwardProfit[i] = std::max(backwardProfit[i + 1], maxPrice - prices[i]);
    }

    int maxProfit = 0;
    for (int i = 0; i < n; i++)
    {
        maxProfit = std::max(maxProfit, forwardProfit[i] + backwardProfit[i]);
    }

    return maxProfit;
}

int main()
{
    std::vector<int> prices = { 3, 3, 5, 0, 0, 3, 1, 4 };
    std::cout << maxProfit(prices);
    return 0;
}