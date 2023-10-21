#include<iostream>
#include<string>
#include<vector>
#include <locale.h>
#include <sstream>
#include <fstream>

using namespace std;

//------------------------------------------------------------------------------------------------------
//Aquí empieza la opcion de Clientes

//Estructura de Inicio de Sección de Administrador
struct Administrador{
	string usuarioAdmin;
	string passwordAdmin;
};

//Estructura para almacenar los datos de los clientes
struct Cliente{
	string nombre;
	string apellido;
	string nit;
	string dpi;
	string telefono;
	string correo;
	string departamento;
}e[100];

//Vector para crear los usuarios
vector<Cliente> clientes;

// Menú de actividades
struct Actividad {
    string nombre;
    double precio;
};

//Inicio de Sección de Administrador
bool inicioSecionAdmin(){
	setlocale(LC_ALL, "");
	string usuarioCliente, password;
	vector<Administrador> admin = {
	    {"ADMINISTRADOR", "4899"}
    };

	cout<<"\t\t\t\t¡Bienvenido a PASEO FAMILIAR!"<<endl<<"\nIngrese su Usuario"<<endl;
	cin>>usuarioCliente;
	cout<<"\nIngrese su contraseña"<<endl;
	cin>>password;
    
    for(const Administrador & administrador : admin){
    	if(administrador.usuarioAdmin == usuarioCliente && administrador.passwordAdmin == password){
    		return true;
		}
	}
	
	cout << "\n\t Lo sentimos, tu usuario o contraseña son incorrectos" << endl;
	return false;
}

void guardarDatos(const vector<Cliente>&nuevoCliente){
	//Creamos el archivo .txt
	ofstream archivo("clientes.txt",ios::app);
	
	if(archivo.is_open()){
		
		for(const auto &cliente:nuevoCliente){
			archivo << "Nombre: " << cliente.nombre << endl;
			archivo << "Apellido: " << cliente.apellido << endl;
			archivo << "No. de DPI: " << cliente.dpi << endl;
			archivo << "No. de Teléfono: " << cliente.telefono << endl;
			archivo << "No. de NIT: " << cliente.nit << endl;
			archivo << "Correo: " << cliente.correo << endl;
			archivo << "Departamento: " << cliente.departamento << endl;
		}
		
		archivo.close();	
	}
	
	
}

//Funcion para registrar nuevos clientes
void registroCliente(){
	setlocale(LC_ALL, "");
	Cliente nuevoCliente;
	cout << "\t\t\t\t\tREGISTRO DE NUEVO CLIENTE"<<endl;
	cout << "\t\t\t\tComencemos con el Registro del Cliente\n"<<endl;
	cout << "Ingrese un nombre:"<<endl;
	cin >> nuevoCliente.nombre;
	
	cout<<"\nIngrese un apellido:"<<endl;
	cin>>nuevoCliente.apellido;
	
	cout<<"\nIngrese un número de DPI:"<<endl;
	cin>>nuevoCliente.dpi;
	
	cout<<"\nIngrese un número de Telefono:"<<endl;
	cin>>nuevoCliente.telefono;
	
	cout<<"\nIngrese un número de NIT:"<<endl;
	cin>>nuevoCliente.nit;
	
	cout<<"\nIngrese un correo electronico:"<<endl;
	cin>>nuevoCliente.correo;
	
	cout<<"\nIngrese el Departamento donde Reside:"<<endl;
	cin>>nuevoCliente.departamento;
	
	clientes.push_back(nuevoCliente); // Añadimos el nuevo cliente al vector
	
	cout<<"\nEl Registro del Cliente " <<nuevoCliente.nombre<<" "<<nuevoCliente.apellido<< ", se completo correctamente su registro.\n\n"<<endl;
}

// Función para actualizar los datos de un cliente
void actualizarCliente(vector<Cliente>& clientes) {
	setlocale(LC_ALL, "");
    string nit;
    cout << "\t\t\tACTUALIZACION DE DATOS DE CLIENTE \n"<< endl;
    cout << "Ingrese el NIT del cliente a actualizar: ";
    cin >> nit;

    for (Cliente& cliente : clientes) {
        if (cliente.nit == nit) {
        	int op;
            cout << "\n\nIngrese la opcion a cambiar: \n\n 1.Nombre \n\n 2.DPI \n\n 3.Teléfono \n\n 4.Correo \n\n 5.Departamento \n\n 6.Regresar\n"<<endl;
            cin >> op;
			switch(op){
				case 1:
		            cout << "\nIngrese el nuevo nombre del cliente: " << endl;
            		cin >> cliente.nombre;
            		cout << "\nSe actualizo correctamente el nuevo nombre del cliente." << endl;
            	break;
            	
            	case 2:
            		cout << "\nIngrese el nuevo número de DPI: " << endl;
            		cin >> cliente.dpi;
            		cout << "\nSe actualizo correctamente el nuevo número de DPI del cliente." << endl;
            	break;
            	
            	case 3:
            		cout << "\nIngrese el nuevo número de Teléfono: " << endl;
            		cin >> cliente.telefono;
            		cout << "\nSe actualizo correctamente el nuevo número de Teléfono del cliente." << endl;
            	break;
            	
            	case 4:
            		cout << "\nIngrese el nuevo Correo: " << endl;
            		cin >> cliente.correo;
            		cout << "\nSe actualizo correctamente el nuevo Correo del cliente." << endl;
            	break;
            	
            	case 5:
            		cout << "\nIngrese el nuevo Departamento:" << endl;
            		cin >> cliente.departamento;
            		cout << "\nSe actualizo correctamente el nuevo Departamento de Re del cliente.\n\n" << endl;
            	break;
            	
            	case 6: 
            		return;
            	
            	default:
            		cout << "Selección una opcción correcta\n\n" << endl;
            	
			}
            
            return;
        }
    }

    cout << "No se encontró un cliente con el NIT proporcionado.\n";
}

// Función para eliminar un cliente
void eliminarCliente(vector<Cliente>& clientes) {
    string nit;
    cout << "\t\t\t\t\tELIMINAR CLIENTE"<< endl;
    cout << "Ingrese el NIT del cliente a eliminar: "<<endl;
    cin >> nit;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->nit == nit) {
            clientes.erase(it);
            cout << "\nCliente eliminado exitosamente.\n";
            return;
        }
    }

    cout << "\nNo se encontró un cliente con el NIT proporcionado.\n";
}
// Función para consultar los datos de un cliente
void consultarCliente(const vector<Cliente>& clientes) {
    string nit;
    cout << "\t\t\tCONSULTA DE DATOS DE CLIENTE\n" << endl;
    cout << "Ingrese el NIT del cliente a consultar: \n";
    cin >> nit;

    for (const Cliente & cliente : clientes) {
        if (cliente.nit == nit) {
            cout << "\nNombre: " << cliente.nombre << "\n\n";
            cout << "Apellido: " << cliente.apellido << "\n\n";
            cout << "DPI: " << cliente.dpi << "\n\n";
            cout << "Telefono: " << cliente.telefono << "\n\n";
            cout << "Correo: " << cliente.correo << "\n\n";
            cout << "Departamento: " << cliente.departamento << "\n\n";
            return;
        }
    }

    cout << "No se encontró un cliente con el NIT proporcionado.\n";
}

int clie(){//Menu de la opcion de clientes
	setlocale(LC_ALL, "");
	int opcion;
	
	while (true){
	    cout << "\t\t\t\t\t\tCLIENTES" << endl;
	    cout << "\t\t\tPASEO FAMILIAR el Centro Recreativo mas Grande de Guatemala" << endl;
		cout << "\n\n 1. Registrar Cliente \n\n 2. Actualización de datos de Cliente \n\n 3. Eliminar Cliente \n\n 4. Consultar Datos de Cliente \n\n 5. Salir" << endl;
	    cout << "\n Seleccione una opción: ";
		cin>>opcion;

		switch (opcion) {
			case 1:
				registroCliente();
				guardarDatos(clientes);
				break;
				
			case 2:
				actualizarCliente(clientes);
				break;
	        
	        case 3:
	        	eliminarCliente(clientes);
	        	break;
	        
	        case 4:
	        	consultarCliente(clientes);
	        	break;
	        
	        case 5:
	        	cout << "Saliendo del programa." << endl;
	        	return 0;    	
	        	
			default:
				cout<<"¡Seleccione una opción valida porfavor!";
		}
	}
}

//-------------------------------------------------------------------------------------------------
//Aquí comienza la opcion de actividades

//Funcion para verificar el Nit si existe
bool verificarNit(){
	string nit;
    cout << "Ingrese su número de NIT: ";
    cin >> nit;

	for(const Cliente & cliente:clientes){//Creamos un ciclo, para traer los datos del vector
	if (cliente.nit == nit) {//Comparamos si los datos del vector son iguales a los ingresados
		cout<<"Bienvenido!! Disfruta tu experiencia."<<endl;
		return true;//Retornamos verdadero si los datos son correctos
	}
	}
	return false;//Retornamos falso si los datos ingresados son incorrectos
}

//Funcion de las actividades
int actividad() {
    vector<Actividad> actividades = {
        {"1. Cancha de Baloncesto: \t Q25.00", 25.0}, {"2. Cancha de Voleibol: \t\t Q25.00", 25.0}, {"3. Gusanito: \t\t\t Q15.00", 15.0},
        {"4. Carro Chocones \t\t Q30.00", 30.0}, {"5. Montaña Rusa \t\t Q20.00", 20.0}, {"6. Billar \t\t\t Q15.00", 15.0},
        {"7. Bolos \t\t\t Q70.00", 70.0}, {"8. Juegos de Mesa \t\t Q30.00", 30.0}, {"9. Mini Golf \t\t\t Q100.00", 100.0},
        {"10. Tiro con Arco \t\t Q100.00", 100.0}
    };
    
    double total = 0;
    while (true) {
        cout << "Menú de actividades:\n";
        for (const auto& actividad : actividades) {
            cout << actividad.nombre << "\n";
        }

        int opcion;
        cout << "Ingrese el número de la actividad que desea: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= actividades.size()) {
            total += actividades[opcion - 1].precio;
            cout << "Ha seleccionado la actividad " << actividades[opcion - 1].nombre << ".";
			cout << "\n\n\t\tSu total actual es Q" << total << ".\n";
        } else {
            cout << "\tLa opción ingresada no es válida.\n";
        }

        char otra;
        cout << "¿Desea elegir otra opción? (s/n): ";
        cin >> otra;

        if (otra != 's') {
            break;
        }
    }

    cout << "\n\n\t\t\tEL TOTAL DE SU COMPRA ES Q" << total << ".\n";

    return 0;
}

//--------------------------------------------------------------------------------------------------
//Menú Secundario
int main2(){
	setlocale(LC_ALL, "");
	int opcion;
	while (true){
		cout << "\t\t\t\t BIENVENIDO ADMINISTRADOR DE PASEO FAMILIAR" << endl;
	    cout << "\t\t\t\tEl Centro Recreativo Mas Grande de Guatemala" << endl;
		cout << "\n\n1. Clientes" << endl;
	    cout << "\n2. Actividades" << endl;
	    cout << "\n3. Salir" << endl;
	    cout << "\nSeleccione una opción: ";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				clie();
				break;
			
			case 2:
					if (verificarNit()){
							actividad();	
						}
					else 
						cout << "No tenemos registrado este nit, favor registrarse antes"<<endl;
				break;
			
			case 3:
				cout << "Saliendo del programa." << endl;
	        	return 0;
	        	
			default:
				cout<<"¡Seleccione una opción valida porfavor!";
			}	
		}
}

//--------------------------------------------------------------------------------------------------
//Menú Principal
int main(){
	setlocale(LC_ALL, "");
	int opcion;
	while (true) {
        cout << "\t\t\t\tBIENVENIDO A PASEO FAMILIAR" << endl;
	    cout << "\t\t\tEl Centro Recreativo mas grande de Guatemala" << endl;
        cout << "1. Iniciar sesión \n" << endl;
        cout << "2. Salir\n" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
	                if (inicioSecionAdmin()){
	                		main2();
						}
					else
						cout << "\n\t\tO simplemente no eres un ADMINISTRADOR \n\n"<<endl;
                break;
            }
            case 2:
                cout << "Saliendo del programa." << endl;
                return 0;
                
            default:
                cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }
}


