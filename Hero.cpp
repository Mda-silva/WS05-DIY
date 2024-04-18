#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "Power.h"

namespace seneca {

	using namespace std;

	Hero::Hero()
	{
		hero_name[0] = 0;
		m_power = nullptr;
		nbr_pow = 0;
		power_level = 0;
	}

	Hero::Hero(const char* name, Power* pw_list, int pwnbr)
	{
		*this = Hero();
		int rar_Sum = 0;
		power_level = 0;
		nbr_pow = 0;
		if (name[0] != '\0' && name != nullptr && pwnbr > 0)
		{
			strcpy(hero_name, name);
			nbr_pow = pwnbr;
			m_power = new Power[nbr_pow];
			for (int i = 0; i < nbr_pow; i++)
			{
				m_power[i] = pw_list[i];
			}	
			for (int i = 0; i < nbr_pow; i++)
			{
				rar_Sum += m_power[i].checkRarity();
			}
			power_level = nbr_pow * rar_Sum;
		}
	}

	Hero::~Hero()
	{
		delete[] m_power;
		m_power = nullptr;
	}

	ostream& Hero::display(ostream& os) const
	{
		os << "Name: " << hero_name << endl;
		os << "List of available powers: " << endl;
		for (int i = 0; i < nbr_pow; i++)
		{
			os << "  Name: " << m_power[i].checkName() << ", Rarity: " << m_power[i].checkRarity() << endl;
		}
		os << "Power Level: " << power_level;
		return os;
	}

	Hero& Hero::operator+=(Power& p_o)
	{
		////Power* temp_power;
		//nbr_pow++;
		//Power* temp_power = new Power[nbr_pow + 1];
		//for (int i = 0; i < nbr_pow; i++)
		//{
		//	temp_power[i] = m_power[i];
		//}

		//delete[] m_power;
		//temp_power[nbr_pow] = p_o;

		//m_power = new Power[nbr_pow];

		//m_power = temp_power;

		Power* temp = new Power[nbr_pow + 1];

		for (int i = 0; i < nbr_pow; i++)
		{
			temp[i] = m_power[i];
		}

		temp[nbr_pow] = p_o;
		nbr_pow++;

		delete[] m_power;

		m_power = temp;
		
		int sum_rar = 0;
		for (int i = 0; i < nbr_pow; i++)
		{
			sum_rar += m_power[i].checkRarity();
		}
		power_level = sum_rar * nbr_pow;


		return *this;
	}

	Hero& Hero:: operator-=(int val)
	{
		power_level -= val;
		return *this;
	}

	bool Hero::operator<(Hero& hero2) const
	{
		if (this->power_level < hero2.power_level) return true;

		return false;
	}

	bool Hero::operator>(Hero& hero2) const
	{
		if (this->power_level > hero2.power_level) return true;

		return false;
	}

	

	Hero& Hero::operator<<(Power& new_pw)
	{
		*this += new_pw;
		return *this;
	}


	Hero& operator>>(Power& t_power, Hero& m_hero)
	{
		//m_hero.operator+=(t_power);
		//m_hero << t_power;
		m_hero += t_power;
		return m_hero;
	}

}