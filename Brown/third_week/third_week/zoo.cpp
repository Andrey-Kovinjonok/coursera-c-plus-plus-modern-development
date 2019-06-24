#include "animals.h"
#include "UnitTestsFramework.h"
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <vector>
#include <memory>


using Zoo = std::vector<std::shared_ptr<Animal>>;


// ��� ������� �������� �� ���� ����� ����� � ������ �� ���� �������� ������.
// ���� ��������� ����� ����� ������ - Tiger, Wolf ��� Fox, ������� ������ ��������� ���������������� ����� � �������.
// � ��������� ������ ��� ������ ���������� ������ � ������������� ���������� runtime_error.
Zoo CreateZoo(std::istream& in) 
{
	Zoo zoo;

	std::string name;
	while (in >> name)
	{
		if (name == "Tiger")
		{
			zoo.emplace_back(std::make_shared<Tiger>());
		}
		else if (name == "Wolf")
		{
			zoo.emplace_back(std::make_shared<Wolf>());
		}
		else if (name == "Fox")
		{
			zoo.emplace_back(std::make_shared<Fox>());
		}
		else
		{
			throw std::runtime_error("!");
		}
	}

	return zoo;
}


// ��� ������� ������ ��������� ���� ������ � �������� � ������� �� ��������
// � �������� � �������� ����� ��� ������� �� ��� ��������� ������ ����������� ������� voice.
// ���������� ������ ������ ������ �������� �������� ������ '\n'.
void Process(const Zoo& zoo, std::ostream& out) 
{
    for (const auto& animal : zoo)
    {
		out << animal->Voice() << '\n';
    }
}


void ZooTest() 
{
	std::istringstream input("Tiger Wolf Fox Tiger");
    std::ostringstream output;
	Process(CreateZoo(input), output);

	const std::string expected =
		"Rrrr\n"
		"Wooo\n"
		"Tyaf\n"
		"Rrrr\n";

	ASSERT_EQUAL(output.str(), expected);
}


void TestZoo() 
{
	TestRunner tr;
	RUN_TEST(tr, ZooTest);
}