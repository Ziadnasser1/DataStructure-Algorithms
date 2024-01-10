#include <iostream>
#include <vector>
using namespace std;

int subSetSum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target +1, false));

    for(int i =0; i<=n; i++){
        dp[i][0] = true;
    }

    for(int i=1;i<=n;i++){
        for(int j=1; j<=target; j++){
            if(nums[i-1] > j){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i - 1]];
            }
        }
    }
    for(int i =0; i<=n; i++){
        for(int j =0; j<=target; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][target];
}

int main() {
    vector<int> nums = {2,3,5,7,10};
    int target = 14;

    if(subSetSum(nums, target)){
        cout<<"subset exists"<<endl;
    }else{
        cout<<"subset does not exist"<<endl;
    }

}
