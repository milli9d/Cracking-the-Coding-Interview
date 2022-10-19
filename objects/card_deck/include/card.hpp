/**
 * This encapsulates a card in a deck of cards
 */
#pragma once

#include <card_defines.hpp>

namespace cpp
{
    class card
    {
    public:
        card(card_type_t type, card_face_t face);
        card(uint8_t type, uint8_t face);
        card();
        ~card();

        void print_card();

    private:
        card_type_t _type = card_type_t::NONE;
        card_face_t _face = card_face_t::NONE;
    };
}