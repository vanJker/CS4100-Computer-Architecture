#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <getopt.h>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

const char *test_file = nullptr;
const int K = 1024;

struct cache_content {
    bool v;
    unsigned int reference;
    unsigned int tag;
    //	unsigned int	data[16];
};

string instructions(vector<int> instrs) {
    string res = "";
    for (auto i : instrs) {
        res.append(to_string(i) + ",");
    }
    res.pop_back();
    return res;
}

void simulate(int cache_size, int block_size, int associativity) {
    int instr = 0;
    vector<int> hit, miss;

    unsigned int tag, index, x;

    int offset_bit = (int)log2(block_size);
    int index_bit = (int)log2(cache_size / block_size / associativity);
    int line = cache_size >> (offset_bit);
    int set_line = line / associativity;

    cache_content *cache = new cache_content[line];
    cout << "cache line:" << line << endl;

    for (int j = 0; j < line; j++) {
        cache[j].v = false;
        cache[j].reference = 0;
    }

    FILE *fp = fopen(test_file, "r"); // read file

    while (fscanf(fp, "%x", &x) != EOF) {
        instr++;

        cout << hex << x << " ";
        int set_index = (x >> offset_bit) & (set_line - 1);
        tag = x >> (index_bit + offset_bit);
        unsigned int lru_index = set_index;

        for (int i = 0; i < associativity; i++) {
            index = set_index + i * set_line;

            if (cache[index].reference < cache[lru_index].reference)
                lru_index = index; // LRU

            if (cache[index].v && cache[index].tag == tag) {
                cache[index].v = true; // hit
                cache[index].reference = instr;
                hit.push_back(instr);
                break;
            } else if (i == associativity - 1) {
                cache[lru_index].v = true; // miss
                cache[lru_index].tag = tag;
                cache[lru_index].reference = instr;
                miss.push_back(instr);
            }
        }
    }
    fclose(fp);

    delete[] cache;

    cout << dec << endl;
    cout << "instructions: " << instr << endl;
    cout << "Hits instructions: " << instructions(hit) << endl;
    cout << "Misses instructions: " << instructions(miss) << endl;
    cout << "Miss rate: " << (double)miss.size() * 100 / (double)instr << "%"
         << endl;
}

int main(int argc, char *argv[]) {
    assert(argc >= 3);
    int cache_size = 4;
    int block_size = 16;
    int associativity = 1;
    int opt;

    while ((opt = getopt(argc, argv, "f:c:b:a:")) != EOF) {
        switch (opt) {
        case 'f':
            test_file = optarg;
            break;
        case 'c':
            cache_size = atoi(optarg);
            assert(cache_size >= 1 && cache_size <= 256);
            break;
        case 'b':
            block_size = atoi(optarg);
            assert(block_size >= 16 && block_size <= 256);
            break;
        case 'a':
            associativity = atoi(optarg);
            assert(associativity >= 1 &&
                   associativity <= (cache_size / block_size));
            break;
        }
    }

    // Let us simulate 4KB cache with 16B blocks
    simulate(cache_size * K, block_size, associativity);
    return 0;
}