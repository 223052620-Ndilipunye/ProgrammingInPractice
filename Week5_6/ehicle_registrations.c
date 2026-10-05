#include <stdio.h>
#include <string.h>

int main() {
    char registrations[20][20];
    char searchReg[20];
    int found = 0;

    for (int i = 0; i < 20; i++) {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }

    printf("\n--- All Vehicle Registrations ---\n");
    for (int i = 0; i < 20; i++) {
        printf("%d: %s\n", i + 1, registrations[i]);
    }

    printf("\nEnter registration number to search for: ");
    scanf("%19s", searchReg);

    for (int i = 0; i < 20; i++) {
        if (strcmp(registrations[i], searchReg) == 0) {
            printf("Registration found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Registration number not found.\n");
    }

    return 0;
}