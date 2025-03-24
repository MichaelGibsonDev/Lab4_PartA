#pragma once
#include <string>
//----------------------------------------------------------------
//                                                              //
//		        DO NOT EDIT THE CODE BELOW                      //
//                                                              //
#define SPADE   L'\u2660'
#define CLUB    L'\u2663'
#define HEART   L'\u2665'
#define DIAMOND L'\u2666'
class Card
{
public:
	Card(std::string suit, std::string face)
	{
		_suit = suit;
		_face = face;
	}

	std::string Suit() const { return _suit; }
	void Suit(std::string suit) { _suit = suit; }

	std::string Face() const { return _face; }
	void Face(std::string face) { _face = face; }

	void Print() const;
	int Compare(Card& otherCard) const;

private:
	std::string _suit;
	std::string _face;

	int Value(std::string face) const;
};

