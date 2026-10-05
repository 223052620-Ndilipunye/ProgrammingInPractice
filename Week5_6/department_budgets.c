#include <stdio.h>

int main() {
    float budgets[10];
    float total = 0, average;

    for (int i = 0; i < 10; i++) {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
        total += budgets[i];
    }

    average = total / 10;

    printf("\n--- Department Budgets (Unsorted) ---\n");
    for (int i = 0; i < 10; i++) {
        printf("Department %d: %.2f\n", i + 1, budgets[i]);
    }

    // Bubble sort from lowest to highest
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - i - 1; j++) {
            if (budgets[j] > budgets[j + 1]) {
                float temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\n--- Total & Average ---\n");
    printf("Total Budget: %.2f\n", total);
    printf("Average Budget: %.2f\n", average);

    printf("\n--- Sorted Budgets (Lowest to Highest) ---\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f\n", budgets[i]);
    }

    return 0;
}