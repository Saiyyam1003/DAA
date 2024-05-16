#include<stdio.h>

typedef struct {
    int value, weight;
    double ratio;
} Item;

void sort(Item arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].ratio < arr[j].ratio) {
                Item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, n);
    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
            printf("Added full item %d: value = %d, weight = %d\n", i+1, arr[i].value, arr[i].weight);
        } else {
            int remain = W - curWeight;
            finalvalue += arr[i].value * ((double) remain / arr[i].weight);
            printf("Added %d/%d of item %d: value = %d, weight = %d\n", remain, arr[i].weight, i+1, arr[i].value, arr[i].weight);
            break;
        }
    }

    return finalvalue;
}

int main() {
    int n, W;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i+1);
        scanf("%d%d", &arr[i].value, &arr[i].weight);
        arr[i].ratio = (double)arr[i].value / arr[i].weight;
    }
    printf("Enter maximum capacity of knapsack: ");
    scanf("%d", &W);
    printf("Maximum value we can obtain = %.2f", fractionalKnapsack(W, arr, n));
    return 0;
}