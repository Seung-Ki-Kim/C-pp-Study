#ifndef C_PP_STUDY_DATA_H
#define C_PP_STUDY_DATA_H

typedef std::string String_t;
typedef double Double_t;

template <typename Type>
class Data {
private:
    Type data_;
public:
    Data(Type data);
    Type GetData();
};

template <> class Data<Double_t> {
private:
    Double_t data_;
public:
    Data(Double_t data);
    Double_t GetData();
};


#endif //C_PP_STUDY_DATA_H