#include <stdio.h>

int main()
{
    char  name1[50];
    char  name2[50];
    float budget = 0;
    float price1 = 0;
    float price2 = 0;
    int   registered1 = 0;
    int   registered2 = 0;
    int   documents1 = 0;
    int   documents2 = 0;
    int   qualified1 = 0;
    int   qualified2 = 0;
    int   preferred = 0;   /* 0 = none, 1 = supplier 1, 2 = supplier 2 */

    printf("TENDER EVALUATION\n");
    printf("-----------------\n");

    printf("Enter available budget: ");
    scanf("%f", &budget);

    printf("\nSUPPLIER 1\n");
    printf("Enter supplier name: ");
    scanf("%49s", name1);
    printf("Enter tender price: ");
    scanf("%f", &price1);
    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered1);
    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documents1);

    printf("\nSUPPLIER 2\n");
    printf("Enter supplier name: ");
    scanf("%49s", name2);
    printf("Enter tender price: ");
    scanf("%f", &price2);
    printf("Is supplier registered? (1=Yes, 0=No): ");
    scanf("%d", &registered2);
    printf("Are all documents complete? (1=Yes, 0=No): ");
    scanf("%d", &documents2);

    /* A supplier qualifies if registered, documents complete and price within budget */
    if (registered1 == 1 && documents1 == 1 && price1 <= budget)
    {
        qualified1 = 1;
    }

    if (registered2 == 1 && documents2 == 1 && price2 <= budget)
    {
        qualified2 = 1;
    }

    /* The preferred supplier is the qualified supplier with the lowest price */
    if (qualified1 == 1 && qualified2 == 1)
    {
        if (price1 <= price2)
        {
            preferred = 1;
        }
        else
        {
            preferred = 2;
        }
    }
    else if (qualified1 == 1)
    {
        preferred = 1;
    }
    else if (qualified2 == 1)
    {
        preferred = 2;
    }

    printf("\nTENDER RESULTS\n");
    printf("--------------\n");
    printf("Budget: %.2f\n", budget);

    printf("\nSupplier: %s\n", name1);
    printf("Price   : %.2f\n", price1);
    if (qualified1 == 0)
    {
        printf("Status  : Disqualified\n");
    }
    else if (preferred == 1)
    {
        printf("Status  : Preferred Supplier\n");
    }
    else
    {
        printf("Status  : Qualified\n");
    }

    printf("\nSupplier: %s\n", name2);
    printf("Price   : %.2f\n", price2);
    if (qualified2 == 0)
    {
        printf("Status  : Disqualified\n");
    }
    else if (preferred == 2)
    {
        printf("Status  : Preferred Supplier\n");
    }
    else
    {
        printf("Status  : Qualified\n");
    }

    if (preferred == 0)
    {
        printf("\nNo supplier qualified.\n");
    }

    return 0;
}