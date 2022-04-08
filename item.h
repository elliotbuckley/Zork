#ifndef ITEM_H_
#define ITEM_H_

#include <map>
#include <string>
#include <iostream>
using namespace std;

class Item {
private:
    string description; // Name of the item
	string longDescription;
    int weightGrams;
	float value;
    //bool weaponCheck;


public:
    Item (string description, int inWeight, float inValue); // declaring overloaded
    Item (string description); // declaring default
	string getShortDescription();
    string getLongDescription();
	int getWeight();
	void setWeight(int weightGrams);
	float getValue();
	void setValue(float value);
	int getWeaponCheck();
	void setWeaponCheck(int weaponCheck);
};

#endif /*ITEM_H_*/
