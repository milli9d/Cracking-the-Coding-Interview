#include <random>
#include <chrono>


#include <card_defines.hpp>
#include <card.hpp>

namespace cpp
{
    void card::print_card()
    {
        printf("CARD: %s of %s.\n",
               card_face_to_str(_face),
               card_type_to_str(_type));
    }

    card::card(card_type_t type, card_face_t face)
        : _type(type), _face(face) {}

    card::card(uint8_t type, uint8_t face)
        : _type(static_cast<card_type_t>(type)),
          _face(static_cast<card_face_t>(face)) {}


    card::card()
    {
        uint32_t seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        srand(seed);

        while (_type == card_type_t::NONE) {
            _type = static_cast<card_type_t>((rand() + 1) % static_cast<uint8_t>(CARD_TYPE_MAX));
        }

        while (_face == card_face_t::NONE) {
            _face = static_cast<card_face_t>((rand() + 1) % static_cast<uint8_t>(CARD_FACE_MAX));
        }       
        
    }

    card::~card() {}

} // namespace cpp
