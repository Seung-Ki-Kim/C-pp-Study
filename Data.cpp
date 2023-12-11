#include <string>
#include "Data.h"
using namespace std;

template <typename Type>
Data<Type>::Data(Type data) {
    data_ = data;
}

template <typename Type>
Type Data<Type>::GetData() {
    return data_;
}

Data<Double_t>::Data(Double_t data) {
    data_ = data;
}

double Data<Double_t>::GetData() {
    return data_ * 2;
}

template class Data<string>;
template class Data<Double_t>;