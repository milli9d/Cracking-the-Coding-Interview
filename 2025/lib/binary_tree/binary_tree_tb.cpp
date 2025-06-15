#include <iostream>
#include <ctime>
#include <unordered_set>

#include <binary_search_tree.hpp>

int main()
{
    printf("Linked List Testbench\n");

    ctci::binary_search_tree<int> _tree;
    std::unordered_set<int> _memo;

    srand(time(0));
    for (int i = 0; i < 50; i++) {
        int val = rand() % 50;
        _tree.insert(val);
        _memo.insert(val);
        printf("Insert val = %d\n", val);
        std::cout << _tree;
    }
    
    for (int i: _memo) {
        printf("Find val %2d\t: %s\n", i,
               _tree.find(i) != nullptr ? "TRUE" : "FALSE");
    }

    for (int i: _memo) {
        printf("Delete val %2d\t: %s\n", i,
               _tree.delete_node(i) == 0 ? "TRUE" : "FALSE");
        std::cout << _tree;
    }


    return 0;
}