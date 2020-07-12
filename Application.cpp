#include "pch.h"
#include "Application.h"

Application::Application() {
    this->mCommand = -1;
}

Application::~Application() {
}

int Application::Run() {
    bool run = false;
    while(!run) {

        switch (GetCommand())
        {
        case 1:
            Add();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Search();
            break;
        case 4:
            Display();
            break;
        case 0:
            run = true;
            break;
        default:
            break;
        }
    }
    return 1;
}

int Application::Add() {
    ItemType temp;
    temp.SetAllRecordFromUser();
    if(MyList.Add(temp)){ return 1; }
    else { return 0; }
}

int Application::Delete() {
    ItemType temp;
    temp.SetIDFromUser();

    if(!MyList.GetItem(temp)) {
        std::cout << "\n\t Couldn't find item. \n";
        return 0;
    }
    else {
        MyList.Delete(temp);
        std::cout << temp;
        std::cout << "\n\t Successfully Deleted. \n";
        return 1;
    }
}

int Application::Display() {
    ItemType temp;
    MyList.ResetPointer();
    
    int length = MyList.GetLength();
    int currentPtr = MyList.GetNextItem(temp);
    
    while(currentPtr < length && currentPtr != -1) {
        std::cout << temp << '\n';
        currentPtr = MyList.GetNextItem(temp);
    }
    return 1;
}

int Application::Search() {
    ItemType temp;
    temp.SetIDFromUser();

    if(MyList.GetItem(temp)) {
        std::cout << temp << '\n';
        return 1;
    }
    else {
        std::cout << "\n\t Couldn't find item. \n";
        return 0;
    }
}

int Application::GetCommand() {
    
    std::cout << "\n\t Simple Sorted List Programme. \n";
    std::cout << "\n\t 1 : Add data.\n";
    std::cout << "\n\t 2 : Delete data.\n";
    std::cout << "\n\t 3 : Search data. \n";
    std::cout << "\n\t 4 : Display all data. \n";
    std::cout << "\n\t 0 : Exit. \n";
    std::cin >> mCommand;
    switch (mCommand)
    {
    case 1:
        mCommand = 1;
        break;
    case 2:
        mCommand = 2;
        break;
    case 3:
        mCommand = 3;
        break;
    case 4:
        mCommand = 4;
        break;
    case 0:
        mCommand = 0;
        break;
    default:
        break;
    }

    return mCommand;
}