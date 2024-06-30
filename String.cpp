#include "String.h"

String::String() noexcept : _data(nullptr), _size(0) {}

String::String(const char* a_data) noexcept : _data(new char[std::strlen(a_data) + 1]), _size(std::strlen(a_data)) {
    std::strcpy(_data, a_data);
}

String::String(const String& other) noexcept : _data(new char[other._size + 1]), _size(other._size) {
    std::strcpy(_data, other._data);
}

String::~String() noexcept {
    delete[] _data;
}

String& String::operator=(const String& other) {
    if (this != &other) {
        delete[] _data;
        _data = new char[other._size + 1];
        std::strcpy(_data, other._data);
        _size = other._size;
    }
    return *this;
}

String& String::operator+=(const String& other) {
    size_t totalSize = _size + other._size;
    char* newData = new char[totalSize + 1];
    std::strcpy(newData, _data);
    std::strcpy(newData + _size, other._data);
    delete[] _data;
    _data = newData;
    _size = totalSize;
    return *this;
}

bool String::operator==(const String & other)
{
    if(this->_size != other._size) return false;
    bool result = true;
    for(size_t i = 0 ; i < this->_size ; i++){
        if(this->_data[i] != other._data[i]){
            result = false;
            break;
        }
    }
    return result;
}

String String::operator+(const String& other) const {
    String result(*this);
    result += other;
    return result;
}

void String::reverse()
{
    for(int i = 0 ; i < this->_size / 2 ; i++)
    {
        int j = this->_size - i - 1;
        std::swap(this->_data[i],this->_data[j]);

    }
}

String String::slice(size_t start, size_t end)
{
    if(start >= end || ((end >= this->_size && end < 0)  || (start >= this->_size && start < 0)) ){
        throw std::exception();
    }
    size_t newSize = end - start + 1;
    char* newData = new char[newSize + 1];
    for (size_t i = 0; i < newSize; i++)
    {
        newData[i] = this->_data[start + i];
    }
    

    newData[newSize] = '\0';
    
    return newData;
}

String String::substr(size_t start, size_t length)
{
    if(start < this->_size && start >= 0 && start + length <= this->_size){
        char* substring = new char[length + 1];
        for(int i = 0 ; i < length ; i++){
            substring[i] = this->_data[start + i];
        }
        substring[length] = '\0';

        return substring;
    }else{
        return *this;
    }
}

char String::at(size_t index)
{
    if(index >= 0 && index < this->_size)
    {
        return this->_data[index];
    }else
    {
        throw std::out_of_range("can not access that index in (at) function");
    }
}

size_t String::find(const String & substring)
{
    if(substring._size > this->_size){
        throw std::exception();
    }else{
        for(int i = 0 ; i < this->_size - substring._size + 1 ; i++){
            if(this->substr(i , substring._size) == substring){
                return i;
            }
        }
    }

    return -1; // this is what came into my mind , i may change it later
    // full of problems


    
}

char& String::operator[](size_t index)
{
    if(index >= 0 && index < this->_size)
    {
        return this->_data[index];
    }else
    {
        throw std::out_of_range("can not access that index with [] operator");
    }
}



// char String::at(size_t index)
// {
//     if(index >= 0 && index < this->_size)
//     {
//         return this->_data[index];
//     }else
//     {
//         throw std::out_of_range("can not access that index in (at) function");
//     }
// }



const char* String::c_str() const {
    return _data;
}

size_t String::length() const {
    return _size;
}


std::ostream & operator<<(std::ostream & os, const String & s)
{
    os << s.c_str();
    return os;
}
