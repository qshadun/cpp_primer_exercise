#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
#include <algorithm>

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

class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string &book, double pri, size_t qty, double disc) : Quote(book, pri),  quantity(qty), discount(disc) {}

    double net_price(size_t n) const override = 0;

    ostream &debug(ostream &os) const override;
protected:
    size_t quantity;
    double discount;
};

class Bulk_quote : public Disc_quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double pri, size_t qty, double disc) : Disc_quote(book, pri, qty, disc) {}

    double net_price(size_t n) const override
    {
        if (n >= quantity)
        {
            return n * price * (1 - discount);
        }
        else
        {
            return n * price;
        }
    }

};

class Limit_quote : public Disc_quote
{
public:
    Limit_quote() = default;
    Limit_quote(const string &book, double pri, size_t qty, double disc) : Disc_quote(book, pri, qty, disc) {}

    double net_price(size_t n) const override
    {
        size_t discounted = std::min(n, quantity);
        size_t undiscounted = n - discounted;
        return discounted * price * (1 - discount) + undiscounted * price;
        
    }

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

ostream &Disc_quote::debug(ostream &os) const
{
    this->Quote::debug(os) << ", quantity=" << quantity << ", discount=" << discount;
    return os;
}

int main()
{
    Quote basic("basic", 5.5);
    Bulk_quote bulk("bulk", 5.5, 10, 0.2);
    Limit_quote limit("limit", 5.5, 10, 0.2);
    print_total(cout, basic, 20);
    print_total(cout, bulk, 20);
    print_total(cout, limit, 20);
    basic.debug(cout) << endl;
    bulk.debug(cout) << endl;
    limit.debug(cout) << endl;
    // Disc_quote disc("aaaa", 10.5, 5, 0.2); // variable type 'Disc_quote' is an abstract class
}