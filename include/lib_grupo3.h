#ifndef LIB_GRUPO3_H
#define LIB_GRUPO3_H 

//Librerias utilizadas 

#include <unistd.h> //librería del SLEEP
#include <iostream>
#include <stdlib.h>
using namespace std;

// Clase 
class participante
{
                unsigned int participant_id;
                string  nombre;
                unsigned int veces_pushed;
        public:
                participante();
                participante (unsigned int id, string nom);

                void set_participant(unsigned int id, string nom);
                void set_pushed (unsigned int cant);
                unsigned int get_participant_id ();
                string get_nombre ();
                unsigned int get_pushed ();
};

//funciones 
int comunicacion_serial(float t1, float t2);
#endif
