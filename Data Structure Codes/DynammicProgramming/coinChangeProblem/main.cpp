#include <iostream>
#include <vector>
using namespace std;

int coinChangeWays(vector<int>& coins, int w) {
    int coinsLength = coins.size();
    vector<vector<int>> dp(coinsLength, vector<int>(w+ 1, 0));

    for (int i = 0; i < coinsLength; i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < coinsLength; i++) {
        for (int j = 1; j <= w; j++) {
            if (coins[i] > j) {
                dp[i][j] = (i > 0) ? dp[i - 1][j] : 0;
            } else {
                dp[i][j] = (i > 0 ? dp[i - 1][j] : 0) + dp[i][j - coins[i]];
            }
        }
    }
    for(int i =0; i<coinsLength; i++){
        for(int j =0; j<=w; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[coinsLength - 1][w];
}
int main() {
    vector<int> coins = {2,3,5,10};
    int total = 15;

    int ways = coinChangeWays(coins, total);

    cout << "Number of ways to get the total: " << ways << endl;


}
