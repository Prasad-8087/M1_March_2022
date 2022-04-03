/**
 * @file function.h
 * @author Prasad Patil
 * 
 */
#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>
#ifndef __FUNCTION_H__
#define __FUNCTION_H__
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <conio.h>
#include <time.h>
#include <ctype.h>



       





#endif /* #define _FUNCTION_H__ */


/**
 * @brief to select floor in building
 */


int selectFloor(void);
/**
 * @brief display office seat booking details
 * 
 */
void showBookingDetails(int choice, char name[10], int id2, int selection, int employeeId);
/**
 * @brief to book seat
 */

void bookSeat(int *, int, int);


/**
 * @brief admin can view all booking or cancelled seats
 * 
 */
void displayBookings(void);


/**
 * @brief Employee can cancel seat booking
 */

void cancelBooking(int *);
/**
 * @brief Employee can create gate pass to enter in office
 */
void createGatePass();
/**
 * @brief To generate and display gate pass to employee
 */ 
void generateGatePass(char name[25], int id);
/**
 * @brief Display unauthorized message to unauthorized employee
 */
void showUnauthorizedMessage();


 #endif /* #define _FUNCTION_H__ */