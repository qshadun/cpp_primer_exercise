#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double pri) : bookNo(book), price(pri) {}
    virtual ~Quote() = default;

    string isbn() const { return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ostream &debug(ostream &os) const;

protected:
    double price;

private:
    string bookNo;
};

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double pri, size_t qty, double disc) : Quote(book, pri), min_qty(qty), discount(disc) {}

    double net_price(size_t n) const override
    {
        if (n >= min_qty)
        {
            return n * price * (1 - discount);
        }
        else
        {
            return n * price;
        }
    }
    ostream &debug(ostream &os) const override;

private:
    double min_qty;
    double discount;
};

double print_total(ostream &os, const Quote &item, size_t n)
{
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}

ostream &Quote::debug(ostream &os) const
{
    os << "bookNo=" << bookNo << ", price=" << price;
    return os;
}

ostream &Bulk_quote::debug(ostream &os) const
{
    this->Quote::debug(os) << ", min_qty=" << min_qty << ", discount=" << discount;
    return os;
}

int main()
{
    Quote basic("abc", 5.5);
    Bulk_quote bulk("abc", 5.5, 10, 0.2);
    print_total(cout, basic, 10);
    print_total(cout, bulk, 10);
    basic.debug(cout) << endl;
    ;
    bulk.debug(cout) << endl;
}