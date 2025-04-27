#include <stdio.h>
#include <math.h>
#define Max 10 //最大概率数量

int main(){
    int X;//概率个数
    double p[Max];//概率
    double I=0,H=0;//概率和，信源熵
    int retry;//用于验证

    while(1){//验证输入正确性
        printf("请输入概率数量:\n\r");
        scanf("%d",&X);
        if(X<1||X>Max){
        printf("错误，概率数量最大为%d,请重新输入。\n\r",Max);
        }
        else break;
    }

    do{
        retry=0;
        for(int i=0;i<X;i++){//输入概率值
            printf("请输入第%d个概率值:\n\r",i+1);
            scanf("%lf",&p[i]);
        
            if(p[i]<0||p[i]>1){
                printf("错误，概率范围为[0,1]\n\r");
                i--;//纠错
            }
            else{
                I+=p[i];
            }
        }

        if(fabs(I-1.0)>1e-6){//验证概率之和
            I=0;
            printf("概率之和应为1，请重新输入所有概率值！\n\r");
            retry=1;
    }
    }while(retry);

    for(int i=0;i<X;i++){//计算信源熵H
        if(p[i]>0){
            H+=p[i]*log2(p[i]);
        }
    }
    H=-H;
    
    printf("信源熵H(X)为:%.6f bit/sign\n\r",H);
    return 0;
}
