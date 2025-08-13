#include <cstdio>


int main(int argc, char** argv) {
    auto len_count_arr = new size_t[argc]();
    size_t max{};

    // 문자열 길이 카운트
    for (int i = 1; i < argc; i++) {
        auto item = argv[i];    // 각 문자열 아이템
        size_t index = 0;

        // 문자열 길이 계산
        while (const auto c = item[index]) {
            len_count_arr[i]++;
            index++;
        }
    }

    // 최대값 찾기; 배열 길이 설정
    for (int i = 0; i < argc; i++) {
        if (max < len_count_arr[i]) {
            max = len_count_arr[i];
        }
    }

    // 히스토그램 생성
    auto result_arr = new size_t[max]();

    for (int i = 1; i < argc; i++) {
        result_arr[len_count_arr[i]]++;
    }

    // 결과 출력
    for (int i = 1; i <= max; i++) {
        bool is_n = false;

        if (result_arr[i] > 0) {
            printf("%d: ", i);

            for (size_t count = 0; count < result_arr[i]; count++) {
                printf("*");
                is_n = true;
            }
        }

        if (is_n) {
            printf("\n");
        }
    }


    delete[] len_count_arr;
    delete[] result_arr;
    return 0;
}