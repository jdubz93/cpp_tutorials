
#include "class_test.hpp"


int main(int argc, char** argv) {
    Student s1;
    s1.setName("bob");
    s1.setId(1);
    s1.setGradDate(2022);

    std::cout << "Name : " << s1.getName() << std::endl;
    std::cout << "ID : " << s1.getId() << std::endl;
    std::cout << "Grad Date : " << s1.getGradDate() << std::endl;

    return 0;
}