// class1.cpp
// 2024 JAN 20

// Tershire

// command:

// comments:
/*
...
*/

#include "class1.h"


namespace threads_using_class
{

// public XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// constructor & destructor ///////////////////////////////////////////////////
Class1::Class1() {}

// member methods /////////////////////////////////////////////////////////////
bool Class1::initialize()
{
    thread_ = std::thread(&Class1::run, this);

    return true;
}

// ----------------------------------------------------------------------------
bool Class1::close()
{
    thread_.join();

    return true;
}

// ----------------------------------------------------------------------------
bool Class1::run()
{
    while (true)
    {
        std::cout << "1";
    }

    return true;
}

} // namespace threads_using_class
