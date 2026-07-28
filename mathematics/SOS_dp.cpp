const int MAXV = 1 << 21;

// sub_mask // usa a presença de valores na submask
vector<int> or_conv(vector<int> freq) {
    for(int len = 1; len < freq.size(); len *= 2) {
        for(int i = 0; i < freq.size(); i += 2 * len) {
            for(int j = 0; j < len; j++) {
                freq[i+j+len] += freq[i+j];
            }
        }
    }
    return freq;
}

// super_mask // tenta tirar o bit com len
vector<int> and_conv(vector<int> freq) {
    for(int len = 1; len < freq.size(); len *= 2) {
        for(int i = 0; i < freq.size(); i += 2 * len) {
            for(int j = 0; j < len; j++) {
                freq[i+j] += freq[i+j+len];
            }
        }
    }
    return freq;
}
