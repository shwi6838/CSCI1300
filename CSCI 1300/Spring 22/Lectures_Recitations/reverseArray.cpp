#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void swap(int myArray[], int startIndex, int endIndex)
{
    int n = myArray[startIndex];
    int m = myArray[endIndex];
    myArray[startIndex] = m;
    myArray[endIndex] = n;
}

void reverseArray (int myArray[], int myArrayLength)
{
    for(int i = 0; i < myArrayLength/2; i++)
    {
        swap(myArray, i, myArrayLength-i-1);
        //cout << i << endl;
        //cout << myArrayLength-i << endl;
    }
}

int main()
{
    int numbers[6] = {1,2,3,4,5,6};
    reverseArray(numbers, 6);
    
    int i=0;
    while(i < 6)
    {
        cout << numbers[i] << endl;
        i++;
    }
}
