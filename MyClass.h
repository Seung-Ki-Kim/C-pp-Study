#ifndef C_PP_STUDY_MYCLASS_H
#define C_PP_STUDY_MYCLASS_H


class MyClass {
public:
    MyClass(int a, int b);
    void myPrint();
    ~MyClass();
protected:
private:
    int regVar;
    const int constVar;
};


#endif //C_PP_STUDY_MYCLASS_H
