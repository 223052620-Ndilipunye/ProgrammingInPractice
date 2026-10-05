#include <stdio.h>
#include "utilities.h"

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

void displayMenu(void) {
    printf("\n====================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("====================================\n");
    printf("1. Add Employee\n");
    printf("2. Display Employees\n");
    printf("3. Calculate Budget\n");
    printf("4. Calculate VAT\n");
    printf("5. Save Records to File\n");
    printf("6. Load Records from File\n");
    printf("7. Generate Report\n");
    printf("8. Exit\n");
    printf("Enter choice: ");
}