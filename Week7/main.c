#include <stdio.h>
#include <string.h>

#define MAX_SUPPLIERS 5

char supplierName[MAX_SUPPLIERS][100];
char supplierEmail[MAX_SUPPLIERS][100];
char supplierPhone[MAX_SUPPLIERS][30];
char supplierTown[MAX_SUPPLIERS][50];
int  supplierCount = 0;

/* Shows a prompt, reads a whole line (spaces allowed) and removes the newline */
void readLine(const char prompt[], char buffer[], int size)
{
    printf("%s", prompt);

    if (fgets(buffer, size, stdin) == NULL)
    {
        buffer[0] = '\0';
        return;
    }

    buffer[strcspn(buffer, "\n")] = '\0';
}

void displayMenu(void)
{
    printf("\n================================\n");
    printf("MUNICIPAL FINANCIAL MANAGEMENT\n");
    printf("================================\n");
    printf("1. Add Supplier\n");
    printf("2. Display Suppliers\n");
    printf("3. Search Supplier\n");
    printf("4. Show Name Length\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
}

/* Returns the position of the supplier, or -1 if not found */
int findSupplier(char name[])
{
    for (int i = 0; i < supplierCount; i++)
    {
        if (strcmp(supplierName[i], name) == 0)
        {
            return i;
        }
    }

    return -1;
}

void addSupplier(void)
{
    char name[100];
    char email[100];
    char phone[30];
    char town[50];

    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("Supplier list is full.\n");
        return;
    }

    readLine("Enter supplier name: ", name, sizeof(name));

    if (strlen(name) == 0)
    {
        printf("Supplier name cannot be empty.\n");
        return;
    }

    if (findSupplier(name) != -1)
    {
        printf("That supplier already exists.\n");
        return;
    }

    readLine("Enter email: ", email, sizeof(email));
    readLine("Enter phone: ", phone, sizeof(phone));
    readLine("Enter town: ", town, sizeof(town));

    strcpy(supplierName[supplierCount], name);
    strcpy(supplierEmail[supplierCount], email);
    strcpy(supplierPhone[supplierCount], phone);
    strcpy(supplierTown[supplierCount], town);
    supplierCount++;

    printf("Supplier added.\n");
}

void displaySuppliers(void)
{
    char description[200];

    if (supplierCount == 0)
    {
        printf("No suppliers yet.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\n--- SUPPLIER DETAILS (%d) ---\n", i + 1);
        printf("Name : %s\n", supplierName[i]);
        printf("Email: %s\n", supplierEmail[i]);
        printf("Phone: %s\n", supplierPhone[i]);
        printf("Town : %s\n", supplierTown[i]);

        /* build a sentence from the stored strings */
        strcpy(description, supplierName[i]);
        strcat(description, " operates in ");
        strcat(description, supplierTown[i]);
        strcat(description, ".");
        printf("%s\n", description);
    }
}

void searchSupplier(void)
{
    char searchName[100];
    int index;

    if (supplierCount == 0)
    {
        printf("No suppliers yet.\n");
        return;
    }

    readLine("Enter supplier name to search: ", searchName, sizeof(searchName));

    index = findSupplier(searchName);

    if (index == -1)
    {
        printf("Supplier not found.\n");
    }
    else
    {
        printf("\nSupplier found.\n");
        printf("Name : %s\n", supplierName[index]);
        printf("Email: %s\n", supplierEmail[index]);
        printf("Phone: %s\n", supplierPhone[index]);
        printf("Town : %s\n", supplierTown[index]);
    }
}

void showNameLengths(void)
{
    if (supplierCount == 0)
    {
        printf("No suppliers yet.\n");
        return;
    }

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("Supplier name length: %d\n", (int)strlen(supplierName[i]));
        printf("Email length: %d\n", (int)strlen(supplierEmail[i]));
        printf("Town length: %d\n", (int)strlen(supplierTown[i]));
    }
}

int main(void)
{
    char line[20];
    int  choice = 0;

    do
    {
        displayMenu();

        if (fgets(line, sizeof(line), stdin) == NULL)
        {
            choice = 5;
        }
        else if (sscanf(line, "%d", &choice) != 1)
        {
            choice = -1;
        }

        switch (choice)
        {
            case 1: addSupplier();      break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier();   break;
            case 4: showNameLengths();  break;
            case 5: printf("Goodbye.\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}