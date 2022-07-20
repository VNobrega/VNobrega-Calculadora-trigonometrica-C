//Desenvolvido por Vítor Nóbrega Vieira 
#include <stdio.h>
#include <math.h>  

void msg(int modo){ //Imprime mensagem de ajuda
    if (modo == 0) printf("\nModo: radianos\n\n");
    else printf("\n\nModo: graus\n\n");
    printf("1 - seno\n2 - cosseno\n3 - tangente\n4 - secante\n5 - cossecante\n6 - cotangente\n7 - arco seno\n8 - arco cosseno\n9 - arco tangente\n10 - mudar modo\n11 - ajuda\n0 - cancelar\n");
    
}

double receberAng(int modo){ //recebe angulo para operacoes
    double ang;
    if (modo == 0) printf("\nIndique o valor do angulo em radianos:\n");
    else printf("\nIndique o valor do angulo em graus:\n");
    scanf("%lf", &ang);
    return ang;
}

double receberArc(char *c){ //recebe o arco para operacoes
    double ang;
    printf("\nIndique o valor do %s:\n", c);
    scanf("%lf", &ang);
    return ang;
}

double convert(double ang, int modo){ //converte angulo de grau pra rad
    if(modo == 1) ang=ang*M_PI/180;	
    return ang;
}

double convertInv(double res, int modo){ //converte angulo de rad pra grau
    if(modo == 1) res=res*180/M_PI;	
    return res;
}

void result(char *c, int modo, double ang, double res){ //calcula e imprime operacoes que recebem angulo
    if (modo == 0) printf("\n%s de %.2lf radianos = %.2lf\n", c, ang, res);
    else printf("\n%s de %.2lf° = %.2lf\n", c, ang, res);
}

void resultInv(char *c, int modo, double ang, double res){ //calcula e imprime operacoes que recevem arco
    if (modo == 0) printf("\n%s de %.2lf = %.2lf radianos\n", c, ang, res);
    else printf("\n%s de %.2lf = %.2lf°\n", c, ang,convertInv(res, modo));
}

int mudar(int modo){ //Muda de rad pra graus (e vice-versa)
    int mod;
    if(modo == 0){
        mod = 1;
        printf("Modo mudado para graus.\n");
    }
    else{
        mod = 0;
        printf("Modo mudado para radianos.\n");
    }

    return mod;
}

void menu(){ //Menu da calculadora
    double ang, res;
    int aux = 1, op, modo = 0;
    printf("#######################################################");
    msg(modo);

    do{
        printf("\nIndique a operacao desejada:\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:     
            ang = receberAng(modo);
            res = sin(convert(ang, modo));
            result("Seno", modo, ang, res);
            break;      
        case 2:
            ang = receberAng(modo);
            res = cos(convert(ang, modo));
            result("Cosseno", modo, ang, res);
            break;
        case 3:
            ang = receberAng(modo);
            res = tan(convert(ang, modo));
            result("Tangente", modo, ang, res);
            break;
        case 4:
            ang = receberAng(modo);
            res = 1/cos(convert(ang, modo));
            result("Secante", modo, ang, res);
            break;
        case 5:
            ang = receberAng(modo);
            res = 1/sin(convert(ang, modo));
            result("Cossecante", modo, ang, res);
            break;
        case 6:
            ang = receberAng(modo);
            res = 1/tan(convert(ang, modo));
            result("Cotangente", modo, ang, res);
            break;
        case 7: 
            ang = receberArc("seno");
            res = asin(ang);
            resultInv("Arco seno", modo, ang, res);
            break;
        case 8:
            ang = receberArc("cosseno");
            res = acos(ang);
            resultInv("Arco cosseno", modo, ang, res);
            break;
        case 9:
            ang = receberArc("tangente");
            res = atan(ang);
            resultInv("Arco tangente", modo, ang, res);
            break;
        case 10:
            modo = mudar(modo);
            break;
        case 11:
            msg(modo);
            break;
        case 0:
            aux = 0;
            break;
        default:
            printf("Comando invalido.\n");
            break;
        }
    printf("\n#######################################################\n");
    }while(aux == 1);
}

int main(){
   
    menu();

    return 0;

}