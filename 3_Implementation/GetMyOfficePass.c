/*!
* \file \GetMyOfficePass\GetMyOfficePass.c
* \author Prasad Patil
* \version 0.1
* \date 30/03/2022
* \brief This is main executable file. In this employee can generate office pass, can book seat in office, cancel booking and admins can view all booking with booked or cancelled status.
* 
* 
* 
*/


/*! Importation of librairies*/
#include "./inc/function.h"
#include "./src/EmployeeDetails.c"
#include "./src/CreateGatePass.c"
#include "./src/FloorSelection.c"

struct employeeDetails employee[300];
int count = 0;
int id2 = 1000;
int main_exit;

/*!
* \fn int main()
* \author Prasad Patil
* \version 0.1
* \date 30/03/2022
* \brief Main function of the program
* \remarks None
* \param argc number of arguments given as inputs
* \param argv value of arguments given as inputs
* \return 0 if all went good
*/
int main()
{
    int **seat, choice, price = 500, slection, i;
    char pass[20], password[20] = "3140";

    seat = (int **)calloc(101, sizeof(int *));
    for (i = 0; i < 3; i++)
        *(seat + i) = (int *)calloc(101, sizeof(int));
    int x;
    int empId;
    int seatAvailable = 0;
    printf("\n\n\n****************************WELCOME TO OFFICE PORTAL****************************\n\n");
    printf("\n\tEnter the company ID to login:");
    scanf("%s", pass);

    if (strcmp(pass, password) == 0)
    {
        printf("\n\tCode Match!\n\tLOADING");
        for (i = 0; i <= 6; i++)
        {
            printf(".");
        }

        while (x != 5)
        {
            printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\n\n\t\t1.Create Gate Pass\n\t\t2.Book Your Seat\n\t\t3.Cancel Your Seat\n\t\t4.View booked setas(only admins)\n\t\t5.Exit\n\n\t Enter your choice:");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                createGatePass();
                break;
            case 2:
                printf("Please enter your employee ID: ");
                scanf(" %d", &empId);
                for (int j = 0; j < count; j++)
                {
                    if (empId == employee[j].employeeID && employee[j].cacelStatus==0)
                    {
                        seatAvailable = 1;
                    }
                }
                if (seatAvailable == 1)
                {
                    seatAvailable = 0;
                    printf("\nIt's look like You already booked seat. If you want to change seat you can cancel previous booking and book seat again.\n");
                }
                else
                {
                    seatAvailable = 0;
                    slection = selectFloor();
                    if (slection < 1 || slection > 3)
                    {
                        printf("Please select valid options.");
                    }
                    else
                    {
                        bookSeat(seat[slection - 1], slection, empId);
                        count++;
                    }
                }

                break;
            case 3:
                slection = selectFloor();
                cancelBooking(seat[slection - 1]);
                break;
            case 4:
                displayBookings();
                break;
            case 5:
                x = 5;
                break;
            default:
                printf("Choice not available\n");
                break;
            }
        }
    }
    else
    {
        printf("\n\nWrong Code!!\a\a\a");
    login_try:
        printf("\nEnter 1 to try again and 0 to exit:");
        scanf("%d", &main_exit);
        if (main_exit == 1)
        {

            system("cls");
            main();
        }

        else if (main_exit == 0)
        {
            system("cls");
        }
        else
        {
            printf("\nInvalid!");
            system("cls");
            goto login_try;
        }
    }
}


/*!
* \fn void bookSeat(int *array, int slection, int empId)
* \author Prasad Patil
* \version 0.1
* \date  30/03/2022
* \brief  Employee can book seat in office.
* \remarks None
* \param array 
* \param slection 
* \param empId 
*/
void bookSeat(int *array, int slection, int empId)
{
    system("cls");
    int i, j;
    for (i = 1; i <= 100; i++)
    {
        if (array[i] == 0)
            printf("%d\t", i);
        else
            printf("*\t", i);
        if (i % 10 == 0)
            printf("\n\n");
    }

    employee[count].employeeID = empId;
    printf("\nPlease enter your name: ");
    scanf(" %19[^\n]%*[^\n]", &employee[count].name);
    printf("Please enter your phone number: ");
    scanf("%u", &employee[count].phone);

    printf("Please select seat number: ");
    scanf("%d", &j);
    if (j > 100 || j < 1)
    {
        printf("This Seat is Unavailable On this Floor\n");
        printf("Please re-enter seat number: ");
        scanf("%d", &j);
    }
    if (array[j] == 1)
    {
        printf("Sorry, this seat is already booked! Please choose another seat.\n");
        scanf("%d", &j);
    }
    else
        array[j] = 1;
    employee[count].seat = j;
    employee[count].floor = slection;
    employee[count].cacelStatus = 0;
    showBookingDetails(j, employee[count].name, id2, slection, employee[count].employeeID);
    id2++;
}


/*!
* \fn void showBookingDetails(int choice, char name[10], int id2, int selection, int employeeId)
* \author Prasad Patil
* \version 0.1
* \date  30/03/2022
* \brief  Display booking details to employee
* \remarks None
* \param choice 
* \param name 
* \param id2 
* \param selection 
* \param employeeId 
*/
void showBookingDetails(int choice, char name[10], int id2, int selection, int employeeId)
{
    system("cls");
    time_t t; // not a primitive datatype
    time(&t);
    printf("\n\n");
    printf("\t----------------------------SEAT BOOKING DETAILS----------------------\n");
    printf("\t======================================================================\n");
    printf("\t Booking ID : %d \t\t\t\n", id2);
    printf("\t EMPLOYEE NAME  : %s\n", name);
    printf("\t EMPLOYEE ID  : %d\n", employeeId);
    printf("\t\t\t\t          Date : %s\n", ctime(&t));
    printf("\t                                  Time      : 11:00 PM TO 7:00 PM \n");
    printf("\t                                  Floor     : %d\n", selection);
    printf("\t                                  Seats No. : %d \n", choice);
    employee[count].id = id2;
    printf("\t=======================================================================\n");
    return;
}


/*!
* \fn void cancelBooking(int *array)
* \author Prasad Patil
* \version 0.1
* \date  30/03/2022
* \brief Employee can cancel booked seats 
* \remarks None
* \param array 
*/
void cancelBooking(int *array)
{
    int Cseat, i, stop;
    printf("Please enter your employee ID : ");
    scanf("%d", &Cseat);
    for (i = 0; i < 300; i++)
    {
        if (Cseat == employee[i].employeeID)
        {
            stop = 5;
            system("cls");
            printf("Hello %s, your seat is %d cancelled", employee[i].name, employee[i].seat);
            array[employee[i].seat] = 0;
            employee[i].cacelStatus = 1;
            i = 300;
        }
    }
    if (stop != 5)
        printf("\nOops! It's look like You haven't booked any seat.\n");
}


/*!
* \fn void displayBookings(void)
* \author Prasad Patil
* \version 0.1
* \date  30/03/2022
* \brief Display all bookings with status booked or cancelled
* \remarks None
*/
void displayBookings(void)
{
    system("cls");
    int i;
    char pass[10], pak[10] = "pass";
    printf("Enter the password to see details: ");
    char *status = "Booked";
    scanf("%s", &pass);
    if (strcmp(pass, pak) == 0)
    {
        for (i = 0; i < count; i++)
        {

            if (employee[i].cacelStatus == 1)
            {
                status = "Cancelled";
            }
            else
            {
                status = "Booked";
            }
            printf("Seat no. %d is booked by %s with Employee ID %d on Floor %d. Seat Status = %s \n", employee[i].seat, employee[i].name, employee[i].employeeID, employee[i].floor, status);
            printf("=============================================================\n");
        }
    }
    else
        printf("Entered password is wrong \n");
    system("PAUSE");
    system("CLS");
}
