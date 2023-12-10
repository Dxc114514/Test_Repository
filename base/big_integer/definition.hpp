#include <bits/stdc++.h>

#define END_ON_BASE 10

typedef int lengthType;
typedef unsigned char digitType;
typedef int numberType;

/// @brief the class to storage an big integer
/// @brief it has a size of 32 bit

class BigInteger {

  public:
    bool positivity;
    lengthType integerLength;
    std::vector<digitType> integerPart;

  public:
    BigInteger();
    BigInteger(const int &number);
    BigInteger(const char *&number);
    BigInteger(const std::string &number);
    BigInteger(const BigInteger &number);

    void operator=(const int &number);
    void operator=(const BigInteger &number);
    void operator=(const std::string &number);
    void operator=(const char *&number);

    friend std::istream &operator>>(std::istream &in, BigInteger &number);
    friend std::ostream &operator<<(std::ostream &out, BigInteger &number);

    bool operator==(const BigInteger &number);
    bool operator!=(const BigInteger &number);
    bool operator>(const BigInteger &number);
    bool operator>=(const BigInteger &number);
    bool operator<(const BigInteger &number);
    bool operator<=(const BigInteger &number);

    BigInteger operator++();
    BigInteger operator+(const int &number);
    BigInteger operator+=(const int &number);
    BigInteger operator+(const BigInteger &number);
    BigInteger operator+=(const BigInteger &number);


  private:
    digitType transCharToDec(const char &tmp_char);
    void recaculateLength(const lengthType &max_length);

    void add_int(BigInteger &number, const int &integer);
    BigInteger add_high_accur(BigInteger &number1, BigInteger &number2);

    // void subtraction(BigInteger &number1,BigInteger &number2);
    // void multiplication(BigInteger &number1,BigInteger &number2);
    // void division(BigInteger &number1,BigInteger &number2);
};


class BigIntegerException : std::exception {
  private:
    const char *message;

  public:
    BigIntegerException(const char *message) : message(message){};
    ~BigIntegerException() {}
    virtual const char *what() { return message; }
};



#include "declaration/io.cpp"

#include "declaration/other.cpp"

#include "declaration/comparison_operator.cpp"

#include "declaration/arithmetic_operator.cpp"
