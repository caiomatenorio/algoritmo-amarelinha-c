#include <stdio.h>

int arrayLength(int array[2])
{
  if (array[1] == -1)
  {
    return 1;
  }
  else
  {
    return 2;
  }
}

void printLocal(int local[2])
{
  if (local[0] == 0 && local[1] == -1)
  {
    printf("Você está no início da amarelinha\n");
  }
  else if (local[0] == 10)
  {
    printf("Você está no céu\nVocê se virou\n");
  }
  else if (arrayLength(local) == 2)
  {
    printf("Você pisou com dois pés em %i e %i\n", local[0], local[1]);
  }
  else
  {
    printf("Você pisou com um pé em %i\n", local[0]);
  }
}

int isIn(int array[2], int value)
{
  for (int i = 0; i < arrayLength(array); i++)
  {
    if (array[i] == value)
    {
      return 1;
    }
  }
  return 0;
}

int main(void)
{
  int pedraEm;
  int proximaCasa[2];
  int amarelinha[9][2] = {{0, -1}, {1, -1}, {2, -1}, {3, 4}, {5, -1}, {6, -1}, {7, 8}, {9, -1}, {10, -1}};
  int rodada = 1;
  int indice = 3;
  int pesEm[2] = {amarelinha[indice][0], amarelinha[indice][1]};

  while (rodada < 10)
  {
    pedraEm = rodada;
    printf("A pedra foi jogada na casa %i\n", pedraEm);

    while (pesEm[0] != 10)
    {
      printLocal(pesEm);
      proximaCasa[0] = amarelinha[indice + 1][0];
      proximaCasa[1] = amarelinha[indice + 1][1];
      if (isIn(proximaCasa, pedraEm))
      {
        if (arrayLength(proximaCasa) == 2)
        {
          indice++;
          pesEm[0] = amarelinha[indice][0];
          pesEm[1] = amarelinha[indice][1];
          if (pesEm[0] == pedraEm)
          {
            pesEm[0] = pesEm[1];
            pesEm[1] = -1;
          }
          else
          {
            pesEm[1] = -1;
          }
        }
        else
        {
          indice += 2;
          pesEm[0] = amarelinha[indice][0];
          pesEm[1] = amarelinha[indice][1];
        }
      }
      else
      {
        indice++;
        pesEm[0] = amarelinha[indice][0];
        pesEm[1] = amarelinha[indice][1];
      }
    }

    while (pesEm[0] != 0)
    {
      printLocal(pesEm);
      proximaCasa[0] = amarelinha[indice - 1][0];
      proximaCasa[1] = amarelinha[indice - 1][1];
      if (isIn(proximaCasa, pedraEm))
      {
        printf("Você pegou a pedra\n");
        if (arrayLength(proximaCasa) == 2)
        {
          indice--;
          pesEm[0] = amarelinha[indice][0];
          pesEm[1] = amarelinha[indice][1];
          if (pesEm[0] == pedraEm)
          {
            pesEm[0] = pesEm[1];
            pesEm[1] = -1;
          }
          else
          {
            pesEm[1] = -1;
          }
        }
        else
        {
          indice -= 2;
          pesEm[0] = amarelinha[indice][0];
          pesEm[1] = amarelinha[indice][1];
        }
      }
      else
      {
        indice--;
        pesEm[0] = amarelinha[indice][0];
        pesEm[1] = amarelinha[indice][1];
      }
    }
    rodada++;
    printf("\n");
  }

  printf("Você venceu a amarelinha\n");
}