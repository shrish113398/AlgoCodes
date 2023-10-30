#include <iostream>
#include <string>
using namespace std;

int solution(string S) {
    int N = S.length();
    int maxSymmetric = 0;

    for (int i = 0; i < N; ++i) {
        int left = i, right = N - 1;
        int numQuestionMarks = 0;

        while (left < right) {
            if (S[left] == '?' || S[right] == '?') {
                numQuestionMarks++;
            } else if (S[left] != S[right]) {
                break;
            }
            left++;
            right--;
        }

        if (left >= right) {
            int symmetricLength = N - numQuestionMarks;
            maxSymmetric = max(maxSymmetric, symmetricLength);
        }
    }

    return maxSymmetric;
}

int main() {
    string S = "<<>>????<<>>";
    int result = solution(S);
    cout << "Length of the longest symmetric substring: " << result << endl;
    return 0;
}
