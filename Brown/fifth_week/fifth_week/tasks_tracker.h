#pragma once
#include <map>
#include <string>
#include <unordered_map>
#include <iostream>
#include <tuple>


enum class TaskStatus 
{
	NEW,          // �����
	IN_PROGRESS,  // � ����������
	TESTING,      // �� ������������
	DONE          // ���������
};


std::ostream& operator <<(std::ostream& out, const TaskStatus& status);


// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
using TasksInfo = std::map<TaskStatus, int>;


class TeamTasksTester;


TasksInfo operator +(const TasksInfo& lhs, const TasksInfo& rhs);


class TeamTasks 
{
public:
	// �������� ���������� �� �������� ����� ����������� ������������
	const TasksInfo& GetPersonTasksInfo(const std::string& person) const;

	// �������� ����� ������ (� ������� NEW) ��� ����������� �������������
	void AddNewTask(const std::string& person);

	// �������� ������� �� ������� ���������� ����� ����������� ������������,
	// ����������� ��. ����
	std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person, 
		int task_count);

private:
	std::unordered_map<std::string, TasksInfo> programmers_;

	void remove_empty(TasksInfo&);

	friend class TeamTasksTester; // for testing private fields of TeamTasks
};


void TestTasksTracker();