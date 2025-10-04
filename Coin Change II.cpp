class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount + 1,0);
        prev[0] = 1;
        for (int j = 1; j <= n; j++) {
        vector<unsigned long long> curr(amount + 1,0);
        curr[0] = 1;

        for (int i = 1; i <= amount; i++) {
                if (i - coins[j - 1] >= 0) {
                    curr[i] = prev[i] + curr[i - coins[j - 1]];
                } else {
                    curr[i] = prev[i];
                }
            }
            prev = curr;
        }

        return (int)prev[amount];
    }
};
