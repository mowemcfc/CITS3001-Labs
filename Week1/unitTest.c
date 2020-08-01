#include<stdlib.h>
#include<time.h>

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

    clock_t start, end;
    double time_used;

    int* a;
    int* a_sorted;
    int a_len; // size of array for random test

    char* e_msg = malloc(64); // error message in case of test fail

    double** test_results;

    for(int i = 0; i < numTests; i++){
        a_len = sizeArray[i];
        a = generate_random_array(a_len);

        start = clock();
        a_sorted = insertSort(a, a_len);
        end = clock();
        time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        record_result(test_results, i, a_len, time_used);

        sprintf(e_msg, "Test %d failed, exiting", i); // unity does not support printf string formatting, so pre-definition with sprintf required
        TEST_ASSERT_TRUE_MESSAGE(is_sorted(a_sorted, a_len), e_msg);
    }

    insertSort(test_results, numTests);
    report_results(test_results);

    free(e_msg);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_function_insertSort);
    return 0;
}