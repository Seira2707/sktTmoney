#include <stdio.h>

struct pInfo
{
    char pName[30];
    int seed;
} playerInfo;

struct coins
{
    int btc;
    int lsk;
    int neo;
    int mtl;
    int xrp;
    int eth;
    int qtum;
} coins;

void sijang(){
    
}

void jasan()
{
    printf("\n플레이어 이름 : %s\n", playerInfo.pName);
    printf("총 자산 : %d\n", playerInfo.seed);
}

int main()
{

    int select;

    printf("플레이어 이름 입력(최대 30자): ");
    scanf("%s", playerInfo.pName);

    printf("시작 seed 머니 입력(최대 1억): ");
    scanf("%d", &playerInfo.seed);

    if (playerInfo.seed > 100000000)
    {
        printf("최대 1억입니다!\n\n");
        printf("시작 seed 머니 입력(최대 1억): ");
        scanf("%d", &playerInfo.seed);
    }
    for(int i=0;i>1;i--){
        printf("\n \n \n \n \n \n \n \n \n \n");
        printf("작업 선택\n시장 보기 : 1  자산 보기 : 2  3 : 종료\n");
        scanf("%d", &select);

        if (select == 1){
            sijang();
        }
        else if (select == 2){
            jasan();
        }
        else if (select == 3){
            break;
        }
    }
    
}
