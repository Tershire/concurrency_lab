// basic_threading.cpp
// 2024 JAN 20

// Tershire

// basic threading in C++
// referred: https://modoocode.com/269

// command:


#include <iostream>
#include <thread>


// PROTOTYPE ==================================================================
void function1();
void function2();
void function3();


// MAIN =======================================================================
int main(int argc, char **argv)
{
    std::thread thread1(function1);
    std::thread thread2(function2);
    std::thread thread3(function3);

    // [1] .join()
    // thread1.join();
    // thread2.join();
    // thread3.join();

    /*
    if .join is commented:
        terminate called without an active exception
        Aborted
    */

    // [2] .detach()
    thread1.detach();
    thread2.detach();
    thread3.detach();

    std::cout << "main ended." << std::endl;

    return 0;
}


// HELPER =====================================================================
void function1()
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << "running: Thread 1" << " (i = " << i << ")" << std::endl;
    }
}

void function2()
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << "running: Thread 2" << " (i = " << i << ")" << std::endl;
    }
}

void function3()
{
    for (int i = 0; i < 7; i++)
    {
        std::cout << "running: Thread 3" << " (i = " << i << ")" << std::endl;
    }
}
