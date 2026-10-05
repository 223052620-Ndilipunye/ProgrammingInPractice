#include <stdio.h>
#include <string.h>
#include "employees.h"

#define MAX_EMP 100

typedef struct {
    int id;
    char name[50];
    double salary;
} Employee;

static Employee employees[MAX_EMP];
static int empCount = 0;

void addEmployee(void) {
    if (empCount >= MAX_EMP) {
        printf("Employee database is full.\n");
        return;
    }
    printf("Enter Employee ID: ");
    scanf("%d", &employees[empCount].id);
    getchar(); // clear newline
    
    printf("Enter Employee Name: ");
    fgets(employees[empCount].name, sizeof(employees[empCount].name), stdin);
    employees[empCount].name[strcspn(employees[empCount].name, "\n")] = '\0';
    
    printf("Enter Salary: ");
    scanf("%lf", &employees[empCount].salary);
    
    empCount++;
    printf("Employee added successfully.\n");
}

void displayEmployees(void) {
    if (empCount == 0) {
        printf("No employee records in memory.\n");
        return;
    }
    printf("\n--- EMPLOYEE LIST ---\n");
    for (int i = 0; i < empCount; i++) {
        printf("ID: %d | Name: %s | Salary: %.2f\n", 
               employees[i].id, employees[i].name, employees[i].salary);
    }
}

void saveEmployeesToFile(void) {
    FILE *fp = fopen("employees.txt", "w");
    if (fp == NULL) {
        perror("Unable to open employees.txt for writing");
        return;
    }
    for (int i = 0; i < empCount; i++) {
        fprintf(fp, "%d %s %.2f\n", employees[i].id, employees[i].name, employees[i].salary);
    }
    fclose(fp);
    printf("Employees saved to employees.txt successfully.\n");
}

void loadEmployeesFromFile(void) {
    FILE *fp = fopen("employees.txt", "r");
    if (fp == NULL) {
        printf("No saved employee file found yet.\n");
        return;
    }
    empCount = 0;
    while (fscanf(fp, "%d %49s %lf", &employees[empCount].id, employees[empCount].name, &employees[empCount].salary) == 3) {
        empCount++;
        if (empCount >= MAX_EMP) break;
    }
    fclose(fp);
    printf("Loaded %d employee(s) from file.\n", empCount);
}