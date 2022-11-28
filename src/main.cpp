#include "tty_lib2.h"
#include "lib_grupo3.h"

int main (int argc, char *argv[]  )
{	  
        float time_pre, time_venta;   
	int max=2; //cantidad de participantes
        int aux=0; // auxiliar para el ciclo
	int read_buf;
	int mayor=0;
	int ganador;
        string  nom;
        unsigned int id=0;

        if (argc !=3)
        {
                cout <<"Error en la cantidad de argumentos"<<endl;
        }

        else
        {
		time_pre=atof(argv[1]);
                time_venta=atof(argv[2]);

	}

        cout<<"\n\n Ingrese la cantidad de participantes:";
        cin >> max ;
        participante participantes[max];
	for (aux=0; aux<max ;aux++)
        {       
                id=0;
                cout<<"\n Nombre del participante "<<aux+1<<":";
                cin>>nom;
                cout<<"\n Número de identiticación:";
                cin>>id;
                participantes[aux].set_participant (id,nom);
			
		read_buf= comunicacion_serial(time_pre,time_venta);

		participantes[aux].set_pushed (char(read_buf));
        	
        }
	for (aux=0; aux<max ;aux++) 
	{ 
		if (mayor<participantes[aux].get_pushed ())
		{	
			mayor=participantes[aux].get_pushed ();
			ganador=aux; 
		}
		
	}
	cout << "\n \t \t \t RESULTADOS:"<<endl;
	cout << "Participante \t\t Número de identiticación \t\t Cantidad de pulsos:"<< endl;
	for (aux=0; aux<max ;aux++)
        { 
		//cout << "Participante " <<aux+1 << ":" <<participantes[aux].get_nombre ()<< endl;
		//cout << "Número de identiticación:" <<participantes[aux].get_participant_id ()<< endl;
		//cout << "Cantidad de pulsos:" <<participantes[aux].get_pushed ()<< endl;
		
		cout <<participantes[aux].get_nombre (); 
 		cout <<"\t\t\t\t"<<participantes[aux].get_participant_id ();
		cout <<"\t\t\t\t\t"<<participantes[aux].get_pushed ()<< endl;

	}
	cout<<"\n El ganador es "<<participantes[ganador].get_nombre ();
	cout<<" con el siguiete puntaje "<< mayor << endl;

}

