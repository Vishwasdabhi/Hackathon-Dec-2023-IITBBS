#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int Max_patient = 100;
#define FILENAME "patientInfo.txt"

struct patient
{
    int id;
    char name[50];
    int age;
    char gender;
};
void addPatient(struct patient *patients[], int *count)
{
    printf("Patient ID :");
    scanf("%d", &patients[*count]->id);
    printf("Name :");
    scanf("%s", &patients[*count]->name);
    printf("Age :");
    scanf("%d", &patients[*count]->age);
    getchar();
here:
    printf("Gender (M/F) :");
    scanf("%c", &patients[*count]->gender);
    if (patients[*count]->gender != 'M' && patients[*count]->gender != 'm' && patients[*count]->gender != 'F' && patients[*count]->gender != 'f')
    {
        printf("Please enter correct Gender\n");
        goto here;
    }
    getchar();
    *count++;
    printf("Patient added succesfully\n");
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    // fprintf(file, "%s %.2f\n", wishes->category, wishes->amount);
    fprintf(file, "Patient ID : %d\nName : %s\nAge : %d\nGender : %c", patients[*count]->id, patients[*count]->name, patients[*count]->age, patients[*count]->gender);

    fclose(file);
}

void searchPatient(struct patient *patients[], int count, int id)
{
    for (int i = 0; i < count; i++)
    {
        if (patients[i]->id == id)
        {
            printf("Patient found!\n");
            printf("ID: %d\n", patients[i]->id);
            printf("Name: %s\n", patients[i]->name);
            printf("Age: %d\n", patients[i]->age);
            printf("Gender: %c\n", patients[i]->gender);
            break;
        }
        else
        {
            printf("Patient not found\n");
        }
    }
}
void viewPatients(struct patient *patients[], int count)
{
    if (count > 0)
    {
        printf("\nPatients Info\n");
        printf("----------------\n");
        // printf("%-20s%-10s\n", "Category", "Amount");
        // printf("----------------\n");

        for (int i = 0; i < count; i++)
        {
            printf("ID    : %d\n", patients[i]->id);
            printf("Name  : %s\n", patients[i]->name);
            printf("Age   : %d\n", patients[i]->age);
            printf("Gender: %c\n", patients[i]->gender);
        }

        printf("----------------\n");
    }
    else
    {
        printf("No Patients to display.\n");
    }
}

int main()
{
    struct patient *patients;
    patients = (struct patient *)malloc(Max_patient * sizeof(struct patient));
    int count = 0;
    int choice;

    do
    {
        printf("\nPatients Menu\n");
        printf("0. Exit\n");
        printf("1. Add Patient\n");
        printf("2. Search Patient\n");
        printf("3. View Patients\n");
        printf("Enter your choice(please enter the number): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting Patients list. Goodbye!\n");
            break;
        case 1:
            addPatient(&patients, &count);
            break;
        case 2:
        {
            int id;
            scanf("%d", &id);
            searchPatient(&patients, count, id);
        }
        break;
        case 3:
            viewPatients(&patients, count);
            break;
        default:
            printf("Invalid choice. Exiting application.\n");
            return 1;
        }
    } while (choice != 0);
    return 0;
}