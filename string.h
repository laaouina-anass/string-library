#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>

class string {
private:
    char* _data;
    size_t _size;

public:
    string() noexcept;
    string(const char* a_data) noexcept;
    string(const string& other) noexcept;
    ~string() noexcept;

    string& operator=(const string& other);
    string& operator+=(const string& other);
    string operator+(const string& other) const;

    const char* c_str() const;
    size_t length() const;
    void print() const;
};

#endif // STRING_H
