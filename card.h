#pragma once
struct card
{
	char color;               //��ɫ
	int value;					//��С				
};
void Swap(card, card);
void Creat_cards(card arr[]);
void Shuffle(card  arr[]);