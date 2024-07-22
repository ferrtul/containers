#include "s21_stack.h"

namespace s21 {
    //// Constructors

    template<class T>
    s21::stack<T>::stack() : vector<T>() {}

    template<class T>
    s21::stack<T>::stack(size_type n) : vector<T>(n) {}

    template<class T>
    s21::stack<T>::stack(std::initializer_list <value_type> const &items)
            : vector<T>(items) {}

    template<class T>
    s21::stack<T>::stack(const stack<T> &s) : vector<T>(s) {}

    template<class T>
    s21::stack<T>::stack(stack<T> &&s)

    noexcept :

    vector<T>(std::move(s)) {}

    //// Operator

    template<class T>
    typename s21::stack<T> &s21::stack<T>::operator=(stack<T> &&s)

    noexcept {
    s21::vector<T>::operator=(std::move(s));
    return *this;
}

//// Element access
template<class T>
typename s21::stack<T>::const_reference s21::stack<T>::top() const {
    return s21::vector < T > ::back();
}

////Capacity
template<class T>
bool s21::stack<T>::empty() {
    return s21::vector < T > ::empty();
}

template<class T>
size_t s21::stack<T>::size() {
    return s21::vector < T > ::size();
}

//// Modifiers
template<class T>
void s21::stack<T>::push(const_reference value) {
    s21::vector < T > ::push_back(value);
}

template<class T>
void s21::stack<T>::pop() {
    s21::vector < T > ::pop_back();
}

} //namespace s21