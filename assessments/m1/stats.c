/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/

/**
 * @file stats.c
 * @brief Statistical analysis of an unsigned char data set.
 *
 * This file contains functions to calculate and display the minimum,
 * maximum, mean, and median values of a data set. It also provides a
 * function to sort the data from largest to smallest.
 *
 * @author Noel Varghese
 * @date October 6, 2026
 */

#include <stdio.h>
#include "stats.h"

/* Size of the data set */
#define SIZE (40)

/**
 * @brief Program entry point.
 *
 * Creates the test data set, displays it, sorts it, calculates all
 * required statistics, displays the sorted data, and prints the results.
 *
 * @return 0 when the program completes successfully.
 */
int main(void)
{
    unsigned char test[SIZE] = {
        34, 201, 190, 154, 8, 194, 2, 6,
        114, 88, 45, 76, 123, 87, 25, 23,
        200, 122, 150, 90, 92, 87, 177, 244,
        201, 6, 12, 60, 8, 2, 5, 67,
        7, 87, 250, 230, 99, 3, 100, 90
    };

    unsigned char minimum = 0;
    unsigned char maximum = 0;
    unsigned char median = 0;
    float mean = 0.0f;

    printf("Array before sorting:\n");
    print_array(test, SIZE);

    /* Sort before calculating the median. */
    sort_array(test, SIZE);

    median = find_median(test, SIZE);
    mean = find_mean(test, SIZE);
    maximum = find_maximum(test, SIZE);
    minimum = find_minimum(test, SIZE);

    printf("Array after sorting:\n");
    print_array(test, SIZE);

    print_statistics(minimum, maximum, mean, median);

    return 0;
}

/**
 * @brief Prints the calculated statistics.
 *
 * @param minimum Minimum value in the data set.
 * @param maximum Maximum value in the data set.
 * @param mean Mean value of the data set.
 * @param median Median value of the data set.
 *
 * @return None.
 */
void print_statistics(unsigned char minimum,
                      unsigned char maximum,
                      float mean,
                      unsigned char median)
{
    printf("The minimum is %d\n", minimum);
    printf("The maximum is %d\n", maximum);
    printf("The mean is %f\n", mean);
    printf("The median is %d\n", median);
}

/**
 * @brief Prints every element of a data array.
 *
 * @param array Pointer to the unsigned char data array.
 * @param counter Number of elements in the array.
 *
 * @return None.
 */
void print_array(unsigned char *array, unsigned int counter)
{
    unsigned int i;

    for (i = 0; i < counter; i++)
    {
        printf("%d,", *(array + i));
    }

    printf("\n\n");
}

/**
 * @brief Finds the median value of a sorted data set.
 *
 * For an even-sized data set, the median is the average of the two
 * middle values. The result is rounded down because the function
 * returns an unsigned char.
 *
 * @param array Pointer to the sorted unsigned char data array.
 * @param counter Number of elements in the array.
 *
 * @return Median value of the data set.
 */
unsigned char find_median(unsigned char *array, unsigned int counter)
{
    unsigned char median = 0;

    if (counter == 0)
    {
        return 0;
    }

    if ((counter % 2) == 0)
    {
        median = (unsigned char)(
            (array[(counter / 2) - 1] + array[counter / 2]) / 2
        );
    }
    else
    {
        median = array[counter / 2];
    }

    return median;
}

/**
 * @brief Calculates the mean of the data set.
 *
 * The sum is accumulated using an unsigned integer to avoid overflow
 * from adding multiple unsigned char values. The result is returned as
 * a float.
 *
 * @param array Pointer to the unsigned char data array.
 * @param counter Number of elements in the array.
 *
 * @return Mean value of the data set.
 */
float find_mean(unsigned char *array, unsigned int counter)
{
    unsigned int accumulator = 0;
    unsigned int i;

    if (counter == 0)
    {
        return 0.0f;
    }

    for (i = 0; i < counter; i++)
    {
        accumulator += array[i];
    }

    return accumulator / (float)counter;
}

/**
 * @brief Finds the maximum value in the data set.
 *
 * @param array Pointer to the unsigned char data array.
 * @param counter Number of elements in the array.
 *
 * @return Maximum value in the data set.
 */
unsigned char find_maximum(unsigned char *array, unsigned int counter)
{
    unsigned char maximum;
    unsigned int i;

    if (counter == 0)
    {
        return 0;
    }

    maximum = array[0];

    for (i = 1; i < counter; i++)
    {
        if (array[i] > maximum)
        {
            maximum = array[i];
        }
    }

    return maximum;
}

/**
 * @brief Finds the minimum value in the data set.
 *
 * @param array Pointer to the unsigned char data array.
 * @param counter Number of elements in the array.
 *
 * @return Minimum value in the data set.
 */
unsigned char find_minimum(unsigned char *array, unsigned int counter)
{
    unsigned char minimum;
    unsigned int i;

    if (counter == 0)
    {
        return 0;
    }

    minimum = array[0];

    for (i = 1; i < counter; i++)
    {
        if (array[i] < minimum)
        {
            minimum = array[i];
        }
    }

    return minimum;
}

/**
 * @brief Sorts the data set from largest to smallest.
 *
 * Uses a simple bubble-sort approach and places the largest value
 * at index zero and the smallest value at the final index.
 *
 * @param array Pointer to the unsigned char data array.
 * @param counter Number of elements in the array.
 *
 * @return None.
 */
void sort_array(unsigned char *array, unsigned int counter)
{
    unsigned int i;
    unsigned int j;
    unsigned char temp;

    if (counter < 2)
    {
        return;
    }

    for (i = 0; i < counter - 1; i++)
    {
        for (j = 0; j < counter - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
