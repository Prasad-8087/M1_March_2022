#include "../inc/function.h"
/**
 * @brief Create gate pass for employee - ask some basic question on basis of that generate gate pass for employee
 * 
 */
void createGatePass()
{
    system("cls");
    int employeeId;
    char name[25];
    char question1;
    char question2;
    char question3;
    char no = 'n';

    printf("\n\tEnter Your Employee ID : ");
    scanf("%d", &employeeId);

    printf("\n\tEnter Your Name : ");
    scanf("%s", &name);

    printf("\n\t****************************** Health Screening Form \t************************");
    // printf("\n\t************\tKindly answer below questions in y/n format\t********************");

    printf("\n\n\t 1.Are you currently experiencing any typical COVID-19 symptoms, i.e. fever, body aches, shortness of breath?(y/n)\n\t\t");
    scanf("%c", &question1);
    question1 = getchar();
    if (tolower(question1) == no)
    {
        printf("\n\t2.Have you been in direct contact with any persons confirmed or suspected of having COVID-19 in the last 14 days?(y/n)\n\t\t");
        scanf("%c", &question2);
        question2 = getchar();

        if (tolower(question2) == no)
        {
            printf("\n\t3.Have you returned from any country within the last 14 days?(y/n)\n\t\t");
            scanf("%c", &question3);
            question3 = getchar();
            if (tolower(question3) == no)
            {
                generateGatePass(name, employeeId);
            }
            else
            {
                showUnauthorizedMessage();
            }
        }
        else
        {
            showUnauthorizedMessage();
        }
    }
    else
    {
        showUnauthorizedMessage();
    }
}
/**
 * @brief  Create and display employee gate pass
 * 
 */
void generateGatePass(char name[25], int id)
{
    system("cls");
    time_t t;
    time(&t);
    printf("\n\n");
    printf("\t------------------------------------------OFFICE GATE PASS-------------------------------------------------\n");
    printf("\t===========================================================================================================\n");
    printf("\t\t\t\t\t**You are authorized to enter office**\n");
    printf("\t\t\t\n Employee ID : %d \t\t\t", id);
    printf("\t\t\t Employee Name  : %s\n", name);
    printf("\t\t\t\t                         Date      : %s\n", ctime(&t));
    printf("\t**Kindly show this pass at office enterance**\n");
    printf("\t**Please carry your digital or physical covid vaccination certificate to complete verification.**\n");
    printf("\t============================================================================================================\n");
    
}

/**
 * @brief Display error message if employee is unauthorized
 * 
 */
void showUnauthorizedMessage()
{
    printf("\n We are sorry but you are not authorized to enter office as saftey precaution ");
}
