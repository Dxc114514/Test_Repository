
namespace StdBigInteger {
    

bool BigInteger::operator==(const BigInteger &number) {
    if (this->positivity != number.positivity) {
        return false;
    }
    if (this->integerLength != number.integerLength) {
        return true;
    }
    // compare from low level to high
    for (int i = 0; i < this->integerLength; i++) {
        if (this->integerPart[i] != number.integerPart[i]) {
            return false;
        }
    }
    return true;
}


bool BigInteger::operator!=(const BigInteger &number) {
    if (this->positivity == number.positivity) {
        return false;
    }
    if (this->integerLength == number.integerLength) {
        return false;
    }
    // compare from low level to high
    for (int i = 0; i < this->integerLength; i++) {
        if (this->integerPart[i] == number.integerPart[i]) {
            return false;
        }
    }
    return true;
}


bool BigInteger::operator>(const BigInteger &number) {
    if (this->positivity != number.positivity) {
        return this->positivity;
    }
    if (this->integerLength != number.integerLength) {
        return this->integerLength > number.integerLength;
    }
    // compare from high level to low
    for (int i = this->integerLength - 1; i >= 0; i--) {
        if (this->integerPart[i] > number.integerPart[i]) {
            return true;
        }
    }
    return false; // return false when two number are equal
}


bool BigInteger::operator<(const BigInteger &number) {
    if (this->positivity != number.positivity) {
        return number.positivity;
    }
    if (this->integerLength != number.integerLength) {
        return this->integerLength < number.integerLength;
    }
    for (int i = this->integerLength - 1; i >= 0; i--) {
        if (this->integerPart[i] < number.integerPart[i]) {
            return true;
        }
    }
    return false; // return false when two number are equal
}


bool BigInteger::operator>=(const BigInteger &number) {
    // positive and zero is greater/equal than negative
    if (this->positivity != number.positivity) {
        return this->positivity;
    }
    if (this->integerLength != number.integerLength) {
        return this->integerLength >= number.integerLength;
    }
    for (int i = this->integerLength - 1; i >= 0; i--) {
        if (this->integerPart[i] > number.integerPart[i]) {
            return true;
        }
    }
    return true; // return true when two number are equal
}


bool BigInteger::operator<=(const BigInteger &number) {
    if (this->positivity != number.positivity) {
        return number.positivity;
    }
    if (this->integerLength != number.integerLength) {
        return this->integerLength <= number.integerLength;
    }
    for (int i = this->integerLength - 1; i >= 0; i--) {
        if (this->integerPart[i] < number.integerPart[i]) {
            return true;
        }
    }
    return true; // return true when two number are equal
}


}; // namespace BigInteger