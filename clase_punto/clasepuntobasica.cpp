// Ejercicio:
// Autor:DEK
// Fecha:
// Comentario:

#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <windows.h>

using namespace std;

/// DEFINICIONES DE CONSTANTES Y FUNCIONES QUE SON UTILIZADAS POR LA CLASE PUNTO
enum Color {
  cNEGRO = 0,
  cAZUL = 1,
  cVERDE = 2,
  cCIAN = 3,
  cROJO = 4,
  cMAGENTA = 5,
  cMARRON = 6,
  cGRIS_CLARO = 7,
  cGRIS = 8,
  cAZUL_CLARO = 9,
  cVERDE_CLARO = 10,
  cCIAN_CLARO = 11,
  cROJO_CLARO = 12,
  cMAGENTA_CLARO = 13,
  cAMARILLO = 14,
  cBLANCO = 15
};
/// Se definen una serie de constantes que asumen el valor que se le asignó.
/// Es más fácil usar cBLANCO para setear el color a blanco, que acordarse el
/// número 15

int tcols(void) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    return -1;
  else
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int trows(void) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    return -1;
  else
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void ocultarCursor() {
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 100;
  info.bVisible = FALSE;
  SetConsoleCursorInfo(consoleHandle, &info);
}

void mostrarCursor() {
  HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO info;
  info.dwSize = 10;
  info.bVisible = TRUE;
  SetConsoleCursorInfo(consoleHandle, &info);
}

void gotoxy(short x,
            short y) { /// UBICA EL CURSOR EN LA POSICIÓN x,y DE LA PANTALLA
  COORD a;
  a.X = x;
  a.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
/// ASIGNA COLORES AL TEXTO Y AL FONDO DEL TEXTO
void textcolor(int colorTexto = 15, int colorFondo = 0) {
  int color = colorTexto + colorFondo * 16;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

///**FIN FUNCIONES

/// CLASE PUNTO
class Punto {
private:
  int x;
  int y;
  int color;

public:
  Punto(int a = 0, int b = 0, int nuevoColor = cNEGRO) {
    x = a;
    y = b;
    color = nuevoColor;
  }
  void Mostrar() {
    textcolor(color, 15);
    gotoxy(x, y);
    cout << (char)219;
  }
  void MostrarValores();
  void Ocultar() {
    gotoxy(x, y);
    cout << " ";
  }
  void setX(int valor) {
    if (valor >= 0 && valor < tcols())
      x = valor;
  }
  void setY(int valor) {
    if (valor >= 0 && valor < trows())
      y = valor;
  }

  void setColor(int nuevo) {
    if (nuevo > 0 && nuevo <= 15) {
      color = nuevo;
    } else {
      color = nuevo % 16;
    }
  }
  int getX() { return x; }
  int getY() { return y; }
  int getColor() { return color; }
  ~Punto() { /// DESTRUCTOR: se ejecuta cuando el objeto cae fuera de su
    /// alcance.
    textcolor(cNEGRO, cBLANCO);
  }
};

void Punto::MostrarValores() {
  cout << x << endl;
  cout << y << endl;
  cout << color << endl;
}

void punto1(bool parpadear = false) {
  Punto obj(10, 5, cAZUL);
  int x, y;
  cout << "INGRESE LA COORDENADA X: ";
  cin >> x;
  cout << "INGRESE LA COORDENADA Y: ";
  cin >> y;
  obj.setX(x);
  obj.setY(y);
  system("cls");

  if (parpadear) {
    while (!kbhit()) {
      obj.Mostrar();
      Sleep(150);
      obj.Ocultar();
      Sleep(150);
    }
  } else {
    obj.Mostrar();
  }
}

void caminarHorizontal() {
  Punto obj(0, trows() / 2, cAZUL);
  int cols{tcols()};
  int i{0};
  while (!kbhit()) {
    obj.setX(i);
    obj.Mostrar();
    Sleep(20);
    obj.Ocultar();
    ++i;
    if (i > cols - 1)
      i = 0;
  }
}

void caminarVertical() {
  Punto obj(tcols() / 2, 0, cAZUL);
  int rows{trows()};
  int i{0};
  while (!kbhit()) {
    obj.setY(i);
    obj.Mostrar();
    Sleep(20);
    obj.Ocultar();
    ++i;
    if (i > rows - 1)
      i = 0;
  }
}

void movDiagonal(Punto &obj, int cols, int rows) {
  int x = obj.getX() + 1;
  int y = obj.getY() + 1;
  x >= cols ? obj.setX(0) : obj.setX(x);
  y >= rows ? obj.setY(0) : obj.setY(y);
}

void llover(bool esperarTecla = false) {
  int rows = trows();
  int cols = tcols();
  const int CANT = 7;
  Punto obj[CANT];

  for (int i = 0; i < CANT; ++i) {
    if (i * 30 < cols) {
      obj[i].setX(i * 30);
    } else {
      obj[i].setX((i * 30) % cols);
    }
    if (i * 4 < rows) {
      obj[i].setY(i * 4);
    } else {
      obj[i].setY((i * 4) % rows);
    }

    obj[i].setColor(cAZUL);
  }

  if (esperarTecla) {
    while (!kbhit()) {
      for (int j = 0; j < CANT; ++j) {
        movDiagonal(obj[j], cols, rows);
        obj[j].Mostrar();
      }
      Sleep(20);
      for (int j = 0; j < CANT; ++j) {
        obj[j].Ocultar();
      }
    }
  } else {
    int i{};
    while (i < 121) {
      for (int j = 0; j < CANT; ++j) {
        movDiagonal(obj[j], cols, rows);
        obj[j].Mostrar();
      }
      Sleep(20);
      for (int j = 0; j < CANT; ++j) {
        obj[j].Ocultar();
      }
      ++i;
    }
  }
}

void punto2(bool alternar = false) {
  cout << "INGRESE LA COORDENADA Y: ";
  int y{};
  cin >> y;

  system("cls");

  Punto obj(0, y, cAZUL);
  for (int i = 0; i < tcols(); ++i) {
    if (alternar)
      obj.setColor((i % 2) + 1);
    obj.setX(i);
    obj.Mostrar();
  }
}

void punto3(bool alternar = false) {
  cout << "INGRESE LA COORDENADA X: ";
  int x{};
  cin >> x;

  system("cls");

  Punto obj(x, 0, cAZUL);
  for (int i = 0; i < trows(); ++i) {
    if (alternar)
      obj.setColor((i % 2) + 1);
    obj.setY(i);
    obj.Mostrar();
  }
}

void punto6(bool hacerMas = false) {
  int rows = trows();
  int cols = tcols();
  int y{rows / 2};

  Punto obj(0, y, cAZUL);
  Punto obj2(cols, y, cVERDE);

  for (int i = 0; i < cols / 2; ++i) {
    obj.setX(i);
    obj2.setX(obj2.getX() - 1);
    obj.Mostrar();
    obj2.Mostrar();
    Sleep(12);
  }

  if (hacerMas) {
    for (int i = obj.getY(); i >= 0; --i) {
      obj.setY(i);
      obj2.setY(i);
      obj.Mostrar();
      obj2.Mostrar();
      Sleep(12);
    }
  }
}

void dibujarRectangulo() {
  int rows = trows();
  int cols = tcols();
  cout << "INGRESE BASE: ";
  int b{};
  cin >> b;
  cout << "INGRESE ALTURA: ";
  int h{};
  cin >> h;

  system("cls");

  int inicioX = (cols / 2) - (b / 2);
  int inicioY = (rows / 2) - (h / 2);
  Punto obj(inicioX, inicioY, cAZUL);

  for (int i = inicioX, n = inicioX + b; i < n; ++i) {
    obj.setX(i);
    obj.Mostrar();
  }

  for (int i = inicioY, n = inicioY + h; i < n; ++i) {
    obj.setY(i);
    obj.Mostrar();
  }

  for (int i = obj.getX(); i >= inicioX; --i) {
    obj.setX(i);
    obj.Mostrar();
  }

  for (int i = obj.getY(); i > inicioY; --i) {
    obj.setY(i);
    obj.Mostrar();
  }
}

int main() {
  srand(time(NULL));
  ocultarCursor();
  textcolor(0, 15);
  int opc;
  while (true) {
    system("cls");
    cout << "----------MENU------------" << endl;
    cout << "1. DIBUJAR UN PUNTO EN LA POSICION QUE EL USUARIO PIDA POR TECLADO"
         << endl;
    cout << "2. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL EN UNA POSICION DEL EJE "
            "Y DEFINIDA"
         << endl;
    cout << "3. DIBUJAR UNA LINEA DE PUNTOS VERTICAL EN UNA POSICION DEL EJE X "
            "DEFINIDA"
         << endl;
    cout << "4. DIBUJAR UNA LINEA DE PUNTOS HORIZONTAL QUE ALTERNE 2 COLORES"
         << endl;
    cout << "5. DIBUJAR UNA LINEA DE PUNTOS VERTICAL QUE ALTERNE 2 COLORES"
         << endl;
    cout << "6. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE "
            "LA PANTALLA "
         << endl;
    cout << " Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE "
            "DISTINTOS COLORES "
         << endl;
    cout << "7. DIBUJAR 2 LINEAS HORIZONTALES QUE NAZCAN EN AMBOS EXTREMOS DE "
            "LA PANTALLA "
         << endl;
    cout << " Y SE ENCUENTREN EN EL CENTRO DE LA PANTALLA. DEBEN SER DE "
            "DISTINTOS COLORES "
         << endl;
    cout << " AL ENCONTRARSE DEBEN LAS LINEAS DEBEN SUBIR HASTA LA POSICIÓN 0 "
            "DE Y "
         << endl;
    cout << "8. HACER UN PUNTO QUE PARPADEE EN LA PANTALLA EN UNA POSICION DADA"
         << endl;
    cout << "9. HACER UN RECTANGULO A PARTIR DE DOS VALORES DE 2 LADOS" << endl;
    cout << "10. HACER UN PUNTO QUE CAMINE POR LA PANTALLA DE MANERA HORIZONTAL"
         << endl;
    cout << "11. HACER UN PUNTO QUE SE DESPLAZE POR LA PANTALLA DE MANERA "
            "VERTICAL"
         << endl;
    cout << "12. DIBUJAR UNA LLUVIA DE PUNTOS" << endl;
    cout << "13. DIBUJAR UNA LLUVIA DE PUNTOS HASTA QUE SE PRESIONA UNA TECLA"
         << endl;
    cout << "OPCION: ";
    cin >> opc;
    system("cls");
    switch (opc) {
    case 1:
      punto1();
      break;
    case 2:
      punto2();
      break;
    case 3:
      punto3();
      break;
    case 4:
      punto2(true);
      break;
    case 5:
      punto3(true);
      break;
    case 6:
      punto6();
      break;
    case 7:
      punto6(true);
      break;
    case 8:
      punto1(true);
      break;
    case 9:
      dibujarRectangulo();
      break;
    case 10:
      caminarHorizontal();
      break;
    case 11:
      caminarVertical();
      break;
    case 12:
      llover();
      break;
    case 13:
      llover(true);
      break;
    case 0:
      return 0;
    }
    system("pause>nul");
  }
  return 0;
}

/**
A partir de la clase Punto resolver lo siguiente:

8) Hacer un punto que parpadee en la pantalla en una posición dada.
9) Hacer un rectangulo, a partir de los valores de 2 lados
10) Hacer un punto que camine por la pantalla de manera horizontal
11) Hacer un punto que se desplaze por la pantalla de manera vertical
12) Hacer una lluvia de puntos aleatoria en la pantalla.
13) Igual que el anterior, pero debe terminar el programa cuando se
toca una tecla
Para este último hay una función que se llama kbhit()

Pueden agregar los métodos que consideren necesarios.
**/
