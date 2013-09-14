#include <stdio.h>
#include <stdlib.h>

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

CU_ErrorCode penetra_binary_test_suite(CU_pSuite *rsuite);

int main()
{
        CU_pSuite penetra_suite = NULL;

        /* initialize the CUnit test registry */
        if (CUE_SUCCESS != CU_initialize_registry()) {
                return CU_get_error();
        }

        /* add a suite to the registry */
        if (CUE_SUCCESS != penetra_binary_test_suite(&penetra_suite))
        {
                fprintf(stderr, "Failed to create test suite.\n");
                CU_cleanup_registry();
                return 1;
        }

        /* Run all tests using the CUnit Basic interface */
        CU_basic_set_mode(CU_BRM_VERBOSE);
        CU_basic_run_tests();
        CU_cleanup_registry();
        return CU_get_error();
}
