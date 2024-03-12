#include "MinHeap.cpp"

int main() {
    // Testprogram 
    std::vector<int> testArray = {4, 10, 3, 5, 1};

    // Udskriv oprindeligt array
    std::cout << "Oprindeligt array: ";
    for (const auto& element : testArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Anvend heapsort på arrayet
    std::vector<int> sortedArray = heapsort(testArray);

    // Udskriv det sorterende array
    std::cout << "Sorteret array: ";
    for (const auto& element : sortedArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}