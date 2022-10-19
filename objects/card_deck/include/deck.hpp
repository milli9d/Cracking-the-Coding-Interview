/**
 * This encapsulates a card in a deck of cards
 */
#pragma once

#include <unordered_set>
#include <vector>
#include <memory>


#include <card_defines.hpp>
#include <card.hpp>

namespace cpp
{
    class deck
    {
    public:
        deck();
        ~deck();
        deck(const deck& e);

        bool is_empty();
        size_t size();

        void print_deck(void);
        void new_full_deck(void);

    private:
        /* private members */
        std::unordered_set<std::shared_ptr<card>> _deck;

        /* private functions */
    
    };
}