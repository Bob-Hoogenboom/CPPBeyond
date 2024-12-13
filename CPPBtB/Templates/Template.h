#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Template
{
public:
    Template() {}

    void add(T element) {
        elements.push_back(element);
        std::cout << "Added element: " << element << std::endl;
    }

    void dump() {
        for (int i = 0; i < elements.size(); i++) {
            std::cout << "Dump element: " << elements[i] << std::endl;
        }
    }

    T get() {
        if (!elements.empty()) {
            std::cout << "Get first element: " << elements.back() << std::endl;
            return elements.front();
        }
        throw std::runtime_error("Template is empty!");
    }

    void put(T element) {
        std::cout << "Put element: " << element << std::endl;
        elements.insert(elements.begin(), element);
    }

    std::size_t size() const {
        std::cout << "Size of elements: " << elements.size() << std::endl;
        return elements.size();
    }

private:
	std::vector<T> elements;
};

