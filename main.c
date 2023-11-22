#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100
#define MAX_COINS 100

struct pInfo
{
    char pName[30];
    int seed;
} playerInfo;

typedef struct
{
    int coins[MAX_COINS];
    int count;
} bitCoins;

void jasan()
{
    printf("\n플레이어 이름 : %s\n", playerInfo.pName);
    printf("총 자산 : %d\n", playerInfo.seed);
}

int main()
{
    int select;
    FILE *fs;
    fs = fopen("UpBitApi.txt", "r");

    if (fs == NULL)
    {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    bitCoins myBitCoins;
    myBitCoins.count = 0;

    char str[MAX_LEN];

    while (fgets(str, MAX_LEN, fs) != NULL)
    {
        char *token = strtok(str, "\n"); // 공백을 기준으로 문자열을 자름

        while (token != NULL)
        {
            if (myBitCoins.count < MAX_COINS)
            {
                myBitCoins.coins[myBitCoins.count] = atoi(token); // 문자열을 정수로 변환하여 저장
                myBitCoins.count++;
            }
            else
            {
                printf("더 이상 저장할 공간이 없습니다.\n");
                break;
            }
            token = strtok(NULL, "\n"); // 다음 토큰을 가져옴
        }
    }

    fclose(fs);

    // 저장된 정수 출력 (테스트용)
    printf("저장된 정수:\n");
    for (int i = 0; i < myBitCoins.count; i++)
    {
        printf("%d ", myBitCoins.coins[i]);
    }
    printf("\n");

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
    for (int i = 0; i > 1; i--)
    {
        printf("\n \n \n \n \n \n \n \n \n \n");
        printf("작업 선택\n시장 보기 : 1  자산 보기 : 2  3 : 종료\n");
        scanf("%d", &select);

        if (select == 1)
        {
            for (int i = 0; i < myBitCoins.count; i++)
            {
                printf("%d번 코인 가격 : %d\n", i, myBitCoins.coins[i]);
            }

            int coinIndex, quantity;
            printf("몇 번 코인을 몇 개 구매하시겠습니까? (코인번호 수량): ");
            scanf("%d %d", &coinIndex, &quantity);

            if (coinIndex < 0 || coinIndex >= myBitCoins.count)
            {
                printf("잘못된 코인 번호입니다.\n");
            }
            else if (quantity < 0)
            {
                printf("잘못된 수량입니다.\n");
            }
            else
            {
                int totalPrice = myBitCoins.coins[coinIndex - 1] * quantity;

                if (totalPrice > playerInfo.seed)
                {
                    printf("자산이 부족합니다.\n");
                }
                else
                {
                    // 코인 구매 처리
                    playerInfo.seed -= totalPrice; // 자산 업데이트
                    printf("%d번 코인을 %d개 구매하셨습니다.\n", coinIndex, quantity);
                    printf("현재 자산: %d\n", playerInfo.seed);
                    // 구매에 따른 플레이어 자산 업데이트
                    // 필요한 추가 로직을 여기에 작성하세요
                }
            }
        }
        else if (select == 2)
        {
            jasan();
        }
        else if (select == 3)
        {
            break;
        }
    }
    return 0;
}
