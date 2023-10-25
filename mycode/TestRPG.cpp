#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>

int Player_damage;
int Monster_damage;
int input;

class Player {
public:
	int LV;          // 플레이어 레벨
	int HP;          // 플레이어 체력
	int EXP;         // 플레이어 경험치
	bool DEAD;       // 플레이어 사망 여부
	int ATK;         // 플레이어 공격력
	int Total_EXP;   // 레벨업을 위한 총 경험치 필요량
	int Total_HP;    // 레벨업을 위한 총 체력 필요량
	int liquid;      // 체력 회복량

	Player();
	void attack();    // 플레이어가 몬스터를 공격하는 함수
	void recover();   // 플레이어의 체력을 회복하는 함수
	void show_status(); // 플레이어의 상태를 출력하는 함수
} player;

class Monster {
public:
	int HP;    // 몬스터 체력
	int ATK;   // 몬스터 공격력

	Monster();
	void attack();    // 몬스터가 플레이어를 공격하는 함수
	void show_status(); // 몬스터의 상태를 출력하는 함수
} monster;

Monster::Monster() {
	HP = 30;
	ATK = 3;
}

Player::Player() {
	LV = 1;
	HP = 50;
	EXP = 0;
	DEAD = false;
	ATK = 5;
}

void Monster::attack() {
	ATK = player.LV * 6;
	Monster_damage = ATK;
	player.HP -= Monster_damage;

	if (player.HP <= 0) {
		player.DEAD = true;
		player.EXP = 0;
		if (player.EXP <= 0) {
			player.EXP = 0;
		}
		std::cout << "플레이어가 사망하셨습니다. 1을 누르면 부활합니다." << std::endl;
		std::cin >> input;
		if (input == 1) {
			std::cout << "플레이어가 부활하였습니다." << std::endl;
			player.DEAD = false;
			player.HP = pow(player.LV, 1.25) * 50;
		}
		else {
			std::cout << "잘못 누르셨습니다. 처음부터 다시 시작하세요." << std::endl;
			player.LV = 1;
			player.EXP = 0;
			player.Total_HP = pow(player.LV, 1.25) * 50;
			player.HP = player.Total_HP;
			player.Total_EXP = 1500 * pow(1.15, player.LV);
			player.ATK = 5 * pow(player.LV, 1.94);
		}
	}
}

void Player::attack() {
	Player_damage = ATK;
	monster.HP -= Player_damage;
	if (monster.HP <= 0) {
		EXP += 72 * pow(1.09, LV);
		monster.HP = 30 * pow(LV, 1.63);
	}
	if (EXP >= Total_EXP) {
		EXP = 0;
		LV += 1;
		Total_EXP = 500 * pow(1.08, LV);
		Total_HP = pow(LV, 1.41) * 50;
		HP = Total_HP;
		monster.HP = 30 * pow(LV, 1.63);
		ATK = 5 * pow(LV, 2.14);
		liquid = Total_HP * 0.2;
	}
}

void Player::recover() {
	HP += liquid;
	if (HP >= Total_HP) {
		HP = Total_HP;
	}
}

void Player::show_status() {
	std::cout << "플레이어 상태 -- " << "레벨 : " << LV << " // " << " HP : " << HP << " // " << " 경험치 : " << EXP
		<< " // " << " 공격력 : " << ATK << "      ";
}

void Monster::show_status() {
	std::cout << "몬스터 상태 -- " << "HP : " << HP << " 몬스터 공격력 : " << ATK << std::endl;
}

int main() {
	player.show_status();
	std::cout << std::endl;
	for (;;) {
		std::cout << std::endl;
		std::cout << "몬스터 공격 : 1을 눌러주세요" << std::endl;
		std::cout << "체력 회복 : 2를 눌러주세요" << std::endl;
		std::cin >> input;
		std::cout << std::endl;
		if (input == 1) {
			player.attack();
			monster.attack();
			player.show_status();
			monster.show_status();
		}
		else if (input == 2) {
			player.recover();
			player.show_status();
		}
		else {
			std::cout << "다시 입력해주세요." << std::endl;
		}
		if (player.LV == 102) {
			std::cout << "축하합니다. 만렙입니다!  1이랑 2를 누르느라 수고하셨습니다." << std::endl;
			break;
		}
	}
	return 0;
}
