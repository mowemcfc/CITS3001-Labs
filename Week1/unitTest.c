#include "../Unity/src/unity.h"
#include "insertSort.h"
#include "helpers.h"

void setUp(void)
{
    //setup stuff
}

void tearDown(void)
{
    //cleanup stuff
}



void test_function_insertSort(void)
{
    printf("hello");
    int* a5 = generate_random_array(500);
    printf("hello");
    int* a5_sorted = insertSort(a5, 500);
    printf("hello");

    TEST_ASSERT_TRUE_MESSAGE(is_sorted(a5_sorted, 500), "Array a5 is not sorted");
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_function_insertSort);
    return 0;
}