#pragma once
#include "UnitTestsFramework.h"
#include <sstream>
#include <string>
#include "sstream"


class Logger
{
public:
	explicit Logger(std::ostream& output_stream) : os(output_stream) {}

	void SetLogLine(bool value) { log_line = value; }
	void SetLogFile(bool value) { log_file = value; }

	void SetFile(const std::string& file);
	void SetLine(const int& line);

	void Log(const std::string& message);

private:
	std::ostream& os;
	bool log_line = false;
	bool log_file = false;

	std::string file_;
	int line_;
};


#define LOG(logger, message)                                                         \
{                                                                                    \
    logger.SetFile(__FILE__);                                                        \
    logger.SetLine(__LINE__);                                                        \
    logger.Log(message);                                                             \
}


inline void TestLog() {
	/* ��� ��������� ����-������ � ���� ������ ��� ����� ����������� ����������
	 * ������ ����� � ��������� �������� (��. ���������� expected ����). ����
	 * �� ��������� �����-�� ��� ���� ������� TestLog, �� ��� ������ ����� ��������,
	 * � ��� ���� �������� ������. ��� ��������.
	 *
	 * ����� ����� ��������, �� ���������� ����������� ������ #line
	 * (http://en.cppreference.com/w/cpp/preprocessor/line), ������� ���������
	 * �������������� ����� ������, � ����� ��� �����. ��������� ���, ������
	 * ����� ������ ������� TestLog ����� ����������� ���������� �� ����, �����
	 * ��� �� ��������� ����� ���*/

#line 1 "logger.cpp"

	std::ostringstream logs;
	Logger l(logs);
	LOG(l, "hello");

	l.SetLogFile(true);
	LOG(l, "hello");

	l.SetLogLine(true);
	LOG(l, "hello");

	l.SetLogFile(false);
	LOG(l, "hello");

	std::string expected = "hello\n";
	expected += "logger.cpp hello\n";
	expected += "logger.cpp:10 hello\n";
	expected += "Line 13 hello\n";
	ASSERT_EQUAL(logs.str(), expected);
}


void TestLogMacro();