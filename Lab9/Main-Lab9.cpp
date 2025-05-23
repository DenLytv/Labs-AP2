#include <iostream>
#include <ctime>

// Function prototypes
template <typename T>
void fillArr(T* arr, const int size);

template <typename T>
void printArr(const T* arr, const int size);

template <typename T>
void quickSort(T* arr, int first, int last);

template <typename T>
void combSort(T* arr, const int size);

template <typename T>
void binaryInsertionSort(T* arr, const int size);

template <typename T>
int binarySearch(T* arr, T item, int low, int high);

template<typename T>
void insertionSort(T* arr, const int size);

int main() {
    // Seed random number generator
    srand(static_cast<unsigned>(time(nullptr)));

    int size;
    // Prompt user for array size
    while (true) {
        std::cout << "Enter size of the array: ";
        std::cin >> size;
        // Handle invalid input
        if (std::cin.fail()) {
            std::cerr << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        }
        // Handle non-positive size
        else if (size <= 0) {
            std::cerr << "Your size is <= 0" << std::endl;
        }
        // Valid input, break the loop
        else
            break;
    }

    // Allocate memory for array
    int* arr = new int[size];

    // Fill the array with random numbers
    fillArr(arr, size);

    // Print initial array
    std::cout << "Initial array: " << std::endl;
    printArr(arr, size);

    // Sort array using insertion sort
    std::cout << "After insertion sort: " << std::endl;
    insertionSort(arr, size);
    printArr(arr, size);

    // Refresh array
    std::cout << "After refresh: " << std::endl;
    fillArr(arr, size);
    printArr(arr, size);

    // Sort array using quick sort
    std::cout << "After quick sort: " << std::endl;
    quickSort(arr, 0, size - 1);
    printArr(arr, size);

    // Refresh array
    std::cout << "After refresh: " << std::endl;
    fillArr(arr, size);
    printArr(arr, size);

    // Sort array using comb sort
    std::cout << "After comb sort: " << std::endl;
    combSort(arr, size);
    printArr(arr, size);

    // Refresh array
    std::cout << "After refresh: " << std::endl;
    fillArr(arr, size);
    printArr(arr, size);

    // Sort array using binary insertion sort
    std::cout << "After binary insertionSort: " << std::endl;
    binaryInsertionSort(arr, size);
    printArr(arr, size);

    // Deallocate memory for array
    delete[] arr;
    arr = nullptr;
}

// Function to fill array with random numbers
template<typename T>
void fillArr(T* arr, const int size) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % 100; // Generate random numbers between 0 and 99
    }
}

// Function to print array elements
template<typename T>
void printArr(const T* arr, const int size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to perform insertion sort on array
template<typename T>
void insertionSort(T* arr, const int size) {
    for (size_t i = 1; i < size; i++) {
        T key = arr[i];
        size_t j;
        for (j = i - 1; j >= 0 && arr[j] > key; j--)
            arr[j + 1] = arr[j];
        arr[j + 1] = key;
    }
}

// Function to perform quick sort on array
template<typename T>
void quickSort(T* arr, int first, int last) {
    T middle = arr[(first + last) / 2];
    int left = first;
    int right = last;
    T tmp;
    do {
        while (arr[right] > middle)
            right--;
        while (arr[left] < middle)
            left++;
        if (left <= right) {
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        }
    } while (left <= right);
    if (right > first)
        quickSort(arr, first, right);
    if (left < last)
        quickSort(arr, left, last);
}

// Function to perform comb sort on array
template<typename T>
void combSort(T* arr, const int size) {
    int step = size / 1.247;
    do
    {
        for (size_t i = 0; i < size; i++)
        {
            step = (size - i) / 1.247;
            for (size_t j = 0; j < size; j++)
            {
                if (j + step >= size)
                    break;
                if (arr[j] > arr[j + step])
                {
                    std::swap(arr[j], arr[j + step]);
                }
            }
        }
    } while (step > 1);
}

// Function to perform binary search on array
template <typename T>
int binarySearch(T* arr, T item, int low, int high) {
    int mid;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (item == arr[mid])
            return mid + 1;
        else if (item > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}

// Function to perform binary insertion sort on array
template <typename T>
void binaryInsertionSort(T* arr, const int size) {
    int loc, j, k;
    T selected;

    for (int i = 1; i < size; ++i) {
        j = i - 1;
        selected = arr[i];

        // Find location where selected should be inserted
        loc = binarySearch(arr, selected, 0, j);

        // Move all elements after location to create space
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}