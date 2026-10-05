#include <stdio.h>

int main() {
    float salaries[50];
    float total = 0;
    float average;
    float highest;
    float lowest;
    float searchVal;
    int found = 0;

    // 1 & 2. Capture salaries for 50 employees into an array
    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    // 3. Display all salaries
    printf("\n--- All Employee Salaries ---\n");
    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
    }

    // 4 & 5. Calculate total salary expenditure and average salary
    for (int i = 0; i < 50; i++) {
        total += salaries[i];
    }
    average = total / 50;

    // 6 & 7. Find highest and lowest salary safely using the first element
    highest = salaries[0];
    lowest = salaries[0];
    for (int i = 1; i < 50; i++) {
        if (salaries[i] > highest) {
            highest = salaries[i];
        }
        if (salaries[i] < lowest) {
            lowest = salaries[i];
        }
    }

    printf("\n--- Salary Report ---\n");
    printf("Total Salary Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    // 8. Search for a particular salary using linear search
    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchVal);
    for (int i = 0; i < 50; i++) {
        if (salaries[i] == searchVal) {
            printf("Salary found at employee position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Salary not found in records.\n");
    }

    // 9. Sort salaries from lowest to highest using bubble sort
    for (int i = 0; i < 50 - 1; i++) {
        for (int j = 0; j < 50 - i - 1; j++) {
            if (salaries[j] > salaries[j + 1]) {
                float temp = salaries[j];
                salaries[j] = salaries[j + 1];
                salaries[j + 1] = temp;
            }
        }
    }

    // 10. Display the sorted salaries
    printf("\n--- Sorted Salaries (Lowest to Highest) ---\n");
    for (int i = 0; i < 50; i++) {
        printf("%.2f\n", salaries[i]);
    }

    return 0;
}