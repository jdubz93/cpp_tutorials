/*Goal: sort students by multiple data vaule
**
**student1: Name: Joe Lime, ID#15, Grad. Date: 2019
**student2: Name: Bob Green, ID#3, Grad. Date: 2020
**student3: Name: SallyAnne Green , ID#1, Grad. Date: 2017
**student4: Name: Annie Blue, ID#10, Grad. Date: 2020
**student5: Name: Jose Lemon, ID#25, Grad. Date: 2016
*/

// #include"main.hpp"
#include<string>
#include <map>
#include <iterator>
#include <iostream> 
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

bool sortby(const std::tuple<std::string, uint32_t, uint32_t>& a,  
               const std::tuple<std::string, uint32_t, uint32_t>& b)
{   
    // return (std::get<1>(a) < std::get<1>(b));
    // return (std::tie(std::get<0>(a), std::get<1>(a), std::get<2>(b)) < std::tie(std::get<0>(b), std::get<1>(b), std::get<2>(a)));
    return ((std::tie(std::get<0>(a), std::get<1>(a), std::get<2>(a))) < (std::tie(std::get<0>(b), std::get<1>(b), std::get<2>(b))));
}

int main()
{
    //ToDo sort the students by name, then by number, then by gradDate
    // std::vector<std::string, uint32_t, uint32_t> list_of_students;
    // std::map<std::string, uint32_t, uint32_t> map_of_students;
    std::map<int, std::tuple<std::string, uint32_t, uint32_t>> map_of_students;

    struct student {
        std::string name;
        uint32_t id;
        uint32_t gradDate;
    };

    struct student s1, s2, s3, s4, s5;
    s1.name = "Joe Lime";
    s1.id = 15;
    s1.gradDate = 2019;
    // student 2
    s2.name = "Bob Green";
    s2.id = 3;
    s2.gradDate = 2020;
    // student 3
    s3.name = "SallyAnne Green";
    s3.id = 1;
    s3.gradDate = 2017;
    // student 4
    s4.name = "Annie Blue";
    s4.id = 10;
    s4.gradDate = 2020;
    // student 5
    s5.name = "Jose Lemon";
    s5.id = 25;
    s5.gradDate = 2016;

    map_of_students.insert(std::make_pair(1, std::make_tuple(s1.name, s1.id, s1.gradDate))); // Student 1
    map_of_students.insert(std::make_pair(2, std::make_tuple(s2.name, s2.id, s2.gradDate))); // Student 2
    map_of_students.insert(std::make_pair(3, std::make_tuple(s3.name, s3.id, s3.gradDate))); // Student 3
    map_of_students.insert(std::make_pair(4, std::make_tuple(s4.name, s4.id, s4.gradDate))); // Student 4
    map_of_students.insert(std::make_pair(5, std::make_tuple(s5.name, s5.id, s5.gradDate))); // Student 5
    
    std::map<int, std::tuple<std::string, uint32_t, uint32_t>>::iterator it;
    std::vector<std::tuple<std::string, uint32_t, uint32_t>> vec;

    for (it = map_of_students.begin(); it != map_of_students.end(); it++) {
        std::cout << it->first << " : " << std::get<0>(it->second) 
        << " : " << std::get<1>(it->second) << " : " << std::get<2>(it->second) << endl;

        vec.push_back(std::make_tuple(std::get<0>(it->second), std::get<1>(it->second), std::get<2>(it->second)));
    }

    std::sort(vec.begin(), vec.end(), sortby);

    std::cout << "--------------------------------" << std::endl;
    std::cout << "Sorted vector tuple (name, id, year)" << std::endl;
    std::cout << "--------------------------------" << std::endl;
    for (auto& it2 : vec) {
        std::cout << std::get<0>(it2) << " : " << std::get<1>(it2) << " : " << std::get<2>(it2) << std::endl;
    }

    return 0;
}