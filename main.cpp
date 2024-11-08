/*
    Make a struct type named person_t which has, name, age and id members.
    Make a program to create an array of 3 persons. Then read 3 persons
    from the standard input and then sort the persons according thier ids
    and print the persons to the standard output. To sort and print use
    only pointers.
*/

#include <iostream>
#include <array>
#include <algorithm>

int constexpr num_of_persons = 3;
struct person_t
{
    std::string name;
    int age;
    int id;
};

int main()
{
    person_t *personsPtr = new person_t[num_of_persons];

    for (int i = 0; i < num_of_persons; i++)
    {
        std::cout << "PERSON " << i + 1 << ":" << std::endl;
        std::cout << "Name > ";
        std::string name;
        std::getline(std::cin, name);
        std::cout << "Age > ";
        int age;
        std::cin >> age;
        std::cin.ignore();
        std::cout << "id > ";
        int id;
        std::cin >> id;
        std::cin.ignore();
        personsPtr[i].name = name;
        personsPtr[i].age = age;
        personsPtr[i].id = id;
        std::cout << std::endl;
    }

    // sort
    for (person_t* iPtr = personsPtr; (iPtr - personsPtr) < num_of_persons - 1; iPtr++) 
    {
        // Pointer to the current struct object
        person_t* minIdPtr = iPtr;
        for (person_t* jPtr = iPtr + 1; (jPtr - personsPtr) < num_of_persons; jPtr++)
        {   
            // Set the object that has the smallest id to min
            if (jPtr->id < minIdPtr->id)
                minIdPtr = jPtr;
        }
        // If the min-pointer points to a new element (otherwise unnecessary to swap
        if (minIdPtr != iPtr)
        {
            std::swap(*minIdPtr, *iPtr);
        }
    }
    
    // print
    for (person_t* ptr = personsPtr; (ptr - personsPtr) < num_of_persons; ptr++)
    {
        std::cout << "Name\t" << ptr->name << "\nAge\t" << ptr->age << "\nid\t" << ptr->id << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

