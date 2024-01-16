// CSCI 1300 Spring 2022
// Author: Shane Wierl
// Recitation: 105 – Tiffany Phan
// Homework 7 - Problem #1

#include <vector>
#include <iostream>
#include <assert>

using namespace std;

/*
Algorithm: Find the sum of all elements of a vector within desired indices.
Check if min index is less than max index
Check if indices are out of vector range
Add each element within bounds to a sum and return sum

*/

int addElements(vector<int> vec1, int min_index, int max_index)
{
    if(min_index > max_index) //Check that min index is greater than max index, return -1 if min is greater
        return -1;

    if(min_index < 0 || max_index >= vec1.size()) //Check if min and max indices are out of the size range of the vector, return -2 if out of bounds
        return -2;

    int sum = 0;
    for(int i = min_index; i <= max_index; i++) //Loop through vector and add each element to an int sum
    {
        sum += vec1[i];
    }

    return sum; // return the sum
}

int main()
{
    vector<int> vec1 = {1, 2, 4, 6, 7, 8, 66}
    int min = 2
    int max = 5
    assert(addElements(vec1, min, max) == 25)
    //Test 1 for sum
}

