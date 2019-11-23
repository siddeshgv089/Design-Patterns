#include<iostream>
#include<vector>
#include<map>



class Task
{
public:
	virtual void execute() = 0;
	virtual ~Task(){}
};


class TaskFactory
{
public:
	virtual Task* createTask() = 0;
	virtual ~TaskFactory(){}
};

class EmailTask :public Task
{
public:
	void execute()
	{
		std::cout << "Email Task Executed " << std::endl;
	}
};

class SMSTask : public Task
{
public:
	void execute()
	{
		std::cout << "SMS Task Executed " << std::endl;
	}
};

class EmailTaskFactory :public TaskFactory
{
public:

	Task * createTask()
	{
		return new EmailTask();
	}
};

class SMSTaskFactory : public TaskFactory
{
public:

	Task* createTask()
	{
		return new SMSTask();
	}
};


//framework code to execute respective tasks

void frameWorkCode(TaskFactory* factory)
{
	Task* task = factory->createTask();
	task->execute();
	delete task;
}


int main()
{
	TaskFactory* SMStaskfac = new SMSTaskFactory();
	frameWorkCode(SMStaskfac);

	TaskFactory* Emailtaskfac = new EmailTaskFactory();
	frameWorkCode(Emailtaskfac);

	delete SMStaskfac;
	delete Emailtaskfac;



	return 0;
}