//
// Created by Leon Wong on 31/Oct.
//

#ifndef DESPAT_MYKITCHEN_REFRIGERATOR_H
#define DESPAT_MYKITCHEN_REFRIGERATOR_H

#include "../Object.h"
#include <iostream>
#include <string>
#include <stdexcept>

/**
 * @brief Refrigerator is a container which can store Ingredients.
 *
 * @tparam T Type of Ingredient you want to store.
 */
template <typename T>
class Refrigerator: public Object {

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
     * @brief Return basic information about the class.
     *
     * @return (string) Name and address of this class.
     */
    virtual std::string who_am_i() const override {
        char ret[32];
        sprintf(ret, "Refrigerator@%d", static_cast<int>(this));
        return ret;
    }

    /**
     * @brief Return a reference in the Refrigerator.
     *
     * @param (const size_t&, aka. const unsigned_int&)index: The index of the content you want to get.
     * @return (content_type&, aka. std::pair<T, int>&) The reference of the content at index.
     * @warning This function does NOT check whether the index is legal!
     */
    content_type& operator[](const size_t& index);

    /**
     * @brief Return a const reference in the Refrigerator.
     *
     * @param (const size_t&, aka. const unsigned_int&)index: The index of the content you want to get.
     * @return (const content_type&, aka. const std::pair<T, int>&) The reference of the content at index.
     * @warning This function does NOT check whether the index is legal!
     */
    const content_type& operator[](const size_t& index) const;

    /**
     * @brief Re organize contents in the Refrigerator.
     *
     * @warning This function ONLY merge identical contents, but NOT SORT them!
     * @see void _lazy_update(const T& to_merge)
     */
    void reorganize();

    /**
     * @brief Remove all contents in this Refrigerator.
     *
     * @warning This function will CLEAR ALL contents for a long time! (REALLY A LONG TIME!）
     */
    void clear();

    /**
     * @brief Push back an element in the array.
     *
     * @param (content_type&, aka. std::pair<T, int>)elem: Element to add to the array.
     */
    void push_back(content_type& elem);

    /**
     * @brief Out_of_boundary_exception will be thrown when there is an illegal visit to the array.
     */
class out_of_boundary_exception: public std::range_error {

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
    virtual const char* what() const _NOEXCEPT {
        char index_str[16];
        sprintf(index_str, "%d", this->index);
        return "Refrigerator out of boundary! " + this->refrigerator->who_am_i() + ": @index: " + index_str;
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
    const content_type& at(size_t index) const throw(out_of_boundary_exception);

    /**
     * Default constructor.
//TODO: Define initial arguments for a refrigerator.
     */
    Refrigerator();

//TODO: Define a constructor for initializing the refrigerator with given arguments.

//TODO: Define Iterator for the Refrigerator.

private:
    /**
     * Pointer to the memory space allocated for this Refrigerator.
     */
    content_type* _array;

    /**
     * Total size of the array, or to say, the maximum amount of Ts you can store in the array.
     */
    size_t _total_size;

    /**
     * Current amount of Ts in the array.
     */
    size_t _current_size;

    /**
     * @brief Lazy update will be called when we need to sort all the Ts in the array and merge those who are identical.
     *
     */
    void _lazy_update();

    /**
     * @brief This function will merge those in the array who are identical, and update their amount.
     *
     * @param (T&)to_merge: The T to merge as one content in the array.
     */
    void _lazy_update(const T& to_merge);

    /**
     * @brief This function will merge those in the array who are identical, and update their amount.
     *
     * @param (T*)to_merge: Pointer to the T to merge as one content in the array.
     * @see void _lazy_update(const T& to_merge)
     */
    void _lazy_update(const T* to_merge);

    /**
     * Flag for whether there is a need to use lazy update.
     */
    bool _need_lazy_update;
};

#endif //DESPAT_MYKITCHEN_REFRIGERATOR_H
