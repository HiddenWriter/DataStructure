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

private:

    int mCommand;
    SortedList<ItemType> MyList;

};