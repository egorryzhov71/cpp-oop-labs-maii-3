#include "/workspaces/C++/include/fivee.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

void Five::checkDigit(unsigned char digit) const{
    if (digit > 4){
        throw std::invalid_argument("Число должно быть от 0 до 4.");
    }
}


Five::Five() : size(1){
    data = new unsigned char[1];
    data[0] = 0;
}

Five::Five(const size_t& n, unsigned char t) : size(n){
    checkDigit(t);
    if (n == 0){
        data = nullptr;
        return;
    }
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i){
        data[i] = t;
    }
}

Five::Five(const std::initializer_list<unsigned char>& t) : size(t.size()) {
    if (size == 0) {
       data = nullptr;
       return;
    }
    
    data = new unsigned char[size];
    size_t i = size - 1;
    for (auto it = t.begin(); it != t.end(); ++it) {
        checkDigit(*it);
        data[i--] = *it; 
    }
}

Five::Five(const std::string& t){
    std::string trimmed = t;
    size_t start_pos = trimmed.find_first_not_of('0');
    if (start_pos == std::string::npos){
        size = 1;
        data = new unsigned char[1];
        data[0] = 0;
        return;
    }
    trimmed = trimmed.substr(start_pos);

    for (char c :  trimmed){
        if ( c < '0' || c > '4'){
            throw std::invalid_argument("Строка содержит недопустимые символы");
        }
    }

    size = trimmed.length();
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i){
        data[i] = trimmed[size - 1 - i] - '0';
    }
}

Five::Five(const Five& other) : size(other.size){
    if (size == 0){
        data = nullptr;
        return;
    }
    data = new unsigned char[size];
    for (size_t i = 0; i < size; ++i){
        data[i] = other.data[i];
    }
}

Five& Five::operator=(const Five& other) {
    if (this != &other) {
        delete[] data;
        
        size = other.size;
        if (size == 0) {
            data = nullptr;
        } else {
            data = new unsigned char[size];
            for (size_t i = 0; i < size; ++i) {
                data[i] = other.data[i];
            }
        }
    }
    return *this; 
}


Five::Five(Five&& other) noexcept : data(other.data), size(other.size) { 
    other.data = nullptr;
    other.size = 0;
}
Five::~Five() noexcept{
    delete[] data;
}
size_t Five::getsize() const{ 
    return size; 
}
unsigned char* Five::getdata() const{
    return data;
}

Five Five::plus(const Five& other) const {
    size_t max_size = std::max(size, other.size);
    Five result(max_size, 0);
    
    int carry = 0;
    for (size_t i = 0; i < max_size; ++i) {
        int digit1 = (i < size) ? data[i] : 0;
        int digit2 = (i < other.size) ? other.data[i] : 0;
        int sum = digit1 + digit2 + carry;
        result.data[i] = sum % 5;
        carry = sum / 5;
    }
    
    if (carry != 0) {
        Five new_result(max_size + 1, 0);
        for (size_t i = 0; i < max_size; ++i) {
            new_result.data[i] = result.data[i];
        }
        new_result.data[max_size] = carry;
        return new_result;
    }
    
    return result;
}

Five Five::minus(const Five& other) const {
    if (this->less(other)) {
        throw std::underflow_error("Невозможно вычесть из меньшего большее.");
    }
    
    Five result(*this);
    int borrow = 0;
    
    for (size_t i = 0; i < size; ++i) {
        int digit2 = (i < other.size) ? other.data[i] : 0;
        int diff = data[i] - digit2 - borrow;
        if (diff < 0) {
            diff += 5;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.data[i] = diff;
    }
    
    size_t new_size = size;
    while (new_size > 1 && result.data[new_size - 1] == 0) {
        new_size--;
    }
    
    if (new_size != size) {
        Five trimmed_result(new_size, 0);
        for (size_t i = 0; i < new_size; ++i) {
            trimmed_result.data[i] = result.data[i];
        }
        return trimmed_result;
    }
    
    return result;
}
Five Five::copy() const {
    return Five(*this);
}
bool Five::equal(const Five& other) const{
    for (size_t i = 0; i < size; ++i){ 
        if (data[i] != other.data[i]){
            return false;
        }
    }
    return true;
}
bool Five::less(const Five& other) const{
    if (size != other.size){
        return size < other.size;
    }
    for (int i = size - 1; i >= 0; --i){
        if (data[i] != other.data[i]){ 
            return data[i] < other.data[i];
        }
    }
    return false;
}
bool Five::greater(const Five& other) const{
    return !less(other) && !equal(other);
}
std::string Five::tostring() const{
    if (size == 0) return "0";
    std::string result;
    for (int i = size - 1; i >= 0; --i){
        result += (data[i] + '0');
    }
    return result;
}