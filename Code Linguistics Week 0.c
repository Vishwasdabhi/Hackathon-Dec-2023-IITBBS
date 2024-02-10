#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int receipt_gen()
{
    char name[50];
    char item[50];
    char outlet[50];
    FILE *ptr = NULL;
    ptr = fopen("generated_reciept.txt", "a");

    printf("Name\n");
    gets(name);
    printf("Item purchased:\n");
    gets(item);
    printf("outlet:\n");
    gets(outlet);
    fprintf(ptr, "Thanks %s for purchasing %s from our %s outlet.\nPlease visit our %s outlet for any kind of problems.We plan to serve you again soon.\n", name, item, outlet, outlet);
    printf("Your reciept has successfully generater in a text file.\n");
    fclose(ptr);
    return 0;
}
#define MAX_EXPENSES 100
#define FILENAME "expenses.txt"

struct Expense
{
    char category[50];
    float amount;
};

struct Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void saveExpenseToFile(struct Expense *expense)
{
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%s %.2f\n", expense->category, expense->amount);

    fclose(file);
}

void loadExpensesFromFile()
{
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%s %f", expenses[numExpenses].category, &expenses[numExpenses].amount) == 2)
    {
        numExpenses++;
        if (numExpenses >= MAX_EXPENSES)
        {
            break;
        }
    }

    fclose(file);
}

void addExpense()
{
    if (numExpenses < MAX_EXPENSES)
    {
        printf("Enter expense category: ");
        scanf("%s", expenses[numExpenses].category);

        printf("Enter expense amount: ");
        scanf("%f", &expenses[numExpenses].amount);

        printf("Expense added successfully!\n");
        numExpenses++;

        // Save the new expense to the file
        saveExpenseToFile(&expenses[numExpenses - 1]);
    }
    else
    {
        printf("Expense tracker is full. Cannot add more expenses.\n");
    }
}

void viewExpenses()
{
    if (numExpenses > 0)
    {
        printf("\nExpense Tracker\n");
        printf("----------------\n");
        printf("%-20s%-10s\n", "Category", "Amount");
        printf("----------------\n");

        for (int i = 0; i < numExpenses; i++)
        {
            printf("%-20sRs%-10.2f\n", expenses[i].category, expenses[i].amount);
        }

        printf("----------------\n");
        float total = 0;
        for (int i = 0; i < numExpenses; i++)
        {
            total += expenses[i].amount;
        }
        printf("Total: Rs%.2f\n", total);
    }
    else
    {
        printf("No expenses to display.\n");
    }
}
int expense_tracker()
{
    // Load expenses from file at the beginning
    loadExpensesFromFile();

    int choice;

    do
    {
        printf("\nExpense Tracker Menu\n");
        printf("0. Exit\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("Enter your choice(pls enter the number): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting Expense Tracker. Goodbye!\n");
            break;
        case 1:
            addExpense();
            break;
        case 2:
            viewExpenses();
            break;
        default:
            printf("Invalid choice. Exiting application.\n");
            return 1;
        }
    } while (choice != 0);

    return 0;
}
int converter()
{
    /*
    1 USD = 83.43 INR
    2.UK pound = 104.69 INR
    3.Russian ruble = 0.91 INR
    4.Australian dollar = 54.92 INR
    5.1 Chinese Yuan = 11.69 INR
    */
    // Giving the list of choices
    int choice;
    float inr, usd, uk_pound, aus_dol, rus_ruble, chi_yuan;
    printf("menu\n0.Exit\n1.INR to USD\n2.USD to INR\n3.INR to UK pound\n4.UK pound to INR\n5.INR to Russian ruble\n6.Russian ruble to INR\n7.INR to Australian dollar\n8.Australian dollar to INR\n9.INR to chinese yuan\n10.Chinese yuan to INR\nEnter your choice(please enter the number)\n");
    // Defining the choices
    while (1)
    {

        scanf("%d", &choice);
        switch (choice)
        {
            // Exit
        case 0:
            printf("Thank you for using our application.\n");
            goto end;
            // INR to USD
        case 1:
            printf("INR :\n");
            scanf("%f", &inr);
            printf("%.2f INR = %.2f USD \n\n\n\n", inr, inr / (float)83.43);
            break;
            // USD to INR
        case 2:
            printf("USD :\n");
            scanf("%f", &usd);
            printf("%.2f USD = %.2f INR \n\n\n\n", usd, usd * (float)83.43);
            break;
        // INR to UK pound
        case 3:
            printf("INR :\n");
            scanf("%f", &inr);
            printf("%.2f INR = %.2f UK pound \n\n\n\n", inr, inr / (float)104.69);
            break;
        // UK pound to INR
        case 4:
            printf("UK pound :\n");
            scanf("%f", &uk_pound);
            printf("%.2f UK pound = %.2f INR \n\n\n\n", uk_pound, uk_pound * (float)104.69);
            break;
        // INR to Russian ruble
        case 5:
            printf("INR :\n");
            scanf("%f", &inr);
            printf("%.2f INR = %.2f Russian ruble \n\n\n\n", inr, inr / (float)0.91);
            break;
        // Russian ruble to INR
        case 6:
            printf("Russian Ruble :\n");
            scanf("%f", &rus_ruble);
            printf("%.2f Russian Ruble = %.2f INR \n\n\n\n", rus_ruble, rus_ruble * (float)0.91);
            break;
        // INR to Australian dollar
        case 7:
            printf("INR :\n");
            scanf("%f", &inr);
            printf("%.2f INR = %.2f Australian Dollar \n\n\n\n", inr, inr / (float)54.92);
            break;
        // Australian dollar to INR
        case 8:
            printf("Australian Dollar :\n");
            scanf("%f", &aus_dol);
            printf("%.2f Australian Dollar = %.2f INR \n\n\n\n", aus_dol, aus_dol * (float)54.92);
            break;
        // INR to chinese yuan
        case 9:
            printf("INR :\n");
            scanf("%f", &inr);
            printf("%.2f INR = %.2f chinese yuan \n\n\n\n", inr, inr / (float)11.69);
            break;
        // Chinese yuan to INR
        case 10:
            printf("Chinese yuan :\n");
            scanf("%f", &chi_yuan);
            printf("%.2f Chinese yuan = %.2f INR \n\n\n\n", chi_yuan, chi_yuan * (float)11.69);
            break;
        // For wrong entry(Ex. Negative integer)
        default:
        {
            printf("The number you've entered is wrong");
        }
        break;
        }
    }
end:
    return 0;
}
int interest_calc()
{
    int select;
    printf("Enter 0 for simple interest and 1 for compound interest\n");
    scanf("%d", &select);
    float princ_amount, time_per, final_amount, int_rate;

    if (select == 0)
    {
        printf("Principal amount :");
        scanf("%f", &princ_amount);
        printf("Rate of interest :");
        scanf("%f", &int_rate);
        printf("Time period:");
        scanf("%f", &time_per);
        final_amount = ((princ_amount * int_rate * time_per / 100) + princ_amount);
        printf("The simple interest is: %.2f\n", final_amount - princ_amount);
        printf("The final amount is: %.2f\n", final_amount);
    }
    else if (select == 1)
    {
        // Get the principal amount, rate of interest, and time period from the user.
        printf("Enter the principal amount: \n");
        scanf("%f", &princ_amount);
        printf("Enter the rate of interest: \n");
        scanf("%f", &int_rate);
        printf("Enter the time period in years: \n");
        scanf("%f", &time_per);

        // Calculate the compound interest using the formula:
        // A = P(1 + r/n)^nt - P
        float ci = princ_amount * pow((1 + int_rate / 100), time_per) - princ_amount;

        // Calculate the compound amount
        float cp = princ_amount * pow((1 + int_rate / 100), time_per);

        // Display the results
        printf("The compound interest is: %.2f\n", ci);
        printf("The final amount is: %.2f\n", cp);
    }

    return 0;
}
int main()
{
    int number;
    printf("Code menu\n0.Exit\n1.Recipt Generator\n2.Expenses Tracker\n3.Currency converter\n4.Interest Calculator\nEnter your choice(please enter the number):");
    scanf("%d", &number);
    switch (number)
    {
    case 0:
        break;
    case 1:
        receipt_gen();
        break;
    case 2:
        expense_tracker();
        break;
    case 3:
        converter();
        break;
    case 4:
        interest_calc();
        break;

    default:
        break;
    }
    return 0;
}
