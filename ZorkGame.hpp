#ifndef ZORKGAME_H_
#define ZORKGAME_H_

#include <iostream>
#include <string>
#include <stdio.h>
#include "rapidxml.hpp"
#include <vector>
#include <iterator>
#include <algorithm> //for std::find()

#include "Room.hpp"
#include "Creature.hpp"
#include "Container.hpp"
#include "Item.hpp"
#include "Trigger.hpp"
#include "Status.hpp"
#include "Owner.hpp"

using namespace rapidxml;
using namespace std;

class ZorkGame
{
public:
	ZorkGame(char*);
	~ZorkGame();

	//Functions to setup the game

	//Helper functions
	void startGame();
	void showRoomDescription();
	void checkUserInput_util();
	void checkUserInput(string);
	void change_room(string);
	void show_inventory();
	void take(string);
	void remove_from_vec(vector<string> &vec, int index);
	void remove_from_vec(vector<string> &vec, string str);
	void open(string);
	void gameOver();
	void read(string);
	void drop(string);
	void put(string, string);
    void turnon(string);
    void attack(string, string);
    
    //Behind the Scenes Commands
    void Add(string);
    void Delete(string);
    void Update(string);
    void performAction(string); //Calls Add, Delete, or Update based on a given action
    /*whatIs: Determines what data type a Zork object is given its name.
     Example: whatIs("key") should return "Item"*/
    string whatIs(string);
    /*whichOne: Determines where a Zork object is in its vector. Returns -1 on failure.
     Example: whichOne("key", itemNodes) will return the index in itemNodes where the "key" item is*/
    template <class T> int whichOne(string, vector<T*>);

    //Trigger functions
    bool trigger_check();
    bool trigger_condition_met(Trigger* trigger);
    void implement_trigger(Trigger* trigger);
    bool trig_owner_met(Trigger* trigger, Owner * o);
    bool trig_status_met(Trigger* trigger, Status * s);
    bool owner_has_object(string owner, string obj);
    bool object_meet_status(string obj, string status);
    string ztype(string obj);
	
	//Arrays that contain Room, Container, Item and Creature Nodes
	vector<Room *> roomNodes;
	vector<Container *> containerNodes;
	vector<Item *> itemNodes;
	vector<Creature *> creatureNodes;

	//Inventory list
	vector<string> inventory;

	bool isGameOver;
	bool isOverriden;
	string userIn; //User input from stdin
	Room * curr_room; //The room I am currently in
};

#endif /* ZORKGAME_H_ */
