#include<iostream>
#include<string>
#include<vector>
#include <locale.h>

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
	string  usuario;
	string password;
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

//Funcion para registrar nuevos clientes
void registroCliente(){
	setlocale(LC_ALL, "");
	Cliente nuevoCliente;
	
	cout<<"Bienvenido!! Comencemos con su registro."<<endl;
	cout<<"Por favor!! Escriba su nombre"<<endl;
	cin>>nuevoCliente.nombre;
	
	cout<<"Ingrese un apellido"<<endl;
	cin>>nuevoCliente.apellido;
	
	cout<<"Ingrese su número de DPI"<<endl;
	cin>>nuevoCliente.dpi;
	
	cout<<"Ingrese su número de Telefono"<<endl;
	cin>>nuevoCliente.telefono;
	
	cout<<"Ingrese su número de NIT"<<endl;
	cin>>nuevoCliente.nit;
	
	cout<<"Escriba su correo electronico"<<endl;
	cin>>nuevoCliente.correo;
	
	cout<<"Escriba el Departamento donde Reside"<<endl;
	cin>>nuevoCliente.departamento;
	
	cout<<"Escriba su usuario"<<endl;
	cin>>nuevoCliente.usuario;
	
	cout<<"Escriba su contraseña"<<endl;
	cin>>nuevoCliente.password;
	
	clientes.push_back(nuevoCliente); // Añadimos el nuevo cliente al vector
	
	cout<<"Felicidades " <<nuevoCliente.nombre<<" "<<nuevoCliente.apellido<< ", completamos su registro."<<endl<<"¡¡Muchas Gracias!!"<<endl;
}

bool inicioSecionAdmin(){
	setlocale(LC_ALL, "");
	string usuarioCliente, password;
	vector<Administrador> admin = {
	    {"ADMINISTRADOR", "4899"}
    };

	cout<<"¡Bienvenido a PASEO FAMILIAR!"<<endl<<"Ingrese su nombre de Usuario"<<endl;
	cin>>usuarioCliente;
	cout<<"Ingrese su contraseña"<<endl;
	cin>>password;
    
    for(const Administrador & administrador : admin){
    	if(administrador.usuarioAdmin == usuarioCliente && administrador.passwordAdmin == password){
    		cout << "\t\t\t¡Bienvenido Administrador de PASEO FAMILIAR!" << "\n Comencemos con la Administración de PASEO FAMILIAR" << endl;
    		return true;
		}
	}
	
	cout << "\n\t Lo sentimos, tu usuario o contraseña son incorrectos" << endl;
	return false;
}

//Funcion para inicio de sección
bool inicioSecion (){
	setlocale(LC_ALL, "");
	string usuarioCliente, password;
	cout<<"¡Bienvenido a PASEO FAMILIAR!"<<endl<<"Ingrese su nombre de Usuario"<<endl;
	cin>>usuarioCliente;
	cout<<"Ingrese su contraseña"<<endl;
	cin>>password;
	
	for(const Cliente & cliente:clientes){//Creamos un ciclo, para traer los datos del vector
		if (cliente.usuario == usuarioCliente && cliente.password == password) {//Comparamos si los datos del vector son iguales a los ingresados
			cout<<"Bienvenido, "<< usuarioCliente<<"!! Disfruta tu experiencia."<<endl;
			return true;//Retornamos verdadero si los datos son correctos
		}
	}
		
	cout<<"Lo sentimos, tu usuario o contraseña son incorrectos."<<endl;
	return false;//Retornamos falso si los datos ingresados son incorrectos
}

// Función para actualizar los datos de un cliente
void actualizarCliente(vector<Cliente>& clientes) {
	setlocale(LC_ALL, "");
    string nit;
    
    cout << "Ingrese el NIT del cliente a actualizar: ";
    cin >> nit;

    for (Cliente& cliente : clientes) {
        if (cliente.nit == nit) {
        	int op;
            cout << "Ingrese la opcion a cambiar: \n 1.Nombre \n 2.DPI \n 3.Teléfono \n 4.Correo \n 5.Departamento \n 6.Regresar"<<endl;
            cin >> op;
			switch(op){
				case 1:
		            cout << "Ingrese el nuevo nombre del cliente: " << endl;
            		cin >> cliente.nombre;
            	break;
            	
            	case 2:
            		cout << "Ingrese el nuevo número de DPI: " << endl;
            		cin >> cliente.dpi;
            	break;
            	
            	case 3:
            		cout << "Ingrese el nuevo número de Teléfono: " << endl;
            		cin >> cliente.telefono;
            	break;
            	
            	case 4:
            		cout << "Ingrese el nuevo Correo: " << endl;
            		cin >> cliente.correo;
            	break;
            	
            	case 5:
            		cout << "Ingrese el nuevo Departamento: " << endl;
            		cin >> cliente.departamento;
            	break;
            	
            	case 6: 
            		return;
            	
            	default:
            		cout << "Selección una opcción correcta" << endl;
            	
			}
            
            return;
        }
    }

    cout << "No se encontró un cliente con el NIT proporcionado.\n";
}

// Función para eliminar un cliente
void eliminarCliente(vector<Cliente>& clientes) {
    string nit;
    cout << "Ingrese el NIT del cliente a eliminar: ";
    cin >> nit;

    for (auto it = clientes.begin(); it != clientes.end(); ++it) {
        if (it->nit == nit) {
            clientes.erase(it);
            cout << "Cliente eliminado exitosamente.\n";
            return;
        }
    }

    cout << "No se encontró un cliente con el NIT proporcionado.\n";
}
// Función para consultar los datos de un cliente
void consultarCliente(const vector<Cliente>& clientes) {
    string nit;
    cout << "Ingrese el NIT del cliente a consultar: ";
    cin >> nit;

    for (const Cliente & cliente : clientes) {
        if (cliente.nit == nit) {
            cout << "Nombre: " << cliente.nombre << "\n";
            cout << "Apellido: " << cliente.apellido << "\n";
            cout << "DPI: " << cliente.dpi << "\n";
            cout << "Telefono: " << cliente.telefono << "\n";
            cout << "Correo: " << cliente.correo << "\n";
            cout << "Departamento: " << cliente.departamento << "\n";
            return;
        }
    }

    cout << "No se encontró un cliente con el NIT proporcionado.\n";
}

int clie(){//Menu de la opcion de clientes
	setlocale(LC_ALL, "");
	int opcion;
	
	while (true){
	    cout << "\t\t\t\tBIENVENIDO A PASEO FAMILIAR" << endl;
	    cout << "\t\t\tEl Centro Recreativo mas grande de Guatemala" << endl;
		cout << "\n\n 1. Registrar usuario \n 2. Actualización de datos de Cliente \n 3. Eliminar Cliente \n 4. Consultar Datos de Cliente \n 5. Salir" << endl;
	    cout << "\n Seleccione una opción: ";
		cin>>opcion;

		switch (opcion) {
			case 1:
				registroCliente();
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
		cout << "\t\t\t\tBIENVENIDO A PASEO FAMILIAR" << endl;
	    cout << "\t\t\tEl Centro Recreativo mas grande de Guatemala" << endl;
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


