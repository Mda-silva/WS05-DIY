#include "Power.h"
#include<iostream>


#ifndef SENECA_HERO_H
#define	SENECA_HERO_H
namespace seneca {
	using namespace std;
	class Hero
	{
	private:
		char hero_name[MAX_NAME_LENGTH];
		Power* m_power;
		int nbr_pow;
		int power_level;

	public:
		Hero();
		Hero(const char* name, Power* pw_list, int pwnbr);
		~Hero();
		ostream& display(ostream& os = cout) const;
		Hero& operator+=(Power& p_o);

		Hero& operator-=(int val);

		bool operator<(Hero& hero2) const;

		bool operator>(Hero& hero2) const;

		//Hero& operator>>(int index, Hero& m_hero[index]);

		//Power& operator>>(Hero& m_hero);
		//Hero& operator>>(const Power& m_power, Hero& m_hero);


		Hero& operator<<(Power& new_pw);

		//friend Hero& operator>>(const Power& t_power, Hero& m_hero);
	};

	Hero& operator>>(Power& t_power, Hero& m_hero);


	



}


#endif // !1