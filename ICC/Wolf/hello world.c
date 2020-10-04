struct coordenadas {
    int maior_linha;
    int menor_linha;
    int maior_coluna;
    int menor_coluna;
};

coordenadas maior_e_menor_coordenadas(int **matriz, int linhas, int colunas) {
    int maior = -100000, menor = 100000;
    coordenadas retorne;
    for (int i = 0; i < linhas; i++)
        {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] > maior) {
                retorno.maior_linha = i;
                retorno.maior_coluna = j;
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                retorno.menor_linha = i;
                retorno.menor_coluna = j;
                menor = matriz[i][j];
            }
        }
    }
    return (retorne);
}
