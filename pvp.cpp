#include"Role.h" 
#include"Pc.h"
#include"pvp.h"
#include<iostream>
using namespace std;
extern char m_col;
extern card  arr[54];//�ƶ�
extern card  Desk[54];//�����ϵ���
extern int arr_loc;//�ƶѶ�����Ӧ����λ��
extern int Desk_n;//��ǰ����������
int PVP(Role r_1, Role r_2)
{
	if (arr_loc == 54 && r_1.Get_num() == 1 &&Desk_n==0)//�ƶѺľ����������ƣ���ʱ�����������н���һ�ţ�
	{										//Ϊ���ƣ������������
		if (r_1.joker_left() == 1)			
			return r_2.Get_NO();
	}
	r_1.Show(); 
	int k;
	for ( k = r_1.Attack(r_1.att_get()); k ==0;k=r_1.Attack(r_1.att_get()));//k=1��2��2����������
	if (k == 2)
		{
			r_1.Get_cards();
			r_2.Get_cards();
			Desk_clean();
			return PVP(r_2, r_1);
		}
	Desk_Show();
	r_2.Show();
	int def = r_2.Defend(r_2.def_get());
	Desk_Show();
	int i = r_2.Check_self(def);
	r_1.Check_defender(i);
	if (i == 2){r_2.Get_cards(); Desk_clean();}
	if (arr_loc == 54 && r_2.Get_num() == 0)//�����ϴ��ж���r_1�ڱ��غϲ����ʤ
		return r_2.Get_NO();				//��ʱ�ж�r_2�Ƿ��ڱ��غϻ�ʤ
	switch (i)
		{
		case 0:return PVP(r_1, r_2);
		case 1:return PVP(r_1, r_2);
		case 2:return PVP(r_2, r_1);
		}
}
int PVP_Turn_1(Role r_1, Role r_2)//���ر���ʤ�ߺ�
{
	r_1.Get_cards();
	r_2.Get_cards();
	int m_loc = choose_m_col_1();
	cout << endl << "����ɫ" << m_col<<endl;
	if (m_loc < 8)
		return PVP(r_2, r_1);
	else
		return PVP(r_1, r_2);
}
int PVP_Turn(Role r_1, Role r_2)
{
	cout << "�Ƿ������0��no��1��yes";
	int in;
	cin >> in;
	if (!in)
		return 0;
	Shuffle();
	arr_loc = 0; 
	Desk_n = 0;
	m_col = arr[53].color;
	cout << endl << "����ɫ" << m_col << endl;
	int i=PVP(r_1, r_2);
	cout << i << "win" << endl;
	if (i == r_1.Get_NO())
	{
		return PVP_Turn(r_1, r_2);
	}
	else
	{
		return PVP_Turn(r_2, r_1);
	}
}
int plVpl()
{
	
	Creat_cards(); cout << "�����ƶ�"<<endl;
	for (int k = 0; k < 54; k++)
		cout << arr[k].color << arr[k].value << " ";
	cout << '\n';
	Shuffle();
	cout << "�����ƶ�" << endl;
	for (int k = 0; k < 54; k++)
		cout <<arr[k].color<< arr[k].value << " ";
	cout << '\n';
	//arr[6].color = 'j';
	Role player(1);
	Role pc(2);
	if (PVP_Turn_1(player, pc) == 1)
	{
		cout << "1 win" << endl; PVP_Turn(player, pc);
	}
	else
	{
		cout << "2 win" << endl; PVP_Turn(pc, player);
	}

	player.~Role();
	pc.~Role();
	
	system("pause");
	return 0;
}
