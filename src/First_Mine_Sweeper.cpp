#include <iostream>
#include <string.h>
#define log(x) std::cout<<x

class Mine{
  public:
    int xm, ym;
    void set_rc(int rowm, int columnM){
      xm=rand() % rowm;
      ym=rand() % columnM;
    }
};

class Minesweeper
{
  public:
    int lost=false;
    int flag=true;
    int level;
    int rows = 0, columns = 0;
    int mines = 0;
    int x = 0, y = 0;
    //int arr;

    //constructor
    Minesweeper(int Level)
      :level(Level)
    {
      log("el nivel es: ")<<level<<std::endl;
      set_level(level);
    }

    //check level and set rows, columns and mines
    void set_level(int level){
      if (level==1){
        //small grid
        log("Facil")<<std::endl;
        rows    = 4;
        columns = 6;
        mines   = 3;
        init_arr(rows, columns, mines);
      }
      else if(level==2){
        //medium grid
        log("Medio")<<std::endl;
        rows    = 8;
        columns = 12;
        mines   = 6;
        init_arr(rows, columns, mines);
      }
      else if(level==3){
        //big grid
        log("Dificil")<<std::endl;
        rows    = 12;
        columns = 18;
        mines   = 9;
        init_arr(rows, columns,mines);
      }
      else{
        log("Favor de elegir un nivel válido")<<std::endl;
        log("Elegir el nivel 1=facil, 2=medio, 3=dificil:")<<std::endl;
        std::cin>>level;
        set_level(level);
      }
    }

    //display initial arr
    void init_arr(int rows,int columns, int mines){
      int arr[rows][columns];
      for (int i =0;i<rows;i++){
        for (int j=0;j<columns;j++){
          arr[i][j]=0;
        }
      }
      std::cout<<" ";
      for (int i=0;i<columns;i++){
        std::cout<<"| "<<i<<" |";
      }
      std::cout<<'\n';
      for (int i =0;i<rows;i++){
        std::cout<<i;
        for (int j=0;j<columns;j++){
          std::cout<<"|   |";
        }
        std::cout<<'\n';
      }
      //aqui hay que pasar el array
      create_mines(rows, columns, mines);
    }

    //create mines with classes
    void create_mines(int rows,int columns,const int mines)
    {
      Mine arr_mines[mines];
      if (flag==true){
        int rowR =rows-1;
        int columnR=columns-1;
        for(int i=0;i<mines;i++){
          arr_mines[i].set_rc(rowR,columnR);
            log("Mina ")<<i+1<<" creada"<<std::endl;
            rowR--;
            columnR--;
        }
        for(int i=0;i<mines;i++){
          std::cout<<"XM:"<<arr_mines[i].xm<<std::endl;
          std::cout<<"YM:"<<arr_mines[i].ym<<std::endl;
          //arr[arr_mines[i].ym][arr_mines[i].xm]=101;
        }
        flag=false;
      }
      check_position(arr_mines);
    }
    
    //input and check if position==mineposition
    void check_position(Mine arr_mines[]){
      log("Digite posicion (x,y): ")<<std::endl;
      std::cin>>x>>y;
      log("x: ")<<x<<" ";
      log("y: ")<<y<<std::endl;
      //valid_pos(x,y); CHECAR QUE ESTA DENTRO DESPUES
      for (int i=0;i<mines;i++){
        if (x==arr_mines[i].xm && y==arr_mines[i].ym){
          lost=true;
        }
      }
      if (lost !=true){
        //print_arr(rows,columns);
        check_position(arr_mines);
      }
      else{
        log("GAME OVER");
      }
    }
    
    //check valid input CHECAR DESPUES
    /*void valid_pos(int x, int y){
      if (rows<y || columns<x){
        log("Digite posicion (x,y) valida: ")<<std::endl;
        std::cin>>x>>y;
        log("x: ")<<x<<" ";
        log("y: ")<<y<<std::endl;
      }
      if (rows<y || columns<x){
      valid_pos(x, y);
      }
    }*/


    //print array HAY QUE PASAR EL ARRAY CON VALORES NO CON CHAR PARA MECANICA DEL JUEGO
    void print_arr(int rows, int columns, int* arr){
      for (int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){

        }
      }
    }
};

int main() {
    int Level=0;
    log("Elegir el nivel 1=facil, 2=medio, 3=dificil:")<<std::endl;
    std::cin>>Level;
    Minesweeper m(Level);
}