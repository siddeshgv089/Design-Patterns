#include<iostream>
#include<vector>
#include<map>


typedef enum MessageType
{
	ERROR,
	WARNING,
	GENERAL
}MessageType;


class Subject;

class Observer
{
public:
	virtual void update(Subject* subject){}
	virtual ~Observer() {}
};


class Subject
{
private:

	std::map<MessageType, std::vector<Observer*>> mp;
	std::string data;
public:
	std::string getData()
	{
		return data;
	}

	void setData(std::string data)
	{
		this->data = data;
	}

	void attach(MessageType event, Observer* observer)
	{
		mp[event].push_back(observer);
	}

	void detach(Observer* observer)
	{

		for (std::map<MessageType, std::vector<Observer*>>::iterator it = mp.begin(); it != mp.end(); it++)
		{
			std::vector<Observer*>::iterator itV = std::find(it->second.begin(), it->second.end(), observer);

			if (itV != it->second.end())
			{
				it->second.erase(itV);
				continue;
			}

		}

	}

	void notify(MessageType message)
	{
		std::map<MessageType, std::vector<Observer*>>::iterator it = mp.find(message);

		if (it != mp.end())
		{
			for (std::vector<Observer*>::iterator i = it->second.begin(); i != it->second.end(); i++)
			{
				(*i)->update(this);
			
			}
		}

	}
	
};

class Logger :public Subject
{
private:
	std::map<MessageType, bool>map;

public:
	Logger()
	{
		map[ERROR] = false;
		map[WARNING] = false;
		map[GENERAL] = false;
	}

	void writeLog(MessageType type, std::string msg)
	{
		if (map[type])
		{
			setData(msg);
			notify(type);
		}
	}


	void enableLoggingOfMessage(MessageType msg)
	{
		map[msg] = true;
	}

	void disableLoggingOfMessage(MessageType msg)
	{
		map[msg] = false;
	}

};




class ConsoleLoggingPlatform : public Observer
{
public:
	void update(Subject* subject)
	{
		std::cout << subject->getData() << std::endl;
	}
};


class FileLoggingPlatform : public Observer
{
private:
	std::string m_name;
public:

	FileLoggingPlatform(std::string name):m_name(name){}

	void update(Subject* subject)
	{
		std::cout << subject->getData() << std::endl;
	}
};

class NetworkLoggingPlatform : public Observer
{
public:

	void update(Subject* subject)
	{
		std::cout << subject->getData() << std::endl;
	}
};


int main() {
	Logger* logger = new Logger();

	ConsoleLoggingPlatform* cp = new ConsoleLoggingPlatform();
	NetworkLoggingPlatform* np = new NetworkLoggingPlatform();
	FileLoggingPlatform* fp = new FileLoggingPlatform("temp");
	
	logger->attach(ERROR, cp);
	logger->attach(WARNING, np);
	logger->attach(GENERAL, fp);

	logger->enableLoggingOfMessage(ERROR);
	logger->enableLoggingOfMessage(WARNING);
	logger->enableLoggingOfMessage(GENERAL);

	logger->writeLog(ERROR, "Error message");
	logger->writeLog(WARNING, "Warning message");
	logger->writeLog(GENERAL, "General message");

	return 0;

}

