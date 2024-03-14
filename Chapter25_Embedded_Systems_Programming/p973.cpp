#include <iostream>
#include <fstream>
#include <cstdint> // Include for uint32_t and other fixed-width types

using namespace std;

void decipher(const uint32_t *const v, uint32_t *const w, const uint32_t *const k) {
    uint32_t y = v[0];
    uint32_t z = v[1];
    uint32_t sum = 0xC6EF3720;
    const uint32_t delta = 0x9E3779B9;

    for (uint32_t n = 32; n-- > 0;) {
        z -= (y << 4 ^ y >> 5) + y ^ sum + k[sum >> 11 & 3];
        sum -= delta;
        y -= (z << 4 ^ z >> 5) + z ^ sum + k[sum & 3];
    }
    w[0] = y;
    w[1] = z;
}

int main() {
    try {
        const int nchar = 2 * sizeof(uint32_t); // Now explicitly 8 bytes
        const int kchar = 2 * nchar;            // Explicitly 16 bytes
        const string ifname = "./chapter25_trythis6_in.txt";
        const string ofname = "./chapter25_trythis6_out.txt";

        string key = "bs";
        while (key.size() < kchar)
            key += '0'; // pad key

        ifstream inf(ifname);
        ofstream outf(ofname);
        if (!inf || !outf)
            throw runtime_error("can't open file");

        // Corrected for uint32_t
        const uint32_t *k = reinterpret_cast<const uint32_t *>(key.data());

        uint32_t inptr[2];
        char outbuf[nchar + 1];
        outbuf[nchar] = 0; // terminator
        uint32_t *outptr = reinterpret_cast<uint32_t *>(outbuf);
        inf.setf(ios_base::hex, ios_base::basefield);

        while (inf >> inptr[0] >> inptr[1]) {
            decipher(inptr, outptr, k);
            outf << outbuf;
        }
    }
    catch (exception &e) {
        cerr << "Exception: " << e.what() << '\n';
    }
    catch (...) {
        cerr << "Exception\n";
    }
}
