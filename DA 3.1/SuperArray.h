#ifndef SUPER_ARRAY
#define SUPER_ARRAY
#include<vector>

class SuperIntArray{
private:
    int* nums;
    int numberOfNums;
public:   
    SuperIntArray();
    SuperIntArray(int nums[],int size);
    SuperIntArray(int num);
    SuperIntArray(std::vector<int> nums);
    ~SuperIntArray();
    SuperIntArray(const SuperIntArray& other);
    int* getNums() const;
    int getSize() const;
    void setNums(int nums[], int size);
    void add(int num);              
    int get(int index) const;     
    void change(int index, int num); 
    SuperIntArray& operator=(const SuperIntArray& right);
    SuperIntArray operator+(const SuperIntArray& right);
    int& operator[](int index);
    friend std::ostream& operator<<(std::ostream& stream, SuperIntArray& right);

    static int getMax(int nums[], int size);
    static int getMin(int nums[], int size);
    static double getMean(int nums[], int size);

};



#endif