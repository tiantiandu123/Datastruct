#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 2017, int month = 9, int day = 10)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	Date& operator=(const Date& d) //赋值运算符重载  
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//获得某月的天数
	int Getmonthday(int _year, int _month)
	{
		//闰年
		if (((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0))
		{
			if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12)
			{
				return 31;
			}
			else if (_month == 2)
			{
				return 29;
			}
			else
			{
				return 30;
			}
		}
		else//平年
		{
			if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10)
			{
				return 31;
			}
			else if (_month == 2)
			{
				return 28;
			}
			else
			{
				return 30;
			}
		}
	}
	//判断日期是否合法 
	bool IsInvalid(int year, int month, int day)//判断日期是否合法
	{
		//此处从1900年开始，如果小于这个日期，则返回fasle
		if ((year > 1900) && (month > 0) && (month<13) && (day>0) && (day < Getmonthday(year, month)))
		{
			return true;
		}
		else
			return false;
	}

	// 前置++ 
	Date& operator++()
	{
		_day += 1;
		return *this;
	}
	// 后置++ 
	Date operator++(int)
	{
		Date temp(*this); //保留当前对象
		_day += 1;
		return temp;
	}
	Date& operator--()
	{
		_day -= 1;
		return *this;
	}
	Date operator--(int)
	{
		Date temp(*this);
		_day -= 1;
		return temp;
	}
	//days天之后的日期 
	Date operator+(int days)
	{
		if (days < 0)//天数若为负数变为减  
		{
			return *this - (0 - days);
		}
		Date temp(*this);
		temp._day += days;
		int daysinmonth = 0;
		while (temp._day >(daysinmonth = Getmonthday(temp._year, temp._month)))
		{
			temp._day -= daysinmonth;
			temp._month++;
			if (temp._year > 12)
			{
				temp._year += 1;
				temp._month = 1;
			}
		}
		return temp;
	}
	// days天之前的日期 
	Date operator-(int days)
	{
		if (days < 0)
		{
			return *this + (0 - days);
		}
		Date temp(*this);
		temp._day -= days;
		while (temp._day <= 0)
		{
			temp._month -= 1;
			if (temp._month <1)
			{
				temp._year -= 1;
				temp._month += 1;
			}
			temp._day += Getmonthday(temp._year, temp._month);
		}
		return temp;
	}

	// 两个日期之间的距离 
	int operator-(const Date& d)
	{
		Date maxDate = *this;
		Date minDate = d;
		if (maxDate < minDate)
		{
			maxDate = d;
			minDate = *this;

		}
		int days = 0;
		while (minDate != maxDate)
		{
			++minDate;
			days++;
		}
		return days;
	}
	/*while (1) {
	if (minDate + days == maxDate)
	break;
	days++;

	}
	return days;
	*/
	bool operator==(const Date& d)
	{
		if ((_year == d._year) && (_month == d._month) && (_day == d._day))
		{
			return true;
		}
		else
			return false;
	}
	bool operator!=(const Date& d)
	{
		if ((_year != d._year) ||
			(_month != d._month) ||
			(_day != d._day))
			return true;
		else
			return false;
	}
	bool operator>(const Date& d)
	{
		if ((d._year < _year) || (d._month < _month) || (d._day < _day))
		{
			return true;
		}
		else
			return false;
	}
	bool operator<(const Date& d)
	{
		if ((d._year > _year) || (d._month > _month) || (d._day > _day))
		{
			return true;
		}
		else
			return false;
	}
	void display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	~Date()
	{}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date c1;
	c1.display();
	Date c2(2017, 9, 11);
	c2.display();
	Date c3;
	c3 = c2;
	c3.display();
	c3 = c1++;
	c3.display();
	c3 = ++c1;
	c3.display();
	cout << "对日期减天数" << endl;
	cout << (c3 - c2) << endl;
	Date c4 = c1 - 100;
	c4.display();
	cout << "两日期比较" << endl;
	Date d4(2016, 10, 9);
	Date d5(2016, 10, 8);
	Date c5;
	cout << boolalpha << c5.IsInvalid(2017, 1, 88) << endl;
	cout << boolalpha << (Date(2016, 10, 1) == d5) << endl;
	system("pause");