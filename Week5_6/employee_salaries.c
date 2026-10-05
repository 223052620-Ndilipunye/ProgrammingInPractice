#include <stdio.h>

int main() {
    float salaries[50];
    float total = 0, average, highest, lowest;
    float searchVal;
    int found = 0;

    for (int i = 0; i < 50; i++) {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }

    printf("\n--- All Employee Salaries ---\n");
    for (int i = 0; i < 50; i++) {
        printf("Employee %d: %.2f\n", i + 1, salaries[i]);
        total += salaries[i];
    }

    average = total / 50;
    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 1; i < 50; i++) {
        if (salaries[i] > highest) highest = salaries[i];
        if (salaries[i] < lowest) lowest = salaries[i];
    }

    printf("\nTotal Expenditure: %.2f\n", total);
    printf("Average Salary: %.2f\n", average);
    printf("Highest Salary: %.2f\n", highest);
    printf("Lowest Salary: %.2f\n", lowest);

    printf("\nEnter a salary to search for: ");
    scanf("%f", &searchVal);
    for (int i = 0; i < 50; i++) {
        if (salaries[i] == searchVal) {
            printf("Salary found at employee position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) printf("Salary not found.\n");

    return 0;
}