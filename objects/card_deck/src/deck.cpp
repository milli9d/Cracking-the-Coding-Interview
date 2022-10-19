/**
 * This encapsulates a card in a deck of cards
 */
#include <unordered_set>
#include <vector>
#include <memory>

#include <card_defines.hpp>
#include <deck.hpp>

namespace cpp
{

    void deck::print_deck(void)
    {
        std::unordered_set<std::shared_ptr<card>>::iterator itr = _deck.begin();

        for (itr; itr != _deck.end(); itr++)
        {
            card &card_ptr = *(itr->get());
            card_ptr.print_card();
        }
    }

    void deck::new_full_deck(void)
    {
        for (uint8_t i_t = 1u; i_t <= static_cast<uint8_t>(CARD_TYPE_MAX); i_t++) {
            for (uint8_t i_f = 1u; i_f <= static_cast<uint8_t>(CARD_FACE_MAX); i_f++) {
                std::shared_ptr<card> new_card = std::make_shared<card>(i_t, i_f);
                new_card->print_card();
                _deck.insert(new_card);
            }
            printf("Size szie %d", _deck.size());
        }
    }

    size_t deck::size(void)
    {
        return _deck.size();
    }

    deck::deck(const deck &e)
    {
        _deck.insert(e._deck.begin(), e._deck.end());
    }

    deck::deck() {}

    deck::~deck() {}
}