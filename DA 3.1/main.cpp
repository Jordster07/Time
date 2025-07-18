#include"Highlander.h"
#include"SuperArray.h"

void printArray(const SuperIntArray& arr, const std::string& label) {
    std::cout << label << ": ";
    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.get(i) << " ";
    }
    std::cout << "\n";
}

int main(){
    Highlander h1("Connor");
    std::cout << Highlander::speak() << "\n";
    std::cout << h1.status() << "\n";

    Highlander h2("Duncan");
    std::cout << Highlander::speak() << "\n";
    std::cout << h2.status() << "\n";


    int initialData[] = {10, 20, 30};
    SuperIntArray original(initialData, 3);

    printArray(original, "Original Array");

    SuperIntArray copy(original);

    printArray(copy, "Copied Array");

    original.change(0, 999);
    printArray(original, "Modified Original");
    printArray(copy, "Unchanged Copy");

    return 0;
}