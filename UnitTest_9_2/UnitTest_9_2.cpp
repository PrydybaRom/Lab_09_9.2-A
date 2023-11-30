#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_09_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest92
{
    TEST_CLASS(UnitTest92)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            // Arrange
            Student students[] = {
                {"Ivanov", 2, Spec::ME, 5, 4, 3},
                {"Petrov", 3, Spec::MF, 4, 4, 4},
                {"Sidorov", 1, Spec::FI, 3, 3, 3}
            };

            // Sorting the array by index for binary search
            int* index = new int[3];
            buildIndex(students, 3, index);

            // Act
            Student searchStudent = { "Petrov", 3, Spec::MF };
            bool result = binarySearchStudent(students, 0, 2, searchStudent);

            // Assert
            Assert::IsTrue(result);

            // Clean up
            delete[] index;
        }

    };
}
