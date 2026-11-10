#include "pch.h"
#pragma warning(disable : 4996)
#include "CppUnitTest.h"
#include "../LR8.1_it/LR8.1_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81it
{
    TEST_CLASS(UnitTest81it)
    {
    public:

        // Перевірка функції Count
        TEST_METHOD(CountTest)
        {
            // порожній рядок
            Assert::AreEqual(0, Count(""));
            // рядок коротший за три символи
            Assert::AreEqual(0, Count("ab"));
            // немає групи abc
            Assert::AreEqual(0, Count("acbbca"));
            // одна група
            Assert::AreEqual(1, Count("abc"));
            // групи на початку, в середині та в кінці
            Assert::AreEqual(3, Count("abc xabcy abc"));
            // групи підряд
            Assert::AreEqual(2, Count("abcabc"));
            // група після зайвих символів ab
            Assert::AreEqual(1, Count("ababc"));
        }

        // Перевірка функції Change
        TEST_METHOD(ChangeTest)
        {
            char s1[] = "";
            char* r1 = Change(s1);
            Assert::AreEqual("", r1);
            delete[] r1;

            char s2[] = "ab";
            char* r2 = Change(s2);
            Assert::AreEqual("ab", r2);
            delete[] r2;

            char s3[] = "abc";
            char* r3 = Change(s3);
            Assert::AreEqual("**", r3);
            // результат також має бути у вхідному параметрі
            Assert::AreEqual("**", s3);
            delete[] r3;

            char s4[] = "xabcyabcz";
            char* r4 = Change(s4);
            Assert::AreEqual("x**y**z", r4);
            delete[] r4;

            char s5[] = "abcabc";
            char* r5 = Change(s5);
            Assert::AreEqual("****", r5);
            delete[] r5;

            char s6[] = "ababc";
            char* r6 = Change(s6);
            Assert::AreEqual("ab**", r6);
            delete[] r6;
        }
    };
}
