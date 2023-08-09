#ifndef ITERATOR_H
#define ITERATOR_H

#include <string>

template <typename Iterator>
class Str_Iterator
{
    public:
        using value_type = typename Iterator::value_type;
        using pointer = value_type*;
        using reference = value_type&;

        Str_Iterator(Iterator it) : str_ptr(&(*it)) {}

        Str_Iterator& operator++() {
            str_ptr++;
            return *this;
        }

        reference operator*() const {
            return *str_ptr;
        }

        bool operator==(const Str_Iterator&) const = default;
        bool operator!=(const Str_Iterator& rhs) const {
            return (str_ptr != rhs.str_ptr);
        }

    private:
        pointer str_ptr;
};

#endif