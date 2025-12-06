// class2.h
// 2024 JAN 20

// Tershire

// command:

// comments:
/*
...
*/

#ifndef THREADSUSINGCLASS_CLASS2_H
#define THREADSUSINGCLASS_CLASS2_H

#include "common.h"


namespace threads_using_class
{

/**
 *
 */
class Class2
{
public:
    typedef std::shared_ptr<Class2> Ptr;

    // constructor & destructor ///////////////////////////////////////////////
    Class2();

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

#endif // THREADSUSINGCLASS_CLASS2_H
