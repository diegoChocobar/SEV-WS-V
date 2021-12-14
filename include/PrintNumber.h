
void custom0(int x);
void custom1(int x);
void custom2(int x);
void custom3(int x);
void custom4(int x);
void custom5(int x);
void custom6(int x);
void custom7(int x);
void custom8(int x);
void custom9(int x);

void mostranumero(int x,int numero){ //Mostra o numero na posicao definida por "X"

  switch(numero)
    {
      case 0:custom0(x);
      break;
      case 1:custom1(x);
      break;
      case 2:custom2(x);
      break;
      case 3:custom3(x);
      break;
      case 4:custom4(x);
      break;
      case 5:custom5(x);
      break;
      case 6:custom6(x);
      break;
      case 7:custom7(x);
      break;
      case 8:custom8(x);
      break;
      case 9:custom9(x);
      break;
    }
}
void custom0(int x)//Seleciona os segmentos para formar o numero 0
{
  lcd.setCursor(x, 1); //Seleciona a linha superior
  lcd.write((byte)0);  //Segmento 0 selecionado
  lcd.write(1);  //Segmento 1 selecionado
  lcd.write(2);
  lcd.setCursor(x, 2); //Seleciona a linha inferior
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void custom1(int x) //Seleciona os segmentos para formar o numero 1
{
  lcd.setCursor(x, 1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x+1,2);
  lcd.write(5);
}

void custom2(int x) //Seleciona os segmentos para formar o numero 2
{
  lcd.setCursor(x, 1);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 2);
  lcd.write(3);
  lcd.write(7);
  lcd.write(7);
}

void custom3(int x)  //Seleciona os segmentos para formar o numero 3
{
  lcd.setCursor(x, 1);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(x, 2);
  lcd.write(7);
  lcd.write(7);
  lcd.write(5);
}

void custom4(int x)  //Seleciona os segmentos para formar o numero 4
{
  lcd.setCursor(x, 1);
  lcd.write(3);
  lcd.write(4);
  lcd.write(2);
  lcd.setCursor(x+2, 2);
  lcd.write(5);
}

void custom5(int x)  //Seleciona os segmentos para formar o numero 5
{
  lcd.setCursor(x, 1);
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 2);
  lcd.write(7);
  lcd.write(7);
  lcd.write(5);
}

void custom6(int x)  //Seleciona os segmentos para formar o numero 6
{
  lcd.setCursor(x, 1);
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(x, 2);
  lcd.write(3);
  lcd.write(7);
  lcd.write(5);
}

void custom7(int x) //Seleciona os segmentos para formar o numero 7
{
  lcd.setCursor(x, 1);
  lcd.write(1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(x+1, 2);
  lcd.write((byte)0);
}

void custom8(int x)  //Seleciona os segmentos para formar o numero 8
{
  lcd.setCursor(x, 1);
  lcd.write((byte)0);
  lcd.write((byte)6);
  lcd.write(2);
  lcd.setCursor(x, 2);
  lcd.write(3);
  lcd.write(7);
  lcd.write(5);
}

void custom9(int x)  //Seleciona os segmentos para formar o numero 9
{
  lcd.setCursor(x, 1);
  lcd.write((byte)0);
  lcd.write((byte)6);
  lcd.write((byte)2);
  lcd.setCursor(x+2, 2);
  lcd.write((byte)5);
}
