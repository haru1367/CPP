#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Date {
	int year_;
	int month_; // 1부터 12까지.
	int day_; // 1부터 31까지.

public:
	void SetDate(int year, int month, int date) {
		year_ = year;
		month_ = month;
		day_ = date;
	}

	void AddDay(int inc) {
		int regular_year[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
		int inregular_year[13] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 };

		if (inc > 365 || inc < 1) {
			std::cout << "범위를 초과하였습니다." << std::endl;
		}
		else {
			day_ = inregular_year[month_ - 1] + day_ + inc;
			if ((year_ % 4 || year_ % 400) && ~(year_ % 100)) { // 윤년 계산 조건

				if (day_ > 366) {
					day_ -= 366;
					year_++;
					for (int i = 0; i <= 11; i++) {
						if (regular_year[i] < day_ && regular_year[i + 1] >= day_) {
							month_ = i + 1;
							day_ = day_ - regular_year[i];
						}
					}
				}
				else {
					for (int i = 0; i <= 11; i++) {
						if (inregular_year[i] < day_ && inregular_year[i + 1] >= day_) {
							month_ = i + 1;
							day_ = day_ - inregular_year[i];
						}
					}
				}

			}
			else {
				if (day_ > 365) {
					day_ -= 365;
					year_++;
					if ((year_ % 4 || year_ % 400) && ~(year_ % 100)) {

						if (day_ > 366) {
							day_ -= 366;
							year_++;
							for (int i = 0; i <= 11; i++) {
								if (regular_year[i] < day_ && regular_year[i + 1] >= day_) {
									month_ = i + 1;
									day_ = day_ - regular_year[i];
									break;
								}
							}
						}
						else {
							for (int i = 0; i <= 11; i++) {
								if (inregular_year[i] < day_ && inregular_year[i + 1] >= day_) {
									month_ = i + 1;
									day_ = day_ - inregular_year[i];
									break;
								}
							}
						}

					}
					else {
						for (int i = 0; i <= 11; i++) {
							if (regular_year[i] < day_ && regular_year[i + 1] >= day_) {
								month_ = i + 1;
								day_ = day_ - regular_year[i];
								break;
							}
						}
					}
				}
				else {
					for (int i = 0; i <= 11; i++) {
						if (regular_year[i] < day_ && regular_year[i + 1] >= day_) {
							month_ = i + 1;
							day_ = day_ - regular_year[i];
							break;
						}
					}
				}
			}
		}
	}

	void AddMonth(int inc) {
		month_ += inc;
		if (month_ > 12) {
			int count = 0;
			while (month_ >= 1 && month_ <= 12) {
				month_ -= 12;
				count += 1;
			}
			year_ += count;
		}
	}

	void AddYear(int inc) {
		year_ += inc;
	}

	void ShowDate() {
		std::cout << "날짜 : " << year_ << " 년 " << month_ << " 월 " << day_ << " 일 " << std::endl;
	}
};

int main() {
	Date day_calculator;
	int setting_year;
	int setting_month;
	int setting_day;
	int addday;
	int addmonth;
	int addyear;

	std::cout << "Date 클래스 테스트입니다." << std::endl;
	std::cout << std::endl;

	std::cout << "날짜를 설정해주세요!" << std::endl;
	std::cout << "연도: ";
	std::cin >> setting_year;
	std::cout << "월: ";
	std::cin >> setting_month;
	std::cout << "일: ";
	std::cin >> setting_day;
	day_calculator.SetDate(setting_year, setting_month, setting_day);

	std::cout << "실행할 항목을 선택해주세요!" << std::endl;
	std::cout << "1. 일수 더하기" << std::endl;
	std::cout << "2. 월수 더하기" << std::endl;
	std::cout << "3. 년수 더하기" << std::endl;

	int user_select;
	std::cout << "선택: ";
	std::cin >> user_select;
	std::cout << std::endl;
	switch (user_select) {
	case 1:
		std::cout << std::endl;
		std::cout << "몇 일을 더할까요: ";
		std::cin >> addday;
		day_calculator.AddDay(addday);
		std::cout << std::endl;
		day_calculator.ShowDate();
		break;
	case 2:
		std::cout << std::endl;
		std::cout << "몇 월을 더할까요: ";
		std::cin >> addmonth;
		day_calculator.AddMonth(addmonth);
		std::cout << std::endl;
		day_calculator.ShowDate();
		break;
	case 3:
		std::cout << std::endl;
		std::cout << "몇 년을 더할까요: ";
		std::cin >> addyear;
		day_calculator.AddYear(addyear);
		std::cout << std::endl;
		day_calculator.ShowDate();
		break;
	default:
		return 0;
	}
	return 0;
}
