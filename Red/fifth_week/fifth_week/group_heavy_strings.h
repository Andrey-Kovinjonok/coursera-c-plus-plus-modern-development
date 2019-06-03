#pragma once
#include <vector>
#include <map>
#include <set>
#include <utility>


// ��������� Group<String> ��� ������������� ���� String
// ��������� vector<String>.
// ��������� ����� � �������� ������������� ��������
// ������� ����� ������� �� ������������ ������ ��������,
// � ������ ����� � vector<Group<String>>.

template <typename String>
using Group = std::vector<String>;


// ��� ���� ��������� ������� ����
// ��������� ������ ����������� typename String::value_type
// ������������ Char<String>

template <typename String>
using Char = typename String::value_type;


template <typename String>
std::vector<Group<String>> GroupHeavyStrings(std::vector<String> strings)
{
	std::map<std::set<Char<String>>, std::vector<String>> tmp_map;

	for (String& str_ : strings)
	{
		std::set<Char<String>> key;
		String value;

		for (auto& ch : str_)
		{
			value.push_back(std::move(ch));
			key.insert(value.back());
		}

		tmp_map[std::move(key)].push_back(std::move(value));
	}

	std::vector<Group<String>> result;
	result.reserve(tmp_map.size());

    for (auto& pair_ : tmp_map)
    {
		result.push_back(std::move(pair_.second));
    }

	return result;
}


void TestGroupHeavyStrings();