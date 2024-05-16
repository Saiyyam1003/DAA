#include <stdio.h>

void findMin(int cost, int coins[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        while (cost >= coins[i]) {
            cost -= coins[i];
            printf("%d ", coins[i]);  // print the coin used
            count++;
        }
        if (cost == 0) break;
    }
    printf("\nTotal coins needed: %d\n", count);
}

int main() {
    int coins[] = {25, 10, 5, 1};  // denominations
    int n = sizeof(coins)/sizeof(coins[0]);
    int cost;
    printf("Enter the total cost: ");
    scanf("%d", &cost);
    printf("Coins used are: ");
    findMin(cost, coins, n);
    return 0;
}