#include "pch.h"
#include "CppUnitTest.h"
#include "D:\education\Lab 8.2\Lab 8.2.cpp" // Обов'язково вкажи шлях до свого файлу .cpp

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(Lab81Variant7Tests)
    {
    public:

        // Тест для перевірки виділення останнього слова
        TEST_METHOD(TestFindLastWord)
        {
            // Case 1: Звичайне речення
            Assert::AreEqual(string("banana"), FindLastWord("apple orange banana"));

            // Case 2: Пробіли після останнього слова
            Assert::AreEqual(string("java"), FindLastWord("learning java    "));

            // Case 3: Лише одне слово в рядку
            Assert::AreEqual(string("hello"), FindLastWord("hello"));

            // Case 4: Порожній рядок або лише пробіли
            Assert::AreEqual(string(""), FindLastWord("   "));
        }

        // Тест для перевірки підрахунку літер 'a'
        TEST_METHOD(TestCountA)
        {
            // Case 1: Кілька літер 'a'
            Assert::AreEqual((size_t)3, CountA("banana"));

            // Case 2: Немає літер 'a'
            Assert::AreEqual((size_t)0, CountA("sky"));

            // Case 3: Велика літера 'A' (якщо додав її в логіку)
   
            Assert::AreEqual((size_t)3, CountA("Ananas"));

            
           // Case 4: Перевірка на велику та малу літери разом
          // Слово "Apple" має 1 велику 'A'
            Assert::AreEqual((size_t)1, CountA("Apple"));
        }

        // Комплексний тест (Act & Assert)
        TEST_METHOD(TestFullLogic)
        {
            const char* testStr = "today is a great day";
            string lastWord = FindLastWord(testStr);
            size_t count = CountA(lastWord);

            Assert::AreEqual(string("day"), lastWord);
            Assert::AreEqual((size_t)1, count);
        }
    };
}