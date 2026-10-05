#include <stdio.h>
#include "employees.h"
#include "budget.h"
#include "utilities.h"
#include "reports.h"

int main(void) {
    int choice;
    
    // Automatically load existing records on startup
    loadEmployeesFromFile();

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }
        getchar(); // clear newline

        switch(choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                handleBudgetModule();
                break;
            case 4: {
                float amount;
                printf("Enter amount for VAT calculation: ");
                scanf("%f", &amount);
                printf("VAT (15%): %.2f\n", calculateVAT(amount));
                break;
            }
            case 5:
                saveEmployeesToFile();
                break;
            case 6:
                loadEmployeesFromFile();
                break;
            case 7:
                generateSystemReport();
                break;
            case 8:
                printf("Saving and exiting MFMS. Goodbye.\n");
                saveEmployeesToFile();
                break;
            default:
                printf("Invalid choice. Please select between 1 and 8.\n");
        }
    } while(choice != 8);

    return 0;
}