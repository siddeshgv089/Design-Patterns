#include<iostream>
#include<map>
#include<vector>


//Implementation of command pattern listetning to corresponding events when invoked by the invoker


class Command
{
public:
	virtual void execute() = 0;
};

class USBConnected :public Command
{
public:
	void execute()
	{
		std::cout << "USBCommand Connected " << std::endl;
	}
};

class USBDisconnected : public Command
{
public:
	void execute()
	{
		std::cout << "USBCommand Disconnected " << std::endl;
	}
};

class WifiConnected : public Command
{
public:
	void execute()
	{
		std::cout << "WifiCommand Connected " << std::endl;
	}
};

class WifiDisconnected : public Command
{
public:
	void execute()
	{
		std::cout << "WifiCOmmand Disconneted " << std::endl;
	}
};

enum EVENTS
{
	USBCONNECTED,
	USBDISCONNECTED,
	WIFICONNECTED,
	WIFIDISCONNECTED,
	
};


class HardwareEventHandler
{
private:
	std::map<EVENTS, std::shared_ptr<Command>> mp;

public:

	void handleEvents(EVENTS events)
	{
		auto it = mp.find(events);

		if (it != mp.end())
		{
			it->second->execute();

		}
	}

	void registerEvents(EVENTS event, std::shared_ptr<Command> s_ptr)
	{
		mp.insert(std::pair<EVENTS,std::shared_ptr<Command>>(event, s_ptr));
	}

};


int main()
{
	//register Events for invoker

	HardwareEventHandler hardevent;

	hardevent.registerEvents(USBCONNECTED, std::make_shared<USBConnected>());
	hardevent.registerEvents(USBDISCONNECTED, std::make_shared<USBDisconnected>());
	hardevent.registerEvents(WIFICONNECTED, std::make_shared<WifiConnected>());
	hardevent.registerEvents(WIFIDISCONNECTED, std::make_shared<WifiDisconnected>());


	hardevent.handleEvents(USBCONNECTED);
	hardevent.handleEvents(USBDISCONNECTED);
	hardevent.handleEvents(WIFICONNECTED);
	hardevent.handleEvents(WIFIDISCONNECTED);

	return 0;

}