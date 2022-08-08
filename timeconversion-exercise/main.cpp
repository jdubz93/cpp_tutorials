#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
// use substr (grab the first two characters starting from (0), (2) ints range)
// use find to locate if AM or PM in string.
// use stoi (string to int)
    int hour = std::stoi(s.substr(0,2));
    size_t pos = s.find("PM");
    std::string hr;
    if (pos != std::string::npos) { // true if PM exists.
        if (hour + 12 < 24) { // add 12 to PM hours to convert to military, must be less than 24;
            hr = std::to_string(hour+12);
        } else {
            if (hour == 12)
                hr = "00"; // change 12am to 00
            // otherwise do nothing.
        }
    }

    // replace first two characters with hr, then erase PM or AM at the end.
    return s.replace(0,2,hr).erase(s.size() - 2);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";
    std::cout << "military : " << result << std::endl;

    fout.close();

    return 0;
}
