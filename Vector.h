#ifndef C_PP_STUDY_VECTOR_H
#define C_PP_STUDY_VECTOR_H

class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();
private:
    double* elem;
    int sz;
};

#endif
