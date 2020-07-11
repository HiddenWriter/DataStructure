#include "pch.h"
#include "ItemType.h"

ItemType::ItemType() {
    this->mName = new char[NAME_SIZE];
    this->mName = "DEFAULT";
    this->mID = -1;
    return;
}

ItemType::~ItemType(){
    this->mName = nullptr;
    delete[] mName;
    return;
}

void ItemType::SetID(int _id) {
    this->mID = _id;
    return;
}

void ItemType::SetName(char* _name) {
    this->mName = _name;
    return;
}

void ItemType::SetIDFromUser() {
    std::cout << "\n\t ID : ";
    std::cin >> this->mID;
    return;
}

void ItemType::SetNameFromUser() {
    std::cout << "\n\t NAME : ";
    std::cin.getline(this->mName, NAME_SIZE);
    return;
}

