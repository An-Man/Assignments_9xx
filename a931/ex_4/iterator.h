#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

const unsigned char kFirstBitMask  = 128; // 1000000
const unsigned char kSecondBitMask = 64;  // 0100000
const unsigned char kThirdBitMask  = 32;  // 0010000
const unsigned char kFourthBitMask = 16;  // 0001000
const unsigned char kFifthBitMask  = 8;   // 0000100

const unsigned int THREE_LEFT = 18;
const unsigned int TWO_LEFT = 12;
const unsigned int ONE_LEFT = 6;

class Str_Iterator
{
    public:
        using iterator_category = std::forward_iterator_tag;
        using difference_type = typename std::string::difference_type;
        using value_type = char32_t;
        using const_pointer = const char32_t*;
        using pointer = char32_t*;
        using reference = char32_t&;
        using const_reference = const char32_t&;
        using iterator = typename std::string::iterator;
        using const_iterator = typename std::string::const_iterator;
        
        Str_Iterator(iterator it) : str_it(it) {}

        Str_Iterator& operator++() {
            char first_byte = *str_it;
            difference_type offset = 1;

            if (first_byte & kFirstBitMask)
            {
                if (first_byte & kThirdBitMask)
                {
                    if (first_byte & kFourthBitMask) {
                        offset = 4;
                    } else {
                        offset = 3;
                    }
                }
                else
                {
                    offset = 2; 
                }
            }
            str_it += offset;
            return *this;
        }

        Str_Iterator operator++(int) {
            Str_Iterator temp = *this;
            ++(*this);
            return temp;
        }

        char32_t operator*() {
            char32_t codepoint = 0;
            char first_byte = *str_it;

            if (first_byte & kFirstBitMask)
            {
                if (first_byte & kThirdBitMask)
                {
                    if (first_byte & kFourthBitMask)
                    {
                        codepoint = (first_byte & 0x07) << THREE_LEFT;
                        char second_byte = *(str_it + 1);
                        codepoint += (second_byte & 0x3f) << TWO_LEFT;
                        char third_byte = *(str_it + 2);
                        codepoint += (third_byte & 0x3f) << ONE_LEFT;
                        char fourth_byte = *(str_it + 3);
                        codepoint += (fourth_byte & 0x3f); 
                    }
                    else
                    {
                        codepoint = (first_byte & 0x0f) << TWO_LEFT;
                        char second_byte = *(str_it + 1);
                        codepoint += (second_byte & 0x3f) << ONE_LEFT;
                        char third_byte = *(str_it + 2);
                        codepoint += (third_byte & 0x3f);
                    }
                }
                else
                {
                    codepoint = (first_byte & 0x1f) << ONE_LEFT;
                    char second_byte = *(str_it + 1);
                    codepoint += (second_byte & 0x3f);
                }
            }
            else
            {
                codepoint = first_byte;
            }
            return codepoint;
        }

        bool operator==(const Str_Iterator&) const = default;
        bool operator!=(const Str_Iterator& rhs) const {
            return (str_it != rhs.str_it);
        }
        bool operator==(iterator rhs) const { return str_it == rhs; }
        bool operator==(const_iterator rhs) const { return str_it == rhs; }
        bool operator!=(iterator rhs) const { return str_it != rhs; }
        bool operator!=(const_iterator rhs) const { return str_it != rhs; }
        

    private:
        iterator str_it;
};



#endif