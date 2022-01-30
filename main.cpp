#include <iostream>
#include <memory>
#include "Unique.hpp"

int main() {
    std::unique_ptr<int> p{new int(5)};
    Unique<int> ptr{new int{5}};

    std::cout << *p << ' ' << *ptr << '\n';
    std::cout << p.get() << ' ' << ptr.get() << '\n';

    auto rawP = p.release();
    auto rawPtr = ptr.release();
    delete rawP;
    delete rawPtr;

    //std::cout << *p << '\n';
    //std::cout << *ptr << '\n';

    std::unique_ptr<int> p2{new int(3)};
    Unique<int> ptr2{new int{3}};
    std::unique_ptr<int> p3;
    std::cout << *ptr2 << '\n';
    //p3 = p2;
    Unique<int> ptr3 = std::move(ptr2);
    //ptr3 = ptr2;
    // std::cout << *p2 <<  << '\n';
    std::cout << *ptr3 << '\n';
    p3 = std::move(p2);
    // ptr3 = std::move(ptr2);

    // std::cout << *p3 << ' ' << *ptr3 << '\n';
    ptr3.reset(new int{10});
    std::cout << *ptr3 << '\n';
    ptr3.reset();


    return 0;
}