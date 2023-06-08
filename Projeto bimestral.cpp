#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int codigo [10] = {1,2,3,4,5,6,7,8,9,10} , escolhap, quant, estoque[10] = {0,10,10,10,10,10,10,10,10,10}, nestoque;
string produto [10] = {" Coca-Cola", "      água", "      H2O", "Elma chips", "  Fandangos", "Batata frita", "     Doritos", "Queijo azedo",            "      Pipoca", "caixa de bis"}, prodescolhido;
float preco [10] = {3,5,4,3,5,1,7,5,9,5}, precoesco, dinheiro, troco;

void pr_produto(int codigo[], string produto[], float preco[])
{
  
  cout << "Codigo     Produto     Preco      estoque" << endl;
     for (int i = 0; i <= 9; i++)
       {
         cout << "  " << codigo[i] << "       " << produto[i] << "    " << preco[i] << "          " << estoque[i] << endl;
       }

   cout << endl;
}




int main() 
{
  
int card = 0, cont;
  
  cout << "                    MAQUINA DE CONVENIENCIA" << endl <<endl;

  cout << "ADMINISTRADOR, insira o seu cartao de acesso:  ";
  cin >> card;
  cout << "CLIENTE, toque a tela";
  cout << endl;
  
  do 
  { cont = cont + 1;
  

    if (card == 0) // Cartao de administrador nao inserido
    {
     
      
      cout << "Bem vindo, cliente\n" << endl;
      pr_produto(codigo,produto,preco);
      cout << "Digite o codigo do produto desejado:  ";
        cin >> escolhap;

         for ( int i = 0; i <=9; i++)
           {
              if (escolhap == codigo[i])
                {
                 cout << "Produto escolhido: " << produto[i];
                  if (estoque[i] > 0)
                     {
                  prodescolhido = produto[i];
                  precoesco = preco[i];
                  nestoque = i;

              cout << endl;
      cout << "Digite a quantidade desejada: ";
      cin >> quant;
         if (quant <= estoque[nestoque])
         {
      cout << endl << endl;
      cout << quant << " de " << prodescolhido << ", custo de: " << (precoesco * quant) << " reais" << endl;
      
      cout << "Insira o dinheiro: ";
      cin >> dinheiro;
      if ((precoesco * quant) <= dinheiro)
      {
        estoque[nestoque] = estoque[nestoque] - quant;
        troco = dinheiro - (precoesco * quant);
        cout << "Troco de " << troco << " reais" << endl;
        cout << "Retire os produtos. Obrigado!" << endl << endl;}
       else
        cout << "DINHEIRO INSUFICIENTE\n\n";
         }
         else
           cout << "ESTOQUE INSUFICIENTE" << endl << endl;
                       
                     }
                  else
                    {
                    cout << " PRODUTO INDISPONIVEL" << endl << endl;
                    break;
                   
                    }
                   
                }
                
           } 
      cout << "ADMINISTRADOR, insira o seu cartao de acesso:  ";
  cin >> card;
      cout << "CLIENTE, toque a tela";
  cout << endl;
      
    } // --------------------------------------------------







   

    if (card == 1) // Cartao de administrador INSERIDO e validado
    {
      cout << "Bem vindo, ADMINISTRADOR" << endl;
      cout << "Confira os estoques de produtos\n\n";
      pr_produto(codigo,produto,preco);
      cout << endl;
      cout << "Digite o codigo do produto que deseja repor ou retire o cartao de acesso para sair: ";
      cin >> escolhap;
      if (escolhap != 0)
      {
        for ( int i = 0; i <=9; i++)
          {
          if (escolhap == codigo[i])
            {
              cout << "Digite a quantidade que deseja repor do produto " << produto[i] << ": ";
              cin >> quant;
              estoque[i] = estoque[i] + quant;
            }
              
          }
      }
      if (escolhap == 0)
      {
        cout << endl;
        card = 0;
      cout << "ADMINISTRADOR, insira o seu cartao de acesso:  ";
  cin >> card;
        cout << "CLIENTE, toque a tela";
  cout << endl;
      }
    } // ---------------------------------------------------
  } 
  while(true);    

return 0;
}
