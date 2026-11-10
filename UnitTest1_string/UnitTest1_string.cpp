#include "pch.h"
#include "CppUnitTest.h"
#include "../LR8.1_string/LR8.1_string.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest81str
{
    TEST_CLASS(UnitTest81str)
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
            string s1 = "";
            Assert::AreEqual("", Change(s1).c_str());

            string s2 = "ab";
            Assert::AreEqual("ab", Change(s2).c_str());

            string s3 = "abc";
            string r3 = Change(s3);
            Assert::AreEqual("**", r3.c_str());
            // результат також має бути у вхідному параметрі
            Assert::AreEqual("**", s3.c_str());

            string s4 = "xabcyabcz";
            Assert::AreEqual("x**y**z", Change(s4).c_str());

            string s5 = "abcabc";
            Assert::AreEqual("****", Change(s5).c_str());

            string s6 = "ababc";
            Assert::AreEqual("ab**", Change(s6).c_str());
        }
    };
}
