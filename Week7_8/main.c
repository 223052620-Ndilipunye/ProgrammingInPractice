#include <stdio.h>
#include <string.h>

// Function Prototypes
void displayMenu();
void addSupplier(char name[], char email[], char phone[], char town[]);
void displaySupplier(char name[], char email[], char phone[], char town[]);
void searchSupplier(char storedName[]);
float calculateVAT(float amount);
float calculateSalary(float basic, float housing, float transport);
float calculateBudget(float revenue, float expenses);

int main() {
    int choice;
    // Single supplier storage for this module demonstration (can be expanded later)
    char supplierName[100] = "";
    char email[100] = "";
    char phone[30] = "";
    char town[50] = "";

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear buffer
            continue;
        }
        getchar(); // Consume trailing newline

        switch(choice) {
            case 1:
                addSupplier(supplierName, email, phone, town);
                break;
            case 2:
                displaySupplier(supplierName, email, phone, town);
                break;
            case 3:
                searchSupplier(supplierName);
                break;
            case 4: {
                float amount;
                printf("Enter amount for VAT calculation: ");
                scanf("%f", &amount);
                printf("VAT (15%): %.2f\n", calculateVAT(amount));
                break;
            }
            case 5: {
                float basic, housing, transport;
                printf("Enter basic salary: ");
                scanf("%f", &basic);
                printf("Enter housing allowance: ");
                scanf("%f", &housing);
                printf("Enter transport allowance: ");
                scanf("%f", &transport);
                printf("Gross Salary: %.2f\n", calculateSalary(basic, housing, transport));
                break;
            }
            case 6: {
                float revenue, expenses, balance;
                printf("Enter total revenue: ");
                scanf("%f", &revenue);
                printf("Enter total expenses: ");
                scanf("%f", &expenses);
                balance = calculateBudget(revenue, expenses);
                printf("Budget Balance: %.2f (", balance);
                if (balance > 0) {
                    printf("SURPLUS)\n");
                } else if (balance < 0) {
                    printf("DEFICIT)\n");
                } else {
                    printf("BALANCED)\n");
                }
                break;
            }
            case 7:
                printf("Exiting MFMS. Goodbye.\n");
                break;
            default:
                printf("Invalid choice. Please select between 1 and 7.\n");
        }
    } while(choice != 7);

    return 0;
}

// Function Definitions

void displayMenu() {
    printf("\n====================================\n");
    printf(" MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("====================================\n");
    printf("1. Add Supplier[cite: 98]\n");
    printf("2. Display Supplier[cite: 98]\n");
    printf("3. Search Supplier[cite: 98]\n");
    printf("4. Calculate VAT[cite: 98]\n");
    printf("5. Calculate Salary[cite: 98]\n");
    printf("6. Calculate Budget[cite: 98]\n");
    printf("7. Exit[cite: 98]\n");
    printf("Enter choice: ");
}

void addSupplier(char name[], char email[], char phone[], char town[]) {
    printf("Enter supplier name: ");
    fgets(name, 100, stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline

    printf("Enter email: ");
    fgets(email, 100, stdin);
    email[strcspn(email, "\n")] = '\0';

    printf("Enter phone number: ");
    fgets(phone, 30, stdin);
    phone[strcspn(phone, "\n")] = '\0';

    printf("Enter town: ");
    fgets(town, 50, stdin);
    town[strcspn(town, "\n")] = '\0';

    printf("Supplier added successfully.\n");
}

void displaySupplier(char name[], char email[], char phone[], char town[]) {
    if (strlen(name) == 0) {
        printf("No supplier record found. Please add a supplier first.\n");
        return;
    }
    printf("\n--- SUPPLIER DETAILS ---\n");
    printf("Name : %s (Length: %zu)\n", name, strlen(name));
    printf("Email: %s (Length: %zu)\n", email, strlen(email));
    printf("Phone: %s\n", phone);
    printf("Town : %s (Length: %zu)\n", town, strlen(town));
}

void searchSupplier(char storedName[]) {
    char searchName[100];
    if (strlen(storedName) == 0) {
        printf("No supplier in the system to search.\n");
        return;
    }
    printf("Enter supplier name to search: ");
    fgets(searchName, 100, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    if (strcmp(storedName, searchName) == 0) {
        printf("Supplier found.\n");
    } else {
        printf("Supplier not found.\n");
    }
}

float calculateVAT(float amount) {
    return amount * 0.15;
}

float calculateSalary(float basic, float housing, float transport) {
    return basic + housing + transport;
}

float calculateBudget(float revenue, float expenses) {
    return revenue - expenses;
}