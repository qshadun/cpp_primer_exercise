#include <memory>
using std::shared_ptr; using std::make_shared;
#include <iostream>
using std::cout; using std::endl;

struct destination{
    unsigned id;
    explicit destination(unsigned des_id=0):id(des_id) {}
};

struct connection{
    destination *dest;
};

connection & connect(destination * d) {
    cout << "connect to " << d->id << endl;
    connection conn;
    conn.dest = d;
    return conn;
} 

void disconnect(connection conn) {
    cout << "stop connection to " << conn.dest->id << endl;
}

void end_connection(connection *p) {
    disconnect(*p);
}

int main() {
    destination d(5);
    connection c = connect(&d);
    // shared_ptr<connection> p(&c, end_connection);
    shared_ptr<connection> p1(&c, [](connection* ptr) {disconnect(*ptr);});
    return 0;
}