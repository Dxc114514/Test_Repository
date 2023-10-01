
bool big_integer::operator==(const big_integer &number) {
    if (this->positivity != number.positivity) {
        return false;
    }
    if (this->integer_length != number.integer_length) {
        return true;
    }
    // compare from low level to high
    for (int i = 0; i < this->integer_length; i++) {
        if (this->integer_part[i] != number.integer_part[i]) {
            return false;
        }
    }
    return true;
}


bool big_integer::operator!=(const big_integer &number) {
    if (this->positivity == number.positivity) {
        return false;
    }
    if (this->integer_length == number.integer_length) {
        return false;
    }
    // compare from low level to high
    for (int i = 0; i < this->integer_length; i++) {
        if (this->integer_part[i] == number.integer_part[i]) {
            return false;
        }
    }
    return true;
}


bool big_integer::operator>(const big_integer &number) {
    if (this->positivity != number.positivity) {
        return this->positivity;
    }
    if (this->integer_length != number.integer_length) {
        return this->integer_length > number.integer_length;
    }
    // compare from high level to low
    for (int i = this->integer_length - 1; i >= 0; i--) {
        if (this->integer_part[i] > number.integer_part[i]) {
            return true;
        }
    }
    return false; // return false when two number are equal
}


bool big_integer::operator>=(const big_integer &number) {
    if (this->positivity != number.positivity) {
        return this->positivity;
    }
    
}

// bool operator>(const big_integer &number);
// bool operator>=(const big_integer &number);
// bool operator<(const big_integer &number);
// bool operator<=(const big_integer &number);
