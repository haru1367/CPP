#include <iostream>

#include <windows.h>

#include <cstdlib>

#include <cmath>

#include <ctime>

using namespace std;

int main() {

	int buy = 0; //주식 구매수량

	long long buy_price = 0; // 구매한 주식의 가치

	long long sum; //현금보유량 + 주식의가치(총가치)

	srand((unsigned int)time(NULL));

	cout << "**투입자금(원) : ";

	long long Money; // 초기투입자금

	cin >> Money;

	long long save = Money;

	bool check = false;

	cout << "**투입한 주식의 현재가격 : ";

	int before_price; //초기 주식 가격

	cin >> before_price;

	sum = Money + (long long)buy * (long long)(buy_price);

	cout << "-----------------------------------------------------------------------------------------------------" << endl;

	int day = 1;

	while (true) {

		cout << "**" << day << "일째**" << endl;

		cout << "** 거래 전 ** " << endl;

		cout << "**거래전가격 : " << before_price << "원" << endl;

		cout << "**거래전보유현금 : " << Money << "원" << endl;

		cout << "**거래전보유주식수량 : " << buy << endl;

		cout << "**거래전보유주식가치 : " << (long long)buy * (long long)(before_price) << "원" << endl;

		cout << "**거래전보유총재화 : " << sum << "원" << endl;

		cout << "**거래전수익률 : " << ((double)sum - (double)save) / (double)save * (double)100 << "%" << endl;

		cout << endl << endl;
		 
		int after_price = (int)(((((double)90) + ((double)(rand() % 201) / (double)(10))) / (double)(100)) * (double)(before_price)); // 주식가격이 -10%에서 10% 까지 변동가능함.

		double rate = ((double)after_price - (double)before_price) / (double)(before_price) * (double)100;

		cout << "주식 변동률 : " << rate << "%" << endl;

		cout << endl;

		if (check == false && rate < -3.0) {

			while (Money - (long long)buy * (long long)after_price > 0) {

				buy++;

			}

			buy--;

			Money -= (long long)buy * (long long)after_price;

			check = true;

			buy_price = after_price * (long long)buy;

		}

		else if ((check == true && rate < -3.0) || (check == true && rate > 3.0)) {

			Money += (long long)buy * (long long)after_price;

			check = false;

			buy = 0;

		}

		sum = Money + (long long)(after_price) * (long long)buy;

		cout << "**거래 후 " << endl;

		cout << "**현재 주식가격 : " << after_price << "원" << endl;

		cout << "**현재 보유현금 : " << Money << "원" << endl;

		cout << "**현재 보유주식수량 : " << buy << endl;

		cout << "**현재 보유주식평가 : " << (long long)buy * (long long)after_price << "원" << endl;

		cout << "**현재 총보유재화 : " << Money + (long long)buy * (long long)after_price << "원" << endl;

		cout << "**현재 수익률 : " << (((double)(sum)-(double)(save)) / (double)(save)) * (double)(100) << "%" << endl;

		before_price = after_price;

		day++;

		cout << endl;

		cout << "--------------------------------------------------------------------------------------------------" << endl;

		if (day == 50) {
			break;
		}
		Sleep(1000 + rand() % 11);

	}

}
