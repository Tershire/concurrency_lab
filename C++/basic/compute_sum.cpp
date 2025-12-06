// compute_sum.cpp
// 2024 JAN 20

// Tershire

// calculate the sum of a set: {x | [1, given_number]) using multiple threads
// referred: https://modoocode.com/269

// command:


#include <iostream>
#include <thread>
#include <vector>


// PROTOTYPE ==================================================================
void adder(const std::vector<int>& numbers, const int& start_index, const int& end_index, int* result);


// MAIN =======================================================================
int main(int argc, char **argv)
{
    // set up task ------------------------------------------------------------
    const int N = 100;

    // whole set of numbers
    std::vector<int> numbers;
    for (int i = 1; i < N + 1; ++i)
    {
        numbers.push_back(i);
    }
    // std::cout << numbers.size() << std::endl;

    // threads
    const int NUM_THREADS = 3;
    
    // partial sums of the set
    std::vector<int> partial_sums(NUM_THREADS);

    // set up threads ---------------------------------------------------------
    const int NUM_NUMBERS_PER_PART = numbers.size()/NUM_THREADS;

    // vector of threads
    std::vector<std::thread> threads;
    int start_index, end_index;
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        start_index = i*NUM_NUMBERS_PER_PART;
        end_index = (i + 1)*NUM_NUMBERS_PER_PART;
        if (i == NUM_THREADS - 1)
        {
            end_index = numbers.size();
        }
        // std::cout << "(" << start_index << ", " << end_index << ")" << std::endl;

        threads.push_back(
            std::thread(adder, 
                numbers, start_index, end_index, &partial_sums[i]));
    }

    // join threads -----------------------------------------------------------
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        threads[i].join();
    }

    // compute the total ------------------------------------------------------
    int total = 0;
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        total += partial_sums[i];
    }
    std::cout << "total: " << total << std::endl;

    std::cout << "main ended." << std::endl;

    return 0;
}


// HELPER =====================================================================
// pass the result using pointer
void adder(const std::vector<int>& numbers, const int& start_index, const int& end_index, int* result)
{
    int sum = 0;
    for (int i = start_index; i < end_index; ++i)
    {
        sum += numbers[i];
    }
    // std::cout << sum << std::endl;

    // pass the result
    *result = sum;

    // print
    std::thread::id this_id = std::this_thread::get_id();
    printf("[thread %x] result of the sum from %d to %d: %d\n", 
        this_id, numbers[start_index], numbers[end_index - 1], sum);
}
