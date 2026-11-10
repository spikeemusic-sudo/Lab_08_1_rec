#include "pch.h"
#include "CppUnitTest.h"

#define UNIT_TESTING
#include "../Lab_08_1_rec/Lab_08_1_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81rec
{
    TEST_CLASS(UnitTest81rec)
    {
    public:

        TEST_METHOD(TestInclude)
        {
            char str1[] = "w_h_i_l_e";
            Assert::IsTrue(Include(str1));

            char str2[] = "world_hello";
            Assert::IsFalse(Include(str2));
        }

        TEST_METHOD(TestChange)
        {
            char str[101] = "abcwhilexyzwhile123";
            char* dest = new char[151];
            dest[0] = '\0';

            char* result = Change(dest, str, dest, 0);

            Assert::AreEqual("abc**xyz**123", dest);
            Assert::AreEqual("abc**xyz**123", result);

            delete[] dest;
        }
    };
}