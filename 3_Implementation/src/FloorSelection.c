#include "../inc/function.h"
int selectFloor(void)
{
    system("cls");
    int choice;
    printf("                       Select Floor\n");
    printf(" ==============================================================\n");
    printf("||                       1- Floor 1                          ||\n");
    printf("||                       2- Floor 2                          ||\n");
    printf("||                       3- Floor 3                          ||\n");
    printf("||===========================================================||\n");
    printf("  Enter your choice: ");
    scanf("%d", &choice);

    return choice;
}