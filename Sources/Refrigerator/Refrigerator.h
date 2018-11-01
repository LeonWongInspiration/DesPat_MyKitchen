//
// Created by Leon Wong on 31/Oct.
//

#ifndef DESPAT_MYKITCHEN_REFRIGERATOR_H
#define DESPAT_MYKITCHEN_REFRIGERATOR_H

#include "../Object.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

/**
 * @brief Refrigerator is a container which can store Ingredients.
 *
 * @tparam T Type of Ingredient you want to store.
 */
template <typename T>
class Refrigerator: public Object {

    friend class Iterator;

    /**
     * size_t will be considered when referring to indices and sizes of arrays.
     */
    using size_t = unsigned int;

    /**
     * amount_type will be considered when referring to amounts of Ts.
     */
    using amount_type = int;

    /**
     * content_type will be saved in the array, and contains the Ingredient and its amount.
     */
    using content_type = std::pair<T, amount_type>;

public:
    /**
     * @brief Get the amopunt of a T.
     *
     * @param (T)elem: T you want to search for.
     * @return (amount_type): The amount of T here.
     */
    amount_type search(T elem) {
        return this->_lazy_update(elem);
    }

    /**
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual std::string who_am_i() const override {
        char ret[32];
        sprintf(ret, "Refrigerator@%d",(int)(this));
        return ret;
    }

    /**
     * @brief Return a reference in the Refrigerator.
     *
     * @param (const size_t&, aka. const unsigned_int&)index: The index of the content you want to get.
     * @return (content_type&, aka. std::pair<T, int>&) The reference of the content at index.
     * @warning This function does NOT check whether the index is legal!
     */
    content_type& operator[](const size_t& index) {
        return this->_array[index];
    }

    /**
     * @brief Return a const reference in the Refrigerator.
     *
     * @param (const size_t&, aka. const unsigned_int&)index: The index of the content you want to get.
     * @return (const content_type&, aka. const std::pair<T, int>&) The reference of the content at index.
     * @warning This function does NOT check whether the index is legal!
     */
    const content_type& operator[](const size_t& index) const {
        return this->_array[index];
    }

    /**
     * @brief Re organize contents in the Refrigerator.
     *
     * @warning This function ONLY merge identical contents, but NOT SORT them!
     * @see void _lazy_update()
     */
    void reorganize() {
        this->_lazy_update();
    }

    /**
     * @brief Remove all contents in this Refrigerator.
     *
     * @warning This function will CLEAR ALL contents for a long time! (REALLY A LONG TIME!）
     */
    void clear() {
        this->_array->clear();
    }

    /**
     * @brief Push back an element in the array.
     *
     * @param (content_type, aka. std::pair<T, int>)elem: Element to add to the array.
     */
    void push_back(content_type elem) {
        this->_array->push_back(elem);
        this->_need_lazy_update = true;
    }

    /**
     * @brief Add a content into the refrigerator defaulting amount to 1.
     *
     * @param (T)ingredient: T you want to insert.
     * @param (amount_type)amount: Amount of T you want to insert.
     */
    void push_back(T ingredient, amount_type amount) {
        this->_array->push_back(std::pair<T, amount_type>(ingredient, amount));
        this->_need_lazy_update = true;
    }

    /**
     * @brief Out_of_boundary_exception will be thrown when there is an illegal visit to the array.
     */
class out_of_boundary_exception: public std::range_error, Object {

    /**
     * size_t will be considered when referring to indices and sizes of arrays.
     */
    using size_t = unsigned int;

private:
    /**
     * Pointer to the Refrigerator.
     */
    Refrigerator* refrigerator;

    /**
     * Index which causes this exception.
     */
    size_t index;

public:
    /**
     * @brief Information about this exception.
     *
     * @return (const char*) Information about this exception.
     */
    virtual const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
        char index_str[16];
        sprintf(index_str, "%d", this->index);
        std::string ret;
        ret = "Refrigerator out of boundary! ";
        ret += this->refrigerator->who_am_i();
        ret += ": @index: ";
        ret.append(index_str);
        return ret.c_str();
    }

    /**
     * @brief Constructor of this exception, requiring the address and more information about this exception.
     *
     * @param (const Refrigerator*)rfr: Refrigerator who throws this exception.
     * @param (size_t)indx: Bad index who causes this exception.
     */
    out_of_boundary_exception(const Refrigerator* rfr, size_t indx):
    refrigerator (rfr),
    index (indx){
    }
};

    /**
     * @brief Get a content at a given index, before which checking if the index is legal.
     *
     * @param (size_t)index: Index of the content you want to get.
     * @return (const content_type&) The content you get.
     * @throws (out_of_boundary_exception) If the index is not legal, this function will throw an exception.
     */
    const content_type& at(size_t index) const throw(out_of_boundary_exception) {
        if (index >= this->_array->size()) {
            throw out_of_boundary_exception(this, index);
        }
        else {
            return this->_array[index];
        }
    }

    class Iterator;
    /**
     * @brief Get an iterator from index 0.
     *
     * @return (Iterator): A new iter.
     */
    Iterator begin() {
        Iterator iter(this, 0);
        return iter;
    }

    /**
     * @brief Get an iterator from index (end).
     *
     * @return (Iterator): A new iter.
     */
    Iterator end() {
        Iterator iter(this, this->_array->size());
        return iter;
    }

    /**
     * Default constructor.
     */
    Refrigerator() {
        this->_array = new std::vector<content_type>();
        this->_need_lazy_update = false;
    }

//TODO: Define a constructor for initializing the refrigerator with given arguments.

//TODO: Define Iterator for the Refrigerator.
/**
 * @brief An Iterator class for reading contents from the Refrigerator.
 *
 */
class Iterator: public Object {
private:
    /**
     * Same definition of size_t in Refrigerator.
     */
    using size_t = unsigned int;

public:

    /**
     * @brief Construct an iter.
     *
     * @param refrigerator: owner
     * @param initial_index: initial index.
     */
    Iterator(Refrigerator* refrigerator, size_t initial_index) :
    _ref(refrigerator),
    _current_index(initial_index) {
    }

    /**
     * @brief Apply ++iter function.
     *
     * @param (Iterator &)iter: Iterator to self-increment.
     * @return (const Iterator): The iterator after increment.
     */
    friend const Iterator operator++(Iterator &iter) {
        iter._current_index += 1;
        return iter;
    }

    /**
     * @brief Apply iter++ function.
     *
     * @return (const Iterator): The iterator before increment.
     */
    const Iterator operator++(){
        Iterator tmp(*this);
        this->_current_index += 1;
        return tmp;
    }

    /**
     * @brief Apply --iter function.
     *
     * @param (Iterator &)iter: The Iterator to self-decrement.
     * @return (const Iterator): The iterator after decrement.
     */
    const Iterator operator--(Iterator &iter) {
        iter._current_index -= 1;
        return iter;
    }

    /**
     * @brief Apply iter-- function.
     *
     * @return (const Iterator): The iterator before decrement.
     */
    const Iterator operator--() {
        this->_current_index -= 1;
        return *this;
    }

    /**
     * @brief Dereference.
     *
     * @param (Iterator &)iter: Iterator to dereference.
     * @return (content_type &): Content gotten from this iterator.
     */
    friend content_type& operator*(Iterator &iter) {
        return iter._ref[iter._current_index];
    }

    /**
     * @brief Const dereference.
     *
     * @param (const Iterator&)iter: The iterator to const deref.
     * @return (const content_type): const content gotten from this iter.
     */
    friend const content_type& operator*(const Iterator &iter) {
        return iter._current_index[iter._ref];
    }

    /**
     * @brief Tell if an iterator is identical to another one.
     *
     * @param LHS Left-hand-side.
     * @param RHS Right-hand-side.
     * @return (bool) Whether one iter is the same with another one.
     */
    friend bool operator==(const Iterator &LHS, const Iterator &RHS) {
        return LHS._ref == RHS._ref && LHS._current_index == RHS._current_index;
    }

    /**
     * @brief Tell if an iterator is not identical to another one.
     *
     * @param LHS Left-hand-side.
     * @param RHS Right-hand-side.
     * @return (bool) Whether one iter is not the same with another one.
     */
    friend bool operator!=(const Iterator &LHS, const Iterator &RHS) {
        return !(LHS == RHS);
    }

    /**
     * @brief Tell if an iterator is less than another one.
     *
     * @param LHS Left-hand-side.
     * @param RHS Right-hand-side.
     * @return (bool) Whether LHS is less than RHS.
     */
    friend bool operator<(const Iterator &LHS, const Iterator &RHS) {
        return LHS._ref == RHS._ref && LHS._current_index < RHS._current_index;
    }

    /**
     * @brief Tell if an iterator is greater than another one.
     *
     * @param LHS Left-hand-side.
     * @param RHS Right-hand-side.
     * @return (bool) Whether LHS is greater than RHS.
     */
    friend bool operator>(const Iterator &LHS, const Iterator &RHS) {
        return LHS._ref == RHS._ref && LHS._current_index > RHS._current_index;
    }

    /**
     * @brief Tell if an iterator is less or equal than another one.
     *
     * @param LHS Left-hand-side.
     * @param RHS Right-hand-side.
     * @return (bool) Whether LHS is less or equal than RHS.
     */
    friend bool operator<=(const Iterator &LHS, const Iterator &RHS) {
        return LHS == RHS || LHS < RHS;
    }

    /**
     * @brief Tell if an iterator is greater or equal than another one.
     *
     * @param LHS Left-hand-side.
     * @param RHS Right-hand-side.
     * @return (bool) Whether LHS is greater or equal than RHS.
     */
    friend bool operator>=(const Iterator &LHS, const Iterator &RHS) {
        return LHS == RHS || LHS > RHS;
    }
private:
    /**
     * Current index of this iter.
     */
    size_t _current_index;

    /**
     * The owner of this iter.
     */
    Refrigerator* _ref;
};

private:
    /**
     * Pointer to the memory space allocated for this Refrigerator.
     */
    std::vector<content_type>* _array;

    /**
     * @brief Lazy update will be called when we need to sort all the Ts in the array and merge those who are identical.
     *
     */
    void _lazy_update() {
        if (!this->_need_lazy_update)
            return;
        std::vector<content_type> vec;
        for (auto i : *(this->_array)) {
            bool not_exist = true;
            size_t index;
            for (int t = 0; t < vec.size(); ++t) {
                if (vec[t].first == i.first) {
                    not_exist = false;
                    vec[t].second += i.second;
                    break;
                }
            }
            if (not_exist) {
                vec.push_back(i);
            }
        }
        this->_need_lazy_update = false;
        delete this->_array;
        this->_array = new std::vector<content_type>(vec);
    }

    /**
     * @brief This function will merge those in the array who are identical, and update their amount.
     *
     * @param (T&)to_merge: The T to merge as one content in the array.
     * @return (amount_type) Amount of to_merge.
     */
    amount_type _lazy_update(const T& to_merge) {
        if (!this->_need_lazy_update) {
            for (auto i : *(this->_array)) {
                if (i.first == to_merge) {
                    return i.second;
                }
            }
        }
        int count = 0;
        for (auto iter = this->_array->begin(); iter != this->_array->end(); ++iter) {
            if (iter->first == to_merge) {
                count += iter->second;
                iter->second = 0;
            }
        }
        this->_array->push_back(content_type(to_merge, count));
        return count;
    }

    /**
     * @brief This function will merge those in the array who are identical, and update their amount.
     *
     * @param (T*)to_merge: Pointer to the T to merge as one content in the array.
     * @return (amount_type): Amount of to_merge.
     * @see void _lazy_update(const T& to_merge)
     */
    amount_type _lazy_update(const T* to_merge) {
        return this->_lazy_update(*to_merge);
    }

    /**
     * Flag for whether there is a need to use lazy update.
     */
    bool _need_lazy_update;
};

#endif //DESPAT_MYKITCHEN_REFRIGERATOR_H
