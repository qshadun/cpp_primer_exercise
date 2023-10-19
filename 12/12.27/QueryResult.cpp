#include "QueryResult.h"

string makePlural(int cnt, const string &s, const string &postfix = "s") {
    return cnt > 1 ? s + postfix : s;
}

ostream &print(ostream &os, const QueryResult &qr) {
    os << "\"" << qr.word << "\" occurs " << qr.total << " " << makePlural(qr.total, "time") << ":\n";
    if (qr.total) {
        for (const auto &ln: *qr.lineNumers) {
            os << "(line " << ln + 1 << ")" << (*qr.lineText)[ln] << std::endl;
        }
    }
    return os;
}