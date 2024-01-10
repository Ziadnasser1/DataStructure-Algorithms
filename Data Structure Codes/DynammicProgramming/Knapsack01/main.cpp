#include <iostream>
#include <vector>
using namespace std;

int knapSack01(vector<int>& weights, vector<int>& profits,int capacity) {
    int n = weights.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity + 1, 0));

    for(int i=1; i<=n; i++){
        for(int w = 0;w<=capacity; w++){
            if(weights[i-1] <= w){
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weights[i-1]] + profits[i-1]) ;
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    for(int i =0; i<=n; i++){
        for(int j =0; j<=capacity; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][capacity];
}

int main() {
    int w = 8;
    vector<int> weights = {3,4,5,6};
    vector<int> profits = {2,3,4,1};

    int mx = knapSack01(weights, profits, w);

    cout << "maximum profit: " << mx << endl;


}
