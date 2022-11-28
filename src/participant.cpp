#include "tty_lib2.h"
#include "lib_grupo3.h"

//funciones de la clase

participante :: participante(): participant_id(0), nombre ("") {}
participante :: participante (unsigned int id, string nom) : participant_id (id),nombre(nom){}

void participante :: set_participant(unsigned int id, string nom)
{
        participant_id = id;
        nombre = nom;
}
void participante :: set_pushed (unsigned int cant)
{
        veces_pushed=cant;
}
unsigned int participante :: get_participant_id ()
{
        return participant_id;
}
string  participante :: get_nombre ()
{
        return nombre;
}
unsigned int participante :: get_pushed ()
{
        return veces_pushed;
}

//funciones  

int comunicacion_serial(float t1, float t2) 
{
	struct termios tty;
        int serial_port;
	config_tty ("/dev/ttyS0", &tty, B9600, &serial_port);
	int read_buf;
        int num_bytes;

	sleep (2); 
	cout<<"\n Preparados ..."<<endl;
        write(serial_port, "s", sizeof(char));
        sleep(t1);

	cout<<"\n Comience a pulsar"<<endl;
		
	write(serial_port, "r", sizeof(char));
	sleep(t2);
	
	cout<<"\n Acabo el tiempo."<<endl;
	write(serial_port, "S", sizeof(char));
  
	num_bytes = read(serial_port, &read_buf, sizeof(read_buf));
	close(serial_port);
	return read_buf;
}