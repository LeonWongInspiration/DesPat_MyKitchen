//
//  Recipe.h
//  Created by yameng on 2018/10/30.
//

#ifndef Recipe_h
#define Recipe_h

#include "../Object.h"
#include <iostream>
#include <list>
#include <thread>
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
    void Update(){
        cout << endl;
        cout << "菜谱" << m_id << "在进行中。" << endl;
    }
    
    /**
     * @brief Set commands of this recipe.
     *
     * @param (list<int>) tList: The list of commands to be set in this recipe.
     * @warning This function is temporory. Command pattern is not completed.
     */
    void SetTime(list<int>tList){
        for(auto i: tList){
            m_Time.push_back(i);
        }
    }
    
    /**
     * @brief Start to execute the commands.
     *
     * @warning This function is temporory. Command pattern is not completed.
     */
    void Start(){
        int pos = 1;
        for(auto i: m_Time){
            cout << endl;
            cout << "菜谱" << m_id << "：正在进行第" << pos << "步" << endl;
            this_thread::sleep_for(chrono::seconds(i));
            pos++;
        }
    }
    
private:
    /**
     * The list of commands.
     */
    list<int> m_Time;
    /**
     * The ID of recipe.
     */
    int m_id;
    
};

#endif /* Recipe_h */
