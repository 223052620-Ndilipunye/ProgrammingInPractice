#include <stdio.h>

int main() {
    char studentName[50];
    float test1, test2, assignment, total;

    printf("Enter student name: ");
    scanf("%49s", studentName);

    printf("Enter Test 1 mark: ");
    scanf("%f", &test1);

    printf("Enter Test 2 mark: ");
    scanf("%f", &test2);

    printf("Enter Assignment mark: ");
    scanf("%f", &assignment);

    total = test1 + test2 + assignment;

    printf("\nStudent Name: %s\n", studentName);
    printf("Total Mark: %.2f\n", total);
    printf("Result: ");

    if (total >= 75 && total <= 100) {
        printf("Distinction\n");
    } else if (total >= 60 && total < 75) {
        printf("Credit\n");
    } else if (total >= 50 && total < 60) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }

    return 0;
}