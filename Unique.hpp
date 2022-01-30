#pragma once

template <class T>
class Unique {
public:
    Unique();
    Unique(T* ptr);
    ~Unique();

    Unique(const Unique<T>&) = delete;
    Unique<T>& operator=(const Unique<T>&) = delete;

    Unique(Unique&& otherPointer) noexcept;
    Unique<T>& operator=(Unique&& otherPointer);

    T& operator*() const;
    T* operator->() const;

    T* get() const;
    T* release();
    void reset(T* newPtr);

private:
    T* data_{};
};

template <class T>
Unique<T>::Unique()
    : data_(nullptr) {}

template <class T>
Unique<T>::Unique(T* ptr)
    : data_(ptr) {}

template <class T>
Unique<T>::Unique::~Unique() {
    delete data_;
}

template <class T>
Unique<T>::Unique(Unique<T>&& otherPointer) noexcept {
    data_ = otherPointer.data_;
    otherPointer.data_ = nullptr;
}

template <class T>
Unique<T>& Unique<T>::operator=(Unique<T>&& otherPointer) {
    if (this != &otherPointer) {
        delete data_;
        data_ = otherPointer.data_;
        otherPointer.data_ = nullptr;
    }
    return *this;
}

template <class T>
T& Unique<T>::operator*() const {
    return *data_;
}

template <class T>
T* Unique<T>::operator->() const {
    return data_;
}

template <class T>
T* Unique<T>::get() const {
    return data_;
}

template <class T>
T* Unique<T>::release() {
    T* temp = data_;
    data_ = nullptr;
    return temp;
}

template <class T>
void Unique<T>::reset(T* newPtr) {
    delete data_;
    data_ = newPtr;
}