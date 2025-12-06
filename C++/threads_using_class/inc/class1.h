// class1.h
// 2024 JAN 20

// Tershire

// command:

// comments:
/*
...
*/

#ifndef THREADSUSINGCLASS_CLASS1_H
#define THREADSUSINGCLASS_CLASS1_H

#include "common.h"


namespace threads_using_class
{

/**
 *
 */
class Class1
{
public:
    typedef std::shared_ptr<Class1> Ptr;

    // constructor & destructor ///////////////////////////////////////////////
    Class1();

    // member methods /////////////////////////////////////////////////////////
    bool initialize();
    bool close();

    bool run();

private:
    // member data ////////////////////////////////////////////////////////////
    std::thread thread_;

    // member methods /////////////////////////////////////////////////////////
    // bool task();
};

} // namespace threads_using_class

#endif // THREADSUSINGCLASS_CLASS1_H
