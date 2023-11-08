
template <class T> int compare(const T&, const T&) {
    return -1;
}

int main() {
    // compare("hi", "world");  // cannot compare, array length diff
    compare("bye", "dad"); // ok
}