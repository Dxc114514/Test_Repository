
void BigInteger::add_int(BigInteger &number, const int &integer) {
    digitType carry = 0;
    number.integerPart[0] += integer;
    for (lengthType i = 0; i < number.integerLength; i++) {
        if (number.integerPart[i] + carry < 10) break;
        number.integerPart[i] += carry;
        carry = number.integerPart[i] / 10;
        number.integerPart[i] %= 10;
    }
    return;
}

BigInteger BigInteger::add_high_accur(BigInteger &number1, BigInteger &number2) {
    BigInteger result;
    digitType carry = 0;
    lengthType length = std::max(number1.integerLength, number2.integerLength);
    for (lengthType i = 0; i < length; i++) {
        result.integerPart[i] = number1.integerPart[i] + number2.integerPart[i] + carry;
        carry = result.integerPart[i] / 10;
        result.integerPart[i] %= 10;
    }
}



