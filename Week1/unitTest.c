#include<stdlib.h>
#include<time.h>

#include "../Unity/src/unity.h"
#include "sort.h"
#include "helpers.h"


void setUp(void)
{
    //setup stuff - not required
}

void tearDown(void)
{
    //cleanup stuff - not required
}

void test_function_mergeSort(void)
{
    int num_tests = 500;
    int* size_array = malloc(num_tests * sizeof(int));
    populate_random_int_array(&size_array, num_tests);
    mergeSort(size_array, 0, num_tests-1);

    int* a;
    int a_len;

    clock_t start, end;
    double time_used;

    double** test_results;
    alloc_results_memory(&test_results, num_tests, 3); // 3 denotes number of columns

    char e_msg[64]; // helpful error message

    for(int i = 0; i < num_tests; i++){
        a_len = size_array[i];
        a = malloc(a_len * sizeof(int));

        start = clock();
        mergeSort(a, 0, a_len-1);
        end = clock();

        time_used = ((double) end - start) / CLOCKS_PER_SEC;
        record_result(&test_results, i, a_len, time_used);

        sprintf(e_msg, "\nTest %d failed, exiting\n", i); // unity does not support printf string formatting, so pre-definition with sprintf required
        TEST_ASSERT_TRUE_MESSAGE(is_sorted(a, a_len), e_msg);
        free(a);
    }

    report_results(test_results, num_tests);
    free(test_results);
    free(size_array);

    printf("\n----END MERGE SORT TEST----\n");
    return;
}

void test_function_insertSort(void)
{
    int numTests = 500; // change this
    int* sizeArray = malloc(numTests * sizeof(int));
    populate_random_int_array(&sizeArray, numTests); // generate random sizes for testing of array
    insertSort(&sizeArray, numTests);

    double** test_results;
    alloc_results_memory(&test_results, numTests, 3); // 3 denotes number of columns

    clock_t start, end;
    double time_used;

    int* a;
    int a_len;

    char* e_msg = malloc(64); // error message in case of test fail

    for(int i = 0; i < numTests; i++){
        a_len = sizeArray[i];
        populate_random_int_array(&a, a_len);

        start = clock();
        insertSort(&a, a_len);
        end = clock();
        time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

        record_result(&test_results, i, a_len, time_used);

        sprintf(e_msg, "\nTest %d failed, exiting", i); // unity does not support printf string formatting, so pre-definition with sprintf required
        TEST_ASSERT_TRUE_MESSAGE(is_sorted(a, a_len), e_msg);

        free(a);
    }

    report_results(test_results, numTests);
    free(test_results);
    free(sizeArray);
    printf("\n ---- END INSERT SORT TEST ----\n");
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_function_insertSort);
    RUN_TEST(test_function_mergeSort);
    return 0;
}