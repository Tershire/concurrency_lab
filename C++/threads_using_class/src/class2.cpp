// class1.cpp
// 2024 JAN 20

// Tershire

// command:

// comments:
/*
...
*/

#include "class2.h"


namespace threads_using_class
{

// public XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
// constructor & destructor ///////////////////////////////////////////////////
Class2::Class2() {}

// member methods /////////////////////////////////////////////////////////////
bool Class2::initialize()
{
    thread_ = std::thread(&Class2::run, this);
    
    return true;
}

// ----------------------------------------------------------------------------
bool Class2::close()
{
    thread_.join();

    return true;
}

// ----------------------------------------------------------------------------
bool Class2::run()
{
    while (true)
    {
        std::cout << "2";
    }

    return true;
}

} // namespace threads_using_class
