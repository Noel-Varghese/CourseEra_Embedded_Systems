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
 * @file stats.h
 * @brief Function declarations for statistical analysis.
 *
 * This header file contains the declarations for the functions used
 * to analyze and sort an unsigned char data set.
 *
 * @author Noel Varghese
 * @date October 6, 2026
 */

#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the minimum, maximum, mean, and median.
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
                      unsigned char median);

/**
 * @brief Prints all elements of a data array.
 *
 * @param array Pointer to the data array.
 * @param counter Number of elements in the array.
 *
 * @return None.
 */
void print_array(unsigned char *array, unsigned int counter);

/**
 * @brief Finds the median value of a sorted data set.
 *
 * @param array Pointer to the sorted data array.
 * @param counter Number of elements in the array.
 *
 * @return Median value.
 */
unsigned char find_median(unsigned char *array, unsigned int counter);

/**
 * @brief Calculates the mean of a data set.
 *
 * @param array Pointer to the data array.
 * @param counter Number of elements in the array.
 *
 * @return Mean value.
 */
float find_mean(unsigned char *array, unsigned int counter);

/**
 * @brief Finds the maximum value in a data set.
 *
 * @param array Pointer to the data array.
 * @param counter Number of elements in the array.
 *
 * @return Maximum value.
 */
unsigned char find_maximum(unsigned char *array, unsigned int counter);

/**
 * @brief Finds the minimum value in a data set.
 *
 * @param array Pointer to the data array.
 * @param counter Number of elements in the array.
 *
 * @return Minimum value.
 */
unsigned char find_minimum(unsigned char *array, unsigned int counter);

/**
 * @brief Sorts a data set from largest to smallest.
 *
 * @param array Pointer to the data array.
 * @param counter Number of elements in the array.
 *
 * @return None.
 */
void sort_array(unsigned char *array, unsigned int counter);

#endif /* __STATS_H__ */
