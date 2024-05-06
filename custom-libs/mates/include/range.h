class Range {
private:
    int first;
    int last;

public:
    Range(int s, int f);
    bool contains(int value);
    int size();

    class Iterator {
    private:
        int current;
    public:
        Iterator(int first);
        int operator*() const;
        Iterator& operator++();
        bool operator!=(const Iterator& other) const;
    };
    Iterator begin() const;
    Iterator end() const;
};