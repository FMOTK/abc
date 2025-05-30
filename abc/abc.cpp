#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int main() {
    ifstream file("./data_prog_contest_problem_2.txt");
    if (!file.is_open()) {
        cout << "No such file!" << endl;
        return 1;
    }

    int n;
    file >> n;

    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        file >> seq[i];
    }
    file.close();

    int min_len = n + 1;
    unordered_map<int, int> count;
    int unique = 0;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        int val = seq[right];
        if (val >= 1 && val <= 26) {
            if (count[val] == 0) unique++;
            count[val]++;
        }

        while (unique == 26) {
            min_len = min(min_len, right - left + 1);

            int left_val = seq[left];
            if (left_val >= 1 && left_val <= 26) {
                count[left_val]--;
                if (count[left_val] == 0) unique--;
            }
            left++;
        }
    }

    if (min_len == n + 1) {
        cout << "NONE" << endl;
    }
    else {
        cout << min_len << endl;
    }

    return 0;
}
