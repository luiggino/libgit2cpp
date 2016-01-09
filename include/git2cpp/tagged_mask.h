#pragma once

namespace git
{
    template<class Tag, class RawType = unsigned int>
    struct tagged_mask_t
    {
        typedef tagged_mask_t self_t;

        explicit tagged_mask_t(RawType value)
            : value_(value)
        {}

        RawType value() const { return value_; }

        operator bool() const { return value_; }

        friend self_t operator ~ (self_t x) { return self_t(~x.value_); }

        friend self_t operator | (self_t x, self_t y) { return self_t(x.value_ | y.value_); }
        friend self_t operator & (self_t x, self_t y) { return self_t(x.value_ & y.value_); }
        friend self_t operator ^ (self_t x, self_t y) { return self_t(x.value_ ^ y.value_); }

    private:
        RawType value_;
    };
}