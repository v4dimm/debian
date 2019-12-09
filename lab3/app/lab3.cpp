#include <iostream>
#include <iomanip>

int funcc(int n)
{       int t;
        asm("fabs");
        asm("fld %0"::"m"(n));
        asm("fstp %0":"=m"(t));
        return t;
}

void tran(int matrix[3][3])
{
        int t;
        for (int i=0; i < 3; i++)
        {
                for (int j=i; j < 3; j++)
                {
                        //t = matrix[i][j];
                                funcc(matrix[i][j]);
                                matrix[i][j] = matrix[j][i];
                                matrix[j][i] = t;
                }
        }
}


int main() {
        int m[3][3] =
        {
         {1,2,3},
         {4,5,6},
         {7,8,9}
        };

        tran(m);
        for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                        printf("%d", m[i][j]);
                }
                printf("\n");
        }
        return 0;
}