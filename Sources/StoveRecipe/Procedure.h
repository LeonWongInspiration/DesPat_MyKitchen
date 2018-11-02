//
//  Procedure.h
//  Created by yameng on 2018/11/2.
//

#ifndef Procedure_h
#define Procedure_h

#include "../Cooker/CookerFactory.h"
#include "../Ingredients/Ingredient.h"
#include "../Object.h"
#include "../Cooker/Cooker.h"
#include <thread>

using namespace std;

/**
 * @brief A basic Command class containing some requirements of commands.
 *
 */
class Command : public Object
{
public:
    
    /**
     * @brief A virtual function to execute its command.
     *
     */
    virtual void Execute() = 0;
    
    /**
     * @brief A virtual function to set cookers the command needs.
     *
     * @return (Cooker *): The cooker pointer that has been add to this command.
     */
    virtual Cooker* SetCooker() = 0;
};

/**
 * @brief A class inherited from Command class containing some requirements of cooking.
 *
 */
class Cook : public Command {
public:
    /**
     * @brief Default constructor.
     *
     */
    Cook() : m_cooker(NULL), m_time(4), m_food(NULL) {}
    /**
     * @brief Construct cook whith ingredient.
     *
     * @param (Ingredient*) ingredient : the ingredient to be cooked.
     */
    Cook(Ingredient* ingredient) : m_cooker(NULL), m_time(5), m_food(ingredient) {}
    /**
     * @brief Default destructor.
     *
     */
    ~Cook() {
        free(m_cooker);
        free(m_food);
    }
    
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Cook@" + add.str();
        return ret;
    }
    
    /**
     * @brief Set cooker of this command.
     *
     * @return (Cooker*) Return the cooker that has been found.
     */
    virtual Cooker* SetCooker() override {
        CookerFactory *pCookerFactory1 = new PotFactory();
        m_cooker = pCookerFactory1->CreateCooker();
        // TODO: 传食物给炊具
        return m_cooker;
    }
    
    /**
     * @brief Execute this command
     *
     */
    virtual void Execute() override {
        SetCookerState(true);
        this_thread::sleep_for(chrono::seconds(m_time));
        SetCookerState(false);
    }
    
protected:
    /**
     * @brief Set the cooker's state.
     *
     * @param (bool) isUsed : Whether this cooker is being used or not.
     */
    void SetCookerState(bool isUsed) {
        if (isUsed) {
            m_cooker->off();
        }
        else {
            m_cooker->on();
        }
    }
    
private:
    /**
     * @brief The duration of this command.
     *
     */
    int m_time;
    /**
     * @brief The ingredient needed by this command.
     *
     */
    Ingredient* m_food;
    /**
     * @brief The cooker needed by this command.
     *
     */
    Cooker* m_cooker;
    
};

/**
 * @brief A class inherited from Command class containing some requirements of Fry.
 *
 */
class Fry : public Command {
public:
    /**
     * @brief Default constructor.
     *
     */
    Fry() : m_cooker(NULL), m_time(5), m_food(NULL) {}
    
    /**
     * @brief Construct fry whith ingredient.
     *
     * @param (Ingredient*) ingredient : the ingredient to be fried.
     */
    Fry(Ingredient* ingredient) : m_cooker(NULL), m_time(5), m_food(ingredient) {}
    
    /**
     * @brief Default destructor.
     *
     */
    ~Fry() {
        free(m_cooker);
        free(m_food);
    }
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Fry@" + add.str();
        return ret;
    }
    
    /**
     * @brief Set cooker of this command.
     *
     * @return (Cooker*) Return the cooker that has been found.
     */
    virtual Cooker* SetCooker() override {
        CookerFactory *pCookerFactory1 = new PotFactory();
        m_cooker = pCookerFactory1->CreateCooker();
        // TODO: 传食物给炊具
        return m_cooker;
    }
    
    /**
     * @brief Execute this command
     *
     */
    virtual void Execute() override {
        SetCookerState(true);
        this_thread::sleep_for(chrono::seconds(m_time));
        SetCookerState(false);
    }
    
protected:
    /**
     * @brief Set the cooker's state.
     *
     * @param (bool) isUsed : Whether this cooker is being used or not.
     */
    void SetCookerState(bool isUsed) {
        if (isUsed) {
            m_cooker->off();
        }
        else {
            m_cooker->on();
        }
    }

private:
    /**
     * @brief The duration of this command.
     *
     */
    int m_time;
    /**
     * @brief The ingredient needed by this command.
     *
     */
    Ingredient* m_food;
    /**
     * @brief The cooker needed by this command.
     *
     */
    Cooker* m_cooker;
};

/**
 * @brief A class inherited from Command class containing some requirements of steam.
 *
 */
class Steam : public Command {
public:
    /**
     * @brief Default constructor.
     *
     */
    Steam() : m_cooker(NULL), m_time(6), m_food(NULL) {}
    
    /**
     * @brief Construct steam whith ingredient.
     *
     * @param (Ingredient*) ingredient : the ingredient to be steamed.
     */
    Steam(Ingredient* ingredient) : m_cooker(NULL), m_time(6), m_food(ingredient) {}
    
    /**
     * @brief Default destructor.
     *
     */
    ~Steam() {
        free(m_cooker);
        free(m_food);
    }
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Steam@" + add.str();
        return ret;
    }
    
    /**
     * @brief Set cooker of this command.
     *
     * @return (Cooker*) Return the cooker that has been found.
     */
    virtual Cooker* SetCooker() override {
        CookerFactory *pCookerFactory1 = new PotFactory();
        m_cooker = pCookerFactory1->CreateCooker();
        // TODO: 传食物给炊具
        return m_cooker;
    }
    
    /**
     * @brief Execute this command
     *
     */
    virtual void Execute() override {
        SetCookerState(true);
        this_thread::sleep_for(chrono::seconds(m_time));
        SetCookerState(false);
    }
    
protected:
    /**
     * @brief Set the cooker's state.
     *
     * @param (bool) isUsed : Whether this cooker is being used or not.
     */
    void SetCookerState(bool isUsed) {
        if (isUsed) {
            m_cooker->off();
        }
        else {
            m_cooker->on();
        }
    }
    
private:
    /**
     * @brief The duration of this command.
     *
     */
    int m_time;
    /**
     * @brief The ingredient needed by this command.
     *
     */
    Ingredient* m_food;
    /**
     * @brief The cooker needed by this command.
     *
     */
    Cooker* m_cooker;
};

/**
 * @brief A class inherited from Command class containing some requirements of roast.
 *
 */
class Roast : public Command {
public:
    /**
     * @brief Default constructor.
     *
     */
    Roast() : m_cooker(NULL), m_time(7), m_food(NULL) {}
    
    /**
     * @brief Construct roast whith ingredient.
     *
     * @param (Ingredient*) ingredient : the ingredient to be roasted.
     */
    Roast(Ingredient* ingredient) : m_cooker(NULL), m_time(7), m_food(ingredient) {}
    
    /**
     * @brief Default destructor.
     *
     */
    ~Roast() {
        free(m_cooker);
        free(m_food);
    }
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Roast@" + add.str();
        return ret;
    }
    
    /**
     * @brief Set cooker of this command.
     *
     * @return (Cooker*) Return the cooker that has been found.
     */
    virtual Cooker* SetCooker() override {
        CookerFactory *pCookerFactory1 = new OvenFactory();
        m_cooker = pCookerFactory1->CreateCooker();
        // TODO: 传食物给炊具
        return m_cooker;
    }
    
    /**
     * @brief Execute this command
     *
     */
    virtual void Execute() override {
        SetCookerState(true);
        this_thread::sleep_for(chrono::seconds(m_time));
        SetCookerState(false);
    }
    
protected:
    /**
     * @brief Set the cooker's state.
     *
     * @param (bool) isUsed : Whether this cooker is being used or not.
     */
    void SetCookerState(bool isUsed) {
        if (isUsed) {
            m_cooker->off();
        }
        else {
            m_cooker->on();
        }
    }
    
private:
    /**
     * @brief The duration of this command.
     *
     */
    int m_time;
    /**
     * @brief The ingredient needed by this command.
     *
     */
    Ingredient* m_food;
    /**
     * @brief The cooker needed by this command.
     *
     */
    Cooker* m_cooker;
};

/**
 * @brief A class inherited from Command class containing some requirements of cutting.
 *
 */
class Cut : public Command {
public:
    /**
     * @brief Default constructor.
     *
     */
    Cut() : m_cooker(NULL), m_time(2), m_food(NULL) {}
    
    /**
     * @brief Construct cook whith ingredient.
     *
     * @param (Ingredient*) ingredient : the ingredient to be cut.
     */
    Cut(Ingredient* ingredient) : m_cooker(NULL), m_time(2), m_food(ingredient) {}
    
    /**
     * @brief Default destructor.
     *
     */
    ~Cut() {
        free(m_cooker);
        free(m_food);
    }
    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual string who_am_i() const override {
        stringstream add;
        add << this;
        string ret = "Cut@" + add.str();
        return ret;
    }
    
    /**
     * @brief Set cooker of this command.
     *
     * @return (Cooker*) Return the cooker that has been found.
     */
    virtual Cooker* SetCooker() override {
        CookerFactory *pCookerFactory1 = new KitchenKnifeFactory();
        m_cooker = pCookerFactory1->CreateCooker();
        // TODO: 传食物给炊具
        return m_cooker;
    }
    
    /**
     * @brief Execute this command
     *
     */
    virtual void Execute() override {
        SetCookerState(true);
        this_thread::sleep_for(chrono::seconds(m_time));
        SetCookerState(false);
    }
    
protected:
    /**
     * @brief Set the cooker's state.
     *
     * @param (bool) isUsed : Whether this cooker is being used or not.
     */
    void SetCookerState(bool isUsed) {
        if (isUsed) {
            m_cooker->off();
        }
        else {
            m_cooker->on();
        }
    }
    
private:
    /**
     * @brief The duration of this command.
     *
     */
    int m_time;
    /**
     * @brief The ingredient needed by this command.
     *
     */
    Ingredient* m_food;
    /**
     * @brief The cooker needed by this command.
     *
     */
    Cooker* m_cooker;
};

#endif /* Procedure_hpp */
