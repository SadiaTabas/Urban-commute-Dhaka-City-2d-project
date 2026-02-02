#include <windows.h>
#include <GL/glut.h>
#include<math.h>

#define MAX_DROPS 400
#define MAX_SNOW 400

float dropX[MAX_DROPS];
float dropY[MAX_DROPS];
float dropSpeed[MAX_DROPS];
bool rainActive = false;


float snowX[MAX_SNOW];
float snowY[MAX_SNOW];
float snowSpeed[MAX_SNOW];
bool snowActive = false;


float sunX = 12.5f;
float sunY = 14.0f;  //  sun   (top)
float moonX = 12.5f;
float moonY = -1.0f; //   moon  (below  )
float sunRadius = 1.0f;

int segments = 100;


bool isNight = false;
bool isSunset = false;
float animationSpeed = 0.05f;






/////////////wave
float waveOffset = 0.0f;

float shipX = -20.0f;
float shipSpeed = 0.03f;


//////////////cloud
float cloudX = 0.0f;
float cloudSpeed = 0.05f;
int cloudDir = 0;


////////////car red
float carX = -5.0f;
float carSpeed = 0.04f;

//////blue car
float car2X = -10.0f;
float car2Speed = 0.04f;

/////orange car
float car3X = -10.0f;
float car3Speed = 0.03f;

///////bus
float busX = -20.0f;
float busSpeed = 0.03f;


//////train
float trainX = -25.0f;
float trainSpeed = 0.05f;
bool trainMoving = false;

////sun////////////ID:A1
void updateAnimation(int value) {
    if (isSunset) {

        sunY -= animationSpeed;
        moonY += animationSpeed;


        if (sunY <= 2.0f) {
            sunY = 2.0f;
            moonY = 14.0f;
            isSunset = false;
            isNight = true;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(16, updateAnimation, 0);
}








////busssss//////ID:A2
void updateBus(int value) {
    busX += busSpeed;
    if (busX > 40.0f)
        busX = -20.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateBus, 0);

}

///////car red/////////ID:A3

void updateCarRed(int value) {
    carX += carSpeed;
    if (carX > 30.0f)
        carX = -5.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateCarRed, 0);
}
///////////////ID:A4
void updateCarBlue(int value) {
    car2X += car2Speed;
    if(car2X > 30.0f)
        car2X = -10.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateCarBlue, 0);
}
/////////////ID:A5
void updateCarOrange(int value) {
    car3X += car3Speed;
    if (car3X > 30.0f)
        car3X = -10.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateCarOrange, 0);
}
//////////////////ID:A6
void updateTrain(int value) {
    if(trainMoving) {
        trainX -= trainSpeed;
        if(trainX < -25.0f)
            trainX =30.0f;
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateTrain, 0);
}
////////////////ID;A7
void updateShip(int value) {
    shipX += shipSpeed;       // move right

    if (shipX > 25.0f)
        shipX = -20.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateShip, 0);
}
////////////////////ID:A8
void updateCloud(int value) {
    cloudX += cloudDir * cloudSpeed;


    if (cloudX > 30.0f)
        cloudX = -30.0f;

    if (cloudX < -30.0f)
        cloudX = 30.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateCloud, 0);}


////////////////ID:A9
void updateRain(int value) {
    if(rainActive) {
        for(int i=0; i<MAX_DROPS; i++) {
            dropY[i] -= dropSpeed[i];
            if(dropY[i] < 0.0f) {
                dropY[i] = 15.0f;
                dropX[i] = (rand() % 4000 / 100.0f) - 10.0f;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateRain, 0);
}
////////////////ID:A10
void updateSnow(int value) {
    if(snowActive) {
        for(int i = 0; i < MAX_SNOW; i++) {
            snowY[i] -= snowSpeed[i];
            if(snowY[i] < 0.0f) {
                snowY[i] = 15.0f;
                snowX[i] = (rand() % 4000 / 100.0f) - 10.0f;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, updateSnow, 0);
}

/////////////ID:A11
void updateWave(int value) {
    waveOffset += 0.05f;
    if(waveOffset > 6.0f)
        waveOffset = 0.0f;

    glutPostRedisplay();
    glutTimerFunc(16, updateWave, 0);
}

////////////ID:A12

void mouse(int button, int state, int x, int y) {
    if (state == GLUT_DOWN) {
        if(button == GLUT_LEFT_BUTTON) {
            //  rain
            rainActive = !rainActive;
        }
        else if(button == GLUT_RIGHT_BUTTON) {
            //  snow
            snowActive = !snowActive;
        }
    }
}

//////////////ID:A13
void keyboard(unsigned char key, int x, int y) {

     // Day/Night
    if (key == 'n' || key == 'N') {
        isNight = !isNight;
        if (!isNight) {
            sunY = 14.0f;  // Reset sun
            moonY = -1.0f;  // Hide moon
            isSunset = false;
        }
    }

    // Sunset animation
    if (key == 'r' || key == 'R') {
        if (!isNight && !isSunset) {
            isSunset = true;
            moonY = -1.0f;
        }
    }

    // Train start
    if (key == 'm' || key == 'M') {
        trainMoving = true;
    }  //stop
    if (key == 's' || key == 'S') {
        trainMoving = false;
    }

    // Cloud movement
    if (key == 'l' || key == 'L') {
    cloudDir = 1;   // move left to right
}
if (key == 'j' || key == 'J') {
    cloudDir = -1;  // move right to left
}



if (key == 'k' || key == 'K') {
    cloudDir = 0;   // stop cloud
}

    glutPostRedisplay();
}

////////////////////////////////////////////////////////bridge line  ID:0
void sabridge() {

    glColor3ub(156, 181, 186);
    glBegin(GL_POLYGON);

        glVertex2f(-0.2227497324041, 8.2991563954655);   // E
        glVertex2f(25.992808946038, 8.3090046905257);   // F
        glVertex2f(25.0, 8.7);                          // J
        glVertex2f(25.9625693208329,8.7613988446563);  // H
        glVertex2f(-0.2229148252709, 8.7613988446563);   // I
        glVertex2f(-0.2271530180748, 8.4785096458232);   // G

    glEnd();
////////////////////////////////////outlinee
     glColor3ub(96, 96, 96);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2227497324041, 8.2991563954655);   // E
        glVertex2f(25.992808946038, 8.3090046905257);   // F
        glVertex2f(25.0, 8.7);                          // J
        glVertex2f(25.9625693208329, 8.7613988446563);  // H
        glVertex2f(-0.2229148252709, 8.7613988446563);   // I
        glVertex2f(-0.2271530180748, 8.4785096458232);   // G*/
     glEnd();
}
//bridge pilar ID:1

void sabridgeP1() {
  glColor3ub( 156, 181, 186);

    glBegin(GL_POLYGON);

          glVertex2f(10.896292806444, 8.2867627212987);   // K
        glVertex2f(10.9657962695623, 7.869741942589);   // L
        glVertex2f(11.1627227483974, 7.811822389904);   // O
        glVertex2f(11.6029113481466, 7.811822389904);   // P
        glVertex2f(11.8230056480212, 7.869741942589);   // M
        glVertex2f(11.8809252006197, 8.2983466318184);   // N

    glEnd();



       glColor3ub(96, 96, 96);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);

          glVertex2f(10.896292806444, 8.2867627212987);   // K
        glVertex2f(10.9657962695623, 7.869741942589);   // L
        glVertex2f(11.1627227483974, 7.811822389904);   // O
        glVertex2f(11.6029113481466, 7.811822389904);   // P
        glVertex2f(11.8230056480212, 7.869741942589);   // M
        glVertex2f(11.8809252006197, 8.2983466318184);   // N

    glEnd();

 }

 void  sabridgeP11() {
    glColor3ub(156, 181, 186);
    glBegin(GL_POLYGON);

        glVertex2f(11.1627227483974, 7.811822389904);   // O
        glVertex2f(11.1511388378777, 6.9661969220513);   // R
        glVertex2f(11.6029113481466, 6.9661969220513);   // Q
        glVertex2f(11.6029113481466, 7.811822389904);   // P

    glEnd();

         glColor3ub(96, 96, 96);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);

    glVertex2f(11.1627227483974, 7.811822389904);   // O
        glVertex2f(11.1511388378777, 6.9661969220513);   // R
        glVertex2f(11.6029113481466, 6.9661969220513);   // Q
        glVertex2f(11.6029113481466, 7.811822389904);   // P
    glEnd();
}


////////ID:2
void sabridgeP2() {
    glColor3ub(156, 181, 186); // same color as first pillar
    glBegin(GL_POLYGON);

        glVertex2f(14.0474513820415, 8.2867627212987); // S
        glVertex2f (14.1414125143692, 7.8761276461912); // U
        glVertex2f (14.3310678324269, 7.8070314496237);  // T
        glVertex2f(14.788486741068, 7.8118223899904);   // V
        glVertex2f (14.9615537613141, 7.8710336011791); // W
        glVertex2f (15.031748861982,8.2983466318184);  // Z

    glEnd();


          glColor3ub(96, 96, 96);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);

   glVertex2f(14.0474513820415, 8.2867627212987); // S
        glVertex2f (14.1414125143692, 7.8761276461912); // U
        glVertex2f (14.3310678324269, 7.8070314496237);  // T
        glVertex2f(14.788486741068, 7.8118223899904);   // V
        glVertex2f (14.9615537613141, 7.8710336011791); // W
        glVertex2f (15.031748861982,8.2983466318184);  // Z
    glEnd();
}

// Pillar 2 base
void sabridgeP22() {
    glColor3ub(156, 181, 186);
    glBegin(GL_POLYGON);

        glVertex2f(14.3268697953706, 7.8118477198722); // U
        glVertex2f(14.3265838302301, 6.9676391223565); // A1
        glVertex2f(14.7760955402726, 6.9655385040299); // B1
        glVertex2f(14.788486741068, 7.811822389904);   // V

    glEnd();


         glColor3ub(96, 96, 96);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(14.3268697953706, 7.8118477198722); // U
        glVertex2f(14.3265838302301, 6.9676391223565); // A1
        glVertex2f(14.7760955402726, 6.9655385040299); // B1
        glVertex2f(14.788486741068, 7.811822389904);   // V

    glEnd();
}

/////////////////////////////pilar 3  ////////ID:3
void sabridgeP3() {
    glColor3ub(156, 181, 186);
    glBegin(GL_POLYGON);

        glVertex2f (17.7980615708803, 8.2867627212987);//c
          glVertex2f(17.9616708302985, 7.8158572180219) ;//D
            glVertex2f (18.065702145127, 7.8104847088054);//C1
            glVertex2f (18.5187427185201, 7.81462206564);//d1
             glVertex2f (18.630548227752005, 7.826602236454838);//E1
             glVertex2f (18.7648630666788, 8.2983466318184);//F12
            glEnd();

         glColor3ub(96, 96, 96);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
 glVertex2f (17.7980615708803, 8.2867627212987);//c
          glVertex2f(17.9616708302985, 7.8158572180219) ;//D
            glVertex2f (18.065702145127, 7.8104847088054);//C1
            glVertex2f (18.5187427185201, 7.81462206564);//d1
             glVertex2f (18.630548227752005, 7.826602236454838);//E1
             glVertex2f (18.7648630666788, 8.2983466318184);//F12

    glEnd();
            }

            void sabridgeP33() {
    glColor3ub(156, 181, 186);
    glBegin(GL_POLYGON);

        glVertex2f(18.065702145127, 7.8104847088054); // C1
        glVertex2f(18.0721297322212, 3.8662337889675); // G1
         glVertex2f (18.5013572218954, 3.8611731752948);   // H1
        glVertex2f(18.5187427185201, 7.81462206564); // D1
    glEnd();

           glColor3ub(96, 96, 96);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
  glVertex2f(18.065702145127, 7.8104847088054); // C1
        glVertex2f(18.0721297322212, 3.8662337889675); // G1
         glVertex2f (18.5013572218954, 3.8611731752948);   // H1
        glVertex2f(18.5187427185201, 7.81462206564); // D1
    glEnd();


}
////////////////////////////////////school ID:4
void sschool() {
    glColor3ub(235, 220, 170);
    glBegin(GL_POLYGON);

        glVertex2f (10.0760514990726, 6.9661969220513);//I1
          glVertex2f(10.0759512457943, 6.5231467677761) ;//J1
            glVertex2f  (10.2133293697777,6.5231467677761);//L2
            glVertex2f (11.9544006476858, 6.5231467677761);//L1
             glVertex2f (11.9544006476858, 6.9661969220513);//k1

            glEnd();

            glBegin(GL_POLYGON);
glVertex2f  (10.2133293697777,6.5231467677761);//L2
          glVertex2f(10.2133293697777, 4.4347734797059) ;//H3
          glVertex2f(11.8847530172387, 3.8877628978036);//I3
           glVertex2f(11.9544006476858, 3.8877628978036);  // R1
            glVertex2f (11.9544006476858, 6.5231467677761);//L1
            glEnd();


        glBegin(GL_POLYGON);
glVertex2f (11.9544006476858, 6.5231467677761);//L1
       glVertex2f (11.9544006476858, 6.9661969220513);//k1
          glVertex2f(12.8849052611321, 7.6053216270926);//N3
           glVertex2f(13.796965064573, 6.9505094605196) ; // O1
            glVertex2f (13.796965064573, 6.5448298264893);//P1
            glEnd();


                    glBegin(GL_POLYGON);
glVertex2f (11.9544006476858, 6.5231467677761);//L1
     glVertex2f(11.9544006476858, 3.8877628978036);  // R1
glVertex2f (13.796965064573, 6.5448298264893);//P1
             glVertex2f(13.7906248040459, 3.8877628978036);  // Q1
             glVertex2f(11.9544006476858, 3.8877628978036);  // R1
            glEnd();

                                glBegin(GL_POLYGON);
                glVertex2f(13.7906248040459, 3.8877628978036);  // Q1
                glVertex2f (13.796965064573, 6.5448298264893);//P1
glVertex2f (15.2391114878045, 6.512572727738);//K3
     glVertex2f(15.2391114878045, 4.4471497859795);  // J3
 glVertex2f(14.4611345549248, 3.7559650469706);

            glEnd();

                           glBegin(GL_POLYGON);

                glVertex2f (13.8012147155723, 6.5448298264893);//P1
                glVertex2f(13.8012147155723, 6.9508043157099); // O1
         glVertex2f(15.3579317099435, 6.9508043157099); // G2
glVertex2f(15.3579317099435, 6.5448298264893);//H2

  glEnd();


}

///////////////////////school ouline
            void sschoolLine(){
                                 glColor3ub(60, 60, 60);
                                 glLineWidth(3);
                                 glBegin(GL_LINE_LOOP);
                      glVertex2f (10.0760514990726, 6.9661969220513);//I1
          glVertex2f(10.0759512457943, 6.5231467677761) ;//J1
            glVertex2f  (10.2133293697777,6.5231467677761);//L2
            glVertex2f (11.9544006476858, 6.5231467677761);//L1
             glVertex2f (11.9544006476858, 6.9661969220513);//k1

            glEnd();
            glBegin(GL_LINE_LOOP);
glVertex2f  (10.2133293697777,6.5231467677761);//L2
          glVertex2f(10.2133293697777, 4.4347734797059) ;//H3
          glVertex2f(11.8847530172387, 3.8877628978036);//I3
           glVertex2f(11.9544006476858, 3.8877628978036);  // R1
            glVertex2f (11.9544006476858, 6.5231467677761);//L1

            glEnd();

                  glBegin(GL_LINE_LOOP);
glVertex2f (11.9544006476858, 6.5231467677761);//L1
       glVertex2f (11.9544006476858, 6.9661969220513);//k1
          glVertex2f(12.8849052611321, 7.6053216270926);//N3
           glVertex2f(13.796965064573, 6.9505094605196) ; // O1
            glVertex2f (13.796965064573, 6.5231467677761);//P1
            glEnd();


                    glBegin(GL_LINE_LOOP);
glVertex2f (11.9544006476858, 6.5231467677761);//L1
     glVertex2f(11.9544006476858, 3.8877628978036);  // R1
        glVertex2f(13.7906248040459, 3.8877628978036);  // Q1
glVertex2f (13.796965064573, 6.5231467677761);//P1
glEnd();

                           glBegin(GL_LINE_LOOP);
                glVertex2f(13.7906248040459, 3.8877628978036);  // Q1
                glVertex2f (13.796965064573, 6.5448298264893);//P1
glVertex2f (15.2391114878045, 6.512572727738);//K3
     glVertex2f(15.2391114878045, 4.4471497859795);  // J3
   glVertex2f(14.4611345549248, 3.7559650469706);

            glEnd();

                                       glBegin(GL_LINE_LOOP);
           glVertex2f (13.8012147155723, 6.5448298264893);//P1
                glVertex2f(13.8012147155723, 6.9508043157099); // O1
         glVertex2f(15.3579317099435, 6.9508043157099); // G2
glVertex2f(15.3579317099435, 6.5448298264893);//H2




  glEnd();

}
////////////////////////////school main dooor  ID:5
void sschoolDoor() {
    glColor3ub(139, 69, 19); // brown door

    glBegin(GL_POLYGON);
    glVertex2f(12.55, 3.8877); //  A5
    glVertex2f(12.55, 4.85);   // t V4
    glVertex2f(13.20, 4.85);   //  W4
    glVertex2f(13.20, 3.8877); //  Z4
    glEnd();

    //////////////////////////// Door outline
    glColor3ub(40, 20, 10);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
    glVertex2f(12.55, 3.8877);
    glVertex2f(12.55, 4.85);
    glVertex2f(13.20, 4.85);
    glVertex2f(13.20, 3.8877);
    glEnd();
}

//////////////////ID:6
void sdrawWindow(float x, float y)   {
    glColor3ub(170, 215, 240);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.4);
    glVertex2f(x + 0.4, y + 0.4);
    glVertex2f(x + 0.4, y);
    glEnd();

    glColor3ub(50, 50, 50);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x, y);
    glVertex2f(x, y + 0.4);
    glVertex2f(x + 0.4, y + 0.4);
    glVertex2f(x + 0.4, y);
    glEnd();
}



void schoolWindowsLeft() {
    sdrawWindow(10.45, 5.6);//B5 C5
    sdrawWindow(11.05, 5.6);
    sdrawWindow(10.45, 4.8);
    sdrawWindow(11.05, 4.8);
}

void schoolWindowsRight() {
    sdrawWindow(14.05, 5.6);//F5 G5
    sdrawWindow(14.65, 5.6);
    sdrawWindow(14.05, 4.9);
    sdrawWindow(14.65, 4.9);


}

void bigSchoolWindow() {
    glColor3ub(170, 215, 240);

    glBegin(GL_POLYGON);
    glVertex2f(12.40, 5.40); // H5
    glVertex2f(12.40, 6.30); //J5
    glVertex2f(13.40, 6.30); // I5
    glVertex2f(13.40, 5.40); //K5
    glEnd();

    ///////////// window outlineeeee
    glColor3ub(50, 50, 50);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(12.40, 5.40);
    glVertex2f(12.40, 6.30);
    glVertex2f(13.40, 6.30);
    glVertex2f(13.40, 5.40);
    glEnd();
}



///////////////////////Hospital ID:7
void shospital() {

    glColor3ub(220, 220, 220);
    glBegin(GL_POLYGON);
        glVertex2f(3.3588f, 3.8689f); //L5
        glVertex2f(3.3588f, 8.8f);//M5
        glVertex2f(6.2f, 8.8f);//V1
        glVertex2f(6.2f, 3.8689f);//N5
    glEnd();


    glColor3ub(200, 200, 200);
    glBegin(GL_POLYGON);
        glVertex2f(3.3588f, 8.8f);
        glVertex2f(3.3588f, 9.0f);
        glVertex2f(6.2f, 9.0f);
        glVertex2f(6.2f, 8.8f);
    glEnd();

    //////////////////// Outline main hospital
    glColor3ub(0, 0, 0);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.3588f, 3.8689f);
        glVertex2f(3.3588f, 8.8f);
        glVertex2f(6.2f, 8.8f);
        glVertex2f(6.2f, 3.8689f);
    glEnd();

    // Outline roof
    glBegin(GL_LINE_LOOP);
        glVertex2f(3.3588f, 8.8f);
        glVertex2f(3.3588f, 9.0f);
        glVertex2f(6.2f, 9.0f);
        glVertex2f(6.2f, 8.8f);
    glEnd();

    // Draw hospital windows
    glColor3ub(135, 206, 235);
    float x_start = 3.5f;
    float x_end = 6.0f;
    float y_start = 4.0f;
    float y_end = 8.5f;
    float x_gap = 0.5f;
    float y_gap = 0.7f;

    for(float y = y_start; y <= y_end - 0.5f; y += y_gap) {
        for(float x = x_start; x <= x_end - 0.4f; x += x_gap) {
            glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x + 0.35f, y);
                glVertex2f(x + 0.35f, y + 0.5f);
                glVertex2f(x, y + 0.5f);
            glEnd();

            // Window outline
            glColor3ub(0, 0, 0);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x, y);
                glVertex2f(x + 0.35f, y);
                glVertex2f(x + 0.35f, y + 0.5f);
                glVertex2f(x, y + 0.5f);
            glEnd();

            glColor3ub(135, 206, 235);
        }
    }



    //red sign

    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(4.75f, 9.05f);
        glVertex2f(4.75f, 9.25f);
        glVertex2f(4.95f, 9.25f);
        glVertex2f(4.95f, 9.05f);
    glEnd();

    // Horizontal part
    glBegin(GL_POLYGON);
        glVertex2f(4.65f, 9.15f);
        glVertex2f(4.65f, 9.35f);
        glVertex2f(5.05f, 9.35f);
        glVertex2f(5.05f, 9.15f);
    glEnd();


}
////////////////////////ID:8

void shospital_section() {
    // Main section building
    glColor3ub(230, 230, 230);
    glBegin(GL_POLYGON);
        glVertex2f(6.2f, 3.8689f);
        glVertex2f(6.2f, 7.5f);
        glVertex2f(8.5f, 7.5f);
        glVertex2f(8.5f, 3.8689f);
    glEnd();


    glColor3ub(180, 180, 180);
    glBegin(GL_POLYGON);
        glVertex2f(6.2f, 7.5f);
        glVertex2f(6.2f, 7.7f);
        glVertex2f(8.5f, 7.7f);
        glVertex2f(8.5f, 7.5f);
    glEnd();

    // Outline
    glColor3ub(40, 40, 40);
    glLineWidth(2.0f);

    // Outline main section
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.2f, 3.8689f);
        glVertex2f(6.2f, 7.5f);
        glVertex2f(8.5f, 7.5f);
        glVertex2f(8.5f, 3.8689f);
    glEnd();

    // Outline roof
    glBegin(GL_LINE_LOOP);
        glVertex2f(6.2f, 7.5f);
        glVertex2f(6.2f, 7.7f);
        glVertex2f(8.5f, 7.7f);
        glVertex2f(8.5f, 7.5f);
    glEnd();

    // Windows for section building
    glColor3ub(160, 210, 235);
    float x_start = 6.3f;
    float x_end = 8.3f;
    float y_start = 4.0f;
    float y_end = 7.0f;
    float x_gap = 0.5f;
    float y_gap = 0.7f;

    for(float y = y_start; y <= y_end - 0.5f; y += y_gap) {
        for(float x = x_start; x <= x_end - 0.4f; x += x_gap) {
            glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x + 0.35f, y);
                glVertex2f(x + 0.35f, y + 0.5f);
                glVertex2f(x, y + 0.5f);
            glEnd();

            // Window outline
            glColor3ub(40, 40, 40);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x, y);
                glVertex2f(x + 0.35f, y);
                glVertex2f(x + 0.35f, y + 0.5f);
                glVertex2f(x, y + 0.5f);
            glEnd();

            glColor3ub(160, 210, 235);
        }
    }


}




////////////////////////////Id:9
 void sbuild() {
    /////////buldinggggggggg
    glColor3ub(120, 130, 125);
    glBegin(GL_POLYGON);
        glVertex2f( -1.0f, 3.8689f); //p5
        glVertex2f( -1.0f, 7.5f);   //o5
        glVertex2f( 1.3065f, 7.5f);  //R5
        glVertex2f( 1.3065f, 3.8689f); //q5
    glEnd();

    // Roof part
    glColor3ub(90, 90, 90);
    glBegin(GL_POLYGON);
        glVertex2f(-1.0f, 7.5f);
        glVertex2f(-1.0f, 7.7f);
        glVertex2f(1.3065f, 7.7f);
        glVertex2f(1.3065f, 7.5f);
    glEnd();


    glColor3ub(135, 206, 235);
    float x_start = -0.9f;
    float x_end = 1.1f;
    float y_start = 4.0f;
    float y_end = 7.0f;
    float x_gap = 0.5f;
    float y_gap = 0.7f;

    for(float y = y_start; y <= y_end - 0.5f; y += y_gap) {
        for(float x = x_start; x <= x_end - 0.4f; x += x_gap) {
            glBegin(GL_POLYGON);
                glVertex2f(x, y);
                glVertex2f(x + 0.35f, y);
                glVertex2f(x + 0.35f, y + 0.5f);
                glVertex2f(x, y + 0.5f);
            glEnd();

            // Window outline
            glColor3ub(40, 40, 40);
            glBegin(GL_LINE_LOOP);
                glVertex2f(x, y);
                glVertex2f(x + 0.35f, y);
                glVertex2f(x + 0.35f, y + 0.5f);
                glVertex2f(x, y + 0.5f);
            glEnd();

            glColor3ub(135, 206, 235); // Reset for next window
        }
    }

    //  door
    glColor3ub(160, 82, 45);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5f, 3.8689f);
        glVertex2f(-0.5f, 5.0f);
        glVertex2f(0.0f, 5.0f);
        glVertex2f(0.0f, 3.8689f);
    glEnd();

    glColor3ub(40, 40,40); // Door outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.5f, 3.8689f);
        glVertex2f(-0.5f, 5.0f);
        glVertex2f(0.0f, 5.0f);
        glVertex2f(0.0f, 3.8689f);
    glEnd();
}

void sbuildline() {
    glColor3ub(40, 40, 40); // Black outline
    glLineWidth(2.0f);

    // Outline main left building
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 3.8689f);
        glVertex2f(-1.0f, 7.5f);
        glVertex2f(1.3065f, 7.5f);
        glVertex2f(1.3065f, 3.8689f);
    glEnd();

    // Outline roof
    glBegin(GL_LINE_LOOP);
        glVertex2f(-1.0f, 7.5f);
        glVertex2f(-1.0f, 7.7f);
        glVertex2f(1.3065f, 7.7f);
        glVertex2f(1.3065f, 7.5f);
    glEnd();
}





////////////////////////////ID:10


void sroad(){   glColor3ub(156, 181, 186);
    glBegin(GL_POLYGON);

                glVertex2f (-0.0083816949771, 3.8675075074537);//K3
                glVertex2f(25.0002204247388, 3.8567948404274); // L3
                 glVertex2f(25.9772565082837, 3.4319623860081); // M3
        glVertex2f(-0.0083816949771, 3.4255626295411); // N3
          glEnd();

  glBegin(GL_POLYGON);
   glColor3ub(156, 181, 186);

                glVertex2f(0.0197944294328, 1.0451562768706);//o3
                glVertex2f(25, 1.0451562768706 ); // P3
                 glVertex2f(25.0145148875891, 0.6381874874979); // Q3
        glVertex2f(0.0077810536887, 0.6381874874979); // R3
        glEnd();



    glBegin(GL_POLYGON);

  glColor3ub(56, 59, 45);
glVertex2f(-0.0083816949771, 3.4255626295411); // N3
 glVertex2f(0.0197944294328, 1.0451562768706);//o3
  glVertex2f(25, 1.0451562768706); // P3
   glVertex2f(25.9772565082837, 3.4319623860081); // M3
 glEnd();





 //outline
     glColor3ub(89, 87, 87); // black
    glLineWidth(3);

    // Outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.00838f, 3.8675f); // K3
        glVertex2f(25.0002f, 3.8567f);  // L3
        glVertex2f(25.9772f, 3.4319f);  // M3
        glVertex2f(-0.00838f, 3.4255f); // N3
    glEnd();

    // Outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.01979f, 1.0451f);  // O3
        glVertex2f(25.0f, 1.0451f);     // P3
        glVertex2f(25.0145f, 0.6381f);  // Q3
        glVertex2f(0.00778f, 0.6381f);  // R3
    glEnd();

    // Outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.00838f, 3.4255f); // N3
        glVertex2f(0.01979f, 1.0451f);  // O3
        glVertex2f(25.0f, 1.0451f);     // P3
        glVertex2f(25.9772f, 3.4319f);  // M3
    glEnd();

}

void dashlineroad(){
    glColor3ub(255, 255, 255); // white color

    // Dash 1
    glBegin(GL_LINES);
        glVertex2f(0.0067100603935, 2.23);
        glVertex2f(1.00603935, 2.23);
          glEnd();


    // Dash 2
     glBegin(GL_LINES);
        glVertex2f(1.4f, 2.23f);
        glVertex2f(3.10f, 2.23f);

    glEnd();

    // Dash 3
     glBegin(GL_LINES);
        glVertex2f(4.00f, 2.23f);
        glVertex2f(5.10f, 2.23f);

    glEnd();

    // Dash 4
  glBegin(GL_LINES);
        glVertex2f(6.8f, 2.23);
        glVertex2f(8.10f, 2.23f);

    glEnd();

    // Dash 5
 glBegin(GL_LINES);
        glVertex2f(9.05f, 2.23f);
        glVertex2f(10.10f, 2.23f);

    glEnd();

    // Dash 6
 glBegin(GL_LINES);
        glVertex2f(11.05f,2.23f);
        glVertex2f(12.3f, 2.23f);

    glEnd();

    // Dash 7
  glBegin(GL_LINES);
        glVertex2f(13.00f, 2.23f);
        glVertex2f(14.05f, 2.23f);

    glEnd();

    // Dash 8 (last)
    glBegin(GL_LINES);
        glVertex2f(15.0f, 2.23f);
        glVertex2f(16.5f, 2.23f);

    glEnd();
    // Dash 9
glBegin(GL_LINES);
    glVertex2f(17.0f, 2.23f);
    glVertex2f(18.2f, 2.23f);
glEnd();

// Dash 10
glBegin(GL_LINES);
    glVertex2f(18.8f, 2.23f);
    glVertex2f(20.0f, 2.23f);
glEnd();

// Dash 11
glBegin(GL_LINES);
    glVertex2f(20.5f, 2.23f);
    glVertex2f(21.7f, 2.23f);
glEnd();

// Dash 12
glBegin(GL_LINES);
    glVertex2f(22.2f, 2.23f);
    glVertex2f(23.5f, 2.23f);
glEnd();

// Dash 13
glBegin(GL_LINES);
    glVertex2f(24.0f, 2.23f);
    glVertex2f(25.0f, 2.23f);
glEnd();
}




// Grass///////ID:11
void sgrass1() {
    glColor3ub(40, 222, 40);

    glBegin(GL_POLYGON);

  glVertex2f(9.561840503148, 3.8050606244273);   // v1
    glVertex2f(9.8962644897881, 4.1252018625452);   // U1
    glVertex2f (10.3457590954872, 4.3445552301264);   // T1
    glVertex2f(10.119383f, 4.402727f);  // U1
    glVertex2f(10.744910305348, 4.5926762524723);  // M1
    glVertex2f(10.9319000613188, 4.5854843387811);  // S1
    glVertex2f(11.2699200048046, 4.3373633164352);  // w1
    glVertex2f(11.5611925092976, 4.1036261214717);  // J2
    glVertex2f(11.7553741789596, 3.8477628978036);  // k2
    glVertex2f(11.9544006476858, 3.8877628978036);  // R1
glVertex2f(9.561840503148, 3.8050606244273);//v1

    glEnd();
}
//////////ID:12
void sgrass2() {
    glColor3ub(40, 222, 40);

    glBegin(GL_POLYGON);

  glVertex2f(14.4611345549248, 3.7559650469706);   // z1
    glVertex2f(15.056071451903, 4.4149443799201);   // A2
    glVertex2f (15.4782847336295, 4.7220085848121);   // B2
    glVertex2f (15.9676683101761, 4.7124128284092);//E2
    glVertex2f(16.2555410022623, 4.3861571107115);  // C2
    glVertex2f (16.6328032361564, 3.7516645195243);  // D2
  glVertex2f(14.4611345549248, 3.7559650469706);   // z1

    glEnd();
}
// Grass /////////// ID:13
void sgrass3() {
    glColor3ub(40, 222, 40); // Green color

    glBegin(GL_POLYGON);

              glVertex2f(21.9911345549248, 3.7559650469706);   // z1 shifted more right
        glVertex2f(22.556071451903, 4.4149443799201);    // A2
        glVertex2f(22.9782847336295, 4.7220085848121);   // B2
        glVertex2f(23.4676683101761, 4.7124128284092);   // E2
        glVertex2f(23.7555410022623, 4.3861571107115);   // C2
        glVertex2f(24.1328032361564, 3.7516645195243);   // D2
        glVertex2f(21.9911345549248, 3.7559650469706);   // z1
    glEnd();


}

//////////wire//////////ID:14

void swire(){
        glColor3ub(104, 115, 104);

    glBegin(GL_POLYGON);

  glVertex2f(16.6212037772401, 3.7678334601274);   // O2
    glVertex2f(16.8544166322897, 3.8586878579686);   // F2
    glVertex2f (16.8544166322897, 6.9824214041235);   // M2
    glVertex2f (16.6212037772401, 7.0023355213052);//I2
    glEnd();

      glBegin(GL_POLYGON);
glVertex2f (16.6212037772401, 7.0023355213052);//I2
  glVertex2f(16.2678400242324, 7.0023355213052);   // p2
    glVertex2f(16.2583958161805, 7.1831947891598);   // q2
    glVertex2f (16.6136049950031,  7.1831947891598);   // R2
    glVertex2f (16.8764509706125,  7.1831947891598);//S2
glVertex2f (17.1692139385013,  7.1831947891598);//T2
glVertex2f (17.1757197822322, 7.0023355213052);//U2
glVertex2f (16.8854827775919, 7.0023355213052);//M2
    glEnd();

        glBegin(GL_POLYGON);
        glVertex2f (16.6136049950031,  7.1831947891598);   // R2
glVertex2f (16.6292289088397, 7.4629460695869);//V2
glVertex2f  (16.8764509706125, 7.4759577570486);//W2
glVertex2f  (16.8717016846538, 7.1931438863093);//S2
 glEnd();
    glBegin(GL_POLYGON);
    glVertex2f (16.6292289088397, 7.4629460695869);//V2
  glVertex2f(16.266687950194, 7.4868635466628);   // Z2
    glVertex2f(16.2585662351733, 7.6492978470778);   // A3
    glVertex2f (16.6240434111069, 7.6574195620985);   // B3
glVertex2f (16.6240434111069, 7.6607901292638);//E3
glVertex2f (17.165069673776, 7.6683004746135);//F3
glVertex2f (17.1999254452368, 7.4777981211512);//G3
glVertex2f  (16.8764509706125, 7.4759577570486);//W2
  glEnd();
      glBegin(GL_QUADS);

       glVertex2f (16.6240434111069, 7.6574195620985);   // B3
    glVertex2f(16.6277123405036, 7.7711662611413);//C3
glVertex2f (16.8595731467085, 7.7792452874097);//D3
glVertex2f (16.8766131605059, 7.6683004746135);//E3

    glEnd();


    glColor3ub(40, 40, 40);
    glLineWidth(2.0f);


    glBegin(GL_LINE_LOOP);
        glVertex2f(16.6212037772401, 3.7678334601274);
        glVertex2f(16.8544166322897, 3.8586878579686);
        glVertex2f(16.8544166322897, 6.9824214041235);
        glVertex2f(16.6212037772401, 7.0023355213052);
    glEnd();


    glBegin(GL_LINE_LOOP);
        glVertex2f(16.6212037772401, 7.0023355213052);
        glVertex2f(16.2678400242324, 7.0023355213052);
        glVertex2f(16.2583958161805, 7.1831947891598);
        glVertex2f(16.6136049950031, 7.1831947891598);
        glVertex2f(16.8764509706125, 7.1831947891598);
        glVertex2f(17.1692139385013, 7.1831947891598);
        glVertex2f(17.1757197822322, 7.0023355213052);
        glVertex2f(16.8854827775919, 7.0023355213052);
    glEnd();


    glBegin(GL_LINE_LOOP);
        glVertex2f(16.6136049950031, 7.1831947891598);
        glVertex2f(16.6292289088397, 7.4629460695869);
        glVertex2f(16.8764509706125, 7.4759577570486);
        glVertex2f(16.8717016846538, 7.1931438863093);
    glEnd();


    glBegin(GL_LINE_LOOP);
        glVertex2f(16.6292289088397, 7.4629460695869);
        glVertex2f(16.266687950194, 7.4868635466628);
        glVertex2f(16.2585662351733, 7.6492978470778);
        glVertex2f(16.6240434111069, 7.6574195620985);
        glVertex2f(17.165069673776, 7.6683004746135);
        glVertex2f(17.1999254452368, 7.4777981211512);
        glVertex2f(16.8764509706125, 7.4759577570486);
    glEnd();


    glBegin(GL_LINE_LOOP);
        glVertex2f(16.6240434111069, 7.6574195620985);
        glVertex2f(16.6277123405036, 7.7711662611413);
        glVertex2f(16.8595731467085, 7.7792452874097);
        glVertex2f(16.8766131605059, 7.6683004746135);
    glEnd();



}



void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * i / num_segments;
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}
///////////////////ID:15
void sdrawCarRed() {
    glPushMatrix();
    glTranslatef(carX, 0.0f, 0.0f);

    // Car body
    glColor3ub(255, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(2.0f, 2.5f);
        glVertex2f(5.5f, 2.5f);
        glVertex2f(5.5f, 3.0f);
        glVertex2f(2.0f, 3.0f);
    glEnd();

    // Roof
    glColor3ub(200, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(2.5f, 3.0f);
        glVertex2f(5.0f, 3.0f);
        glVertex2f(4.7f, 3.3f);
        glVertex2f(2.8f, 3.3f);
    glEnd();

    // Window
    glColor3ub(135, 206, 235);
    glBegin(GL_POLYGON);
        glVertex2f(2.8f, 3.05f);
        glVertex2f(4.7f, 3.05f);
        glVertex2f(4.6f, 3.18f);
        glVertex2f(2.9f, 3.18f);
    glEnd();

    // Wheels
    glColor3ub(0, 0, 0);
    drawCircle(2.6f, 2.5f, 0.2f, 50);
    drawCircle(4.9f, 2.5f, 0.2f, 50);

    glColor3ub(192, 192, 192);
    drawCircle(2.6f, 2.5f, 0.1f, 50);
    drawCircle(4.9f, 2.5f, 0.1f, 50);

    glPopMatrix();
}
///////////////////////////ID:16
void sbluecar2() {
glPushMatrix();
    glTranslatef(car2X, 0.0f, 0.0f);
    // -------- Car body --------
    glColor3ub(100, 149, 237);
    glBegin(GL_QUADS);
        glVertex2f(5.0, 1.4);
        glVertex2f(8.0, 1.4);
        glVertex2f(8.0, 1.85);
        glVertex2f(5.0, 1.85);
    glEnd();

    // -------- Roof  --------
    glColor3ub(30, 144, 255);
    glBegin(GL_QUADS);
        glVertex2f(5.8, 1.85);
        glVertex2f(7.2, 1.85);
        glVertex2f(7.0, 2.35);
        glVertex2f(6.0, 2.35);
    glEnd();

    // -------- Windows --------
    glColor3ub(173, 216, 230);
    glBegin(GL_QUADS);
        glVertex2f(5.9, 1.95);
        glVertex2f(7.1, 1.95);
        glVertex2f(6.9, 2.25);
        glVertex2f(6.1, 2.25);
    glEnd();

    // -------- Wheels --------
    glColor3ub(40, 40, 40);
    drawCircle(5.7, 1.35, 0.28, 50);
    drawCircle(7.3, 1.35, 0.28, 50);

    glColor3ub(192, 192, 192);
    drawCircle(5.7, 1.35, 0.14, 50);
    drawCircle(7.3, 1.35, 0.14, 50);
    glPopMatrix();

}

///////////////////////////ID:17
    void scar3() {
    glPushMatrix();
    glTranslatef(car3X, 2.8111f, 0.0f);


    glColor3ub(255, 165, 0);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(2.5f, 0.0f);
        glVertex2f(2.5f, 0.4f);
        glVertex2f(0.0f, 0.4f);
    glEnd();

    // Roof
    glColor3ub(255, 140, 0);
    glBegin(GL_QUADS);
        glVertex2f(0.3f, 0.4f);
        glVertex2f(2.2f, 0.4f);
        glVertex2f(2.0f, 0.7f);
        glVertex2f(0.5f, 0.7f);
    glEnd();

    // Windows
    glColor3ub(135, 206, 235);
    glBegin(GL_QUADS);
        glVertex2f(0.5f, 0.45f);
        glVertex2f(2.0f, 0.45f);
        glVertex2f(1.9f, 0.65f);
        glVertex2f(0.6f, 0.65f);
    glEnd();

    // Wheels
    glColor3ub(40, 40, 40);
    drawCircle(0.6f, -0.1f, 0.2f, 50);
    drawCircle(2.0f, -0.1f, 0.2f, 50);

    // Wheel rims
    glColor3ub(192, 192, 192);
    drawCircle(0.6f, -0.1f, 0.1f, 50);
    drawCircle(2.0f, -0.1f, 0.1f, 50);

    glPopMatrix();

}




///////////////////////bus //////////////////ID:18

void sdrawBRTCbus() {
    glPushMatrix();
    glTranslatef(busX, 0.0f, 0.0f); // moves bus horizontally

    //  Bus body
    glColor3ub(200, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(1.877246f, 3.188146f);
        glVertex2f(8.673606f, 3.188146f);
        glVertex2f(8.673606f, 4.815086f);
        glVertex2f(1.877246f, 4.815086f);
    glEnd();

    // --- Roof ---
    glColor3ub(255, 255, 0);
    glBegin(GL_POLYGON);
        glVertex2f(1.877246f, 4.515089f);
        glVertex2f(8.673606f, 4.515089f);
        glVertex2f(8.673606f, 4.665089f);
        glVertex2f(1.877246f, 4.665089f);
    glEnd();

    // --- Windows ---
    glColor3ub(135, 206, 235);
    // Window 1
    glBegin(GL_POLYGON);
        glVertex2f(2.177246f, 3.703146f);
        glVertex2f(3.177246f, 3.703146f);
        glVertex2f(3.177246f, 4.403146f);
        glVertex2f(2.177246f, 4.403146f);
    glEnd();
    // Window 2
    glBegin(GL_POLYGON);
        glVertex2f(3.227246f, 3.703146f);
        glVertex2f(4.227246f, 3.703146f);
        glVertex2f(4.227246f, 4.403146f);
        glVertex2f(3.227246f, 4.403146f);
    glEnd();
    // Window 3
    glBegin(GL_POLYGON);
        glVertex2f(4.277246f, 3.703146f);
        glVertex2f(5.277246f, 3.703146f);
        glVertex2f(5.277246f, 4.403146f);
        glVertex2f(4.277246f, 4.403146f);
    glEnd();
    // Window 4
    glBegin(GL_POLYGON);
        glVertex2f(5.327246f, 3.703146f);
        glVertex2f(6.327246f, 3.703146f);
        glVertex2f(6.327246f, 4.403146f);
        glVertex2f(5.327246f, 4.403146f);
    glEnd();
    // Window 5
    glBegin(GL_POLYGON);
        glVertex2f(6.377246f, 3.703146f);
        glVertex2f(7.377246f, 3.703146f);
        glVertex2f(7.377246f, 4.403146f);
        glVertex2f(6.377246f, 4.403146f);
    glEnd();
    // Window 6
    glBegin(GL_POLYGON);
        glVertex2f(7.427246f, 3.703146f);
        glVertex2f(8.427246f, 3.703146f);
        glVertex2f(8.427246f, 4.403146f);
        glVertex2f(7.427246f, 4.403146f);
    glEnd();

    //  Window vertical lines
    glColor3ub(40,40,40);
    // Lines
    glBegin(GL_LINES);
        glVertex2f(2.177246f, 3.703146f); glVertex2f(2.177246f, 4.403146f);
        glVertex2f(3.177246f, 3.703146f); glVertex2f(3.177246f, 4.403146f);
        glVertex2f(4.177246f, 3.703146f); glVertex2f(4.177246f, 4.403146f);
        glVertex2f(5.177246f, 3.703146f); glVertex2f(5.177246f, 4.403146f);
        glVertex2f(6.177246f, 3.703146f); glVertex2f(6.177246f, 4.403146f);
        glVertex2f(7.177246f, 3.703146f); glVertex2f(7.177246f, 4.403146f);
        glVertex2f(8.177246f, 3.703146f); glVertex2f(8.177246f, 4.403146f);
    glEnd();

    // --- Front lights ---
    glColor3ub(255, 255, 0);
    glBegin(GL_POLYGON);
        glVertex2f(8.673606f, 3.503146f);
        glVertex2f(8.823606f, 3.503146f);
        glVertex2f(8.823606f, 4.003146f);
        glVertex2f(8.673606f, 4.003146f);
    glEnd();

    // --- Wheels ---
    glColor3ub(40,40,40);
    drawCircle(3.0f, 3.17f, 0.35f, 50);  // Left wheel
    drawCircle(7.8f, 3.17f, 0.35f, 50);  // Right wheel

    glColor3ub(192,192,192);
    drawCircle(3.0f, 3.17f, 0.15f, 50);
    drawCircle(7.8f, 3.17f, 0.15f, 50);

    glPopMatrix();
}

/////////////////////////ID:19
void sriver() {
    // River body
    glPushMatrix();
    glColor3ub(39, 165, 230);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, -2.0f);
        glVertex2f(25.0f, -2.0f);
        glVertex2f(25.0f, 1.0f);
        glVertex2f(0.0f, 1.0f);
    glEnd();
    glPopMatrix();

    // Waves
    glPushMatrix();
    glTranslatef(waveOffset, 0.0f, 0.0f);

    glColor3ub(206, 240, 242);
    glLineWidth(2.0f);

    // Wave 1
    glBegin(GL_LINE_STRIP);
        glVertex2f(2.0f, -0.2f);
        glVertex2f(3.0f,  0.0f);
        glVertex2f(4.0f, -0.2f);
        glVertex2f(5.0f,  0.0f);
        glVertex2f(6.0f, -0.2f);
    glEnd();

    // Wave 2
    glBegin(GL_LINE_STRIP);
        glVertex2f(8.0f,  0.2f);
        glVertex2f(9.0f,  0.4f);
        glVertex2f(10.0f, 0.2f);
        glVertex2f(11.0f, 0.4f);
        glVertex2f(12.0f, 0.2f);
    glEnd();

    // Wave 3
    glBegin(GL_LINE_STRIP);
        glVertex2f(15.0f, -0.1f);
        glVertex2f(16.0f,  0.1f);
        glVertex2f(17.0f, -0.1f);
        glVertex2f(18.0f,  0.1f);
        glVertex2f(19.0f, -0.1f);
    glEnd();

    glPopMatrix();
}
//////////////////////ID:20

 void sship() {


    glPushMatrix();
    glTranslatef(shipX, 0.0f, 0.0f);
    // Ship body
    glColor3ub(133, 68, 32);
    glBegin(GL_POLYGON);
        glVertex2f(12.5f, -1.48);
        glVertex2f(15.5f, -1.48);
        glVertex2f(16.0f, -0.68f);
        glVertex2f(12.0f, -0.68f);
    glEnd();

    // Upper body
    glColor3ub(205,133,264);
    glBegin(GL_POLYGON);
        glVertex2f(12.8f, -0.68f);
        glVertex2f(15.2f, -0.68f);
        glVertex2f(14.9f, -0.38f);
        glVertex2f(13.1f, -0.38f);
    glEnd();

    // Mast
    glColor3ub(70, 70, 70);
    glLineWidth(3);
    glBegin(GL_LINES);
        glVertex2f(14.0f, -0.38f);
        glVertex2f(14.0f, 0.58f);
    glEnd();

    // Sail
    glColor3ub(240,240,230);
    glBegin(GL_TRIANGLES);
        glVertex2f(14.0f, 0.52f);
        glVertex2f(14.0f,  -0.38f);
        glVertex2f(14.7f, 0.02f);
    glEnd();

    // Flag
    glColor3ub(240, 41, 7);
    glBegin(GL_TRIANGLES);
        glVertex2f(14.0f, 0.52f);
        glVertex2f(14.5f, 0.52f);
        glVertex2f(14.0f, 0.37);
    glEnd();
 glPopMatrix();
}

////////////////ID:21

void strain(){  glPushMatrix();
    glTranslatef(trainX, 0.0f, 0.0f);

    glColor3ub(237, 203, 9);
glBegin(GL_POLYGON);
// E_4
glVertex2f(9.3979954583887, 8.8878637510805);
// F_4
glVertex2f(9.2693759946158, 9.3745404377748);

// G_4
glVertex2f(9.6855204549955, 10.0218762650321);

// H_4
glVertex2f(14.5405391594254, 10.0210507494484);
glVertex2f(14.5559519172172, 8.8879363131054);// I_4
glEnd();

glBegin(GL_POLYGON);
// J_4
glVertex2f(14.7333112700473,10.0210507494484);

// L_4
glVertex2f(19.2547569064849, 10.0210507494484);

// M_4
glVertex2f(19.6106784172466, 9.2954526677283);

// N_4
glVertex2f(19.4853495186768, 8.8879363131054);

// K_4
glVertex2f(14.7333112700473, 8.8879363131054);

glEnd();

 glColor3ub(0, 0, 0);
 glLineWidth(2);
glBegin(GL_LINE_LOOP);

// E_4
glVertex2f(9.3979954583887, 8.8878637510805);
// F_4
glVertex2f(9.2693759946158, 9.3745404377748);

// G_4
glVertex2f(9.6855204549955, 10.0218762650321);

// H_4
glVertex2f(14.5405391594254, 10.0210507494484);
glVertex2f(14.5559519172172, 8.8879363131054);// I_4
glEnd();
glLineWidth(2);
glBegin(GL_LINE_LOOP);

// J_4
glVertex2f(14.7333112700473,10.0210507494484);

// L_4
glVertex2f(19.2547569064849, 10.0210507494484);

// M_4
glVertex2f(19.6106784172466, 9.2954526677283);

// N_4
glVertex2f(19.4853495186768, 8.8879363131054);

// K_4
glVertex2f(14.7333112700473, 8.8879363131054);
glEnd();

//majher dag
glBegin(GL_LINES);
glLineWidth(2);
    glVertex2f(14.5, 9.5);//O4
    glVertex2f(14.7015416716107, 9.5033599244312);//P4

glEnd();

glColor3ub(180, 220, 255);

// Window 1
glBegin(GL_QUADS);
    glVertex2f(10.2, 9.8);
    glVertex2f(11.0, 9.8);
    glVertex2f(11.0, 9.2);
    glVertex2f(10.2, 9.2);
glEnd();

// Window 2
glBegin(GL_QUADS);
    glVertex2f(11.5, 9.8);
    glVertex2f(12.3, 9.8);
    glVertex2f(12.3, 9.2);
    glVertex2f(11.5, 9.2);
glEnd();

// Window 3
glBegin(GL_QUADS);
    glVertex2f(15.5, 9.8);
    glVertex2f(16.3, 9.8);
    glVertex2f(16.3, 9.2);
    glVertex2f(15.5, 9.2);
glEnd();



// DOOR

glColor3ub(240, 240, 240);
glBegin(GL_QUADS);
    glVertex2f(13.2, 9.85);
    glVertex2f(14.0, 9.85);
    glVertex2f(14.0, 8.9);
    glVertex2f(13.2, 8.9);
glEnd();

// Door handle
glColor3ub(0, 0, 0);
glBegin(GL_LINES);
    glVertex2f(13.8, 9.4);
    glVertex2f(13.9, 9.4);
glEnd();

glColor3ub(180, 220, 255);

// Back Window 1
glBegin(GL_QUADS);
    glVertex2f(15.3, 9.8);
    glVertex2f(16.1, 9.8);
    glVertex2f(16.1, 9.2);
    glVertex2f(15.3, 9.2);
glEnd();

// Back Window 2
glBegin(GL_QUADS);
    glVertex2f(16.6, 9.8);
    glVertex2f(17.4, 9.8);
    glVertex2f(17.4, 9.2);
    glVertex2f(16.6, 9.2);
glEnd();

// Back Window 3
glBegin(GL_QUADS);
    glVertex2f(17.9, 9.8);
    glVertex2f(18.7, 9.8);
    glVertex2f(18.7, 9.2);
    glVertex2f(17.9, 9.2);
glEnd();



// WHEELS

glColor3ub(40, 40, 40);

// Front wheel 1
glBegin(GL_POLYGON);
    glVertex2f(10.75f, 8.7f);
    glVertex2f(10.67675f, 8.87675f);
    glVertex2f(10.5f, 8.95f);
    glVertex2f(10.32325f, 8.87675f);
    glVertex2f(10.25f, 8.7f);
    glVertex2f(10.32325f, 8.52325f);
    glVertex2f(10.5f, 8.45f);
    glVertex2f(10.67675f, 8.52325f);
glEnd();

// Front wheel 2
glBegin(GL_POLYGON);
    glVertex2f(13.75f, 8.7f);
    glVertex2f(13.67675f, 8.87675f);
    glVertex2f(13.5f, 8.95f);
    glVertex2f(13.32325f, 8.87675f);
    glVertex2f(13.25f, 8.7f);
    glVertex2f(13.32325f, 8.52325f);
    glVertex2f(13.5f, 8.45f);
    glVertex2f(13.67675f, 8.52325f);
glEnd();

// Back wheel 1
glBegin(GL_POLYGON);
    glVertex2f(16.25f, 8.7f);
    glVertex2f(16.17675f, 8.87675f);
    glVertex2f(16.0f, 8.95f);
    glVertex2f(15.82325f, 8.87675f);
    glVertex2f(15.75f, 8.7f);
    glVertex2f(15.82325f, 8.52325f);
    glVertex2f(16.0f, 8.45f);
    glVertex2f(16.17675f, 8.52325f);
glEnd();

// Back wheel 2
glBegin(GL_POLYGON);
    glVertex2f(18.75f, 8.7f);
    glVertex2f(18.67675f, 8.87675f);
    glVertex2f(18.5f, 8.95f);
    glVertex2f(18.32325f, 8.87675f);
    glVertex2f(18.25f, 8.7f);
    glVertex2f(18.32325f, 8.52325f);
    glVertex2f(18.5f, 8.45f);
    glVertex2f(18.67675f, 8.52325f);
glEnd();



glColor3ub(0, 0, 0);
glLineWidth(1.5f);
// Window 1 outline
glBegin(GL_LINE_LOOP);
    glVertex2f(10.2, 9.8);
    glVertex2f(11.0, 9.8);
    glVertex2f(11.0, 9.2);
    glVertex2f(10.2, 9.2);
glEnd();

// Window 2 outline
glBegin(GL_LINE_LOOP);
    glVertex2f(11.5, 9.8);
    glVertex2f(12.3, 9.8);
    glVertex2f(12.3, 9.2);
    glVertex2f(11.5, 9.2);
glEnd();

// Window 3 outline
glBegin(GL_LINE_LOOP);
    glVertex2f(15.5, 9.8);
    glVertex2f(16.3, 9.8);
    glVertex2f(16.3, 9.2);
    glVertex2f(15.5, 9.2);
glEnd();

glBegin(GL_LINE_LOOP);
    glVertex2f(13.2, 9.85);
    glVertex2f(14.0, 9.85);
    glVertex2f(14.0, 8.9);
    glVertex2f(13.2, 8.9);
glEnd();

// Back Window 1
glBegin(GL_LINE_LOOP);
    glVertex2f(15.3, 9.8);
    glVertex2f(16.1, 9.8);
    glVertex2f(16.1, 9.2);
    glVertex2f(15.3, 9.2);
glEnd();

// Back Window 2
glBegin(GL_LINE_LOOP);
    glVertex2f(16.6, 9.8);
    glVertex2f(17.4, 9.8);
    glVertex2f(17.4, 9.2);
    glVertex2f(16.6, 9.2);
glEnd();

// Back Window 3
glBegin(GL_LINE_LOOP);
    glVertex2f(17.9, 9.8);
    glVertex2f(18.7, 9.8);
    glVertex2f(18.7, 9.2);
    glVertex2f(17.9, 9.2);
glEnd();

 glPopMatrix();





}




///////////////////cloud ID:22


 void sdrawCloud(float cx, float cy, float scale, int numCircles) {


    glColor3ub(227, 248, 250);


    float offsets[5][2] = {
        {-0.3f, 0.0f}, {0.0f, 0.1f}, {0.3f, 0.0f}, {-0.15f, 0.2f}, {0.15f, 0.25f}
    };

    for(int i = 0; i < 5 && i < 5; i++) {
        float x = cx + offsets[i][0] * scale;
        float y = cy + offsets[i][1] * scale;
        float r = 0.25f * scale;
        drawCircle(x, y, r, 50);


    }
}



void drawAllClouds() {
    glPushMatrix();
    glTranslatef(cloudX, 0.0f, 0.0f);



    sdrawCloud(2.0f, 12.00f, 2.5f, 5);
    sdrawCloud(6.0f, 13.90f, 1.8f, 5);
    sdrawCloud(10.0f, 13.9f, 1.2f, 5);
    sdrawCloud(14.0f, 14.3f, 2.0f, 5);
    sdrawCloud(18.0f, 13.90f, 1.5f, 5);
    sdrawCloud(3.5f, 14.0f, 1.5f, 5);
    sdrawCloud(8.0f, 12.4f, 2.0f, 5);
    sdrawCloud(12.0f, 12.8f, 1.5f, 5);
    sdrawCloud(16.0f, 12.0f, 2.0f, 5);
    sdrawCloud(22.0f, 12.7f, 2.5f, 5);
    sdrawCloud(19.80f, 11.2f, 1.9f, 5);

    glPopMatrix();
}
////////////////////////////draw tree ////ID:23
 void drawTree(float shiftX) {
    // Draw trunk
    glColor3ub(139, 69, 19);
    glBegin(GL_POLYGON);
        glVertex2f(3.594f - shiftX, 2.088f);
        glVertex2f(3.594f - shiftX, 5.252f);
        glVertex2f(3.835f - shiftX, 5.252f);
        glVertex2f(3.835f - shiftX, 2.088f);
    glEnd();

    // Draw leaves (aligned with trunk)
    // Bottom triangle
    glColor3ub(34, 139, 34);
    glBegin(GL_TRIANGLES);
        glVertex2f(2.894f - shiftX, 5.252f);
        glVertex2f(4.135f - shiftX, 5.252f);
        glVertex2f(3.715f - shiftX, 5.752f);
    glEnd();

    // Middle triangle
    glColor3ub(50, 205, 50);
    glBegin(GL_TRIANGLES);
        glVertex2f(2.954f - shiftX, 5.5f);
        glVertex2f(4.075f - shiftX, 5.5f);
        glVertex2f(3.715f - shiftX, 6.05f);
    glEnd();

    // Top triangle
    glColor3ub(34, 139, 34);
    glBegin(GL_TRIANGLES);
        glVertex2f(3.0f - shiftX, 5.8f);
        glVertex2f(4.0f - shiftX, 5.8f);
        glVertex2f(3.715f - shiftX, 6.25f);
    glEnd();
}

//////////////bulding ID:24
void building1(){
    glColor3ub(216, 238, 242);
    glBegin(GL_POLYGON);
        glVertex2f(1.299, 3.5);
        glVertex2f(2.299, 3.5);
        glVertex2f(2.299, 7.4);
        glVertex2f(1.299, 7.4);
    glEnd();

    // Outline
    glColor3ub(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
   glVertex2f(1.299, 3.5);
        glVertex2f(2.299, 3.5);
        glVertex2f(2.299, 7.4);
        glVertex2f(1.299, 7.4);
    glEnd();
}
//////////////////ID:25
void building2(){
    glColor3ub(216, 238, 242);
    glBegin(GL_POLYGON);
        glVertex2f(17.69, 3.5);
        glVertex2f(19.59 ,3.5);
        glVertex2f(19.59, 6.4);
        glVertex2f(17.69, 6.4);
    glEnd();

    // Outline
    glColor3ub(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
     glVertex2f(17.69, 3.5);
        glVertex2f(19.59, 3.5);
        glVertex2f(19.59, 6.4);
        glVertex2f(17.69, 6.4);
    glEnd();
}


//////////////ID:26
void building3(){
    glColor3ub(216, 238, 242);
    glBegin(GL_POLYGON);
        glVertex2f(19.299, 3.5);
        glVertex2f(21.29,3.5);
        glVertex2f(21.29, 7.4);
        glVertex2f(19.299, 7.4);
    glEnd();

    // Outline
    glColor3ub(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
     glVertex2f(19.299, 3.5);
        glVertex2f(21.29,3.5);
        glVertex2f(21.29, 7.4);
        glVertex2f(19.299, 7.4);
    glEnd();
}


/////////////////ID:27
void building4(){
    glColor3ub(216, 238, 242);
    glBegin(GL_POLYGON);
        glVertex2f(21.299, 3.5);
        glVertex2f(23.29,3.5);
        glVertex2f(23.29, 6.4);
        glVertex2f(21.299, 6.4);
    glEnd();

    // Outline
    glColor3ub(0,0,0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
      glVertex2f(21.299, 3.5);
        glVertex2f(23.29,3.5);
        glVertex2f(23.29, 6.4);
        glVertex2f(21.299, 6.4);
    glEnd();
}

void buildingBigDoor() {
    glColor3ub(139, 69, 19);

    glBegin(GL_POLYGON);
        glVertex2f(19.85f, 3.5f);
        glVertex2f(19.85f, 5.05f);
        glVertex2f(20.75f, 5.05f);
        glVertex2f(20.75f, 3.5f);
    glEnd();

    // Door outline
    glColor3ub(0, 0, 0);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
        glVertex2f(19.85f, 3.5f);
        glVertex2f(19.85f, 5.05f);
        glVertex2f(20.75f, 5.05f);
        glVertex2f(20.75f, 3.5f);
    glEnd();
}

/////////////////trafficsignal ID:28
void sdrawTraffic() {
   glColor3ub(50, 50, 50);
    glBegin(GL_POLYGON);
        glVertex2f(22.0, 3.5);
        glVertex2f(22.1f, 3.5);
        glVertex2f(22.1f,6.0f);
        glVertex2f(22.0, 6.0f);
    glEnd();

    // Pole outline
    glColor3ub(0, 0, 0);
    glLineWidth(2);
    glBegin(GL_LINE_LOOP);
         glVertex2f(22.0, 3.5);
        glVertex2f(22.1f, 3.5);
        glVertex2f(22.1f,6.0f);
        glVertex2f(22.0, 6.0f);
    glEnd();



    glColor3ub(80, 80, 80);
    glBegin(GL_POLYGON);
        glVertex2f(21.85f, 5.5f);
        glVertex2f(22.25f,5.5f);
        glVertex2f(22.25f,6.3f);
        glVertex2f(21.85f,6.3f );
    glEnd();

    // Box outline
    glColor3ub(0, 0, 0);
    glBegin(GL_LINE_LOOP);
         glVertex2f(21.85f, 5.5f);
        glVertex2f(22.25f,5.5f);
        glVertex2f(22.25f,6.3f);
        glVertex2f(21.85f,6.3f );
    glEnd();


    float radius = 0.08f;
    drawCircle(22.05f,6.2f, radius, 50);
    glColor3ub(255, 0, 0); // Red
    drawCircle(22.05f, 6.2f, radius, 50);

    glColor3ub(255, 255, 0); // Yellow
    drawCircle(22.05f,5.95f, radius, 50);

    glColor3ub(0, 255, 0); // Green
    drawCircle(22.05f, 5.7f, radius, 50);
}


/////////////////ID:29

void sSun() {
    // Draw sun during day or sunset
    if (!isNight) {
        if (isSunset) {
            glColor3ub(255, 140, 0);  // Orange for sunset
        } else {
            glColor3ub(255, 223, 0);  // Yellow for day
        }
        drawCircle(sunX, sunY, sunRadius, segments);
    }

    // Draw moon during night
    if (isNight || moonY > 0) {
        glColor3ub(245, 245, 245);
        drawCircle(moonX, moonY, sunRadius, segments);
    }
}

////////////////////////rain ID:30
//  raindrops
void initRain() {
    for(int i=0; i<MAX_DROPS; i++) {
        dropX[i] = (rand() % 4000 / 100.0f) - 15.0f;
        dropY[i] = (rand() % 1500 / 100.0f);
        dropSpeed[i] = 0.1f + ((float)rand()/RAND_MAX)*0.1f;
    }
}



void drawRain() {
    if(!rainActive) return;

    if(isNight)
    glColor3ub(207, 217, 227);
else
    glColor3ub(200, 230, 255);   // day rain

    glLineWidth(2.0f);

    glBegin(GL_LINES);
    for(int i = 0; i < MAX_DROPS; i++) {
        glVertex2f(dropX[i], dropY[i]);
        glVertex2f(dropX[i], dropY[i] - 0.5f);
    }
        glEnd();
    }

//////////////////show ID:31

void initShow() {
//   snow
for(int i = 0; i < MAX_SNOW; i++) {
    snowX[i] = ((rand() % 5000) / 100.0f) - 25.0f;
    snowY[i] = (rand() % 1500) / 100.0f + 10.0f;
    snowSpeed[i] = 0.01f + (rand() % 10) / 100.0f;
}

}

void drawSnow() {
    // Draw snow if active
if (snowActive) {
    glColor3ub(255, 255, 255);
    glPointSize(3.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < MAX_SNOW; i++) {
        glVertex2f(snowX[i], snowY[i]);
    }
    glEnd();
}

}



void display() {

    if (isNight) {
        glClearColor(60.0/255.0, 81.0/255.0, 99.0/255.0, 1.0f); // Night sky
    } else {
        glClearColor(176.0/255.0, 224.0/255.0, 230.0/255.0, 1.0f); // Day sky
    }
    glClear(GL_COLOR_BUFFER_BIT);

sSun() ;

 drawAllClouds();


      strain();


    sabridge();

    sabridgeP1();
     sabridgeP11();

     sabridgeP2();
     sabridgeP22();

     sabridgeP3();
     sabridgeP33();

     sschool();
     sschoolLine();
     sschoolDoor();
     schoolWindowsLeft();
     schoolWindowsRight();
     bigSchoolWindow();


     sbuild();
     sbuildline();
       shospital();
shospital_section();

     swire();




drawTree(1.0f);
drawTree(-5.87f);
drawTree(-19.87f);
drawTree(-20.77f);






//beside tree Building 1

///////////////// Building 1 windows
  building1();
sdrawWindow(1.45f, 4.3f);
sdrawWindow(1.45f, 5.0f);
sdrawWindow(1.45f, 5.8f);


// Building 2 windows
  building2();
sdrawWindow(17.85f, 4.3f);
sdrawWindow(18.55f, 4.3f);

sdrawWindow(17.85f, 5.3f);
sdrawWindow(18.55f, 5.3f);


 //Building 4

  building3();
buildingBigDoor();
sdrawWindow(19.60f, 6.4f);
sdrawWindow(20.60f, 6.4f);

 sdrawWindow(19.60f, 5.6f);
sdrawWindow(20.60f, 5.6f);


 // Building 5

  building4();
sdrawWindow(21.50f, 4.3f);
sdrawWindow(21.50f, 5.3f);
sdrawWindow(22.40f, 4.3f);
sdrawWindow(22.40f, 5.3f);






 sdrawTraffic();

 sriver();


sship();


sgrass1();
sgrass2();
sgrass3();
sroad();
dashlineroad();

sdrawBRTCbus();
 scar3();
     sdrawCarRed();
     sbluecar2();
         drawRain();
   drawSnow();




    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    // Display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Window size & position
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(100, 100);

    // Create window
    glutCreateWindow("Dhaka City");

    // Projection setup
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 25, -2, 15);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    initRain();
    initShow();

    // Register callbacks
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
        glutTimerFunc(0, updateShip, 0);
         glutTimerFunc(0, updateCarRed, 0);
         glutTimerFunc(0, updateBus, 0);
         glutTimerFunc(0, updateCarBlue, 0);
          glutTimerFunc(0, updateCarOrange, 0);
glutTimerFunc(0, updateTrain, 0);
  glutTimerFunc(16, updateCloud, 0);
  glutTimerFunc(16, updateSnow, 0);
  glutTimerFunc(16, updateRain, 0);
  glutTimerFunc(16, updateWave, 0);
  glutTimerFunc(0,updateAnimation, 0);


  glutSwapBuffers();
    // Start main loop
    glutMainLoop();

    return 0;
}

