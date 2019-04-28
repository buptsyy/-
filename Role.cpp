#include "Role.h"


extern char m_col;
extern card  arr[54];//�ƶ�
extern card  Desk[54];//�����ϵ���
extern int arr_loc;//�ƶѶ�����Ӧ����λ��
extern int Desk_n;//��ǰ����������
Role::Role(int i)
{
	card Cards[30];//��������30��
	num = 0;
	NO = i;
}


Role::~Role()
{
	cout <<NO<< " end"<<endl;
}
void Role::Get_cards() //iΪ�ƶ����ڶѶ�����������λ��
{
	if (num < 8)
		for (; num < 8 && arr_loc < 54; num++, arr_loc++)//���Ʋ���8�� ���� �ƶѺľ�
		{
			agetb(&Cards[num], arr [arr_loc]);
		}
}
void Role::GetBack_cards()//*iΪ��������������
{
	for (; Desk_n > 0; Desk_n--)
	{
		agetb(&Cards[num] , arr[Desk_n - 1]);
		num++;
	}
	Desk_clean();
}
void Role::Show()
{
	cout << NO << "�Ž�ɫ ";
	for (int i = 0; i < num; i++)
		cout << Cards[i].color << Cards[i].value << " ";
	cout << endl;
}
bool Role::a_judge( int i, card hand)//����Desk_nֱ�Ӳ���
{
	for (; i > 0; i--)
		if (hand.value == Desk[i - 1].value)
			return 1;
	return 0;
}
void Role::card_out(int loc)//���locΪX-1����X���ƴ��
{
	for (; loc < num-1; loc++)
		agetb(&Cards[loc], Cards[(loc + 1)]);//��������
		num--;							//������-1
}
int Role::Attack( int loc)
{
	if (Cards[loc-1].color == 'j')//���ɴ������
		return 0;
	if (loc == 0)
	{
		if (Desk_n>0)
			return 2;
		else
			return 0;//�������ƣ���ʱ�������
	}
	bool b;
	if (Desk_n == 0)
		b = 1;	//�������ƣ�ֱ�Ӵ��
	else
		 b=a_judge( Desk_n, Cards[loc-1]);//�ж��Ƿ���Դ��
	if (b)
	{
		agetb(&Desk[Desk_n], Cards[loc - 1]);//��������
		Desk_n++;							//��������+1
		card_out(loc - 1);					//��ȥ������
		return 1;
	}
	else
		return 0;
}
bool Role::d_judge(card desk, card hand)
{
	if (hand.color == 'j')//����
		return 1;
	if (hand.color == m_col && desk.color != m_col)//����
		return 1;
	if (hand.color == desk.color && hand.value > desk.value)//ͬ��ɫ�ȴ�С
		return 1;
	return 0;	
}
int Role::Defend(int loc)

{
	if (loc == 0)
	{
		return 0;
	}
	bool b = d_judge(Desk[Desk_n - 1], Cards[loc - 1]);
	if (b)
	{
		agetb(&Desk[Desk_n], Cards[loc - 1]);
		Desk_n++;
		card_out(loc - 1);
	}
	else
	{	
		return 3;
	}
	if (num == 0)
	{	
		return 2;//������,ѡ����ƻ�����
	}
	else
		return 1;//��������
}
int Role::Check_self(int i)//return !=3
{
	switch (i)
	{
	case 0:GetBack_cards();  Desk_clean(); return 0;
	case 1:break;
	case 2:cout << "�Ƿ���������?\n0:��" << endl; int i; cin >> i; cout << endl;
		if (i == 0)
		{
			return Check_self(0);
		}
		else
			return 2;
	case 3:
		cout << "����ѡ����Ч";
		Check_self(Defend(i = def_get()));//choose_again
		break;
	}
	return i;
}
int Role::Check_defender(int i)
{
	switch (i)
	{
	case 0:Get_cards(); break;// ���ֽ��������ֽ���
	case 1:break;//
	case 2:Get_cards();  break;//���ֽ������ı乥��
	}
	return i;
}
