#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Coupon code generator for special discount
//making code with random characters and numbers
char getRandomChar()
{
    const char charset[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    return charset[rand() % sizeof(charset)];
}
//generating coupon code when function called
void getcouponcode(char *couponcode, int size)
{
    for (int i = 0; i < size; i++)
    {
        couponcode[i] = getRandomChar();
    }
    couponcode[size] = '\0';
}
int couponcodegen()
{
    int size;
    printf("Size of the coupon code:");
    scanf("%d", &size);
    char *couponcode = (char *)malloc((size + 1) * sizeof(char));
    srand((unsigned int)time(NULL));
    getcouponcode(couponcode, size);
    printf("The coupon code is %s\n", couponcode);
    free(couponcode);
    return 0;
}
//GST calculator for different goods
int gstcalc()
{
    int choice;
    float price, gst_rate;
    printf("Select your product type :\n");
    printf("1 for necessity items like milk, wheat flour\n");
    printf("2 for rough diamonds\n");
    printf("3 for gold silver etc\n");
    printf("4 for others\n");
    scanf("%d", &choice);
    switch (choice)
    //For necessity item like milk,wheat,flour
    {
    case 1:
        printf("Price of the product:");
        scanf("%f", &price);
        printf("GST on selected item is 0%%.\n");
        gst_rate = 0;
        printf("GST : %.2f\nFinal Price : %.2f\n", (price * gst_rate / 100), price + (price * gst_rate / 100));
        break;
    //For Rough diamonds
    case 2:
        printf("Price of the product:");
        scanf("%f", &price);
        printf("GST on selected item is 0.25%%.\n");
        gst_rate = 0.25;
        printf("GST : %.2f\nFinal Price : %.2f\n", (price * gst_rate / 100), price + (price * gst_rate / 100));
        break;
    //For gold, silver jewellary    
    case 3:
        printf("Price of the product:");
        scanf("%f", &price);
        printf("GST on selected item is 3%%.\n");
        gst_rate = 3;
        printf("GST : %.2f\nFinal Price : %.2f\n", (price * gst_rate / 100), price + (price * gst_rate / 100));
        break;
    //For all other items
    case 4:
        printf("Price of the product:");
        scanf("%f", &price);
    here:
        printf("GST on the item in %% (ie. 5/12/18/28):");
        scanf("%f", &gst_rate);
        if (gst_rate != 5 && gst_rate != 12 && gst_rate != 18 && gst_rate != 28)
        {
            printf("Please enter valid GST rate\n");
            goto here;
        }
        else
        {
            printf("GST : %.2f\nFinal Price : %.2f\n", (price * gst_rate / 100), price + (price * gst_rate / 100));
            break;
        }
    default:
        break;
    }
    return 0;
}
//Shipping cost calculator according to weight of goods and distance to delivery point
int shippingcostcalc()
{
    int choice;
    float rate, distance, weight;
    printf("Weight(in kgs):");
    scanf("%f", &weight);
    printf("Distance(in kms):");
    scanf("%f", &distance);
    printf("Select the method of shipping:\n");
    printf("1 for By air \n");
    printf("2 for By road \n");
    printf("3 for By water \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        if (weight <= 10)
        {
            rate = 15;
            float cost = distance * rate;
            if (cost >= 50000)
            {
                printf("Cost = 50000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        else if (weight <= 1000 && weight > 10)
        {
            rate = 12;
            float cost = distance * rate;
            if (cost >= 70000)
            {
                printf("Cost = 70000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        else if (weight > 1000)
        {
            rate = 10;
            float cost = distance * rate;
            if (cost >= 100000)
            {
                printf("Cost = 100000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        break;
    case 2:
        if (weight <= 10)
        {
            rate = 12;
            float cost = distance * rate;
            if (cost >= 20000)
            {
                printf("Cost = 20000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        else if (weight <= 1000 && weight > 10)
        {
            rate = 10;
            float cost = distance * rate;
            if (cost >= 50000)
            {
                printf("Cost = 50000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        else if (weight > 1000)
        {
            rate = 8;
            float cost = distance * rate;
            if (cost >= 70000)
            {
                printf("Cost = 70000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        break;
    case 3:
        if (weight <= 10)
        {
            rate = 10;
            float cost = distance * rate;
            if (cost >= 15000)
            {
                printf("Cost = 15000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        else if (weight <= 1000 && weight > 10)
        {
            rate = 7;
            float cost = distance * rate;
            if (cost >= 30000)
            {
                printf("Cost = 30000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        else if (weight > 1000)
        {
            rate = 5;
            float cost = distance * rate;
            if (cost >= 50000)
            {
                printf("Cost = 50000\n");
            }
            else
            {
                printf("Cost = %.2f\n", cost);
            }
        }
        break;

    default:
        break;
    }
    return 0;
}
//Wishlist manager for shopping cart 
#define MAX_WISHES 100
#define FILENAME "wishlist.txt"

struct wishes
{
    char category[50];
    float amount;
};

struct wishes wishes[MAX_WISHES];
int numwishes = 0;

void saveWishesToFile(struct wishes *wishes)
{
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    fprintf(file, "%s %.2f\n", wishes->category, wishes->amount);

    fclose(file);
}
//To load previously added wishes from file
void loadWishesFromFile()
{
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    while (fscanf(file, "%s %f", &wishes[numwishes].category, &wishes[numwishes].amount) == 2)
    {
        numwishes++;
        if (numwishes >= MAX_WISHES)
        {
            break;
        }
    }

    fclose(file);
}
//To add wishes to wishlist
void addWishes()
{
    if (numwishes < MAX_WISHES)
    {
        printf("Enter Wish category: ");
        scanf("%s", wishes[numwishes].category);

        printf("Enter Wish price amount: ");
        scanf("%f", &wishes[numwishes].amount);

        printf("Wish added successfully!\n");
        numwishes++;

        // Save the new Wish to the file
        saveWishesToFile(&wishes[numwishes - 1]);
    }
    else
    {
        printf("Wishlist is full. Cannot add more wishes.\n");
    }
}
//To view previously added wishes
void viewWishes()
{
    if (numwishes > 0)
    {
        printf("\nWishlist\n");
        printf("----------------\n");
        printf("%-20s%-10s\n", "Category", "Amount");
        printf("----------------\n");

        for (int i = 0; i < numwishes; i++)
        {
            printf("%d: %-20sRs%-10.2f\n", i + 1, wishes[i].category, wishes[i].amount);
        }

        printf("----------------\n");
        float total = 0;
        for (int i = 0; i < numwishes; i++)
        {
            total += wishes[i].amount;
        }
        printf("Total: Rs%.2f\n", total);
    }
    else
    {
        printf("No wishes to display.\n");
    }
}
//To remove previously added wishes from wishlist
void removeWishes()
{
    viewWishes();
    printf("Enter the wish to be removed(S.No):");
    FILE *file = fopen("wishlist.txt", "w");
    int rem;
    scanf("%d", &rem);
    if (numwishes < 0)
    {
        printf("No wishes in wishlist\n");
    }
    else
    {
        for (int i = rem - 1; i < numwishes - 1; i++)
        {
            wishes[i] = wishes[i + 1];
        }
        fprintf(file, "%s %.2f\n", wishes->category, wishes->amount);
        printf("Wish removed!\n");
        numwishes--;
        fclose(file);
    }
}
int wishlistmanager()
{
    // Load wishes from file at the beginning
    loadWishesFromFile();

    int choice;

    do
    {
        printf("\nWishlist Menu\n");
        printf("0. Exit\n");
        printf("1. Add Wish\n");
        printf("2. View Wish\n");
        printf("3. remove Wish\n");
        printf("Enter your choice(pls enter the number): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting Wishlist. Goodbye!\n");
            break;
        case 1:
            addWishes();
            break;
        case 2:
            viewWishes();
            break;
        case 3:
            removeWishes();
            break;
        default:
            printf("Invalid choice. Exiting application.\n");
            return 1;
        }
    } while (choice != 0);

    return 0;
}
//Merging all of thhe above functions
int main()
{
    int choice;
    while (choice != 0)
    {
        printf("Code menu\n0.Exit\n1.Coupon code Generator\n2.GST Calculator\n3.Shipping cost calculator\n4.Wishlist manager\nEnter your choice(please enter the number):");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            printf("Closing application.Have a nice day!");
            break;
        case 1:
            couponcodegen();
            break;
        case 2:
            gstcalc();
            break;
        case 3:
            shippingcostcalc();
            break;
        case 4:
            wishlistmanager();
            break;

        default:
            break;
        }
    }
    return 0;
}