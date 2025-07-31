#include<cstdio>
#include<vector>
#include <algorithm>


int mode(const int* values, size_t length) {    // 최빈값
    if (length == 0) {
        return 0;
    }

    std::vector<int> sorted_vector(values, values+length);
    std::sort(sorted_vector.begin(), sorted_vector.end());

    // init
    int mode_value = sorted_vector[0];
    int current_value = sorted_vector[0];
    int current_count = 1;
    int max_count = 1;
    int mode_count = 1; // 무결성 검사

    for (size_t i = 1; i < length; i++) {
        if (sorted_vector[i] == current_value) {    // 현재 값 <-> 기준 값 비교; 카운트 증가
            current_count += 1;
        } else {    // 기준 값 변경; 해당 값 카운트 종료
            current_value = sorted_vector[i];
            current_count = 1;
        }

        if (current_count > max_count) {    // mode 갱신
            max_count = current_count;
            mode_value = current_value;
            mode_count = 1;
        }
        else if (current_count == max_count && mode_value != current_value) {   // 카운트 동일, 값 다름; 중복 의심
            mode_count += 1;
        }
    }

    return (mode_count == 1) ? mode_value : 0;
}



