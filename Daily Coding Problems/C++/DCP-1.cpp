/**************************************************************************************************
Good morning! Here's your coding interview problem for today.

This problem was recently asked by Google.

Given a list of numbers and a number k, return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

Bonus: Can you do this in one pass?
**************************************************************************************************/
#include <iostream>
#include <bits/stdc++.h>

//Returns if the array(second parameter) contains at least a pair which sum is given in the first parameter
bool isTwoElemArraySum(int k, int array[], int length)
{
    int count = 0;
    bool status = false;
    std::unordered_map<int, int> m;

    //****************************************
    // Naive solution: O(n^2) time complexity
    //****************************************
    // Consider all possible pairs and check their sums
    //int sum = 0;
    //for (int i = 0; i < length; i++)
    //{
    //    for (int j = 0; j < length; j++)
    //    {
    //        sum = array[i] + array[j];
    //        if (sum == k)
    //        {
    //            status = true;
    //        }
    //        else
    //            continue;
    //    }
    //}

    //******************************************************************
    // Efficient solution: O(n) time complexity(only when searching...)
    //******************************************************************
    //int twice_count = 0; 
    // Store counts of all elements in map m
    //for (int i = 0; i < length; i++)
    //    m[array[i]]++;

    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    //for (int i = 0; i < length; i++)
    //{
    //    twice_count += m[k - array[i]]; 
        //es.: (k=17)-(array[0]=10) = 7 => m[7] = 1 => twice_count = 1
        //es.: (k=17)-(array[3]=7) = 10 => m[10] = 1 => twice_count = 1 + 1

        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
    //    if (k - array[i] == array[i])
    //        twice_count--; // if in the array there are more than one element equal to one another, the counter should be decreased
    //}
    //(Notice that every pair is counted twice)
    //twice_count /= 2;

    //if (twice_count >= 1)
    //    status = true;

    //******************************************************************
    // Better solution: O(n^2) time complexity (Find contains a for inside it's source code)
    //******************************************************************
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
    int k = 17;
    int numbers[4] = {10, 15, 3, 7};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    if (isTwoElemArraySum(k, numbers, n))
        std::cout << "True" << std::endl;

    return 0;
}
