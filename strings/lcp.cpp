// Longest Common Prefix
string a, b;
int i = 0, j = n;
while(j > i) {
    int mid = (i+j+1)/2;
    if(a.substr_hash(0, mid) == b.substr_hash(0, mid)) {
        i = mid;
    } else {
        j = mid - 1;
    }
}
