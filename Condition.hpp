//
//  Condition.hpp
//  Zork
//
//  Created by Geoff on 10/27/17.
//  Copyright © 2017 Geoff. All rights reserved.
//

#ifndef Condition_hpp
#define Condition_hpp

#include <stdio.h>
#include <string>

#include "rapidxml.hpp"
#include "Owner.hpp"
#include "Status.hpp"

using namespace std;
using namespace rapidxml;

class Condition {
public:
    Status status;
    Owner owner;
    
    Condition(xml_node<>* xnode) {
        int numConditions = condition_count(xnode);
        if (numConditions == 2) {
            setupStatus(xnode);
        } else if (numConditions == 3) {
            setupOwner(xnode);
        }
    }
    ~Condition();
    
    void setupStatus(xml_node<>* xnode) {
        for(xml_node<> * curr = xnode->first_node(); curr; curr = curr->next_sibling()) {
            if(string(curr->name()) == "object"){
                this->status.object = curr -> value();
            }
            if(string(curr->name()) == "status"){
                this->status.status = curr -> value();
            }
        }
    }
    
    void setupOwner(xml_node<>* xnode) {
        for(xml_node<> * curr = xnode->first_node(); curr; curr = curr->next_sibling()) {
            if(string(curr->name()) == "object"){
                this->owner.object = curr -> value();
            }
            if(string(curr->name()) == "has"){
                this->owner.has = curr -> value();
            }
            if(string(curr->name()) == "owner"){
                this->owner.owner = curr -> value();
            }
        }
    }
    
    int condition_count(xml_node<>* xnode) {
        int num = 0;
        for(xml_node<> * curr = xnode->first_node(); curr; curr = curr->next_sibling()) {
            num++;
        }
        return num;
    }
};

#endif /* Condition_hpp */
