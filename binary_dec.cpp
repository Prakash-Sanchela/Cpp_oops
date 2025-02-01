
int binaryToDecimal(const std::string& binaryStr) {
    int num = 0;

    for (char ch : binaryStr) {
        if (ch != '0' && ch != '1') {
            throw std::invalid_argument("Invalid input: Not a binary string");
        }
        num = num * 2 + (ch - '0'); // Convert binary to decimal step by step
    }

    return num;
}
