#ifndef STRING_H
#define STRING_H

#include <cstring>
#include <iostream>

class String {
private:
    char* _data;
    size_t _size;

public:
    /// CONSTRUCTORS /////
    String() noexcept;
    String(const char* a_data) noexcept;
    String(const String& other) noexcept;
    // deconstructor
    ~String() noexcept;

    //// OPERATORS ///////
    String& operator=(const String& other);
    String& operator+=(const String& other);
    char& operator[](size_t index);
    bool operator == (const String& other);
    String operator+(const String& other) const;

    /// FUNCTIONS ////////
    void reverse();
    String slice(size_t start , size_t end);
    String substr(size_t start , size_t length);
    const char* c_str() const;
    size_t length() const;
    char at(size_t index);
    size_t find(const String& substring);


    friend std::ostream& operator<<(std::ostream& os, const String& s);
};

#endif // STRING_H
