#include <bits/stdc++.h>
using namespace std;

int solve(int i, int prev, vector<int> &nums, vector<vector<int>> &dp) {
    if (i == nums.size()) return 0;
    if (dp[i][prev + 1] != -1) return dp[i][prev + 1];
    int notTake = solve(i + 1, prev, nums, dp);
    int take = 0;
    if (prev == -1 || nums[i] > nums[prev]) {
        take = 1 + solve(i + 1, i, nums, dp);
    }
    return dp[i][prev + 1] = max(take, notTake);
}

int main() {

}