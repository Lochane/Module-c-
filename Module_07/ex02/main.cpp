#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i += 1)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i += 1)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return EXIT_FAILURE;
        }
    }
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << "\n";
    }   
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    delete[] mirror;//
    return EXIT_SUCCESS;
}

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	Array<int>	a(3);
// 	Array<int>	b(3);

// 	for (size_t i = 0; i < a.size(); i += 1) {
// 		std::cout << "a[" << i << "] = " << a[i] << "\n";
// 	}
// 	std::cout << std::endl;
// 	for (size_t i = 0; i < b.size(); i += 1) {
// 		std::cout << "b[" << i << "] = " << b[i] << "\n";
// 	}
// 	a[0] = 1123;
// 	a[1] = 1;
// 	a[2] = 1;
// 	std::cout << std::endl;
// 	std::cout << "AFTER FILLING A WITH 1's" << std::endl;
// 	for (size_t i = 0; i < a.size(); i += 1) {
// 		std::cout << "a[" << i << "] = " << a[i] << "\n";
// 	}
// 	std::cout << std::endl;
// 	for (size_t i = 0; i < b.size(); i += 1) {
// 		std::cout << "b[" << i << "] = " << b[i] << "\n";
// 	}
// 	b = a;

// 	std::cout << "AFTER B = A" << std::endl;
// 	for (size_t i = 0; i < a.size(); i += 1) {
// 		std::cout << "a[" << i << "] = " << a[i] << "\n";
// 	}
// 	std::cout << std::endl;
// 	for (size_t i = 0; i < b.size(); i += 1) {
// 		std::cout << "b[" << i << "] = " << b[i] << "\n";
// 	}


//     // Empty Array
//     Array<int> empty;

// 	// OUT OF BOUNDS EXCEPTION
//     try {
//         std::cout << a[a.size() + 1] << std::endl;
//     }
//     catch (std::exception& e) {
//         std::cerr << e.what() << std::endl;
//     }

// 	return EXIT_SUCCESS;
// }