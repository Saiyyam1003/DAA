#include <stdio.h>
#include <limits.h>

void coinChange(int coins[], int numCoins, int amount) {
    int dp[amount + 1];
    int usedCoins[amount + 1];

    dp[0] = 0;
    usedCoins[0] = 0;

    for (int i = 1; i <= amount; i++) {
        dp[i] = INT_MAX;
        usedCoins[i] = -1;
    }

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i && dp[i - coins[j]] + 1 < dp[i]) {
                dp[i] = dp[i - coins[j]] + 1;
                usedCoins[i] = coins[j];
            }
        }
    }

    if (dp[amount] == INT_MAX) {
        printf("No solution found.");
        return;
    }

    printf("Denominations used: ");
    while (amount > 0) {
        printf("%d ", usedCoins[amount]);
        amount -= usedCoins[amount];
    }
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int amount;
    printf("Enter the amount: ");
    scanf("%d",&amount);

    coinChange(coins, numCoins, amount);

    return 0;
}