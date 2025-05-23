//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \|
//                / _||||| -:- |||||- \|
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Dao Trong Nguyen _ 20235390 _ IT2-03 _ IT3040 _ 750829_ 2024.2

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data_90;
    struct Node* next_90;
} Node;

Node* prepend(Node* head_90, int data_90) {
    Node* newNode_90 = (Node*)malloc(sizeof(Node));
    newNode_90->data_90 = data_90;
    newNode_90->next_90 = head_90;
    return newNode_90;
}

void print(Node* head_90) {
    Node* curr_90 = head_90;
    while(curr_90 != NULL) {
        printf("%d ", curr_90->data_90);
        curr_90 = curr_90->next_90;
    }
    printf("\n");
}

Node* reverse(Node* head_90) {
    Node* prev_90 = NULL;
    Node* curr_90 = head_90;
    while(curr_90 != NULL) {
        Node* nextNode_90 = curr_90->next_90;
        curr_90->next_90 = prev_90;
        prev_90 = curr_90;
        curr_90 = nextNode_90;
    }
    return prev_90;
}

int main() {
    int n_90, u_90;
    scanf("%d", &n_90);
    Node* head_90 = NULL;
    for(int i = 0; i < n_90; ++i) {
        scanf("%d", &u_90);
        head_90 = prepend(head_90, u_90);
    }
    printf("Original list: ");
    print(head_90);
    head_90 = reverse(head_90);
    printf("Reversed list: ");
    print(head_90);
    return 0;
}