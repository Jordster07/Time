#include "SuperArray.h"
#include<iostream>

SuperIntArray::SuperIntArray(){
    nums = nullptr;
    numberOfNums = 0;
}

SuperIntArray::SuperIntArray(int nums[], int size){
numberOfNums = size;
this->nums = new int[size];

for(int i=0; i < size; ++i){
    this->nums[i]=nums[i];
}
}

SuperIntArray::SuperIntArray(int num) {
    numberOfNums = num;
    nums = new int[num];
    for (int i = 0; i < num; ++i) {
        nums[i] = 0;
    }
}

SuperIntArray::SuperIntArray(std::vector<int> numsV) {
    numberOfNums = numsV.size();
    nums = new int[numberOfNums];
    for (int i = 0; i < numberOfNums; ++i) {
        nums[i] = numsV[i];
    }
}

SuperIntArray::SuperIntArray(const SuperIntArray& other) {
    numberOfNums = other.numberOfNums;
    nums = new int[numberOfNums];

    for (int i = 0; i < numberOfNums; ++i) {
        nums[i] = other.nums[i];
    }
}

SuperIntArray::~SuperIntArray(){
    delete[] nums;
}
int* SuperIntArray::getNums() const {
    return nums;
}

int SuperIntArray::getSize() const {
    return numberOfNums;
}

void SuperIntArray::setNums(int numsArr[], int size) {
    numberOfNums = size;
    nums = new int[size];
    for (int i = 0; i < size; ++i) {
        nums[i] = numsArr[i];
    }
}

void SuperIntArray::add(int num) {
    int* newArray = new int[numberOfNums + 1];
    for (int i = 0; i < numberOfNums; ++i) {
        newArray[i] = nums[i];
    }
    newArray[numberOfNums] = num;
    delete[] nums;
    nums = newArray;
    ++numberOfNums;
}

int SuperIntArray::get(int index) const {
    if (index >= 0 && index < numberOfNums) {
        return nums[index];
    } else {
        std::cout << "Index out of bounds.\n"; 
        return -1;
    }
}

void SuperIntArray::change(int index, int num) {
    if (index >= 0 && index < numberOfNums) {
        nums[index] = num;
    } else {
        std::cout << "Index out of bounds.\n"; 
    }
}

int SuperIntArray::getMax(int nums[], int size) {
    if (size <= 0) return -1;
    int maxVal = nums[0];
    for (int i = 1; i < size; ++i) {
        if (nums[i] > maxVal) maxVal = nums[i];
    }
    return maxVal;
}

int SuperIntArray::getMin(int nums[], int size) {
    if (size <= 0) return -1;
    int minVal = nums[0];
    for (int i = 1; i < size; ++i) {
        if (nums[i] < minVal) minVal = nums[i];
    }
    return minVal;
}

double SuperIntArray::getMean(int nums[], int size) {
    if (size <= 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
    }
    return static_cast<double>(sum) / size;
}