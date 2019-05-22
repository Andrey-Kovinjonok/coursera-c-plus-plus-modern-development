#include "Person.h"
#include <iterator>


std::string FindNameByYear(const std::map<int, std::string>& names, int year)
{
	auto iter = names.upper_bound(year);

	if (iter != names.begin())
	{
		return std::prev(iter)->second;
	}

	return "";
}


void Person::ChangeFirstName(int year, const std::string& first_name)
{
	first_names[year] = first_name;
}


void Person::ChangeLastName(int year, const std::string& last_name)
{
	last_names[year] = last_name;
}


std::string Person::GetFullName(int year)
{
	// �������� ��� � ������� �� ��������� �� ��� year
	const std::string first_name = FindNameByYear(first_names, year);
	const std::string last_name = FindNameByYear(last_names, year);

	// ���� � ���, � ������� ����������
	if (first_name.empty() && last_name.empty()) {
		return "Incognito";

		// ���� ���������� ������ ���
	}
	else if (first_name.empty()) {
		return last_name + " with unknown first name";

		// ���� ���������� ������ �������
	}
	else if (last_name.empty()) {
		return first_name + " with unknown last name";

		// ���� �������� � ���, � �������
	}
	else {
		return first_name + " " + last_name;
	}
}