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

    // create thread ==========================================================
    // thread#(pointer-to-member, object)
    std::thread thread1(&Class1::run, class1);
    std::thread thread2(&Class2::run, class2);

    // main thread task =======================================================
    while (true)
    {
        std::cout << "-0-";
    }

    // join thread (<!> required: otherwise exception) ========================
    thread1.join();
    thread2.join();

    return 0;
}
