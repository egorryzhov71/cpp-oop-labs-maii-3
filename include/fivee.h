#include <string>
#include <stdexcept>

class Five {
    private:
        unsigned char* data;
        size_t size;
        void checkDigit(unsigned char digit) const;

    public:
        Five();
        Five(const size_t& n, unsigned char t = 0);
        Five(const std::initializer_list <unsigned char>& t);
        Five(const std::string& t);
        Five(const Five& other);
        Five(Five&& other) noexcept;
        ~Five() noexcept;

        size_t getsize() const;
        unsigned char* getdata() const;

        Five plus(const Five& other) const;
        Five minus(const Five& other) const;
        Five copy() const;

        bool equal(const Five& other) const;
        bool less(const Five& other) const;
        bool greater(const Five& other) const;

        std::string tostring() const;

};