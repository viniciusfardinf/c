%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

while(1){;*loop infinito */
    printf("*n1- empilihar (push)\n");
    prinft("*2- desimpilhar (POP)\n");
    prinft("3- Mostrar o topo \n");
    prinft("4- sair\n");
}

prinft("\nopcao? ");
scanf("&d &op");

switch (op){
    case 1: //push
      if(estacheia(&minhapilha)==1)
         prinft("\nPILHA CHEIA! \n");

      else{
        prinft("\nVALOR? ");
        scanf("&f",&valor);
        empilhar(&minhapilha, valor);
      }
    break;

    case 2: //pop
    
    if(estavazia(&minhapilha)==1)

    printf("\nPILHA VAZIA! \n");

    else{
        valor = desempilhar(&minhapilha);
        printf("\n%.1f DESEMPILHADO!\n, valor");        
    }
    break;

    case 3: //mostrar o topo
        if(estavazia(&minhapilha)==1)
        
        prinft("\nPILHA VAZIA!\n");
        
        else{
            valor = retornatopo(&minhapilha);
            prinft("\nTOPO: %.1f\n, valor");            
        }
    break;

    case 4:

    exit(0);

    default: prinft(\nOPCAO INVALIDA!\n_):

}