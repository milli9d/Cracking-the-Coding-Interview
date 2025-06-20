#include <iostream>
#include <ctime>

#include <linked_list.hpp>

int main()
{
    printf("Linked List Testbench\n");
    ctci::linked_list<int> list{};
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        list.push_front(val);
        std::cout << list << std::endl;
        printf("Push front %2d sz : %zu\n", val, list.size());
    }

    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        list.push_back(val);
        std::cout << list << std::endl;
        printf("Push back  %2d sz : %zu\n", val, list.size());
    }

    std::cout << list << std::endl;
    list.reverse();
    std::cout << "Reversed\n" << list << "\n\n\n";

    for (int i = 0; i < 10; i++) {
        int val = list.front();
        list.pop_front();
        std::cout << list << std::endl;
        printf("Pop front %d sz : %zu\n", val, list.size());
    }

    for (int i = 0; i < 10; i++) {
        int val = list.back();
        list.pop_back();
        std::cout << list << std::endl;
        printf("Pop back  %d sz : %zu\n", val, list.size());
    }

    std::cout << list << std::endl;
    list.insert(1, 200);
    list.insert(0, 100);
    for (int i = 0; i < 10; i++) {
        list.insert(1, i);
    }

    std::cout << list << std::endl;

    list.remove(0u);
    list.remove(list.size() / 2u);
    list.remove(list.size() - 1u);

    std::cout << list << std::endl;

    return 0;
}