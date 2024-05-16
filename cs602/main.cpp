#include <GL/glut.h>
#include <iostream>
#include <string>

GLfloat angle = 0.0f;
GLfloat scale_factor = 1.0f;
GLfloat translationX = 0.0f;
int selectedObject = 1;

std::string Response = "Syed Ali Raza";

GLfloat light_position[] = {1.0f, 1.0f, 1.0f, 0.0f};
GLfloat light_diffuse[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat light_ambient[] = {1.0f, 1.0f, 1.0f, 1.0f};

GLfloat material_diffuse_cube[] = {0.0f, 0.0f, 1.0f, 1.0f};
GLfloat material_diffuse_sphere[] = {1.0f, 0.0f, 0.0f, 1.0f};
GLfloat material_diffuse_torus[] = {1.0f, 1.0f, 0.0f, 1.0f};

GLfloat material_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
GLfloat material_shininess = 100.0f;

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialf(GL_FRONT, GL_SHININESS, material_shininess);
}

void drawCube() {
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_cube);
    glutSolidCube(1.0);
}

void drawSphere() {
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_sphere);
    glutSolidSphere(0.5, 20, 20);
}

void drawTorus() {
    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse_torus);
    glutSolidTorus(0.2, 0.5, 20, 20);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(translationX, 0.0f, -5.0f);
    glRotatef(angle, 1.0f, 1.0f, 0.0f);
    glScalef(scale_factor, scale_factor, scale_factor);

    if (selectedObject == 1) {
        drawCube();
    } else if (selectedObject == 2) {
        drawSphere();
    } else if (selectedObject == 3) {
        drawTorus();
    }

    std::cout << "SYED ALI RAZA " << Response << std::endl;

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (GLfloat)w / (GLfloat)h, 0.1f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
    case '2':
    case '3':
        selectedObject = key - '0';
        break;
    case 'q':
        angle += 5.0f;
        break;
    case 'e':
        angle -= 5.0f;
        break;
    case 'w':
        scale_factor += 0.1f;
        break;
    case 's':
        scale_factor -= 0.1f;
        break;
    case 'a':
        translationX -= 0.1f;
        break;
    }

    glutPostRedisplay();
}

void idle() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Syed Ali Raza");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(idle);

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glutMainLoop();

    return 0;
}

