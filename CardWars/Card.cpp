#include "Card.h"
#include <iostream>
#include <string>
#include <io.h>
#include <fcntl.h>
#include <sstream>
#include <iomanip>
#include <vector>
//----------------------------------------------------------------
//                                                              //
//		        DO NOT EDIT THE CODE BELOW                      //
//     
// 
void PrintIntro()
{
	std::vector<Card> intro{ Card("Hearts",""), Card("Diamonds","") ,Card("Clubs","") ,Card("Spades","") };
	for (auto& card : intro)
	{
		card.Print();
	}
	std::wcout << " PG2 Lab4";
	for (int i = intro.size() - 1; i >= 0; i--)
	{
		intro[i].Print();
	}
	std::wcout << "\n";

}

void Card::Print() const
{
	std::cout << std::setw(2) << _face;


#if defined(_WIN32) || defined(__MSDOS__)
	_setmode(_fileno(stdout), _O_U16TEXT);
#endif

	if(_suit=="Hearts")
		std::wcout << HEART;
	else if(_suit== "Diamonds")
		std::wcout << DIAMOND;
	else if (_suit == "Clubs")
		std::wcout << CLUB;
	else if (_suit == "Spades")
		std::wcout << SPADE;
	std::wcout.flush();


#if defined(_WIN32) || defined(__MSDOS__)
	_setmode(_fileno(stdout), _O_TEXT);
#endif
}


int Card::Compare(Card& otherCard) const
{
	int pValue = Value(_face);
	int cValue = Value(otherCard.Face());
	if (pValue > cValue)
		return 1;//player wins
	else if (pValue < cValue)
		return -1;//npc wins 

	return 0;
}

int Card::Value(std::string face) const
{
	int value;
	if (sizeof(face) == 3) //10 card
		value = 10;
	else
	{
		char first = face[0];
		if (first == 'A')
			value = 1;
		else if (first == 'J')
			value = 11;
		else if (first == 'Q')
			value = 12;
		else if (first == 'K')
			value = 13;
		else
			value = std::stoi(face);
	}

	return value;
	//return (int)face;
}