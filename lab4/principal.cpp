#include "./include/fabrica.h"
#include <iostream>
using namespace std;

void mostrarTitulo(string s){
    cout << "\n";
    for(int i=0;i<10;i++)
        cout<<" ";
    cout << s << "\n";
    for(int i=0;i<9;i++)
        cout<<" ";
    for(unsigned int i=0;i<s.length()+2;i++)
        cout<<"~";
    cout << "\n";
}

void mostrarSet(set<string> s){
    int n = 1;
    for(auto it = s.begin(); it != s.end(); ++it){
        cout << n << "-" << (*it) << endl;
        n++;
    }
}

void mostrarSetNum(set<int> s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {
        cout << "-" << (*it) << endl;
    }
}

string obtenerEleccion(set<string> s, int n){
    set<string>::iterator it = s.begin();
    n--;
    while(n > 0){
        it++;
        n--;
    }
    return (*it);
}

int obtenerEleccionNum(set<int> s, int n){
    set<int>::iterator it = s.begin();
    n--;
    while (n > 0)
    {
        it++;
        n--;
    }
    return (*it);
}

int main() {
    Fabrica* f = Fabrica::getInstancia();
    ICurso* ic = f->getICurso();
    IUsuario* iu = f->getIUsuario();
    bool encendido = true;
    while(encendido){
        int opcion;
        string vacio;
        cout << "Seleccione caso de uso:\n 0-Cargar datos de entrada\n 1-Alta de usuario\n 2-Consulta de usuario\n 3-Alta de idioma\n 4-Consultar idiomas\n 5-Alta de curso\n 6-Agregar lección\n 7-Agregar ejercicio\n 8-Habilitar curso\n 9-Eliminar curso\n 10-Consultar curso\n 11-Inscribirse a curso\n 12-Realizar ejercicio\n 13-Consultar estadísticas\n 14-Suscribirse a notificaciones\n 15-Consulta de notificaciones\n 16-Eliminar suscripciones\n 17-Salir\n";
        cin >> opcion;
        
        switch (opcion){
        case 0:
        {
            bool altaI, altaU, habilitarC;

            
            //I1
            altaI = ic->altaIdioma("Ingles");
            
            //I2
            altaI = ic->altaIdioma("Aleman");
            
            //I3
            altaI = ic->altaIdioma("Portugues");
            
            //U1
            iu->ingresarDatosUsuario("jpidiom","asdfg123","Juan Perez","Soy un apasionado del aprendizaje de idiomas.");
            iu->ingresarDatosEstudiante("Argentina",15,07,1995);
            altaU = iu->confirmarAltaEstudiante();
            
            //U2
            iu->ingresarDatosUsuario("marsilva","qwer456","Maria Silva","Como amante de los idiomas disfruto explorando nuevas formas de interactuar.");
            iu->ingresarDatosEstudiante("Ecuador",28,02,1998);
            altaU = iu->confirmarAltaEstudiante();
            
            //U3
            iu->ingresarDatosUsuario("pero12","789werty","Pedro Rodriguez","Soy un entusiasta del aprendizaje de idiomas.");
            iu->ingresarDatosEstudiante("Peru",10,11,1994);
            altaU = iu->confirmarAltaEstudiante();
            
            //U4
            iu->ingresarDatosUsuario("laugu","c1v2b3m4","Laura Gutierrez","Estoy fascinada por la forma en que las palabras pueden unir a las personas.");
            iu->ingresarDatosEstudiante("Chile",22,04,1997);
            altaU = iu->confirmarAltaEstudiante();
            
            //U5
            iu->ingresarDatosUsuario("carlo22","tyuipz147","Carlos Lopez","Emocionado por adquirir fluidez en diferentes lenguas.");
            iu->ingresarDatosEstudiante("Uruguay",03,9,1996);
            altaU = iu->confirmarAltaEstudiante();
            
            //U6
            iu->ingresarDatosUsuario("anator","1qsxc36","Ana Torres","Disfruto de la belleza de las diferentes estructuras y sonidos.");
            iu->ingresarDatosEstudiante("Argentina",12,01,1999);
            altaU = iu->confirmarAltaEstudiante();
            
            //U7
            iu->ingresarDatosUsuario("luher24","t7h8y5u6","Lucia Hernandez","Emocionada en la riqueza cultural que cada idioma ofrece.");
            iu->ingresarDatosEstudiante("Colombia",25,06,1993);
            altaU = iu->confirmarAltaEstudiante();
            
            //U8
            iu->ingresarDatosUsuario("dagon","1w2e3r4t5","David Gonzalez","Aprender nuevas lenguas y sumergirme en diferentes culturas.");
            iu->ingresarDatosEstudiante("Uruguay",8,12,1997);
            altaU = iu->confirmarAltaEstudiante();
            
            //U9
            iu->ingresarDatosUsuario("carmor","6yu7i8m9","Carmen Morales","El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.");
            iu->ingresarDatosEstudiante("Chile",17,03,1995);
            altaU = iu->confirmarAltaEstudiante();
            
            //U10
            iu->ingresarDatosUsuario("jose24","qwj789p","Jose Fernandez","Disfruto del proceso de descubrir nuevas formas de comunicarme.");
            iu->ingresarDatosEstudiante("Bolivia",02,8,1998);
            altaU = iu->confirmarAltaEstudiante();
            
            //U11
            iu->ingresarDatosUsuario("langMaster","P4s512","Marta Grecia","Soy una profesora apasionada por los idiomas.");
            iu->ingresarInstituto("Instituto de Idiomas Moderno");
            iu->ingresarEspecializacion("Ingles");
            iu->ingresarEspecializacion("Portugues");
            altaU = iu->confirmarAltaProfesor();
            
            //U12
            iu->ingresarDatosUsuario("linguaPro","Pess23","Carlos Petro","Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas.");
            iu->ingresarInstituto("Centro Global");
            iu->ingresarEspecializacion("Ingles");
            iu->ingresarEspecializacion("Aleman");
            iu->ingresarEspecializacion("Portugues");
            altaU = iu->confirmarAltaProfesor();
            
            //U13
            iu->ingresarDatosUsuario("talkExpert","Secret1","Laura Perez","Soy una profesora entusiasta del aprendizaje de idiomas.");
            iu->ingresarInstituto("Instituto de Idiomas Vanguardia");
            iu->ingresarEspecializacion("Aleman");
            altaU = iu->confirmarAltaProfesor();
            
            //U14
            iu->ingresarDatosUsuario("lingoSensei","Secure2","Franco Lopez","Apasionada en guiar a mis estudiantes en su viaje por nuevos horizontes idiomaticos.");
            iu->ingresarInstituto("Centro de Idiomas");
            iu->ingresarEspecializacion("Portugues");
            altaU = iu->confirmarAltaProfesor();
            
            //U15
            iu->ingresarDatosUsuario("wordMaestro","Passw0","Ana Morales","Soy una profesora comprometida en desarrollo de habilidades idiomaticas.");
            iu->ingresarInstituto("Instituto de Idiomas Progreso");
            iu->ingresarEspecializacion("Ingles");
            altaU = iu->confirmarAltaProfesor();

            
            //C1
            ic->ingresarDatosCurso("Ingles para principiantes","Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", Principiante);
            ic->seleccionarEspecializacion("Ingles");
            ic->seleccionarProfesor("langMaster");
            ic->ingresarLeccion("Saludos y Presentaciones", "Aprender a saludar y despedirse");
            ic->ingresarEjercicioTraduccion("Presentaciones","Mucho gusto en conocerte","Nice to meet you");
            ic->ingresarEjercicioCompletarPalabras("Presentaciones formales","Please --- me to introduce ---","allow, myself");
            ic->ingresarLeccion("Artículos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
            ic->ingresarEjercicioTraduccion("Plurales regulares","I have two brothers and three sisters","Tengo dos hermanos y tres hermanas");
            ic->ingresarEjercicioCompletarPalabras("Sustantivos contables en plural","Can I have --- water, please?","some");
            ic->altaCurso();
            habilitarC = ic->habilitarCurso("Ingles para principiantes");

            //C2
            ic->ingresarDatosCurso("Curso de ingles basico","Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", Principiante);
            ic->seleccionarEspecializacion("Ingles");
            ic->seleccionarProfesor("langMaster");
            ic->ingresarLeccion("Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, Aprender a formar los plurales regulares e irregulares de sustantivos");
            ic->ingresarEjercicioCompletarPalabras("Actividades diarias","Wake ---","up");
            ic->ingresarLeccion("Presente Simple", "Aprender el uso del presente simple");
            ic->altaCurso();
            habilitarC= ic->habilitarCurso("Curso de ingles basico");

            //C3
            ic->ingresarDatosCurso("Ingles intermedio: mejora tu nivel","Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", Medio);
            ic->seleccionarEspecializacion("Ingles");
            ic->seleccionarProfesor("linguaPro");
            ic->agregarPrevia("Ingles para principiantes");
            ic->ingresarLeccion("Conversaciones cotidianas","Aprender a hacer preguntas y respuestas en situaciones comunes");
            ic->ingresarEjercicioCompletarPalabras("Consultas de la hora","Q: Do you --- the time?, A: Yes, it is half --- 4","have, past");
            ic->altaCurso();
            habilitarC = ic->habilitarCurso("Ingles intermedio: mejora tu nivel");

            // C4
            ic->ingresarDatosCurso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", Avanzado);
            ic->seleccionarEspecializacion("Ingles");
            ic->seleccionarProfesor("linguaPro");
            ic->agregarPrevia("Ingles para principiantes");
            ic->agregarPrevia("Ingles intermedio: mejora tu nivel");
            ic->ingresarLeccion("Uso de modales avanzados", "Explorar el uso de los modales complejos");
            ic->ingresarEjercicioTraduccion("Dar consejos o expresar obligacion", "You should visit that museum","Deberias visitar ese museo");
            ic->altaCurso();
            habilitarC = ic->habilitarCurso("Curso avanzado de ingles");

            //C5
            ic->ingresarDatosCurso("Portugues intermedio","Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", Medio);
            ic->seleccionarEspecializacion("Portugues");
            ic->seleccionarProfesor("linguaPro");
            ic->ingresarLeccion("Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");
            ic->ingresarEjercicioTraduccion("Imperativo","Fale comigo","Habla conmigo");
            ic->altaCurso();
            habilitarC = ic->habilitarCurso("Portugues intermedio");

            //C6
            ic->ingresarDatosCurso("Portugues avanzado","Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", Avanzado);
            ic->seleccionarEspecializacion("Portugues");
            ic->seleccionarProfesor("lingoSensei");
            ic->agregarPrevia("Portugues intermedio");
            ic->altaCurso();
            habilitarC = ic->habilitarCurso("Portugues avanzado");

            //N1
            ic->inscripcionCurso("jpidiom");
            ic->confirmarInscripcion("Ingles para principiantes", 01, 01, 2022);
            // e1 l1
            iu->cargarEjerciciosAprobados("jpidiom", "Ingles para principiantes",1);
            // e2 l1
            iu->cargarEjerciciosAprobados("jpidiom", "Ingles para principiantes",2);
            // e3 l2
            iu->cargarEjerciciosAprobados("jpidiom", "Ingles para principiantes",1);
            // e4 l2
            iu->cargarEjerciciosAprobados("jpidiom", "Ingles para principiantes",2);

            //N2
            ic->inscripcionCurso("jpidiom");
            ic->confirmarInscripcion("Ingles intermedio: mejora tu nivel", 12, 06, 2022);
            // e6 l5
            iu->cargarEjerciciosAprobados("jpidiom","Ingles intermedio: mejora tu nivel",1);

            //N3
            ic->inscripcionCurso("jpidiom");
            ic->confirmarInscripcion("Curso avanzado de ingles", 02, 03, 2023);

            //N4
            ic->inscripcionCurso("marsilva");
            ic->confirmarInscripcion("Ingles para principiantes", 02, 01, 2022);
            // e1 l1
            iu->cargarEjerciciosAprobados("marsilva","Ingles para principiantes",1);
            // ej2 l1
            iu->cargarEjerciciosAprobados("marsilva","Ingles para principiantes",2);
    

            //N5
            ic->inscripcionCurso("pero12");
            ic->confirmarInscripcion("Ingles para principiantes", 02, 01, 2022);
            // ej 1 l1
            iu->cargarEjerciciosAprobados("pero12","Ingles para principiantes",1);
            // ej 2 l1
            iu->cargarEjerciciosAprobados("pero12","Ingles para principiantes",2);
            // ej4 l2
            iu->cargarEjerciciosAprobados("pero12","Ingles para principiantes",2);


            //N6
            ic->inscripcionCurso("laugu");
            ic->confirmarInscripcion("Ingles para principiantes", 03, 01, 2023);

            //N7
            ic->inscripcionCurso("laugu");
            ic->confirmarInscripcion("Portugues intermedio", 03, 01, 2023);

            //N8
            ic->inscripcionCurso("carlo22");
            ic->confirmarInscripcion("Portugues intermedio", 05, 01, 2023);

/*
faltan cosas
*/
            cout <<"\nSe cargaron exitosamente los datos de entrada\n\n";

        break;
        }
            
        case 1:
        {
            mostrarTitulo("Alta de usuario");
            string nickname,contrasenia,nombre,descripcion;
            cout << "Ingrese un nickname: ";
            cin.ignore();
            getline(cin, nickname);
            bool cond = true;
            do
            {
                cout << "Ingrese una contrasenia (de mínimo 6 caracteres): ";
                getline(cin, contrasenia);
                if (contrasenia.length() >= 6)
                    cond = false;
                else
                    cout << "La contrasenia ingresada es demasiado corta.\n";
            } while (cond);
            cout << "Ingrese un nombre: ";
            getline(cin, nombre);
            cout << "Ingrese una descripción: ";
            getline(cin, descripcion);
            iu->ingresarDatosUsuario(nickname, contrasenia, nombre, descripcion);
            int opcion2;
            cout << "Seleccione el tipo de usuario que desdea crear:\n 1- Estudiante\n 2- Profesor\n";
            cin >> opcion2;
            switch(opcion2){
                case 1:
                {
                    string paisResidencia;
                    int dia, mes, anio;
                    cout << "Ingrese el país donde reside: ";
                    cin.ignore();
                    getline(cin, paisResidencia);
                    cout << "Ingrese su fecha de nacimiento:\n Día: ";
                    cin >> dia;
                    cout << " Mes: ";
                    cin >> mes;
                    cout << " Anio: ";
                    cin >> anio;
                    iu->ingresarDatosEstudiante(paisResidencia, dia, mes, anio);
                    bool altaE = iu->confirmarAltaEstudiante();
                    if (altaE)
                        cout << "Se realizó con exito el alta del estudiante en el sistema\n";
                    else
                        cout << "Error. El nickname ingresado ya existe en el sistema\n";    
                break;
                }
            
                case 2:
                {
                    string instituto;
                    cout << "Ingrese el nombre del instituto donde trabaja: ";
                    cin.ignore();
                    getline(cin, instituto);
                    iu->ingresarInstituto(instituto);                    
                    bool cond = true;
                    do
                    {
                        int opcion3;
                        cout << "¿Desea agregar especializaciones?\n 1- Sí\n 2- No\n";
                        cin >> opcion3;
                        switch (opcion3)
                        {
                        case 1:
                        {
                            cout << "Seleccione el número de la especialización que desea agregar:\n";
                            int op;
                            set<string> idiomasSistema = iu->listarIdiomasDisponibles();
                            mostrarSet(idiomasSistema);
                            cin >> op;
                            if ((op >= 1) && (op <= idiomasSistema.size())){
                                string idioma = obtenerEleccion(idiomasSistema, op); 
                                iu->ingresarEspecializacion(idioma);
                                cout << "Se agregó " << idioma << " a las especializaciones del usuario\n";
                            } else 
                               cout << "Opción no reconocida\n"; 
                        break;    
                        }    
                        case 2:
                            cond = false;
                        break;       
                        default:
                        cout << "Opción no reconocida\n";
                            break;
                        }
                    } while (cond);
                    bool altaP = iu->confirmarAltaProfesor();
                    if (altaP)
                        cout << "Se realizó con exito el alta del profesor en el sistema\n";
                    else
                        cout << "Error. El nickname ingresado ya existe en el sistema\n";
                break;
                }
                default:
                cout << "Opción no reconocida\n";
                break;
            }
            cout << "\n";
        break;
        }
        case 2:
        {
            mostrarTitulo("Consultar usuario");
            cout << "Seleccione el número del usuario que desea consultar:\n";
            set<string> nicknames = iu->listarUsuariosSistema();
            mostrarSet(nicknames);
            cout << "\n";
            int opcion;
            cin >> opcion;
            if ((opcion >= 1) && (opcion <= nicknames.size())){
                string nickname = obtenerEleccion(nicknames, opcion);
                iu->consultarUsuario(nickname);
            } else {
                cout << "Error. Opción no reconocida.\n";
            }
            cout << "\n";
        break;
        }


        case 3:
        {
            mostrarTitulo("Alta de idioma");
            string idioma;
            cout<< "Ingrese el nombre del idioma que desea agregar al sistema:\n";
            cin.ignore();
            getline(cin, idioma);
            bool altaI = ic->altaIdioma(idioma);
            if (altaI)
                        cout << "Se realizó con exito el alta del idioma en el sistema\n";
                    else
                        cout << "Error. El idioma ingresado ya existe en el sistema\n";
            cout << "\n";
        break;  
        }

        case 4:
        {
            mostrarTitulo("Consultar idiomas");
            cout << "Idiomas existentes en el sistema:\n";
            set<string> idiomasSistema = iu->listarIdiomasDisponibles();
            for(set<string>::iterator it=idiomasSistema.begin(); it!=idiomasSistema.end(); ++it){
                cout << '-' << (*it) << endl;
            }
            cout << "\n";
        break; 
        }
            

        case 5:
        {
            mostrarTitulo("Alta de curso");
            string nicknameProfesor, nombreCurso, descripcion, nombreIdioma, nombreCursoHabilitado, tema, objetivo, descEjercicio, frase, solucion;
            DificultadCurso dificultad;
            int op, opcion4, opcion5, opcion6, opcion7, opcion8, opcion9;
            cout << "Esta es la lista de nicknames de los profesores existentes en el sistema:\n";
            set<string> profesoresSistema = ic->listarProfesores();
            mostrarSet(profesoresSistema);
            cout << "Seleccionar el número del nickname del profesor que dictara el curso:\n";
            cin >> op;
            if ((op >= 1) && (op <= profesoresSistema.size())){
                nicknameProfesor = obtenerEleccion(profesoresSistema, op);
                ic->seleccionarProfesor(nicknameProfesor);
                cout << "Ingresar datos del curso\n\n";
                cout << "Nombre:\n";
                cin.ignore();
                getline(cin,nombreCurso);
                cout << "Descripción:\n";
                getline(cin,descripcion);
                cout << "Elegir la dificultad del curso (Ingrese el número de las siguientes opciones):\n 1- Principiante\n 2- Medio\n 3- Avanzado\n";
                cin >> opcion4;
                switch (opcion4){
                    case 1:{
                        dificultad = Principiante;
                        break;
                    }
                    case 2:{
                        dificultad = Medio;
                        break;
                    }
                    case 3:{
                        dificultad = Avanzado;
                        break;
                    }
                    default:{
                        cout << "Opción no reconocida\n";
                    break;
                    }
                }
                ic->ingresarDatosCurso(nombreCurso, descripcion, dificultad);
                cout << "Estos son los idiomas en los que se especializa el profesor seleccionado:\n";
                set<string> idiomasEspecializado = ic->listarIdiomasEspecializadoProfesor();
                mostrarSet(idiomasEspecializado);
                int op2;
                cout << "Seleccione el número del nombre del idioma del cual se dará el curso:\n";
                cin >> op2;
                if ((op2 >= 1) && (op2 <= idiomasEspecializado.size()))
                {
                    nombreIdioma = obtenerEleccion(idiomasEspecializado, op2);
                    ic->seleccionarEspecializacion(nombreIdioma);
                    cout << "¿Se desean agregar cursos existentes como previas de éste?:\n 1- Sí\n 2- No\n";
                    cin >> opcion5;
                    switch(opcion5)
                    {
                        case 1:
                        {
                            cout << "Estos son los cursos habilitado en el sistema:\n";
                            set<string> cursosHabilitados = ic->listarCursosHabilitados();
                            mostrarSet(cursosHabilitados);
                            bool cond1 = true;
                            do {
                                cout << "¿Desea agregar previas?:\n 1- Si\n 2- No\n";
                                cin >> opcion6;
                                switch(opcion6)
                                {
                                    case 1:
                                    {
                                        int op3;
                                        cout << "Seleccione el número del curso habilitado quiere agregar:\n";
                                        cin >> op3;
                                        if ((op3 >= 1) && (op3 <= cursosHabilitados.size())) {
                                            nombreCursoHabilitado = obtenerEleccion(cursosHabilitados, op3);
                                            bool previa = ic->agregarPrevia(nombreCursoHabilitado);
                                            if (previa)
                                                cout << "El curso previo " << nombreCursoHabilitado << " fue agregado con éxito.\n";
                                            else
                                                cout << "El curso seleccionado no puede ser previa\n";
                                        } else 
                                            cout << "Opción no reconocida\n";
                                        break;
                                    }
                                    case 2:
                                    {
                                        cond1 = false;
                                        break;
                                    }
                                    default:
                                    {
                                    cout << "Opción no reconocida\n";
                                    break;
                                    }
                                }
                            } while (cond1);
                            break;
                        }
                        case 2:
                        {
                            break;
                        }
                        default: 
                            cout << "Opción no reconocida\n";
                            break;
                    }
                    bool cond2 = true;
                    do
                    {
                        cout << "¿Se desean agregan lecciones?:\n 1- Sí\n 2- No\n";
                        cin >> opcion7;
                        switch(opcion7)
                        {
                            case 1:
                            {
                                cout << "Ingrese los siguientes datos:\n";
                                cout << "Tema:\n";
                                cin.ignore();
                                getline(cin,tema);
                                cout << "Objetivo:\n";
                                getline(cin,objetivo);
                                ic->ingresarLeccion(tema, objetivo);
                                bool cond3 = true;
                                do
                                {
                                    cout << "¿Se desean agregar ejercicios para esta lección?:\n 1- Sí\n 2- No\n";
                                    cin >> opcion8;
                                    switch(opcion8)
                                    {
                                        case 1:
                                        {
                                            cout << "¿De quó tipo es el ejercicio?:\n 1- Completar Palabra\n 2- Traducción\n";
                                            cin >> opcion9;
                                            switch(opcion9)
                                            {
                                                case 1:
                                                {
                                                    cout << "Ingrese además los siguientes datos:\n";
                                                    cout << "Descripción:\n";
                                                    cin.ignore();
                                                    getline(cin,descEjercicio);
                                                    cout << "Frase del ejercicio:\n";
                                                    getline(cin,frase);
                                                    cout << "Solución del ejercicio:\n";
                                                    getline(cin,solucion);
                                                    ic->ingresarEjercicioCompletarPalabras(descEjercicio, frase, solucion);
                                                    cout << "Se ingresó con éxito el ejercicio de completar palabras.\n";
                                                    break;
                                                }
                                                case 2:
                                                {
                                                    cout << "Ingrese además los siguientes datos:\n";
                                                    cout << "Descripción:\n";
                                                    cin.ignore();
                                                    getline(cin,descEjercicio);
                                                    cout << "Frase del ejercicio:\n";
                                                    getline(cin,frase);
                                                    cout << "Solución del ejercicio:\n";
                                                    getline(cin,solucion);
                                                    ic->ingresarEjercicioTraduccion(descEjercicio, frase, solucion);
                                                    cout << "Se ingresó con óxito el ejercicio de traducción.\n";
                                                    break;
                                                }
                                                default:
                                                    cout << "Opcion no reconocida\n";
                                                    break;
                                            }
                                            break;
                                        }
                                        case 2:
                                        {
                                            cond3 = false;
                                            break;
                                        }
                                        default:
                                            cout << "Opción no reconocida\n";
                                            break;
                                    }
                                } while (cond3);
                                break;
                            }
                            case 2:
                            {
                                cond2 = false;
                                break;
                            }
                            default:
                                cout << "Opción no reconocida\n";
                                break;
                            
                        }
                    } while (cond2);
                    bool alta = ic->confirmarAltaCurso();
                    if (alta){
                        cout << "Se ingresó exitosamente el curso al sistema.\n";
                    } else {
                        cout << "El curso a ingresar ya existe en el sistema.\n";
                    }
                } else 
                    cout << "Opción no reconocida\n";
                
            } else 
                cout << "Opción no reconocida\n";
            cout << "\n";      
        break;
        }
        
        case 6:
        {
            mostrarTitulo("Agregar lección");
            string cursoNoHabilitado, tema, objetivo, descEjercicio, frase, solucion;
            int opcion, opcion1;
            cout << "Estos son los cursos no habilitados en el sistema:\n";
            set<string> cursosNoHabilitados = ic->listarCursosNoHabilitados();
            for(set<string>::iterator it=cursosNoHabilitados.begin(); it!=cursosNoHabilitados.end(); ++it){
                cout << "-" << (*it) <<endl;
            }
            cout << "Ingrese el nombre del curso al que quiere agregarle una nueva lección:\n";
            cin.ignore();
            getline(cin, cursoNoHabilitado);
            if(ic->existeCurso(cursoNoHabilitado)){
                ic->seleccionarCursoNoHabilitado(cursoNoHabilitado);
                cout << "Ingrese los siguientes datos:\n";
                cout << "Tema:\n";
                cin.ignore();
                getline(cin,tema);
                cout << "Objetivo:\n";
                getline(cin, objetivo);
                ic->ingresarLeccion(tema, objetivo);
                bool cond4 = true;
                do
                {
                    cout << "¿Se desean agregar ejercicios a la leccion?:\n 1- Si\n 2- No\n";
                    cin >> opcion;
                    switch(opcion)
                    {
                        case 1:
                        {
                            cout << "¿De que tipo es el ejercicio?:\n 1- Completar Palabra\n 2- Traduccion\n";
                            cin >> opcion1;
                            cout << "Ingrese además los siguientes datos:\n";
                            cout << "Descripcion:\n";
                            cin.ignore();
                            getline(cin,descEjercicio);
                            cout << "Frase del ejercicio:\n";
                            getline(cin,frase);
                            cout << "Solucion del ejercicio:\n";
                            getline(cin,solucion);
                            switch(opcion1)
                            {
                                case 1:
                                {
                                    ic->ingresarEjercicioCompletarPalabras(descEjercicio, frase, solucion);
                                    cout << "Se ingreso con exito el ejercicio completar palabras.\n";
                                    break;
                                }
                                case 2:
                                {
                                    ic->ingresarEjercicioTraduccion(descEjercicio, frase, solucion);
                                    cout << "Se ingreso con exito el ejercicio traduccion.\n";
                                    break;
                                }
                                default:
                                    cout << "Opcion no reconocida\n";
                                    break;
                            }
                            break;
                        }
                        case 2:
                        {
                            cond4 = false;
                            break;
                        }
                        default:
                            cout << "Opcion no reconocida\n";
                            break;
                    }
                } while (cond4);                
                ic->confirmarAltaLeccion();
                cout << "Se ingreso la leccion existosamente!\n\n";
            } else 
                cout <<"Error. El curso ingresado no existe en el sistema.\n\n";
            
        break;
        }

        case 7:
        {
            mostrarTitulo("Agregar ejercicio");
            string cursoNoHabilitado, descEjercicio, frase, solucion;
            int id, op;
            cout << "Estos son los cursos no habilitados en el sistema:\n";
            set<string> cursosNoHabilitados = ic->listarCursosNoHabilitados();
            for(set<string>::iterator it=cursosNoHabilitados.begin(); it!=cursosNoHabilitados.end(); ++it){
                cout << "-" << (*it) <<endl;
            }
            cout << "Ingrese el nombre del curso al que quiere agregarle una nueva lección:\n";
            cin.ignore();
            getline(cin, cursoNoHabilitado);
            ic->seleccionarCursoNoHabilitado(cursoNoHabilitado);
            cout << "Estas son las lecciones definidas en el curso seleccionado:\n";
            set<int> lecciones = ic->listarLeccionesDefinidas(cursoNoHabilitado);
            for(set<int>::iterator it=lecciones.begin(); it!=lecciones.end(); ++it){
                cout << "-" << (*it) <<endl;
            }
            cout << "Seleccione la lección a la cual se le va a agregar ejercicios:\n";
            cin >> id;
            ic->seleccionarLeccion(id);
            cout << "¿De qué tipo es el ejercicio?:\n 1- Completar Palabra\n 2- Traducción\n";
            cin >> op;
            cout << "Ingrese además los siguientes datos:\n";
            cout << "Descripción:\n";
            cin.ignore();
            getline(cin,descEjercicio);
            cout << "Frase del ejercicio:\n";
            getline(cin,frase);
            cout << "Solución del ejercicio:\n";
            getline(cin,solucion);
            switch(op)
            {
                case 1:
                {
                    ic->ingresarEjercicioCompletarPalabras(descEjercicio, frase, solucion);
                    break;
                }
                case 2:
                {
                    ic->ingresarEjercicioTraduccion(descEjercicio, frase, solucion);
                    break;
                }
                default:
                    cout << "Opcion no reconocida\n";
                    break;
            }
            ic->confirmarAltaEjercicio();
            cout << "Se ingresó con exito el ejercicio!\n\n";
        break;
        }

        case 8: 
        {
            mostrarTitulo("Habilitar curso");
            int habilitado;
            set<string> cursosNoHabilitados = ic->listarCursosNoHabilitados();
            if (cursosNoHabilitados.size() != 0){
                cout << "Los cursos no habilitados son los siguientes:\n";
                mostrarSet(cursosNoHabilitados);
                cout << "Ingrese el índice del curso que quiere habilitar:\n";
                int opcionCurso;
                cin >> opcionCurso;
                cin.clear();
                cin.ignore();
                if (opcionCurso >= 1 && opcionCurso <= cursosNoHabilitados.size()) {
                    string nombreCursoAHabilitar = obtenerEleccion(cursosNoHabilitados, opcionCurso);  
                    habilitado = ic->habilitarCurso(nombreCursoAHabilitar);
                    if (habilitado == 1){
                        cout << "El curso " << nombreCursoAHabilitar << " se habilitó exitosamente.\n";
                    } else if (habilitado == 2) {
                        cout << "El curso " << nombreCursoAHabilitar << " no tiene lecciones.\n";
                    } else if (habilitado == 3) {
                        cout << "El curso " << nombreCursoAHabilitar << " tiene al menos una lección sin ejercicios.\n"; //se podria decir cual a futuro
                    } else if (habilitado == -1) {
                        cout << "Hubo un error.\n";
                    }
                } else {
                    cout << "Error. Opción no reconocida.\n";
                    cout << "\n";
                }
            } else {
                cout << "No hay cursos para habilitar en el sistema.\n";
            }
        break;
        }


        case 9:{
            mostrarTitulo("Eliminar curso");
            int habilitado;
            set<string> cursos = ic->listarCursos();
            if (cursos.size() != 0)  {
                cout << "Los cursos en el sistema son los siguientes:\n";
                mostrarSet(cursos);
                cout << "Ingrese el índice del curso que quiere eliminar:\n";
                int opcionCurso;
                cin >> opcionCurso;
                if (opcionCurso >= 1 && opcionCurso <= cursos.size()){
                    string nombreCursoAEliminar = obtenerEleccion(cursos, opcionCurso);
                    bool eliminado = ic->eliminarCurso(nombreCursoAEliminar);
                    if (eliminado){
                        cout << "El curso " << nombreCursoAEliminar << " se eliminó correctamente.\n";          
                        cout << "\n";     
                    } else {
                        cout << "El curso " << nombreCursoAEliminar << " no se eliminó.\n"; // vaya a saber uno por qué
                        cout << "\n";
                    }
                } else {
                    cout << "Error. Opción no reconocida.\n";
                    cout << "\n";
                }
            } else {
                cout << "No hay cursos en el sistema para eliminar.\n";
                cout << "\n";
            }
        break;
        }

        case 10:
        {
            mostrarTitulo("Consultar cursos");
            cout << "Cursos existentes en el sistema:\n";
            set<string> cursoSistema;
            cursoSistema = ic -> listarCursos();
            mostrarSet(cursoSistema);
            int op;
            cout << "\n";
            cout << "Seleccione el número del curso que desea consultar: \n";
            cin >> op;
            if ((op >= 1) && (op <= cursoSistema.size())){
                string nombreCurso = obtenerEleccion(cursoSistema, op);
                ic -> mostrarCurso(nombreCurso);
            } else {
                cout << "El curso seleccionado no existe \n";
            }
        }
        break;

        case 11:{
            mostrarTitulo("Inscribirse a curso");
            int eleccion;
            set<string> estudiantes = ic->listarEstudiantes();
            mostrarSet(estudiantes);
            cout << "Seleccione el número de lista de su nickname: " << endl;
            cin >> eleccion;
            if(eleccion > 0 && eleccion <= estudiantes.size()){
                string nickname = obtenerEleccion(estudiantes, eleccion);
                set<string> cursos = ic->inscripcionCurso(nickname);
                mostrarSet(cursos);
                cout << "Seleccione el número en la lista del curso que desea inscribirse: " << endl;
                cin >> eleccion;
                if(eleccion > 0 && eleccion <= cursos.size()){
                    string nombreCurso = obtenerEleccion(cursos, eleccion);
                    cout << "Ingrese la fecha de su ingreso de la siguiente forma dd mm aaaa: " << endl;
                    int dia,mes,anio;
                    cin >> dia >> mes >> anio;
                    if(ic->confirmarInscripcion(nombreCurso,dia,mes,anio)){
                        cout << "La inscripción se ha realizado con éxito \n";
                    }
                }
                else
                    cout << "La opcion seleccionada no es correcta. \n";
            }
            else
                cout << "La opción seleccionada no es correcta. \n";
        }
        break;

        case 12: 
        {
            mostrarTitulo("Realizar ejercicio");
            string sol;
            int opcionNickname;
            cout << "Seleccione el número del estudiante que desea realizar el ejercicio:\n";
            set<string> nicknamesEstudiantes = iu->listarEstudiantesSistema(); 
            mostrarSet(nicknamesEstudiantes);
            cout << "\n";   
            cin >> opcionNickname;
            if ((opcionNickname >= 1) && (opcionNickname <= nicknamesEstudiantes.size())) {
                string nickname = obtenerEleccion(nicknamesEstudiantes, opcionNickname);
                set<string> cursosNA = iu->listarCursosNoAprobados(nickname);
                if (cursosNA.size() == 0) {
                    cout << "El estudiante no tiene cursos sin aprobar.\n";
                } else {
                cout << "Se listan los cursos sin aprobar del estudiante ingresado:\n";
                mostrarSet(cursosNA);
                cout << "\n";
                int opcionCurso;
                cin >> opcionCurso;
                string nombreCurso = obtenerEleccion(cursosNA, opcionCurso);
                if ((opcionCurso >= 1) && (opcionCurso <= cursosNA.size())){             
                    set<int> ejerciciosNoAprobados = iu->listarEjerciciosNoAprobados(nombreCurso);
                    if (ejerciciosNoAprobados.size() > 0){
                        cout << "Seleccione el ejercicio que desea realizar:\n";
                        mostrarSetNum(ejerciciosNoAprobados);
                        cout << "\n";
                        int idEjercicio;
                        cin >> idEjercicio;
                        int opcionEjercicio = obtenerEleccionNum(ejerciciosNoAprobados, idEjercicio);
                        if ((opcionEjercicio >= 1) && (opcionEjercicio <= ejerciciosNoAprobados.size())){
                            cout << "Ejercicio " << idEjercicio << ":\n";
                            iu->consultarInfoEjercicio(idEjercicio);
                            cout << "¿Desea ingresar la solución?\n 1-Sí \n 2- No\n";
                            int opcionSolucion;
                            cin >> opcionSolucion;
                            if (opcionSolucion == 1){
                                cout << "Ingrese la solución del ejercicio:\n";
                                cin.ignore();
                                getline(cin, sol);
                                bool comparacion = iu->compararSoluciones(sol);
                                if (comparacion){
                                    cout << "La solución es correcta. Se ha aprobado el ejercicio.\n";
                                } else {
                                    cout << "La solución no es correcta.\n";
                                }
                            } else if (opcionSolucion == 2){
                                break;
                            } else {
                                cout << "Error. Opción no reconocida.\n";
                                cout << "\n";
                            }
                        } else {
                            cout << "Error. Opción no reconocida.\n";
                            cout << "\n";
                        }
                    } else {
                        cout << "El estudiante no tiene ejercicios sin aprobar.\n";
                        cout << "\n";
                    }
                    
                } else {
                    cout << "Error. Opción no reconocida.\n";
                    cout << "\n";
                }
                }
            } else {
                cout << "Error. Opción no reconocida.\n";
                cout << "\n";
            }
        }
        break;

            
        case 13:{
            mostrarTitulo("Consultar estadísticas");
            int categoria;
            cout << "Seleccione una de las categorías: \n" << "1- Estudiante \n" << "2- Profesor \n" << "3- Curso \n" << endl;
            cin >> categoria;
            switch(categoria){
                case 1:{
                    set<string> estudiantes = ic->listarEstudiantes();
                    cout << "Seleccione el nickname del estudiante en la siguiente lista\n";
                    mostrarSet(estudiantes);
                    int eleccion;
                    cin >> eleccion;
                    string nickEstudiante = obtenerEleccion(estudiantes,eleccion);
                    set<DTAvanceCurso*> estadisticasEst = ic->obtenerEstadisticasEstudiante(nickEstudiante);
                    for(auto it = estadisticasEst.begin(); it != estadisticasEst.end(); ++it){
                        if((*it)->getAvance() == 1){
                            cout << "Curso: " << (*it)->getNombreCurso() << endl;
                            cout << "Avance: " << (*it)->getAvance() << " Aprobado" << endl;
                        }else{
                            cout << "Curso: " << (*it)->getNombreCurso() << endl;
                            cout << "Avance: " << (*it)->getAvance() << endl;
                        }
                    }
                }
            break;
            case 2:{
                set<string> profesores = ic->listarProfesores();
                int eleccion;
                cout << "Seleccione el nickname del profesor en la siguiente lista \n";
                mostrarSet(profesores);
                cin >> eleccion;
                string nickProfesor = obtenerEleccion(profesores,eleccion);
                vector<DTPromedioCurso> estadisticasProf = ic->obtenerEstadisticasProfesor(nickProfesor);
                vector<DTPromedioCurso>::iterator it;
                for(it = estadisticasProf.begin(); it != estadisticasProf.end(); ++it){
                    cout << "Curso: " << it->getInfoCurso() << "\nPromedio de aprobación: " << it->getPromedio() << endl;
                }
            }
            break;
            case 3:{
                set<string> cursos = ic->listarCursos();
                cout << "Seleccione el nombre del curso que desea consultar en la siguiente lista \n";
                mostrarSet(cursos);
                int eleccion;
                cin >> eleccion;
                string nombreCurso = obtenerEleccion(cursos,eleccion);
                DTPromedioCurso estadisticaCurso = ic->obtenerEstadisticasCurso(nombreCurso);
                cout << "Curso: " << estadisticaCurso.getInfoCurso() << "\nPromedio de aprobación: " << estadisticaCurso.getPromedio() << endl;
            }
            break;
            default: cout << "La categoría seleccionada no es correcta. \n";
            }
        }    
        break;

        case 14:
        {
            mostrarTitulo("Suscribirse a notificación");
            cout << "Seleccione el número del nickname correspondiente:\n";
            set<string> nicknames = iu->listarUsuariosSistema();
            mostrarSet(nicknames);
            int op;
            cin >> op;
            bool cond = true;
            if ((op >= 1) && (op <= nicknames.size())){
                string nickname = obtenerEleccion(nicknames, op);
                do{
                    int op2;
                    cout << "¿Desea suscribirse a un idioma?\n 1- Sí\n 2- No\n";
                    cin >> op2;
                    switch (op2){
                        case 1:
                        {
                            cout << "Seleccione el número del idioma al que desea suscribirse:\n";
                            set<string> idiomas = iu->suscribirNotificaciones(nickname);
                            mostrarSet(idiomas);
                            int op3;
                            cin >> op3;
                            if ((op3 >= 1) && (op3 <= idiomas.size())){
                                string idioma = obtenerEleccion(idiomas, op3); 
                                iu->confirmarSuscripcion(nickname, idioma);
                                cout << "Se realizó con exito la suscripcion a " << idioma << endl;
                            } else 
                                cout << "Opcion no reconocida\n"; 
                        break;  
                        }    
                        case 2:
                            cond = false;
                        break;
                    default:
                        cout << "Opción no reconocida\n";
                    break;
                    } 
                } while (cond);
            } else 
                cout << "Opción no reconocida\n";
            cout << "\n";        
        break;
        }

        case 15:
        {
            mostrarTitulo("Consultar notificaciones");
            cout << "Seleccione el número del usuario que desea consultar sus notificaciones:\n";
            set<string> nicknames = iu->listarUsuariosSistema();
            mostrarSet(nicknames);
            int op;
            cin >> op;
            if ((op >= 1) && (op <= nicknames.size())){
                string nickname = obtenerEleccion(nicknames, op);
                set<DTNotificacion*> notificaciones = iu->consultarNotificaciones(nickname);
                cout << "Notificaciones sin leer:\n";
                for(auto it = notificaciones.begin(); it != notificaciones.end(); ++it){
                    (*it)->mostrarNotificacion();
                }
                iu->eliminarNotificaciones(nickname);
            }
            cout << "\n";
        break;        
        }

        case 16:
        {
            mostrarTitulo("Eliminar suscripciones");
            cout << "Seleccione el número del nickname correspondiente:\n";
            set<string> nicknames = iu->listarUsuariosSistema();
            mostrarSet(nicknames);
            int op;
            cin >> op;
            bool cond = true;
            if ((op >= 1) && (op <= nicknames.size())){
                string nickname = obtenerEleccion(nicknames, op);
                do{
                    int op2;
                    cout << "¿Desea cancelar su suscripción a un idioma?\n 1- Sí\n 2- No\n";
                    cin >> op2;
                    switch (op2){
                        case 1:
                        {
                            cout << "Seleccione el número del idioma al que desea desuscribirse:\n";
                            set<string> idiomas = iu->cancelarSuscripciones(nickname);
                            mostrarSet(idiomas);
                            int op3;
                            cin >> op3;
                            if ((op3 >= 1) && (op3 <= idiomas.size())){
                                string idioma = obtenerEleccion(idiomas, op3); 
                                iu->eliminarSuscripcion(nickname, idioma);
                                cout << "Se eliminó la suscripcion a " << idioma << endl;
                            } else 
                                cout << "Opcion no reconocida\n"; 
                        break;  
                        }    
                        case 2:
                            cond = false;
                        break;
                    default:
                        cout << "Opción no reconocida\n";
                    break;
                    } 
                } while (cond);
            } else 
                cout << "Opción no reconocida\n";
            cout << "\n";        
        break;
        }
        

        case 17:
            encendido = false;
        break;


        default:
            cout << "Opcion no reconocida\n";
            break;
        }
    } 

    return 0;
};