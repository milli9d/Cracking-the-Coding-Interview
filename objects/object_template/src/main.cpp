#include <cstdio>

#include <card.hpp>
#include <deck.hpp>
#include <card_defines.hpp>


int main()
{   
    printf("Hello World\n");
    cpp::deck new_game;
    new_game.new_full_deck();
    new_game.print_deck();

    cpp::deck copy = new_game;
    copy.print_deck();
    printf("Size %d %d", new_game.size(), copy.size());
    return 0;
}