#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// N개의 소수를 생성하는 함수
vector<int> primes(int &N) {
    vector<int> prime;
    prime.push_back(2);
    prime.push_back(3);
    for (int i = 4; i < 10000; i++) {
        int count = 0;
        for (int j = 2; j < i; j++) {
            if (i % j != 0) {
                count++;
            }
        }
        if (count == i - 2) {
            prime.push_back(i);
        }
        if (prime.size() == N) {
            break;
        }
    }
    return prime;
}

// 주어진 N 개의 소수를 사용하여 가장 긴 합성수 수열을 생성하는 함수
int solution(int N) {
    vector<int> prime = primes(N); // N개의 소수 생성
    long long index = 4; // 합성수 수열의 시작 값
    vector<long long> num; // 수열의 최소 소인수를 저장할 배열
    int temp = 0; // 현재까지의 최대 연속 합성수 수열 길이
    long long fac = 1; // N개의 소수를 모두 곱한 값

    for (int i = 0; i < prime.size(); i++) {
        fac *= prime[i]; // N개의 소수를 곱함
    }

    while (index > 3 && index <= fac) {
        int cnt = 0;
        for (int i = 0; i < prime.size();) {
            if (index % prime[i] == 0) {
                num.push_back((long long)prime[i]); // 현재 숫자의 최소 소인수를 배열에 추가
                break;
            } else {
                i++;
            }
            if (i == prime.size()) {
                int number = num.size();
                if (temp <= number) {
                    temp = number;
                    for (int j = 0; j < num.size(); j++) {
                        cout << num[j] << " ";
                    }
                    cout << "/// " << number << "(" << index - number << ")";
                    cout << endl;
                }
                num.clear(); // 배열 초기화
            }
        }
        index++;
    }
    return 1;
}

int main() {
    cout << solution(11) << endl; // 소수를 11개 사용해 만들 수 있는 가장 긴 합성수 수열
}
