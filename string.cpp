#include "string.h"

string::string() noexcept : _data(nullptr), _size(0) {}

string::string(const char* a_data) noexcept : _data(new char[std::strlen(a_data) + 1]), _size(std::strlen(a_data)) {
    std::strcpy(_data, a_data);
}

string::string(const string& other) noexcept : _data(new char[other._size + 1]), _size(other._size) {
    std::strcpy(_data, other._data);
}

string::~string() noexcept {
    delete[] _data;
}

string& string::operator=(const string& other) {
    if (this != &other) {
        delete[] _data;
        _data = new char[other._size + 1];
        std::strcpy(_data, other._data);
        _size = other._size;
    }
    return *this;
}

string& string::operator+=(const string& other) {
    size_t totalSize = _size + other._size;
    char* newData = new char[totalSize + 1];
    std::strcpy(newData, _data);
    std::strcpy(newData + _size, other._data);
    delete[] _data;
    _data = newData;
    _size = totalSize;
    return *this;
}

string string::operator+(const string& other) const {
    string result(*this);
    result += other;
    return result;
}

const char* string::c_str() const {
    return _data;
}

size_t string::length() const {
    return _size;
}

void string::print() const {
    std::cout << _data;
}
