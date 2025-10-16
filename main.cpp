#include <iostream>

int main() {
    int codeArray[48] = {16, 6, 19, 24, 14, 11, 18, 12, 15, 17, 2, 13, 22, 7, 10, 3, 23, 5, 20, 8, 9, 1, 4, 21, 116, 108, 32, 33, 104, 119, 101, 105, 32, 104, 111, 116, 97, 117, 32, 111, 109, 32, 101, 99, 107, 71, 100, 120};
    int* pointerArray[24] = {};
    int n = 24;

    // TODO: Implement the main function to print out secret code from codeArray using pointerArray.

    //  1) Build an index map:
    //     Scan the first half of codeArray. Each position p contains a rank from 1 to n.
    //     At index i of pointerArray, store a pointer to the cell in ascending order of rank.

    //  2) Decode and print:
    //     Iterate index of pointerArray i from 0 to n-1.
    //     For each i, move forward by n elements to reach the paired ASCII code in the second half of codeArray.
    //     Convert that ASCII value to a character and print it.

    for ( int i = 0; i < n; i++) {
        int rank = codeArray[i];
        pointerArray[rank - 1] = &codeArray[i]; // <= 포인터 자체의 값(주소)를 변경하는 코드, 포인터가 codeArray[i]의 주소를 가리키도록 하는 것
                                                // *pointerArray[rank - 1] = &codeArray[i]; => 정수형 변수에 주소값을 대입하려고 하는 것 => 오류
    }                                           // pointerArray[i] -> int*형 포인터 변수
                                                // codeArray[i] → int형 값
                                                //  &codeArray[i] → int*형 주소값
    for (int i = 0; i < n; i++) {
        int value = *(pointerArray[i] + n); // 포인터 + 정수 연산 가능, 포인터 + 포인터 => 오류
        std::cout << static_cast<char>(value); // std::endl은 단순히 \n처럼 줄바꿈을 넣는다. + 버퍼 비운다.
    }

    return 0;


}
