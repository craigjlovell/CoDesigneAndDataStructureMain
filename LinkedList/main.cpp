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
}