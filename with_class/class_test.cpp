#include "class_test.hpp"

void Student::setName(const std::string& name) {
    _name = name;
}

void Student::setId(const uint32_t& id) {
    _id = id;
}

void Student::setGradDate(const uint32_t& date) {
    _date = date;
}

std::string Student::getName() const {
    return _name;
}

uint32_t Student::getId() const {
    return _id;
}

uint32_t Student::getGradDate() const {
    return _date;
}