#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define PI 3.141592f

bool click;
int raton[2];

class Mira {
   public:
      int posicion[2];
      
      void Posicionar(int x, int y) {
         posicion[0] = x;
         posicion[1] = y;
      }
      
      void Pintar() {
         glPushMatrix();
         glLineWidth(2);
         glTranslatef(posicion[0],posicion[1],0);
         glColor3f(1,0,0);
         glBegin(GL_LINES);
            glVertex3f(0,15,0);
            glVertex3f(0,-15,0);
            glVertex3f(15,0,0);
            glVertex3f(-15,0,0);
         glEnd();
         glBegin(GL_LINE_STRIP);
            for( float i = 0; i <= (2*PI); i += (PI/16) ) glVertex3f(10*cosf(i),10*sinf(i),0);
         glEnd();
         glPopMatrix();
      }
};

class Diana {
   public:
      float centro[2], timer[2], tipo;
      bool existe, disparada;
      
      void Pintar() {
         if (existe && !disparada) {
            glPushMatrix();
            glTranslatef(centro[0],centro[1],0);
            glColor3f(1,1,1);
            glBegin(GL_TRIANGLE_FAN);
               glVertex3f(0,0,0);
               for (float ang = 0; ang <= PI*2 + 0.1f; ang += PI/8) glVertex3f(20*tipo*cosf(ang),20*tipo*sinf(ang),0);
            glEnd();
            glColor3f(0,0.25f,1);
            glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0,0,0);
               for (float ang = 0; ang <= PI*2 + 0.1f; ang += PI/8) glVertex3f(15*tipo*cosf(ang),15*tipo*sinf(ang),0);
            glEnd();
            glColor3f(1,1,1);
            glBegin(GL_TRIANGLE_FAN);
               glVertex3f(0,0,0);
               for (float ang = 0; ang <= PI*2 + 0.1f; ang += PI/8) glVertex3f(10*tipo*cosf(ang),10*tipo*sinf(ang),0);
            glEnd();
            glColor3f(0,0.25f,1);
            glBegin(GL_TRIANGLE_FAN);
               glVertex3f(0,0,0);
               for (float ang = 0; ang <= PI*2 + 0.1f; ang += PI/8) glVertex3f(5*tipo*cosf(ang),5*tipo*sinf(ang),0);
            glEnd();
            glPopMatrix();
         }
      }
      
      void Iniciar(float ctox, float ctoy, float tiempo, float tip) {
         centro[0] = ctox;
         centro[1] = ctoy;
         timer[0] = tiempo;
         timer[1] = (60.0f*15.0f)/(4-tip);
         tipo = tip;
         existe = 0;
         disparada = 0;
      }
      
      void Evolucionar() {
         if (timer[0] >= 0.0f) timer[0] -= 1.0f;
         if (timer[0] < 0.0f) {
            existe = 1;
            if (timer[1] >= 0.0f) timer[1] -= 1.0f;
            else existe = 0;
         }
      }
      
      float Distancia() {
         return sqrt( pow(raton[0] - centro[0],2) + pow(raton[1] - centro[1],2) );
      }
      
      int Disparo() {
         if (existe && click && !disparada) {
            int puntos = 0;
            float dist = Distancia();
            if (dist < 20*tipo) {
               click = 0;
               disparada = 1;
               puntos = 4*(3-tipo);
               for (float i = 15; i > 0; i -= 5) {
                  if (dist < i*tipo) {
                     puntos += 4*(3-tipo);
                  }
               }
            }
            return puntos;
         }
         return 0;
      }
};

class Panel {
   public:
      Diana dianas[100];
      Mira mirilla;
      int puntostotal;
      
      void Iniciar() {
         for (int i = 0; i < 100; i++) {
            int tipo = (rand() % 3) + 1;
            int time = i*32;
            float cX = 20*tipo + (rand() % (800 - 2*20*tipo));
            float cY = 20*tipo + (rand() % (600 - 2*20*tipo));
            dianas[i].Iniciar(cX, cY, time, tipo);
         }
         puntostotal = 0;
      }
      
      void Evolucionar() {
         for (int i = 0; i < 100; i++) {
            dianas[i].Evolucionar();
            puntostotal += dianas[i].Disparo();
         }
         mirilla.Posicionar(raton[0], raton[1]);
      }
      
      void Pintar() {
         glPushMatrix();
         char puntos_texto[30];
         sprintf(puntos_texto,"Puntos: %i",puntostotal);
         glRasterPos2f(350,590);
         for (int i=0; i<strlen(puntos_texto); i++) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, puntos_texto[i]);
         glPopMatrix();
      }
} panel;

void PintarEscena() {
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0,800,0,600,-1,1);
   
   glMatrixMode(GL_MODELVIEW);
   glClear(GL_COLOR_BUFFER_BIT);
   glLoadIdentity();
   
   for (int i = 0; i < 200; i++) panel.dianas[i].Pintar();
   panel.mirilla.Pintar();
   panel.Pintar();
   
     glutSwapBuffers();
}

void ReProyectar(int w, int h) {
   glutReshapeWindow(800,600);
   glViewport(0, 0, w, h);

     PintarEscena();
}

void Mover(int value) {
   glutTimerFunc(16,Mover,1);
   glutPostRedisplay();
   
   panel.Evolucionar();
}

void Raton(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) click = 1;
   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) click = 0;
   raton[0] = x;
   raton[1] = 600 - y;
}

void RatonMov(int x, int y) {
   raton[0] = x;
   raton[1] = 600 - y;
}

int main(int argc, char **argv) {
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
   glutInitWindowSize(800,600);
   glutInitWindowPosition(40,40);
   glutCreateWindow("Shooter 2D por HarZe");

   srand((unsigned)time(0));
   panel.Iniciar();

   glutReshapeFunc(ReProyectar);
   glutDisplayFunc(PintarEscena);
   glutMouseFunc(Raton);
   glutMotionFunc(RatonMov);
   glutPassiveMotionFunc(RatonMov);
   glutTimerFunc(16,Mover,1);

   glutMainLoop();
   return 0;
}