#pragma once

#include <iostream>

class Concrete {
public:
    Concrete();
    ~Concrete();

    virtual void abstract_method();
    virtual void concrete_method();

    void array_method(int* ad, int size);
    void array_method(double* ad, int size);

    void uint_ref_assign(unsigned int& target, unsigned int value);

    operator const char*();

public:
    double m_data[4];
    int m_int;
    const int m_const_int;
    
    static int s_int;

};

