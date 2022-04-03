# Test Plan and Test Ouput

| **Test ID** | **HLT ID** | **Description**                                              | **Exp IN** | **Exp OUT** | **Actual Out** |**PASS/FAIL**  |    
|-------------|-----|--------------------------------------------------------------|------------|-------------|----------------|------------------|
|  T_01|H_01| Provide required details for login with company code| code| Successfully logined In | Successfully logined In| PASS |
|  T_02|H_02| When wrong company code is entered| code|  Entered Code is wrong | Entered  is wrong | PASS |
|  T_03|H_03|Display the  details of option available|  Enter choice | Display list | Display list | PASS |
|  T_04|H_04|Generate gate pass|  Complete health screening form | Allow/Deny Employee | Show Gate Pass Deatils | PASS |
|  T_05|H_05|Display the  details for floor selection|  Enter choice | Display list | Display list | PASS |
|  T_06|H_06|Reserve desk|  Display details | Display reservation details | Display reservation details  | PASS |
|  T_07|H_07|Cancel desk|  Display details | Display cancellation details | Display cancellation details  | PASS |
|  T_08|H_08|  Summary of a reservation for booked seat| enter choice | Booking ID,Employee ID, Customer name,Floor Number,Date | Booking ID,Customer name,Show Name,Hallno,Price| PASS |
|  T_09|H_09| Cancel a ticket   |ID number|  Your ticket is cancelled | Your ticket is cancelled | PASS |
|  T_07|H_03| Change the price of ticket (only admin) | password| Please enter new price | Please enter new price   | PASS |
|  T_08|H_03| Change the price of ticket after login (only admin) | enter new price -price|Price Updated Successfully | Price Updated Successfully  | PASS |
|  T_09|H_03|Summary of all bookings (only admin) | password | Entered Password is wrong  |  Entered Password is wrong |PASS |
|  T_10|H_05|To view the reserved or cancelled seats |password| summary of booking|summary of booking | PASS |
|  T_11|H_05|When wrong password is entered to view the reserved/cancelled ticket|Correct Password | Entered Password is wrong|Entered Password is wrong | PASS |













