#pragma once
class Application
{

public:

// Constructor and Destructor
    Application();
    ~Application();

    int GetCommand();

    int Run();

    int Add();

    int Delete();

    int Display();

    int Search();

	int QuickSortItem();
private:

    int mCommand;
    SortedList<ItemType> MyList;

};
