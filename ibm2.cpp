#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubjectsNumber(vector<int>& answered, vector<int>& needed, int g) {
    int n = answered.size();
    vector<int> remaining(n);

    // Calculate remaining questions to answer for each subject
    for (int i = 0; i < n; ++i) {
        remaining[i] = max(0, needed[i] - answered[i]);
    }

    // Sort remaining questions in ascending order
    sort(remaining.begin(), remaining.end());

    int count = 0;
    for (int i = 0; i < n && g >= 0; ++i) {
        if (g >= remaining[i]) {
            count++;
            g -= remaining[i];
        }
    }

    return count;
}

int main() {
    vector<int> answered = {2, 4};
    vector<int> needed = {4, 5};
    int g = 1;

    int maxSubjects = maxSubjectsNumber(answered, needed, g);
    cout << "Maximum number of subjects that can be passed: " << maxSubjects << endl;

    return 0;
}