/*
 * Name        : Assignment 1, Topic 1
 * Author      : Michael Harris
 * Description : Various Functions for Topic 1
 * Sources     : None for Now
 */

#ifndef ASSIGNMENT_1_H
#define ASSIGNMENT_1_H

// Add any includes and using statements Here
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Definition for func to check if string is alphabetical
bool CheckAlphabetic(string message);

// Count words in a string definition
int CountWords(string message);

// Caesar Cipher Shift unless string contains non-alpha chars
bool EncryptString(string &message, int amount = 3);

// DecryptString Function unless contain non-alpha char
bool DecryptString(string &message, int amount);

// Determine average of values in array. At least size of 1
double ComputeAverage(double numbers[], int size = 1);

// Find and return smallest value in array
double FindMinValue(double numbers[], int size = 1);

// Find and return highest value in array
double FindMaxValue(double numbers[], int size = 1);

#endif
