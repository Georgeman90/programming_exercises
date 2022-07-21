/**************************************************************************************************
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
**************************************************************************************************/
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <ratio>

#define DIM 10000
#define CONV_TO_MS 1000

//****************************************
//  Naive solution: O(n^2) time complexity
//****************************************
//  Consider all possible pairs and check their sums
bool isTwoElemArraySum_naive(int k, int array[], int length)
{
    // Returns if the array(second parameter) contains at least a pair which sum is given in the first parameter
    int count = 0;
    bool status = false;
    // std::unordered_map<int, int> m;
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            sum = array[i] + array[j];
            if (sum == k)
            {
                status = true;
            }
            else
                continue;
        }
    }
    return status;
}

//******************************************************************
// Efficient solution: O(n) time complexity(only when searching...)
//******************************************************************
bool isTwoElemArraySum_eff(int k, int array[], int length)
{
    int count = 0;
    bool status = false;
    int twice_count = 0;
    std::unordered_map<int, int> m;
    // Store counts of all elements in map m
    for (int i = 0; i < length; i++)
        m[array[i]]++;

    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < length; i++)
    {
        twice_count += m[k - array[i]];
        // es.: (k=17)-(array[0]=10) = 7 => m[7] = 1 => twice_count = 1
        // es.: (k=17)-(array[3]=7) = 10 => m[10] = 1 => twice_count = 1 + 1

        // if (arr[i], arr[i])
        // pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (k - array[i] == array[i])
            twice_count--; // if in the array there are more than one element equal to one another, the counter should be decreased
    }
    //(Notice that every pair is counted twice)
    twice_count /= 2;

    if (twice_count >= 1)
        status = true;

    return status;
}
//******************************************************************
// Better solution: O(n) time complexity (worst case scenario O(n^2))
//******************************************************************
bool isTwoElemArraySum_better(int k, int array[], int length)
{
    int count = 0;
    bool status = false;
    std::unordered_map<int, int> m;
    for (int i = 0; i < length; i++)
    {
        if (m.find(k - array[i]) != m.end())
        {
            count += m[k - array[i]];
        }
        m[array[i]]++;
    }

    if (count >= 1)
        status = true;

    return status;
}

// Driver function to test the above function
int main()
{
    int k = rand() % 200;
    double duration;
    int numbers[DIM];
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<double> time_span;

    for (int i = 0; i < DIM; i++)
        numbers[i] = rand() % 100;

    start = std::chrono::high_resolution_clock::now();
    if (isTwoElemArraySum_naive(k, numbers, DIM))
    {
        std::cout << "True" << std::endl;
    }
    end = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    std::cout << "The naive solution took: " << time_span.count() * CONV_TO_MS << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    if (isTwoElemArraySum_eff(k, numbers, DIM))
    {
        std::cout << "True" << std::endl;
    }
    end = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    std::cout << "The efficient solution took: " << time_span.count() * CONV_TO_MS << "ms" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    if (isTwoElemArraySum_better(k, numbers, DIM))
    {
        std::cout << "True" << std::endl;
    }
    end = std::chrono::high_resolution_clock::now();
    time_span = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    std::cout << "The better solution took: " << time_span.count() * CONV_TO_MS << "ms" << std::endl;

    return 0;
}
