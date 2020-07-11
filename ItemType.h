#pragma once

class ItemType{
public:
    ItemType();
    ~ItemType();
    
    void SetID(int _id);
    void SetName(char* _name);
    void SetIDFromUser();
    void SetNameFromUser(); 
    int GetID();
    char* GetName();

    // operator overloading
    bool operator==(ItemType _item) {
        if(this->GetID() == _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    void operator=(ItemType _item) {
        this->SetID(_item.GetID());
        this->SetName(_item.GetName());
        return;
    }
    bool operator<(ItemType _item) {
        if(this->GetID() < _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    bool operator>(ItemType _item) {
        if(this->GetID() > _item.GetID()) {
            return true;
        }
        else {
            return false;
        }
    }
    
private:
    char* mName;
    int mID;
};

