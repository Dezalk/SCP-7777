#include <iostream>
#include "scp_7777.hxx"

int main() {
    for (std::size_t i = 0; const std::string& instance : scp_7777::instances) {
        i++;
        if (instance[0] != '[') {
            std::cout << "[Instance " << i << "]\n";
            std::string encoded = scp_7777::encode(instance, 0x7777, 0x7777);
            std::string decoded = scp_7777::decode(encoded);
            std::cout << "Original (" << instance.length() << " ch) :\t" << instance << '\n';
            std::cout << "Encoded (" << encoded.length() << " ch) :\t" << encoded << '\n';
            std::cout << "Decoded (" << decoded.length() << " ch) :\t" << decoded << "\n\n";
        }
    }
}
