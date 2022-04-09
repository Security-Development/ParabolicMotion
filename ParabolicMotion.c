#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

void mPrint(char m[32][32]){
    for(int i = 31; i > 0; i--){
        for(int j = 0; j < 32; j++){
            printf("%c ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    double vx, vy;
    double v, angle, gravity, radian, time, result, h;

    char map[32][32]; // map 값을 0으로 초기화

    for(int i = 0; i < 32; i++){
        for(int j = 0; j < 32; j++){
            map[i][j] = '□';
        }
    }

    v = 5; // 초기 속도
    angle = 70; // 던지는 각도 설정
    gravity = 0.5; // 중력
    radian = angle * M_PI / 180; // 각도를 호도법으로 변환
    time = 0; // 시간

    //vx = v * cos(radian) * time; // x의 속도
    //vy = (v * sin(radian)* time) - (0.5 * gravity * pow(time, 2)); // y의 속도

    h = (pow(v, 2)* pow(sin(radian), 2)) / (2 * gravity); // 최고 높이

    while(vy >= 0){
        vx = v * cos(radian) * time; // x의 시간 변화량 좌표
        vy = (v * sin(radian)* time) - (0.5 * gravity * pow(time, 2)); // y의 시간 변화량 좌표

        map[(int)vy][(int)vx] = 'A';
        printf("vx : %f \nvy : %f\nh => %f\n\n", vx, vy, h);

        time += 1;

    }

    mPrint(map);
    //printf("vx : %f \nvy : %f\nh => %f", vx, vy, h);

   return 0;
}
