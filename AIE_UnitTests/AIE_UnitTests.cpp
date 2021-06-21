#include "pch.h"
#include "CppUnitTest.h"

#include "../LinkedList/LinkedList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

template<int ID>
class MockClass
{
public:

    MockClass()
    {
        counter += 1;
    }

    MockClass(MockClass& copy)
    {
        counter += 1;
    }

    ~MockClass()
    {
        counter -= 1;
    }

    static int counter;
};


template<int ID>
int MockClass<ID>::counter = 0;

namespace AIEUnitTests
{
    TEST_CLASS(AIELinkedListTest)
    {
    public:

        TEST_METHOD(Can_Create_Empty_List)
        {
            // Setup
            // -------------------------------
            LinkedList<int> list;

            // -------------------------------
            // Below we assert, check our expectations match

                // First and Last node in an empty list should be null
            Assert::IsNull(list.FirstNode());
            Assert::IsNull(list.LastNode());

            // the IsEmpty function should return true
            Assert::IsTrue(list.IsEmpty());

            // for an empty list begin and end should be the same
            Assert::IsTrue(list.begin() == list.end());

            // an empty list should have a count of 0
            Assert::IsTrue(list.Count() == 0);
        }

        TEST_METHOD(Can_Create_List_With_Initialiser_List)
        {
            // Setup
            // -------------------------------
            LinkedList<int> list = { 10, 20, 30, 40 };

            // -------------------------------
            // Below we assert, check our expectations match

            // First and Last nodes should not be null
            Assert::IsNotNull(list.FirstNode());
            Assert::IsNotNull(list.LastNode());

            // First and Last nodes should have a value of 10 and 40
            Assert::AreEqual(list.FirstNode()->value, 10);
            Assert::AreEqual(list.LastNode()->value, 40);

            // The IsEmpty function should return false
            Assert::IsFalse(list.IsEmpty());

            // should be able to iterate through each item
            // lets check the values are as we expect
            int arr[5] = { 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }


        TEST_METHOD(PushBack)
        {
            // Write another test
            LinkedList<int> list;

            list.PushBack(10);
            list.PushBack(20);
            list.PushBack(30);
            list.PushBack(40);

            Assert::IsNotNull(list.FirstNode());
            Assert::IsNotNull(list.LastNode());

            // First and Last nodes should have a value of 10 and 40
            Assert::AreEqual(list.FirstNode()->value, 10);
            Assert::AreEqual(list.LastNode()->value, 40);

            // The IsEmpty function should return false
            Assert::IsFalse(list.IsEmpty());

            // should be able to iterate through each item
            // lets check the values are as we expect
            int arr[5] = { 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }

        }

        TEST_METHOD(PopBack)
        {
            // Write another test
            LinkedList<int> list = { 10, 20, 30, 40, 50 };

            list.PopBack();

            Assert::AreEqual(list.FirstNode()->value, 10);
            Assert::AreEqual(list.LastNode()->value, 40);
        }

        TEST_METHOD(PushFront)
        {
            // Write another test
            LinkedList<int> list = { 10, 20, 30, 40 };

            list.PushFront(5);

            int arr[5] = { 5, 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }
        
        TEST_METHOD(PopFront)
        {
            // Write another test
            LinkedList<int> list = { 10, 20, 30, 40 };

            list.PopFront();

            Assert::AreEqual(list.FirstNode()->value, 20);
            Assert::AreEqual(list.LastNode()->value, 40);

            int arr[3] = { 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

        TEST_METHOD(Remove)
        {
            // Write another test
            LinkedList<int> list = { 30, 10, 20, 30, 40, 30 };

            for (auto iter = list.begin(); iter != list.end();)
            {
                if (*iter == 30)
                {
                    iter = list.Remove(iter);
                }
                else
                {
                    iter++;
                }
            }

            Assert::IsTrue(list.Count() == 3);


            int arr[3] = { 10, 20, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

        TEST_METHOD(Insert_beginning)
        {
            // Write another test
            
            LinkedList<int> list = { 10, 20, 30, 40 };

            auto iter = std::find(list.begin(), list.end(), 10);

            Assert::IsTrue(iter == list.begin());

            list.Insert(iter, 5);

            Assert::AreEqual(list.FirstNode()->value, 5);
            Assert::AreEqual(list.LastNode()->value, 40);
        }

        TEST_METHOD(Insert_middle)
        {
            // Write another test
            LinkedList<int> list = { 10, 20, 30, 40 };

            auto iter = std::find(list.begin(), list.end(), 30);

            list.Insert(iter, 25);

            Assert::AreEqual(list.FirstNode()->next->next->value, 25);
            Assert::AreEqual(list.LastNode()->prev->prev->value, 25);
        }

        TEST_METHOD(Insert_end)
        {
            // Write another test
            LinkedList<int> list = { 10, 20, 30, 40 };      

            list.Insert(list.end(), 45);

            Assert::AreEqual(list.LastNode()->value, 45);
        }

        TEST_METHOD(Clear)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };

            list.Clear();

            Assert::IsNull(list.FirstNode());
            Assert::IsNull(list.LastNode());
            
        }

        TEST_METHOD(Swap1)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };

            auto iterA = list.begin();
            //iterA++;

            auto iterB = list.begin();
            iterB++;
            //iterB++;

            list.Swap(iterA, iterB);
            Assert::IsTrue(list.FirstNode()->value == 20);

            int arr[4] = { 20, 10, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }

        }

        TEST_METHOD(Swap2)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };

            auto iterA = list.begin();
            iterA++;

            auto iterB = list.begin();
            iterB++;
            iterB++;

            list.Swap(iterA, iterB);

            int arr[4] = { 10, 30, 20, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }

        }

        TEST_METHOD(Swap3)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };

            auto iterA = list.begin();
            iterA++;
            iterA++;

            auto iterB = list.begin();
            iterB++;
            iterB++;
            iterB++;

            list.Swap(iterA, iterB);

            Assert::IsTrue(list.LastNode()->value == 30);

            int arr[4] = { 10, 20, 40, 30 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }

            

        }

        TEST_METHOD(Sort_Doesnt_change_sorted_list)
        {
            LinkedList<int> list = { 10, 20, 30, 40 };
            list.Sort();

            int arr[4] = { 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

        TEST_METHOD(Sort_Sorts_unsorted_list)
        {
            LinkedList<int> list = { 20, 10, 40, 30 };
            list.Sort();

            int arr[4] = { 10, 20, 30, 40 };
            int index = 0;

            for (auto iter = list.begin(); iter != list.end(); iter++)
            {
                // de-reference iter to get its value
                // compare it against the value in our array
                Assert::AreEqual(*iter, arr[index]);
                index++;
            }
        }

        TEST_METHOD(list_deletes_nodes)
        {
            {
                LinkedList<MockClass<999>> list;
                list.PushBack(MockClass<999>());
                list.PushBack(MockClass<999>());
                list.PushBack(MockClass<999>());
                list.PushBack(MockClass<999>());
            }

            Assert::AreEqual(MockClass<999>::counter, 0);


        }
    };
}
