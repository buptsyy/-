#pragma once
#include"card.h"
#include<iostream>
using namespace std;
extern char m_col;
extern card  arr[54];//�ƶ�
extern card  Desk[54];//�����ϵ���
extern int arr_loc;//�ƶѶ�����Ӧ����λ��
extern int Desk_n;//��ǰ����������
class Role
{
private:
	card  Cards[30] ;//����
	int num;  //������
	int NO;						//��ɫ���
public:
	Role(int i );
	~Role();
	int Get_num() { return num; }
	int Get_NO() { return NO; }
	bool joker_left() { return (Cards[0].color == 'j'); }
    void Get_cards();//�ƶ�
	void GetBack_cards();//��������
	void Show();
	bool a_judge(int i,card hand);//��������,��������Ҫ�������
	bool d_judge(card desk, card hand);
	int Attack(int loc);//�������飬���������������Ƶ�λ��
	int Defend(int loc);//����0��ֱ�����ƣ�����1�����سɹ���
						//����2�����ƺľ���ֱ�ӽ�������,ѡ����ƻ�����
						//����3, ����ѡ����Ч
	void card_out(int loc);//���locΪX-1����X���ƴ��
	//���޸İ汾��
	int att_get()
	{
		int i;
		cout << "����" << NO << "��ҽ���ʱ����ڼ�����"<<endl;
		cin >> i;
		cout << endl;
		return i;
	}
	//���޸İ汾��
	int def_get()
	{
		int i;
		cout << "����" << NO << "��ҷ���ʱ����ڼ�����" << endl;
		cin >> i;
		cout << endl;
		return i;
	}
	int Check_self(int i);//return !=3
	int Check_defender(int i);

};

