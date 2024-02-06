#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <list>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

class Neurona{
private:
    int id, posicion_x, posicion_y, red, green, blue;
    float voltaje;
public:
    Neurona(int _id, float _voltaje, int _posicion_x, int _posicion_y, int _red, int _green, int _blue)
        : id(_id), voltaje(_voltaje), posicion_x(_posicion_x), posicion_y(_posicion_y), red(_red), green(_green), blue(_blue) {}

    void print()const{
        cout << "ID: " << id << ", Voltaje: " << voltaje << ", Posicion: (" << posicion_x << ", " << posicion_y << ")" << ", Color: (" << red << ", " << green << ", " << blue << ")" << std::endl;
    }
};

class Lista {
private:
    std::list<Neurona> listaNeuronas;
public:
    void agregar_inicio(){
        int id, posicion_x, posicion_y, red, green, blue;
        float voltaje;

        cout << "Ingrese los datos de la neurona:" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Voltaje: ";
        cin >> voltaje;
        cout << "Posicion X: ";
        cin >> posicion_x;
        cout << "Posicion Y: ";
        cin >> posicion_y;
        cout << "Color (Red Green Blue): ";
        cin >> red >> green >> blue;

        Neurona nuevaNeurona(id, voltaje, posicion_x, posicion_y, red, green, blue);
        listaNeuronas.push_front(nuevaNeurona);

        cout << "Neurona agregada al inicio." << endl;
    }
    void agregar_final(){
        int id, posicion_x, posicion_y, red, green, blue;
        float voltaje;

        cout << "Ingrese los datos de la neurona:" << endl;
        cout << "ID: ";
        cin >> id;
        cout << "Voltaje: ";
        cin >> voltaje;
        cout << "Posicion X: ";
        cin >> posicion_x;
        cout << "Posicion Y: ";
        cin >> posicion_y;
        cout << "Color (Red Green Blue): ";
        cin >> red >> green >> blue;

        Neurona nuevaNeurona(id, voltaje, posicion_x, posicion_y, red, green, blue);
        listaNeuronas.push_back(nuevaNeurona);

        cout << "Neurona agregada al final." << endl;
    }
    void mostrar(){
        if (listaNeuronas.empty()) {
            cout << "La lista de neuronas esta vacia." << endl;
            return;
        }
        cout << "Lista de neuronas:" << endl;
        for (const Neurona& neurona : listaNeuronas) {
            neurona.print();
        }
    }
};

void MainWindow::on_pushButton_pressed()
{
    std::cout<<"hello world";
}


void MainWindow::on_pushButton_clicked()
{
    Lista solicitudNeurona;
    int op;
    do{
        std::cout<<"\n\t\t\t--- NEURONAS ---"<<endl;
        std::cout<<"\n[1]. AGREGAR AL INICIO\n[2]. AGREGAR AL FINAL\n[3]. MOSTRAR TODO\n[4]. SALIR"<<endl;
        std::cout<<"\nOpcion:";
        cin>>op;
        switch(op){
        case 1:
            solicitudNeurona.agregar_inicio();
            break;
        case 2:
            solicitudNeurona.agregar_final();
            break;
        case 3:
            solicitudNeurona.mostrar();
            break;
        }
    }while(op!=4);
}

