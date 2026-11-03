#include <stdio.h>
#include <string.h>

#define NUM_SALARIES 50
#define NUM_BUDGETS  10
#define NUM_REGS     20

float salaries[NUM_SALARIES];
float budgets[NUM_BUDGETS];
char  registrations[NUM_REGS][20];

int salariesCaptured = 0;
int budgetsCaptured  = 0;
int regsCaptured     = 0;

/* ---------- A. Employee salaries ---------- */

void captureSalaries(void)
{
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        printf("Enter salary for employee %d: ", i + 1);
        scanf("%f", &salaries[i]);
    }
    salariesCaptured = 1;
}

void displaySalaries(void)
{
    if (salariesCaptured == 0)
    {
        printf("No salaries captured yet.\n");
        return;
    }

    printf("\nEmployee Salaries\n");
    for (int i = 0; i < NUM_SALARIES; i++)
    {
        printf("%d. %.2f\n", i + 1, salaries[i]);
    }
}

void salaryStatistics(void)
{
    float total = 0;
    float highest;
    float lowest;

    if (salariesCaptured == 0)
    {
        printf("No salaries captured yet.\n");
        return;
    }

    highest = salaries[0];
    lowest = salaries[0];

    for (int i = 0; i < NUM_SALARIES; i++)
    {
        total = total + salaries[i];

        if (salaries[i] > highest)
        {
            highest = salaries[i];
        }
        if (salaries[i] < lowest)
        {
            lowest = salaries[i];
        }
    }

    printf("\n--- Salary Statistics ---\n");
    printf("Total salary  : %.2f\n", total);
    printf("Average salary: %.2f\n", total / NUM_SALARIES);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary : %.2f\n", lowest);
}

void searchSalary(void)
{
    float target;
    int found = 0;

    if (salariesCaptured == 0)
    {
        printf("No salaries captured yet.\n");
        return;
    }

    printf("Enter salary to search for: ");
    scanf("%f", &target);

    for (int i = 0; i < NUM_SALARIES; i++)
    {
        if (salaries[i] == target)
        {
            printf("Salary %.2f found for employee %d.\n", target, i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Salary not found.\n");
    }
}

/* ---------- B. Department budgets ---------- */

void captureBudgets(void)
{
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("Enter budget for department %d: ", i + 1);
        scanf("%f", &budgets[i]);
    }
    budgetsCaptured = 1;
}

void displayBudgets(void)
{
    if (budgetsCaptured == 0)
    {
        printf("No budgets captured yet.\n");
        return;
    }

    printf("\nDepartment Budgets\n");
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("%d. %.2f\n", i + 1, budgets[i]);
    }
}

void budgetStatistics(void)
{
    float total = 0;

    if (budgetsCaptured == 0)
    {
        printf("No budgets captured yet.\n");
        return;
    }

    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        total = total + budgets[i];
    }

    printf("\n--- Budget Statistics ---\n");
    printf("Total budget  : %.2f\n", total);
    printf("Average budget: %.2f\n", total / NUM_BUDGETS);
}

void sortBudgets(void)
{
    float temp;

    if (budgetsCaptured == 0)
    {
        printf("No budgets captured yet.\n");
        return;
    }

    /* bubble sort: lowest to highest */
    for (int i = 0; i < NUM_BUDGETS - 1; i++)
    {
        for (int j = 0; j < NUM_BUDGETS - i - 1; j++)
        {
            if (budgets[j] > budgets[j + 1])
            {
                temp = budgets[j];
                budgets[j] = budgets[j + 1];
                budgets[j + 1] = temp;
            }
        }
    }

    printf("\nBudgets sorted from lowest to highest:\n");
    for (int i = 0; i < NUM_BUDGETS; i++)
    {
        printf("%d. %.2f\n", i + 1, budgets[i]);
    }
}

/* ---------- C. Vehicle registrations ---------- */

void captureRegistrations(void)
{
    for (int i = 0; i < NUM_REGS; i++)
    {
        printf("Enter vehicle registration %d: ", i + 1);
        scanf("%19s", registrations[i]);
    }
    regsCaptured = 1;
}

void displayRegistrations(void)
{
    if (regsCaptured == 0)
    {
        printf("No registrations captured yet.\n");
        return;
    }

    printf("\nVehicle Registrations\n");
    for (int i = 0; i < NUM_REGS; i++)
    {
        printf("%d. %s\n", i + 1, registrations[i]);
    }
}

void searchRegistration(void)
{
    char target[20];
    int found = 0;

    if (regsCaptured == 0)
    {
        printf("No registrations captured yet.\n");
        return;
    }

    printf("Enter registration to search for: ");
    scanf("%19s", target);

    for (int i = 0; i < NUM_REGS; i++)
    {
        if (strcmp(registrations[i], target) == 0)
        {
            printf("Registration %s found at position %d.\n", target, i + 1);
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("Registration not found.\n");
    }
}

/* ---------- Menu ---------- */

int main()
{
    int choice = -1;
    int result;
    int c;

    do
    {
        printf("\nMUNICIPAL INFORMATION MANAGEMENT SYSTEM\n");
        printf("---------------------------------------\n");
        printf(" 1. Capture 50 salaries\n");
        printf(" 2. Display salaries\n");
        printf(" 3. Salary statistics\n");
        printf(" 4. Search salary\n");
        printf(" 5. Capture 10 department budgets\n");
        printf(" 6. Display budgets\n");
        printf(" 7. Budget statistics\n");
        printf(" 8. Sort budgets (lowest to highest)\n");
        printf(" 9. Capture 20 vehicle registrations\n");
        printf("10. Display registrations\n");
        printf("11. Search registration\n");
        printf(" 0. Exit\n");
        printf("Enter your choice: ");

        result = scanf("%d", &choice);

        if (result == EOF)
        {
            choice = 0;
        }
        else if (result != 1)
        {
            /* the user typed something that is not a number */
            while ((c = getchar()) != '\n' && c != EOF)
            {
            }
            choice = -1;
        }

        switch (choice)
        {
            case 1:  captureSalaries();       break;
            case 2:  displaySalaries();       break;
            case 3:  salaryStatistics();      break;
            case 4:  searchSalary();          break;
            case 5:  captureBudgets();        break;
            case 6:  displayBudgets();        break;
            case 7:  budgetStatistics();      break;
            case 8:  sortBudgets();           break;
            case 9:  captureRegistrations();  break;
            case 10: displayRegistrations();  break;
            case 11: searchRegistration();    break;
            case 0:  printf("Goodbye.\n");    break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 0);

    return 0;
}