#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct CalculatorNode* startLocation = NULL;

struct CalculatorNode {
   float a;
   float b;
   char name[20];
   int(*fptr)(int, int);
   struct CalculatorNode* next; //다음 노드의 주소를 저장할 포인터
};

int add(int, int);
int sub(int, int);
int mul(int, int);
int divs(int, int);

int add(int a, int b)
{
   int result = a + b;
   return result;
}
int sub(int a, int b)
{
   int result = a - b;
   return result;
}
int mul(int a, int b)
{
   int result = a * b;
   return result;
}
int divs(int a, int b)
{
   float result = (float)a / (float)b;
   return result;
}

int main()
{
   while (1) {
      printf("Choose->1.노드생성 2.노드모두출력 3.노드결과모두출력 4.노드모두삭제 5.종료:\n");

      int i;
      scanf("%d", &i);

      if (i == 5)
      {
         printf("종료합니다");
         break;
      }
      switch (i)
      {
      case 1:
         printf("노드 생성 모드입니다. 숫자 2개 입력\n");

         float a;
         float b;
         char sign;
         printf("Enter the num1:");
         scanf("%f", &a);
         printf("Enter the num2:");
         scanf("%f", &b);
         printf("Enter the Calculator sing(e.g. '+', '-', '*', '/'):");
         scanf("\n%c", &sign);
         struct CalculatorNode* node =malloc(sizeof(struct CalculatorNode));
         node->a = a;
         node->b = b;
         node->next = NULL;

         int(*fptr)(int, int)=NULL;
         int x;

         if (sign == '+')
         {
            fptr = add;
            x = fptr(a, b);
            printf("%d\n", x);
         }
         if (sign == '-')
         {
            fptr = sub;
            x = fptr(a, b);
            printf("%d\n", x);
         }
         if (sign == '*')
         {
            fptr = mul;
            x = fptr(a, b);
            printf("%d\n", x);
         }
         if (sign == '/')
         {
            fptr = divs;
            x = fptr(a, b);
            printf("%d\n", x);
         }

         node->fptr = fptr;

         if (startLocation == NULL) {
            startLocation = node;
         }

         else
         {
            struct CalculatorNode* temp = startLocation;
            if (temp == NULL) {
               startLocation = temp;
            }
            else {
               while (1)
               {
                  if (temp->next == NULL)
                  {
                     temp->next = node;
                     break;
                  }

                  else
                     temp = temp->next;
               }
            }
            printf("노드를 생성하고 추가했습니다.");
         }

         break;
      case 2:
         if (startLocation == NULL)
         {
            printf("노드가 하나도 없음\n");
         }
         else
         {
            struct CalculatorNode* temp = startLocation;
            while (1)
            {
               if (temp->next == NULL)
                  break;
               else
                  temp = temp->next;
            }
         }

         break;
      case 3:
         if (startLocation == NULL)
         {
            printf("노드가 하나도 없음\n");
         }
         else
         {
            struct CalculatorNode* temp = startLocation;
            while (1)
            {
               printf("%d\n",temp->fptr(temp->a, temp->b));
               if (temp->next == NULL)
               {
                  break;
               }
               else
                  temp = temp->next;
            }
         }

         break;
      case 4:
         if (startLocation == NULL)
         {
            printf("노드가 하나도 없습니다.\n");
         }
         else
         {
            struct CalculatorNode* temp = startLocation;
            while (1)
            {
               struct CalculatorNode* temp2 = temp->next;
               free(temp);
               if (temp2 == NULL)
                  break;
               else
                  temp = temp2;

            }
         }

         break;
      case 5:
         break;
      }
   }
}