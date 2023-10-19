struct Y;

struct X
{
    Y *y;
};

struct Y
{
    X x;
};

int main()
{
    X x;
    Y y;
    y.x = x;
    x.y = &y;
    return 0;
}