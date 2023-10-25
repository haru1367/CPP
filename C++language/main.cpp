#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Date {
	int year_;
	int month_; // 1���� 12����.
	int day_; // 1���� 31����.

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
			std::cout << "������ �ʰ��Ͽ����ϴ�." << std::endl;
		}
		else {
			day_ = inregular_year[month_ - 1] + day_ + inc;
			if ((year_ % 4 || year_ % 400) && ~(year_ % 100)) { // ���� ��� ����

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
		std::cout << "��¥ : " << year_ << " �� " << month_ << " �� " << day_ << " �� " << std::endl;
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

	std::cout << "Date Ŭ���� �׽�Ʈ�Դϴ�." << std::endl;
	std::cout << std::endl;

	std::cout << "��¥�� �������ּ���!" << std::endl;
	std::cout << "����: ";
	std::cin >> setting_year;
	std::cout << "��: ";
	std::cin >> setting_month;
	std::cout << "��: ";
	std::cin >> setting_day;
	day_calculator.SetDate(setting_year, setting_month, setting_day);

	std::cout << "������ �׸��� �������ּ���!" << std::endl;
	std::cout << "1. �ϼ� ���ϱ�" << std::endl;
	std::cout << "2. ���� ���ϱ�" << std::endl;
	std::cout << "3. ��� ���ϱ�" << std::endl;

	int user_select;
	std::cout << "����: ";
	std::cin >> user_select;
	std::cout << std::endl;
	switch (user_select) {
	case 1:
		std::cout << std::endl;
		std::cout << "�� ���� ���ұ��: ";
		std::cin >> addday;
		day_calculator.AddDay(addday);
		std::cout << std::endl;
		day_calculator.ShowDate();
		break;
	case 2:
		std::cout << std::endl;
		std::cout << "�� ���� ���ұ��: ";
		std::cin >> addmonth;
		day_calculator.AddMonth(addmonth);
		std::cout << std::endl;
		day_calculator.ShowDate();
		break;
	case 3:
		std::cout << std::endl;
		std::cout << "�� ���� ���ұ��: ";
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
