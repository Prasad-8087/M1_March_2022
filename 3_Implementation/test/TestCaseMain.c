#include "../unity/unity.h"
#include "../unity/unity_internals.h"
#include "../unity/unity.c"

#include "../inc/function.h"
#include "../src/CreateGatePass.c"
#include "../src/FloorSelection.c"

#define PROJECT_NAME "GetMyOfficePass"

// Prototypes
void test_createGatePass(void);
void test_selectFloor(void);
void test_generateGatePass(void);

void test_showUnauthorizedMessage(void);

void setUp() {}

void tearDown() {}

int main()
{
  UNITY_BEGIN();

  // Run Test functions for registration and vaccine status
  RUN_TEST(test_createGatePass);
  RUN_TEST(test_selectFloor);
  RUN_TEST(test_generateGatePass);
  RUN_TEST(test_showUnauthorizedMessage);
  return UNITY_END();
}

// Test functions
void test_createGatePass(void)
{
  createGatePass();
}

// Test functions
void test_selectFloor(void)
{
   selectFloor(); 
}

void test_showUnauthorizedMessage(){
  showUnauthorizedMessage();
}
// Test functions
void test_generateGatePass(void)
{
  char* test = "testPasstesttesttesttestt";
  generateGatePass(test,2);
  
 //  selectFloor(); 
}
