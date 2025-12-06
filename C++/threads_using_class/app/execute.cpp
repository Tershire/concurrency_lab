// execute.h
// 2024 JAN 20

// Tershire

// command:

// comments:
/*
...
*/

#include <iostream>

#include "common.h"
#include "class1.h"
#include "class2.h"


using namespace threads_using_class;


int main(int argc, char **argv)
{
    Class1::Ptr class1 = std::make_shared<Class1>();
    Class2::Ptr class2 = std::make_shared<Class2>();

    // initiate thread ========================================================
    class1->initialize();
    class2->initialize();

    // main thread task =======================================================
    while (true)
    {
        std::cout << "-0-";
    }

    // join thread (<!> required: otherwise exception) ========================
    class1->close();
    class2->close();

    return 0;
}
