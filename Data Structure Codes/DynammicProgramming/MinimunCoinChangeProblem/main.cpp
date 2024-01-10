#include <iostream>
#include <vector>
using namespace std;

int MinCoinChangeWays(vector<int>& coins, int w) {
    int coinsLength = coins.size();
    vector<vector<int>> dp(coinsLength, vector<int>(w+ 1, INT_MAX));

    for (int i = 0; i < coinsLength; i++) {
        dp[i][0] = 0;
    }

    for (int i = 0; i < coinsLength; i++) {
        for (int j = 1; j <= w; j++) {
            if (coins[i] > j) {
                dp[i][j] = (i > 0) ? dp[i - 1][j] : INT_MAX;
            } else {
                dp[i][j] = min((i > 0) ? dp[i - 1][j] : INT_MAX, 1 + dp[i][j - coins[i]]);
            }
        }
    }
    for(int i =0; i<coinsLength; i++){
        for(int j =0; j<=w; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return (dp[coinsLength - 1][w] == INT_MAX) ? -1 : dp[coinsLength - 1][w];
}
int main() {
    vector<int> coins = {1,5,6,9};
    int total = 10;

    int ways = MinCoinChangeWays(coins, total);

    cout << "Number of ways to get the total: " << ways << endl;


}
