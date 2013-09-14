#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

void penetra_open_TEST()
{
        CU_ASSERT(1 == 1);
}

CU_ErrorCode penetra_binary_test_suite(CU_pSuite *rsuite)
{
        CU_pSuite suite = NULL;

        if (NULL == rsuite) {
                return -1;
        }

        suite = CU_add_suite("Penetra", NULL, NULL);
        if(NULL == suite) {
                *rsuite = NULL;
                return CU_get_error();
        }

        if ((NULL == CU_add_test(suite,
                                 "malelf_binary_open_TEST",
                                 penetra_open_TEST))) {
                *rsuite = NULL;
                return CU_get_error();
        }

        *rsuite = suite;
        return CUE_SUCCESS;
}
