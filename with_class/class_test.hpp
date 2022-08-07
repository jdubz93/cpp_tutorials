#include <iostream>
#include <string>

class Student {
    public:
        Student() = default;
        ~Student() = default;

        void setName(const std::string& name);
        void setId(const uint32_t& id);
        void setGradDate(const uint32_t& date);

        std::string getName() const;
        uint32_t getId() const;
        uint32_t getGradDate() const;

    private:
        std::string _name;
        uint32_t _id;
        uint32_t _date;
};