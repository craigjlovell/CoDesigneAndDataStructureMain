#include <iostream>
#include "LinkedList.h"
int main(int argc, char** argv)
{
    LinkedList<int> myList = {30, 10, 20, 30, 50, 50, 60, 40, 80, 90, 100, 30 };

    auto iter = std::find(myList.begin(), myList.end(), 10);
    myList.Insert(iter, 15);
    myList.Sort();

    for (auto iter = myList.begin(); iter != myList.end();)
    {
        // we want to remove all occurences of 99
        if (*iter == 30)
        {
            // remove the node - update iter so that its pointing
            // at the next valid item
            iter = myList.Remove(iter);         
        }
        else
        {
            // if we didnt remove, we can move to the next item
            iter++;
        }        
    }

    
    for (auto& value : myList)
    {
        std::cout << value << std::endl;
    }
    
    /*

    LinkedList<int> myList = { 10, 20, 30, 40, 30, 50, 60 };
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.PushBack(70);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;

    myList.PushFront(5);
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 8" << std::endl;

    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 7" << std::endl;

    myList.PopFront();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 6" << std::endl;

    myList.Remove(std::find(myList.begin(), myList.end(), 30));
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 5" << std::endl;

    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    myList.PopBack();
    std::cout << "Count: " << myList.Count() << "\t\t Expected: 0" << std::endl;
    */
}