// with_mutex.cpp
// 2024 JAN 20

// Tershire

/* example where a shared variable is accessed by multiple threads
with a proper mutex */
// referred: https://modoocode.com/269

// command:

// comments:
/*
unlike the normal mutex,
lock_guard works fine when activated.
unique_lock also works fine.
*/


#include <iostream>
#include <thread>
#include <mutex>
#include <vector>


// PROTOTYPE ==================================================================
void counter(const int& N, int& count, bool& use_mutex, std::mutex& mutex);


// MAIN =======================================================================
int main(int argc, char **argv)
{
    // USER ===================================================================
    bool use_mutex;
    char user_input;
    std::cout << "use mutex?: ";
    std::cin >> user_input;
    if (user_input == 'y' | user_input == 'Y') {use_mutex = true;}
    else if (user_input == 'n' | user_input == 'N') {use_mutex = false;}
    else {std::cout << "what do you mean" << std::endl; return -1;}

    // set up task ------------------------------------------------------------
    const int N = 1.5E1;
    int count = 0;

    // threads
    const int NUM_THREADS = 3;

    // set up threads ---------------------------------------------------------
    // mutex
    std::mutex mutex;
    
    // vector of threads
    std::vector<std::thread> threads;
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        threads.push_back(
            std::thread(counter,
                N, std::ref(count), std::ref(use_mutex), std::ref(mutex))); // std::ref() (?)
    }

    // main thread task -------------------------------------------------------
    // print
        std::thread::id this_id = std::this_thread::get_id();
        printf("[thread %x (main)] count: %d\n", 
            this_id, count);

    // join threads -----------------------------------------------------------
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        threads[i].join();
    }

    std::cout << "count: " << count << std::endl;

    std::cout << "main ended." << std::endl;

    return 0;
}


// HELPER =====================================================================
void counter(const int& N, int& count, bool& use_mutex, std::mutex& mutex)
{
    for (int i = 0; count < N; ++i)
    {
        // if (use_mutex) {std::lock_guard<std::mutex> lock(mutex);} // or
        if (use_mutex) {std::unique_lock<std::mutex> lock(mutex);};
        
        count += 1;

        // print
        std::thread::id this_id = std::this_thread::get_id();
        printf("[thread %x] count: %d\n", 
            this_id, count);
        
        /* automatic unlock at the end of the scope
        */
    }
}
