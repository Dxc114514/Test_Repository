



digitType BigInteger::transCharToDec(const char &tmpChar) {
    if (isdigit(tmpChar)) {
        return int(tmpChar - '0');
    } else if (isupper(tmpChar)) {
        return int(tmpChar - 'A' + 10);
    } else if (islower(tmpChar)) {
        return int(tmpChar - 'a' + 10);
    }
    return -1;
}

void recaculateLength(const lengthType &maxLength) {
    for (lengthType i = maxLength; i >= 0; i--) {
    }
}



// namespace StdBigInteger