//
//  Recipe.h
//  Created by yameng on 2018/10/30.
//

#ifndef Recipe_h
#define Recipe_h

#include "../Object.h"
#include "Procedure.h"
#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief A basic Observer class containing some requirements of observers.
 *
 */
class Observer : public Object
{
public:
    /**
     * @brief A virtual function to update its state when this observer has received messages from subject.
     *
     */
    virtual void Update() = 0;
    
};

/**
 * @brief A class inherited from Observer class containing some requirements of the recipe.
 *
 */
class Recipe : public Observer
{
public:
    
    /**
     * @brief Default constructor.
     *
     */
    Recipe() : m_id(0) {}
    
    /**
     * @brief Default destructor.
     *
     */
    ~Recipe() {}
    
    /**
     * @brief Constructor of this recipe, requiring its id.
     *
     * @param (const int) id: the identifier of this recipe.
     */
    Recipe(const int id) : m_id(id) {}
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Recipe@" + add.str();
        return ret;
    }
    
    /**
     * @brief Update its state when this observer has received messages from subject.
     *
     */
    virtual void Update() override {
        cout << "菜谱" << m_id << "在进行中。" << endl;
    }
    
    /**
     * @brief Set commands of this recipe.
     *
     * @param (Command*) pCommand: Command to be set in this recipe.
     */
    void SetCommand(Command* pCommand){
        m_commands.push_back(pCommand);
    }
    
    /**
     * @brief Start to execute the commands.
     *
     */
    virtual void Start(){
        int pos = 1;
        while (m_commands.size() != 0) {
            cout << "菜谱" << m_id << "：正在进行第" << pos << "步" << endl;
            Command* pCommand = m_commands[0];
            pCommand->Execute();
            m_commands.erase(m_commands.begin());
            pos++;
        }
    }
    
private:
    /**
     * The list of commands.
     */
    vector<Command *>m_commands;
    /**
     * The ID of recipe.
     */
    const int m_id;
    
};

#endif /* Recipe_h */
