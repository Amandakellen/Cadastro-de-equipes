#include <iostream>//biblioteca padrao c++
#include<conio.h>//foi ultilizada para  a funcao getch()
#include <cstdlib>
#define cont 10
using namespace std;
struct olimpiada
{
    char nome[100];
    int nmedalhas[3];
    int pontuacao;
};
void cadastro(olimpiada time[cont] );
void imprime(olimpiada time[cont]);
void placar(olimpiada time[cont]);
int main()
{
    olimpiada equipe[cont];
    cadastro(equipe);
    placar(equipe);
    imprime(equipe);
    getch();
}

void cadastro(olimpiada time[cont])
{
      int i,soma=0;
    for(i=0;i<cont;i++)
    {
        cout<<"\nEquipe "<<i+1<<":";//equivalente a printf

        cin>>time[i].nome;//equivalente a scanf
        cout<<"\nMedalhas de ouro:";

        cin>>time[i].nmedalhas[0];
        soma=3*time[i].nmedalhas[0];
        cout<<"\nMedalhas de prata:";

        cin>>time[i].nmedalhas[1];
        soma+=2*time[i].nmedalhas[1];
        cout<<"\nMedalhas de bronze:";

        cin>>time[i].nmedalhas[2];

        soma+=1*time[i].nmedalhas[2];
        time[i].pontuacao=soma;
        soma=0;
        system("clear||cls");

    }
}

void placar(olimpiada time[cont])//Faz a compara��o das pontiua��es
{
     int i, j;
     olimpiada aux;
     for(i=0;i<cont-1;i++)
     {
         for(j=i+1;j<cont;j++)
         {
              if(time[j].pontuacao==time[i].pontuacao)//se as pontua��es s�o  iguais,para verificar a coloca��o � analisado o numero de medalhas
             {
                 if(time[j].nmedalhas[0]>time[i].nmedalhas[0])//se o  numero de medalhas de ouro da posi��o j for maior q a da posi��o i � feito a troca
                 {
                   aux=time[i];
                   time[i]=time[j];
                   time[j]=aux;
                 }
                 else
                 {
                      if(time[j].nmedalhas[0]==time[i].nmedalhas[0])//se o numero de medalhas de outro da posi��o j e i forem iguais
                    {
                         if(time[j].nmedalhas[1]>time[i].nmedalhas[1])//se o numero de medalhas de prata de j for maior q a de i
                          {
                           aux=time[i];
                           time[i]=time[j];
                           time[j]=aux;
                          }
                         else
                         {
                            if(time[j].nmedalhas[1]==time[i].nmedalhas[1])//se o numero de medalhas de prata de i e j forem iguais
                            {
                                 if(time[j].nmedalhas[2]>time[i].nmedalhas[2])//se o numero de medalhas de bronze da posi��o  j � maior que da posicao i
                                  {
                                   aux=time[i];
                                   time[i]=time[j];
                                   time[j]=aux;
                                  }
                            }
                         }

                     }
                 }
             }
             else{//se as pontua��es n�o forem iguais
                  if(time[j].pontuacao>time[i].pontuacao)//se a pontua��o da posi��o j � maior q i
                 {
                   aux=time[i];
                   time[i]=time[j];
                   time[j]=aux;
                 }
               }


          }
     }
}

void imprime(olimpiada time[cont])
{
    int i;
    cout<<"COLOCACAO\n";
      for(i=0;i<cont;i++)
    {
        cout<<"\n"<<i+1<<"lugar:\n";
        cout<<"\nEquipe "<<i+1<<":"<<time[i].nome;
        cout<<"\nPontuacao:"<<time[i].pontuacao;
        cout<<"\n\nMedalhas:";
        cout<<"\nOuro:"<<time[i].nmedalhas[0];
        cout<<"\nPrata:"<<time[i].nmedalhas[1];
        cout<<"\nBronze:"<<time[i].nmedalhas[2];


        cout<<"\n------------------------------\n";

    }
}
