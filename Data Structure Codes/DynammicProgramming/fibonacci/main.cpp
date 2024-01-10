#include <iostream>
#include <vector>
using namespace std;

static int count = 0;

//normal approach
//int fib1(int n){
//    count++;
//    if(n<0)
//        return -1;
//    if(n==0)
//        return 0;
//    if(n==1)
//        return 1;
//    int sum = fib1(n-1)+fib1(n-2);
//    return sum;
//}

//dp approach bottom up
//int fib2(int n){
//    count++;
//    vector<int> dp(n + 1, -1);
//    dp[0] = 0;
//    dp[1] = 1;
//    for(int i=2;i<=n;i++){
//        dp[i] = dp[i-1]+dp[i-2];
//    }
//    return dp[n];
//}

//dp approach top down
int fib3(int n, vector<int> &dp){

    if(dp[n]!=-1)
        return dp[n];
    count++;
    if(n<0)
        return -1;
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    dp[n] = fib3(n-1, dp)+fib3(n-2, dp);
    return dp[n];

}
int main() {
    int n;
    cin>>n;

    //  normal approach
    //  cout<<fib1(n)<<endl;

    //  dp approach bottom up
    //  cout<<fib2(n)<<endl;

    //  dp approach top down
    vector<int> dp(n + 1, -1);
    cout<<fib3(n, dp)<<endl;

    cout<<count<<endl;
}