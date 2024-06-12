#include <GL/glut.h>
#include <cstdlib> // Para generar los colores aleatorios

// Variables para la posición y color del cuadro
float posX = 0.0f;
float posY = 0.0f;
float colorR = 1.0f; // Componente rojo del color
float colorG = 1.0f; // Componente verde del color
float colorB = 1.0f; // Componente azul del color

// Función para dibujar el cuadro
void draw() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpiar la pantalla

    // Dibujar el cuadro con el color actual
    glColor3f(colorR, colorG, colorB);
    glBegin(GL_QUADS);
    glVertex2f(posX - 0.1f, posY - 0.1f); // Esquina inferior izquierda
    glVertex2f(posX + 0.1f, posY - 0.1f); // Esquina inferior derecha
    glVertex2f(posX + 0.1f, posY + 0.1f); // Esquina superior derecha
    glVertex2f(posX - 0.1f, posY + 0.1f); // Esquina superior izquierda
    glEnd();

    glFlush(); // Finalizar el dibujo
}

// Función para manejar las teclas
void keyboard(unsigned char key, int x, int y) {
    // Cambiar la posición del cuadro y generar un nuevo color aleatorio
    switch (key) {
    case 'w': // Mover hacia arriba
        posY += 0.1f;
        break;
    case 's': // Mover hacia abajo
        posY -= 0.1f;
        break;
    case 'a': // Mover hacia la izquierda
        posX -= 0.1f;
        break;
    case 'd': // Mover hacia la derecha
        posX += 0.1f;
        break;
    }

    // Generar nuevos componentes de color aleatorios
    colorR = static_cast<float>(rand()) / RAND_MAX;
    colorG = static_cast<float>(rand()) / RAND_MAX;
    colorB = static_cast<float>(rand()) / RAND_MAX;

    glutPostRedisplay(); // Volver a dibujar la escena
}

// Función principal
int main(int argc, char** argv) {
    //Configuracion de GLUT y creacion de la ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Cuadro Primitivo con Movimiento y Cambio de Color");
    glClearColor(0.5f, 0.5f, 0.5f, 0.5f); // Color de fondo gris 
    gluOrtho2D(-1.2, 1.2, -1.2, 1.2); // Ampliar el sistema de coordenadas
    glutDisplayFunc(draw);
    glutKeyboardFunc(keyboard); // Registrar la función de teclado
    glutMainLoop();//bucle principal del GLUT
    return 0;
}