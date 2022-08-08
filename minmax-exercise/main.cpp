#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    if (((sizeof(arr) / sizeof(arr[0])) - 1) == 5) {
        std::sort(std::begin(arr), std::end(arr));
        // for (int& idx : arr) {
        //     std::cout << idx << ' ';
        // }

        int min[4];
        uint64_t min_total = 0;
        for (int i = 0; i < 4; i++) {
            min[i] = arr[i];
            min_total += arr[i];
        }
        int max[4];
        uint64_t max_total = 0;
        for (int k = 1; k < 5; k++) {
            max[k] = arr[k];
            max_total += arr[k];
        }
        std::cout << min_total << " " << max_total << std::endl;
    } else {
        std::cout << "Error: Invalid number of elements" << std::endl;
        return;
    }
}

int main()
{

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
