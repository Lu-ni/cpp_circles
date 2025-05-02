#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
   public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    virtual ~Fixed();

    void setRawBits(int const raw);
    int getRawBits(void) const;

   private:
    static const int N_FRACTIONAL_BITS = 8;
    int raw_bits_;
    // Private members go here
};

#endif  // FIXED_HPP
