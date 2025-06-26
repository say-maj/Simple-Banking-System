#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Account {
    int accNo;
    char name[50];
    float balance;
};

void createAccount() {
    struct Account a;
    FILE *f = fopen("bank.txt", "a");

    printf("Enter Account Number: ");
    scanf("%d", &a.accNo);
    printf("Enter Name: ");
    scanf(" %[^\n]", a.name);
    printf("Enter Initial Deposit: ");
    scanf("%f", &a.balance);

    fprintf(f, "%d,%s,%.2f\n", a.accNo, a.name, a.balance);
    fclose(f);
    printf("✅ Account Created Successfully!\n");
}

void checkBalance() {
    int acc;
    struct Account a;
    int found = 0;

    printf("Enter Account Number: ");
    scanf("%d", &acc);

    FILE *f = fopen("bank.txt", "r");
    while (fscanf(f, "%d,%[^,],%f\n", &a.accNo, a.name, &a.balance) != EOF) {
        if (a.accNo == acc) {
            printf("Account Holder: %s\nBalance: ₹%.2f\n", a.name, a.balance);
            found = 1;
            break;
        }
    }

    if (!found) printf("❌ Account not found.\n");

    fclose(f);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== Simple Banking System =====\n");
        printf("1. Create Account\n");
        printf("2. Check Balance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: checkBalance(); break;
            case 3: exit(0);
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

