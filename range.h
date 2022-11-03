#ifndef RANGE_HEADER_FILE
#define RANGE_HEADER_FILE

class Iterator
{
    int pos = 0;

public:
    Iterator(int pos = 0)
    {
        this->pos = pos;
    }

    int operator*()
    {
        return pos;
    }

    Iterator &operator++()
    {
        return *this;
    }
    bool operator!=(const Iterator &other)
    {
        return pos != other.pos;
    }
};

class Range
{
    int a;
    int b;

public:
    Range(int from, int to, int step = 1)
    {
        a = from;
        b = to;
    }
    Iterator begin()
    {
        return Iterator(a);
    }
    Iterator end()
    {
        return Iterator(b);
    }
};

#endif