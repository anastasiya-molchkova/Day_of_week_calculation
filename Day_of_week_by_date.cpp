/* Дано целое число в диапазоне от 1 до 365. 
Определить, какой день недели выпадает на это число, если 1 января - понедельник. */

#include <iostream>
//#include <cstdint> // для использования целочисленных типов фиксированного размера

// получаем от пользователя число от 1 до 365
uint16_t get_day_number()
{
	std::cout << "Please input the day of year (any number from 1 to 365): ";
	int answer;
	std::cin >> answer;
	while (std::cin.fail() || (answer < 1) || (answer > 365))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Error! Please input the number from 1 to 365: ";
		std::cin >> answer;
	}
	return static_cast<uint16_t>(answer);
}

// определяем день недели исходя из того, что 1 - понедельник
void day_of_week_print(const uint16_t day)
{
	enum Days_of_week{Sun, Mon, Tue, Wed, Thu, Fri, Sat, days_num};
	switch (static_cast<Days_of_week>(day % Days_of_week::days_num))
	{
		case Mon: std::cout << "It's Monday \n"; break;
		case Tue: std::cout << "It's Tuesday \n"; break;
		case Wed: std::cout << "It's Wednesday \n"; break;
		case Thu: std::cout << "It's Thursday \n"; break;
		case Fri: std::cout << "It's Friday \n"; break;
		case Sat: std::cout << "It's Saturday \n"; break;
		case Sun: std::cout << "It's Sunday \n"; break;
	}
}

int main()
{
	day_of_week_print(get_day_number());
	return 0;
}