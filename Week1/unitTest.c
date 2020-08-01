#include<stdlib.h>
#include "../Unity/src/unity.h"
#include "insertSort.h"
#include "helpers.h"


void setUp(void)
{
    //setup stuff - not required
}

void tearDown(void)
{
    //cleanup stuff - not required
}

void test_function_insertSort(void)
{
    int numTests = 500; // change this
    int* sizeArray = generate_random_array(numTests); // generate random sizes for testing of array

    int* a;
    int* a_sorted;
    int a_len; // size of array for random test

    // Error and test messages
    char* e_msg = malloc(64);
    char* t_msg = malloc(64);

    for(int i = 0; i < numTests; i++){
        sprintf(t_msg, "Starting test %d, length %d", i, a_len);
        TEST_MESSAGE(t_msg);

        a_len = sizeArray[i];
        a = generate_random_array(a_len);
        a_sorted = insertSort(a, a_len);

        sprintf(e_msg, "Test %d failed, exiting", i);
        TEST_ASSERT_TRUE_MESSAGE(is_sorted(a_sorted, a_len), e_msg);
    }

    free(e_msg);
    free(t_msg);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_function_insertSort);
    return 0;
}