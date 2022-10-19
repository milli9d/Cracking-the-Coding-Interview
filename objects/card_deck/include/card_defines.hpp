#pragma once

#include <cstdint>
#include <string>
#include <cstdlib>

namespace cpp
{
    #define CARD_TYPE_MAX (card_type_t::DIAMOND)
    #define CARD_FACE_MAX (card_face_t::KING)  



    typedef enum class card_type_e : uint8_t
    {
        NONE = 0x0u,
        HEART = 0x01u,
        CLUB = 0x02u,
        SPADE = 0x03u,
        DIAMOND = 0x04u
    } card_type_t;

    constexpr const char* card_type_to_str(card_type_t e) throw()
    {
        switch (e)
        {
        case (card_type_t::NONE):
            return "None";
        case (card_type_t::HEART):
            return "Heart";
        case (card_type_t::CLUB):
            return "Club";
        case (card_type_t::SPADE):
            return "Spade";
        case (card_type_t::DIAMOND):
            return "Diamond";
        default:
            return "unknown";
        }
    }

    typedef enum class card_face_e : uint8_t
    {
        NONE = 00u,
        ACE = 01u,
        JACK = 11u,
        QUEEN = 12u,
        KING = 13u
    } card_face_t;

    constexpr const char* card_face_to_str(card_face_t e) throw();

    constexpr const char* card_face_to_str(card_face_t e) throw()
    {
        switch (e)
        {
        case (card_face_t::NONE):
            return "None";
        case (card_face_t::ACE):
            return "Ace";
        case static_cast<card_face_t>((static_cast<uint8_t>(card_face_t::ACE) + 1u)) ... static_cast<card_face_t>(static_cast<uint8_t>(card_face_t::JACK) - 1u):
            {
                char* str = new char(3);
                snprintf(str, sizeof(str), "%d", static_cast<uint8_t>(e));
                return const_cast<char*>(str);
            }
        case (card_face_t::JACK):
            return "Jack";
        case (card_face_t::QUEEN):
            return "Queen";
        case (card_face_t::KING):
            return "King";
        default:
            return "unknown";
        }
    }



}