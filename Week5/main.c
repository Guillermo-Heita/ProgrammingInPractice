#include <stdio.h>

int main()
{
    float salary  = 0;
    float total   = 0;
    float highest = 0;
    float lowest  = 0;
    float average = 0;

    printf("MUNICIPAL EMPLOYEE SALARY ANALYSIS\n");
    printf("----------------------------------\n");

    for (int i = 1; i <= 50; i++)
    {
        printf("Enter salary for employee %d: ", i);
        scanf("%f", &salary);

        total = total + salary;

        /* the first salary starts both the highest and the lowest */
        if (i == 1)
        {
            highest = salary;
            lowest = salary;
        }

        if (salary > highest)
        {
            highest = salary;
        }

        if (salary < lowest)
        {
            lowest = salary;
        }
    }

    average = total / 50;

    printf("\n--- Salary Report ---\n");
    printf("Total salary  : %.2f\n", total);
    printf("Average salary: %.2f\n", average);
    printf("Highest salary: %.2f\n", highest);
    printf("Lowest salary : %.2f\n", lowest);

    return 0;
}