#include "s21_array.h"

class reference;
namespace s21 {

    template <class T, std::size_t N>
    array<T, N>::array() {
        fill({});
    }

    template <typename T, std::size_t N>
    array<T, N>::array(std::initializer_list<value_type> const &items) {
        std::copy(items.begin(), items.end(), arr_);
    }

    template <class T, std::size_t N>
    array<T, N>::array(const array &a) {
        std::copy(a.arr_, a.arr_ + size_, arr_);
    }

    template <typename T, std::size_t N>
    array<T, N>::array(array &&a) noexcept {
    std::move(a.arr_, a.arr_ + size_, arr_);
}

template <class T, std::size_t N>
array<T, N>::~array() {
    clear();
}

template <class T, std::size_t N>
typename s21::array<T, N> &s21::array<T, N>::operator=(
        array<T, N> &&v) noexcept {
if (this != &v) {
for (std::size_t i = 0; i < size_; ++i) {
arr_[i] = std::move(v.arr_[i]);
}
}
return *this;
}

// Element_access

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::at(size_type pos) const {
    return arr_[pos];
}

template <class T, std::size_t N>
typename array<T, N>::reference array<T, N>::operator[](size_type pos) {
    return arr_[pos];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::front() const {
    return arr_[0];
}

template <class T, std::size_t N>
typename array<T, N>::const_reference array<T, N>::back() const {
    return arr_[N - 1];
}

template <class T, std::size_t N>
typename array<T, N>::iterator array<T, N>::data() {
    return arr_;
}

// iterators
template <class T, std::size_t N>
typename s21::array<T, N>::iterator array<T, N>::begin() const {
    return Iterator(arr_);
}

template <class T, std::size_t N>
typename s21::array<T, N>::iterator array<T, N>::end() const {
    return Iterator(arr_ + size_);
}

template <class T, std::size_t N>
typename s21::array<T, N>::const_iterator array<T, N>::cbegin() const {
    return ConstIterator(arr_ + size_);
}

template <class T, std::size_t N>
typename s21::array<T, N>::const_iterator array<T, N>::cend() const {
    return ConstIterator(arr_ + size_);
}

// capacity

template <class T, std::size_t N>
bool array<T, N>::empty() const {
    return !size_;
}

template <class T, std::size_t N>
typename array<T, N>::size_type array<T, N>::size() const {
    return size_;
}

template <typename T, std::size_t N>
typename array<T, N>::size_type array<T, N>::max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(value_type);
}

// modifiers
template <class T, std::size_t N>
void array<T, N>::clear() {
    //  delete[] arr_;
}

template <class T, std::size_t N>
void array<T, N>::swap(array<T, N> &other) {
    std::swap(arr_, other.arr_);
    std::swap(size_, other.size_);
}

template <class T, std::size_t N>
void array<T, N>::fill(const_reference value) {
    for (size_type i = 0; i < size_; i++) {
        arr_[i] = value;
    }
}
}  // namespace s21