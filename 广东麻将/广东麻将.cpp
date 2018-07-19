// �㶫�齫.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"��visual studio��������Ҫ��ӣ�����strcpy������Ϊ��strcpy_s��
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <vector>
#include <time.h>
#include<iostream>
#include <algorithm>

using namespace std;

//�ƽṹ��
typedef struct Pai {
	int Number;
	char Name[5];
}Card;

//�������ƺ�������������
struct less {
	bool operator()(Card C1, Card C2) {
		return(C1.Number < C2.Number);
	};
}myobject;

static vector<Card> OldArray;//ϴ��ǰ������
static vector<Card> NewArray;//ϴ�ƺ�������
static vector<Card> GiveOutArray;//���ƺ������Ƶ�����
static vector<Card> Player;//�����������
static vector<Card> PlayerC1;//�������1��������
static vector<Card> PlayerC2;//�������1��������
static vector<Card> PlayerC3;//�������1��������
static vector<Card> PlayerGangAndPeng;//�ܺ������Ƶ�����
static vector<Card> PlayerC1GangAndPeng;//�ܺ������Ƶ�����
static vector<Card> PlayerC2GangAndPeng;//�ܺ������Ƶ�����
static vector<Card> PlayerC3GangAndPeng;//�ܺ������Ƶ�����

void Init();
void CardWash(vector<Card> &OldArray, vector<Card> &NewArray);
void CardGiveout();
int CardPengOrMingGang();
int CardCanHu(int TureOrFalse);
void UI();

//������
void Init() {
	Card card[136] = {};
	for (int i = 0; i <= 6; i++) {//0-27���鶫�������з���
		card[i].Number = i + 1;
	}
	for (int i = 7; i <= 13; i++) {
		card[i].Number = i - 6;
	}
	for (int i = 14; i <= 20; i++) {
		card[i].Number = i - 13;
	}
	for (int i = 21; i <= 27; i++) {
		card[i].Number = i - 20;
	}
	for (int i = 28; i <= 36; i++) {//28-63��������
		card[i].Number = i - 17;
	}
	for (int i = 37; i <= 45; i++) {
		card[i].Number = i - 26;
	}
	for (int i = 46; i <= 54; i++) {
		card[i].Number = i - 35;
	}
	for (int i = 55; i <= 63; i++) {
		card[i].Number = i - 44;
	}
	for (int i = 64; i <= 72; i++) {//64-99������
		card[i].Number = i - 43;
	}
	for (int i = 73; i <= 81; i++) {
		card[i].Number = i - 52;
	}
	for (int i = 82; i <= 90; i++) {
		card[i].Number = i - 61;
	}
	for (int i = 91; i <= 99; i++) {
		card[i].Number = i - 70;
	}
	for (int i = 100; i <= 108; i++) {//100-135����Ͳ
		card[i].Number = i - 69;
	}
	for (int i = 109; i <= 117; i++) {
		card[i].Number = i - 78;
	}
	for (int i = 118; i <= 126; i++) {
		card[i].Number = i - 87;
	}
	for (int i = 127; i <= 135; i++) {
		card[i].Number = i - 96;
	}
	for (int i = 0; i <= 135; i++) {//�������ƽ��и�������
		switch (card[i].Number / 10) {
		case 0:
			switch (card[i].Number % 10) {
			case 1:
				strcpy_s(card[i].Name, "��");
				break;
			case 2:
				strcpy_s(card[i].Name, "��");
				break;
			case 3:
				strcpy_s(card[i].Name, "��");
				break;
			case 4:
				strcpy_s(card[i].Name, "��");
				break;
			case 5:
				strcpy_s(card[i].Name, "��");
				break;
			case 6:
				strcpy_s(card[i].Name, "��");
				break;
			case 7:
				strcpy_s(card[i].Name, "��");
				break;
			}
			break;
		case 1:
			switch (card[i].Number % 10) {
			case 1:
				strcpy_s(card[i].Name, "һ��");
				break;
			case 2:
				strcpy_s(card[i].Name, "����");
				break;
			case 3:
				strcpy_s(card[i].Name, "����");
				break;
			case 4:
				strcpy_s(card[i].Name, "����");
				break;
			case 5:
				strcpy_s(card[i].Name, "����");
				break;
			case 6:
				strcpy_s(card[i].Name, "����");
				break;
			case 7:
				strcpy_s(card[i].Name, "����");
				break;
			case 8:
				strcpy_s(card[i].Name, "����");
				break;
			case 9:
				strcpy_s(card[i].Name, "����");
				break;
			}
			break;
		case 2:
			switch (card[i].Number % 10) {
			case 1:
				strcpy_s(card[i].Name, "һ��");
				break;
			case 2:
				strcpy_s(card[i].Name, "����");
				break;
			case 3:
				strcpy_s(card[i].Name, "����");
				break;
			case 4:
				strcpy_s(card[i].Name, "����");
				break;
			case 5:
				strcpy_s(card[i].Name, "����");
				break;
			case 6:
				strcpy_s(card[i].Name, "����");
				break;
			case 7:
				strcpy_s(card[i].Name, "����");
				break;
			case 8:
				strcpy_s(card[i].Name, "����");
				break;
			case 9:
				strcpy_s(card[i].Name, "����");
				break;
			}
			break;
		case 3:
			switch (card[i].Number % 10) {
			case 1:
				strcpy_s(card[i].Name, "һͲ");
				break;
			case 2:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			case 3:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			case 4:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			case 5:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			case 6:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			case 7:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			case 8:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			case 9:
				strcpy_s(card[i].Name, "��Ͳ");
				break;
			}
			break;
		}
	}
	for (int i = 0; i <= 135; i++) {//��ʼ������ǰ��ȫ���Ƶ�����
		OldArray.push_back(card[i]);
	}
	CardWash(OldArray, NewArray);//ϴ��
	return;
}

//ϴ�ƺ���
void CardWash(vector<Card> &OldArray, vector<Card> &NewArray) {
	for (int i = 135; i > 0; i--) {
		srand(unsigned(time(NULL)));
		// ѡ�е�����±�
		int index = rand() % i;
		// ����ѡ�е��±꽫ԭ����ѡ�е�Ԫ��push��������
		NewArray.push_back(OldArray[index]);
		// ��ԭ������ѡ�е�Ԫ���޳�
		OldArray.erase(OldArray.begin() + index);
	}
	/*for (vector<Card>::iterator it = NewArray.begin(); it != NewArray.end(); it++) {
	cout << it->Name << it->Number <<" ";
	}
	cout << endl;*/
	return;
}

//��ʾPC��ҳ�����
void CardThatPcJustGiveOut(int pcplayer) {
	switch (pcplayer) {
	case 1:
		cout << "PC1������Ϊ��" << GiveOutArray.back().Name << endl;
		break;
	case 2:
		cout << "PC2������Ϊ��" << GiveOutArray.back().Name << endl;
		break;
	case 3:
		cout << "PC3������Ϊ��" << GiveOutArray.back().Name << endl;
		break;
	default:
		break;
	}
	return;
}

//��ʾʣ������
void CardLeft() {
	int NO = NewArray.size();
	cout << endl << "                                                                     ʣ������: " << NO << endl;
	return;
}

//���ƺ���
void CardGiveout() {
	int count = 1;
	for (int i = 135; i >83; i--) {
		switch (count)
		{
		case 1:
			Player.push_back(NewArray.back());//�����������
			break;
		case 2:
			PlayerC1.push_back(NewArray.back());//�������1��������
			break;
		case 3:
			PlayerC2.push_back(NewArray.back());//�������1��������
			break;
		case 4:
			PlayerC3.push_back(NewArray.back());//�������1��������
			break;
		default:
			break;
		}
		NewArray.pop_back();
		if (count == 4)
			count = 1;
		else
		{
			count++;
		}

	}
	return;
}

//���ƻ����ܺ���
int CardPengOrMingGang() {
	int count = 0;
	char YorN;
	int GorPorN = 0;
	Card  temp;
	vector <Card>::iterator it = Player.begin();
	if (!GiveOutArray.empty()) {
		for (; it != Player.end(); it++) {
			if ((*it).Number == GiveOutArray.back().Number) {
				count++;
			}
		}
	}
	if (count == 2) {
		it = Player.begin();
		cout << "�Ƿ�����Y/N" << endl;
		cin >> YorN;
		while (YorN != 'Y' && YorN != 'y' && YorN != 'n' && YorN != 'N') {
			cout << "�����������������룿Y/N" << endl;
			cin >> YorN;
		}
		if (YorN == 'y' || YorN == 'Y') {
			for (; it != Player.end(); ) {
				if ((*it).Number == GiveOutArray.back().Number) {
					temp.Number = GiveOutArray.back().Number;
					strcpy_s(temp.Name, (GiveOutArray.back().Name));
					PlayerGangAndPeng.push_back(temp);
					PlayerGangAndPeng.push_back(temp);
					PlayerGangAndPeng.push_back(temp);
					sort(PlayerGangAndPeng.begin(), PlayerGangAndPeng.end(), myobject);//����ҵ������ư��ƺŴ�С��������
					it = Player.erase(it);
					if (it != Player.end()) {
						it = Player.erase(it);//���������һ��Ҫָ����һ��
					}
					else {
						Player.erase(it);//�������һ����itָ�����¸�ֵ
					}
					
				}
				else {
					it++;
				}
			}
			return 1;//������1
		}
		else if (YorN == 'n' || YorN == 'N') {
			return 0;//����������0
		}
		else {
			return 0;
		}
	}
	if (count == 3) {
		it = Player.begin();
		cout << "ѡ�������߸ܻ򲻲�����1/2/3" << endl;
		cin >> GorPorN;
		while (GorPorN != 1 && GorPorN != 2 && GorPorN != 3) {
			cout << "�����������������룿Y/N" << endl;
			cin >> GorPorN;
		}
		int count1 = 0;
		switch (GorPorN) {
		case 1:
			for (; it != Player.end(); ) {
				if ((*it).Number == GiveOutArray.back().Number) {
					temp.Number = GiveOutArray.back().Number;
					strcpy_s(temp.Name, (GiveOutArray.back().Name));
					PlayerGangAndPeng.push_back(temp);
					PlayerGangAndPeng.push_back(temp);
					PlayerGangAndPeng.push_back(temp);
					sort(PlayerGangAndPeng.begin(), PlayerGangAndPeng.end(), myobject);
					it = Player.erase(it);
					Player.erase(it);
					count1=2;
					if (count1 == 2) {
						return 1;//������1
					}
				}
				else {
					it++;
				}
			}
			break;
		case 2:
			for (; it != Player.end();) {
				if ((*it).Number == GiveOutArray.back().Number) {
					temp.Number = GiveOutArray.back().Number;
					strcpy_s(temp.Name, (GiveOutArray.back().Name));
					PlayerGangAndPeng.push_back(temp);
					PlayerGangAndPeng.push_back(temp);
					PlayerGangAndPeng.push_back(temp);
					PlayerGangAndPeng.push_back(temp);
					sort(PlayerGangAndPeng.begin(), PlayerGangAndPeng.end(), myobject);
					it = Player.erase(it);
					it = Player.erase(it);
					Player.erase(it);
					count1=3;
					if (count1 == 3) {
						return 2;//�ܷ���2
					}
				}
				else {
					it++;
				}
			}
			break;
		case 3:
			return 0;
		default:
			return 0;
		}
	}
	return 0;
}

//�����ƺ���
void CardAnGang() {

}

//���ƺ���
int CardCanHu(int IsPlayerOrPC) {
	int length = Player.size() - 1;
	int first = 0;
	while (first != length) {
		for (int second = first + 1; second <= length; second++) {
			if (Player[first].Number == Player[second].Number) {
				vector <Card> temp(Player);
				temp.erase(temp.begin() + first);
				temp.erase(temp.begin() + second - 1);
				vector <Card> temp1(temp);
				while (!temp1.empty()) {
					if (((*temp1.begin()).Number == (*(temp1.begin() + 1)).Number == (*(temp1.begin() + 2)).Number)
						|| ((*temp1.begin()).Number + 1 == (*(temp1.begin() + 1)).Number && (*temp1.begin()).Number + 2 == (*(temp1.begin() + 2)).Number)) {
						temp1.erase(temp1.begin());
						temp1.erase(temp1.begin());
						temp1.erase(temp1.begin());
					}
					else if (temp1.empty()) {
						cout << "�Ƿ�Ҫ����?Y/N" << endl;
						char YorN;
						cin >> YorN;
						if (YorN == 'Y' || YorN == 'y') {
							return 1;//���Ժ��Ʒ���1
						}
						else if (YorN == 'N' || YorN == 'n') {
							return 0;
						}
						else {
							return 0;
						}
					}
					else if (((*temp1.begin()).Number != (*(temp1.begin() + 1)).Number) || ((*temp1.begin()).Number + 1 != (*(temp1.begin() + 1)).Number)) {
						break;
					}
				}
			}
		}
		first++;
	}
	return 0;
}

//��ʾ�������
void CardInHand() {
	cout << endl << "----------------------------------------����----------------------------------------" << endl;
	int length = Player.end() - Player.begin();
	for (int i = 1; i <= length - 5; i++) {
		cout << i;
		cout << "     ";
	}
	for (int i = length - 4; i <= length; i++) {
		cout << i;
		cout << "    ";
	}
	cout << endl;
	vector <Card>::iterator it = Player.begin();
	for (; it != Player.end(); it++) {
		if (((*it).Name)[2] == '\0') {
			cout << (*it).Name << "    ";
		}
		else {
			cout << (*it).Name << "  ";
		}
	}
	cout << endl << "------------------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << endl << "----------�ܺ�������------------" << endl;
	if (PlayerGangAndPeng.empty()==false) {
		vector <Card>::iterator it1 = PlayerGangAndPeng.begin();
		for (; it1 != PlayerGangAndPeng.end(); it1++) {
			if (((*it1).Name)[2] == '\0') {
				cout << (*it1).Name << "    ";
			}
			else{
				cout << (*it1).Name << "  ";
			}
		}
	}
	cout << endl << " --------------------------------" << endl;
	cout << endl;
	cout << endl;
	return;
}

//���ƺ���
void NextCard(int IsPlayerOrPC) {
	switch (IsPlayerOrPC)
	{
	case 1:
		Player.push_back(NewArray.back());
		NewArray.erase(NewArray.end() - 1);
		sort(Player.begin(), Player.end(), myobject);//����ҵ��ư��ƺŴ�С��������
		break;
	case 2:
		PlayerC1.push_back(NewArray.back());
		NewArray.erase(NewArray.end() - 1);
		break;
	case 3:
		PlayerC2.push_back(NewArray.back());
		NewArray.erase(NewArray.end() - 1);
		break;
	case 4:
		PlayerC3.push_back(NewArray.back());
		NewArray.erase(NewArray.end() - 1);
		break;
	default:
		break;

	}
}

//���ƺ���
void GiveUpCard(int IsPlayerOrPC) {
	Card  temp;
	switch (IsPlayerOrPC)
	{
	case 1:
		cout << "��ѡ��Ҫ������:";
		int NO;
		cin >> NO;
		Player.erase(Player.begin() + NO - 1);
		CardInHand();
		break;
	case 2:
		temp.Number = (*PlayerC1.begin()).Number;
		strcpy_s(temp.Name, ((*PlayerC1.begin()).Name));
		PlayerC1.erase(PlayerC1.begin());
		GiveOutArray.push_back(temp);
		CardThatPcJustGiveOut(1);
		break;
	case 3:
		temp.Number = (*PlayerC2.begin()).Number;
		strcpy_s(temp.Name, ((*PlayerC2.begin()).Name));
		PlayerC2.erase(PlayerC2.begin());
		GiveOutArray.push_back(temp);
		CardThatPcJustGiveOut(2);
		break;
	case 4:
		temp.Number = (*PlayerC3.begin()).Number;
		strcpy_s(temp.Name, ((*PlayerC3.begin()).Name));
		PlayerC3.erase(PlayerC3.begin());
		GiveOutArray.push_back(temp);
		CardThatPcJustGiveOut(3);
		break;
	default:
		break;
	}
}

//��ǰ����߼�
int excute(int player,int gangorpeng) {//���뵱ǰ���id���Ƿ������
	if (NewArray.empty()) {
		return 1;
	}
	int CanHu = 0;
	if (gangorpeng == 0|| gangorpeng == 2) {
		NextCard(player);//���ƺ���
	}
	CardLeft();//��ʾʣ������
	if (player == 1) {
		CardInHand(); //���������ʾ����
		CanHu = CardCanHu(player);// �ж��Ƿ��ܺ�����1������0
	}
	if (CanHu == 0) {
		GiveUpCard(player);//���ƺ���
	}
	return CanHu;//�����Ƿ�ǰ����Ƿ�ѡ���˺�����Ϣ��
}

//��������
void UI() {
	int PLAYER = 1;
	int PC1 = 2;
	int PC2 = 3;
	int PC3 = 4;
	int CanHu = 0;
	int pengorgang=0;
	cout << "                                       " << "�㶫�齫" << endl;
	Init();
	CardGiveout();
	cout << "                                 " << "ϴ����ɣ��Ծֿ�ʼ��" << endl;
	while (CanHu != 1 && !NewArray.empty()) {
		CanHu = excute(PLAYER,pengorgang);
		CanHu = excute(PC1,0);
		pengorgang=CardPengOrMingGang();//������Ժ���1��Ŀǰ����ҿ�����ܣ�;
		if (pengorgang == 1|| pengorgang == 2) {
			pengorgang = 0;//����0;
			continue;
		}
		CanHu = excute(PC2,0);
		pengorgang = CardPengOrMingGang();//������Ժ���1��Ŀǰ����ҿ�����ܣ�;
		if (pengorgang == 1 || pengorgang == 2) {
			pengorgang = 0;
			continue;
		}
		CanHu = excute(PC3,0);
		pengorgang = CardPengOrMingGang();//������Ժ���1��Ŀǰ����ҿ�����ܣ�;
		if (pengorgang == 1 || pengorgang == 2) {
			pengorgang = 0;
			continue;
		}
	}
	cout << "                                     " << "�Ծֽ�����" << endl;
	return;
}


int main()
{
	UI();
	return 0;
}

