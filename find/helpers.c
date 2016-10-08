/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
 
 /**
 *
 * functions implemented by Yevgeniya Deysner
 * j.deysner@gmail.com
 *
 */   
 
#include <cs50.h>

#include "helpers.h"

bool binarySearch(int value,int values[] , int first, int last) 
{
    while (last-first >= 0)
    {
        int middle = (last+first)/2;
        if (value==values[middle])
        {
            return true;
        }
        else if(value > values[middle])
        {
            first = middle+1;
        }
        else if(value < values[middle])
        {
            last = middle-1;
        }
    }

    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // implements a searching algorithm
    sort (values, n);
    return binarySearch(value, values, 0, n-1);
  
}

//exchanges values in positions a and b 
void change (int a, int b, int values[], int n)
{
    if (values[a] > values[b])
    {
        int temp = values[a];
        values[a] = values[b];
        values[b] = temp;
    }    
}

//sets in position a the lowest value from i to n
void scan (int a, int values[], int n)
{
    for (int i = a; i < n; i++)
    {
        change (a, i, values, n);
    }
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implements an O(n^2) sorting algorithm
    for(int i = 0; i < n; i++)
    {
        //sets in position i the lowest value from i to n
        scan (i, values, n);
    }
    return;
}