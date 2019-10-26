#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/extensions/TestFactoryRegistry.h"
#include "cppunit/ui/text/TextTestRunner.h"


#include "project.h"


class TestMatrix : public CppUnit::TestCase {
public:

    void Test_compare_matrix()
    {
        int t = 5;
        int **matrix1 = (int**)malloc(t* sizeof(int*));
        for (int i=0; i<t; i++) matrix1[i]=(int*)malloc(sizeof(int)*t);

        for (int i=0; i<t; i++)
        {for (int j = 0; j < t; j++)
           matrix1[i][j] = 1;
        }

        CPPUNIT_ASSERT_EQUAL_MESSAGE("Mutrices must be equal", Compare_matrix(matrix1, matrix1, t, t), 0);

        int **matrix2 = (int**)malloc(t* sizeof(int*));
        for (int i=0; i<t; i++) matrix2[i]=(int*)malloc(sizeof(int)*t);


        CPPUNIT_ASSERT_EQUAL_MESSAGE("Mutrices must not be equal", Compare_matrix(matrix1, matrix2, t, t), -1);

        for (int i=0; i<t; i++) free (matrix1[i]);
        free (matrix1);
        for (int i=0; i<t; i++) free (matrix2[i]);
        free (matrix2);
    }

    void Test_check_matrix_filling()
    {
        int t = 5;
        int **matrix1 = (int**)malloc(t* sizeof(int*));
        for (int i=0; i<t; i++) matrix1[i]=(int*)malloc(sizeof(int)*t);

      //  Fill_matrix(matrix1, 0);

        for (int i=0; i<t; i++) free (matrix1[i]);
        free (matrix1);
    };


CPPUNIT_TEST_SUITE(TestMatrix);
        CPPUNIT_TEST (Test_compare_matrix);
        CPPUNIT_TEST(Test_check_matrix_filling);
    CPPUNIT_TEST_SUITE_END();
};


CPPUNIT_TEST_SUITE_REGISTRATION(TestMatrix);

int main() {

    CppUnit::Test* test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
    CppUnit::TextTestRunner runner;
    runner.addTest(test);
    runner.run();
    return 0;
}