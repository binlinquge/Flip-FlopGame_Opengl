#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<SOIL.h>
#include<GL/glut.h>

#define ELE_NUM 16

GLfloat vertices[][3] = { { 0.0 ,0.0 ,-5.0 },{ 198.0, 0.0, -5.0 },{ 198.0,198.0,-5.0 },{ 0.0,198,-5.0 },{ 0.0, 0.0, 5.0 },{ 198.0,0.0,5.0 },{ 198.0, 198.0, 5.0 },{ 0.0, 198.0, 5.0 } };
float group[16][4] = { { -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 },{ -1.0,0.0,0.0,0.0 } };
GLfloat theta[] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
GLfloat judge[] = { 0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0 };
float delta = 0.25;
GLint axis = 2;
GLfloat fAspect;
GLuint texture[6];
int rotate_buf = -1;
int sec, min, hour;
int stop = 0;
char timeA[9];

//record the start time
void settime()
{
    time_t timer;
    struct tm * timeinfo;
    timer = time(NULL);
    timeinfo = localtime(&timer);

    sec = timeinfo->tm_sec;
    min = timeinfo->tm_min;
    hour = timeinfo->tm_hour;
}

//draw the time one character by one character
void drawTime(const char* str)
{
    float x = 0;
    for (int i = 0; i < 8 && *str != '\0'; str++, i++)
    {

        glPushMatrix();
        switch (*str)
        {
        case '1':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(12.5, 10.0, 0.0);
            glVertex3f(12.5, 40.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '2':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(20, 25.0, 0.0);
            glVertex3f(5, 25.0, 0.0);
            glVertex3f(5, 10.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '3':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(20, 25.0, 0.0);
            glVertex3f(5, 25.0, 0.0);
            glVertex3f(20, 25.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glVertex3f(5, 10.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '4':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(5.0, 40.0, 0.0);
            glVertex3f(5.0, 25.0, 0.0);
            glVertex3f(20.0, 25.0, 0.0);
            glVertex3f(20.0, 40.0, 0.0);
            glVertex3f(20.0, 10.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '5':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(5, 25.0, 0.0);
            glVertex3f(20, 25.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glVertex3f(5, 10.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '6':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(5, 10.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glVertex3f(20, 25.0, 0.0);
            glVertex3f(5, 25.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '7':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(12.5, 10.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '8':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(5, 10.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(5, 25.0, 0.0);
            glVertex3f(20, 25.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '9':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(5, 10.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(5, 25.0, 0.0);
            glVertex3f(20, 25.0, 0.0);
            glEnd();
            x += 25;
            break;
        case '0':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_LINE_STRIP);
            glVertex3f(5, 10.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(5, 40.0, 0.0);
            glVertex3f(5, 10.0, 0.0);
            glEnd();
            x += 25;
            break;
        case ':':
            glTranslatef(x, 800.0, 0.0);
            glBegin(GL_POLYGON);
            glVertex3f(10, 10.0, 0.0);
            glVertex3f(20, 10.0, 0.0);
            glVertex3f(20, 20.0, 0.0);
            glVertex3f(10, 20.0, 0.0);
            glEnd();
            glBegin(GL_POLYGON);
            glVertex3f(10, 30.0, 0.0);
            glVertex3f(20, 30.0, 0.0);
            glVertex3f(20, 40.0, 0.0);
            glVertex3f(10, 40.0, 0.0);
            glEnd();
            x += 25;
            break;

        }

        glPopMatrix();
    }
}
//arrange the match groups (init the group array wich contains group information and the color for each group
void mkgroup()
{
    srand((int)time(NULL));
    for (int i = 0; i < 16; i++)
    {
        if (group[i][0] == -1)
        {
            while (group[i][0] == i || group[i][0] == -1 || group[(int)group[i][0]][0] != -1)
            {
                group[i][0] = (int)rand() % 16;
            }
            group[(int)group[i][0]][0] = i;
            group[i][1] = (rand() % 10);
            group[i][2] = (rand() % 10);
            group[i][3] = (rand() % 10);
            group[(int)group[i][0]][1] = group[i][1];
            group[(int)group[i][0]][2] = group[i][2];
            group[(int)group[i][0]][3] = group[i][3];
        }
    }
}
//operate the judge array to tell the program which cube need to be rotated
void spinCube(GLuint id)
{
    static int success = 0;
    static int num = 0;
    static int num_array[2];
    judge[(int)id - 1] += 1;
    num_array[num] = (int)id - 1;
    num++;
    if (num == 2)
    {
        if (((int)group[num_array[0]][0]) == num_array[1]) success++;
        else {
            if (judge[num_array[1]] > 0) rotate_buf = num_array[0];
            else
            {
                judge[num_array[0]] += 1;
            }
            judge[num_array[1]] += 1;
        }
        num = 0;
    }
    if (success == 8) stop = 1;
}

//init draws include lines and time
void drawLines() {
    int i;
    int sec_cur, min_cur, hour_cur, sec_pass, min_pass, hour_pass;
    time_t rawtime;
    struct tm * timeinfo;
    glLineWidth(2.5);
    glColor3f(1.0, 0, 0);
    for (i = 0; i <= 800; i += 200)
    {
        glBegin(GL_LINES);
        glVertex3f(i, 0.0, 0.0);
        glVertex3f(i, 800, 0);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(0.0, i, 0.0);
        glVertex3f(800, i, 0);
        glEnd();
    }
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    if (stop == 0) {
        sec_cur = timeinfo->tm_sec;
        min_cur = timeinfo->tm_min;
        hour_cur = timeinfo->tm_hour;
        sec_pass = sec_cur - sec;
        min_pass = min_cur - min;
        hour_pass = hour_cur - hour;
        if (sec_pass < 0) { sec_pass += 60; min_pass -= 1; }
        if (min_pass < 0) { min_pass += 60; hour_pass -= 1; }
        timeA[0] = (int)(hour_pass / 10) + 48;
        timeA[1] = (int)(hour_pass % 10) + 48;
        timeA[2] = ':';
        timeA[3] = (int)(min_pass / 10) + 48;
        timeA[4] = (int)(min_pass % 10) + 48;
        timeA[5] = ':';
        timeA[6] = (int)(sec_pass / 10) + 48;
        timeA[7] = (int)(sec_pass % 10) + 48;
        timeA[8] = '\0';
    }
    drawTime(timeA);
}
void keyboard(unsigned char key, int x, int y)
{

}

//draw the face of one cube with vertex a b c d
void face(int a, int b, int c, int d)
{
    glBegin(GL_POLYGON);
    glVertex3fv(vertices[a]);
    glVertex3fv(vertices[b]);
    glVertex3fv(vertices[c]);
    glVertex3fv(vertices[d]);
    glEnd();
}

//arrange color for the faces of one cube
void colorcube(void)
{
    float pixels[] = {
        0.0f, 0.0f, 0.0f,   100.0f, 100.0f, 100.0f,
        100.0f, 100.0f, 100.0f,   0.0f, 0.0f, 0.0f
    };

    GLuint textures[2];
    int width=200, height=200;
    unsigned char* image =
        SOIL_load_image("image/1.png", &width, &height, 0, SOIL_LOAD_RGB);

    glBindTexture(GL_TEXTURE_2D, textures[0]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
        GL_UNSIGNED_BYTE, image);
    static int i = 0;
    glColor3f(0, 0, 1.0);
    face(0, 3, 2, 1);
    glColor3f(0, 1.0, 0);
    face(2, 3, 7, 6);
    face(0, 4, 7, 3);
    face(1, 2, 6, 5);
    glColor3f(group[i][1] / 10, group[i][2] / 10, group[i][3] / 10);
    i++; if (i > 15) i = 0;

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 2, 2, 0, GL_RGB, GL_FLOAT, pixels);
    face(4, 5, 6, 7);
    glColor3f(0, 1.0, 0);
    face(0, 1, 5, 4);
    SOIL_free_image_data(image);
}

//display the cubes
void display(void)
{
    int i,j,z=0;
    glClearColor(0.0, 0.0, 0.0, 1.0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    drawLines();
    glPopMatrix();

    glPushMatrix();
//    glTranslatef(0.0, 0.0, 0.0);
    glInitNames();
    glPushName(0);
    for (i = 0; i <= 3; i++)
        for (j = 0; j<=3; j++)
    {
        glPushMatrix();
        glTranslatef(200*j, 200.0*i, 0.0);
    //    glLoadName((GLuint)(i+j+1));
        glRotatef(theta[z], 1.0, 1.0, 0.0);
        colorcube();
        glPopMatrix();
        z++;
    }
    glutSwapBuffers();

}

//init the way of projection
void myReshape(int w, int h)
{
    GLfloat aspect = (GLfloat)w / (GLfloat)h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 800, 0, 850, 400.0, -400.0);
    glMatrixMode(GL_MODELVIEW);
}

//process which cube to rotate with the click
void ProcessSelection(int x, int y)
{
    if (y > 50 && y < 250)
    {
        if (x > 0 && x < 200 && theta[12] != 180) spinCube(13);
        else if (x > 200 && x < 400 && theta[13] != 180) spinCube(14);
        else if (x > 400 && x < 600 && theta[14] != 180) spinCube(15);
        else if (x > 600 && x < 800 && theta[15] != 180) spinCube(16);
    }
    else
        if (y > 250 && y < 450)
        {
            if (x > 0 && x < 200 && theta[8] != 180) spinCube(9);
            else if (x > 200 && x < 400 && theta[9] != 180) spinCube(10);
            else if (x > 400 && x < 600 && theta[10] != 180) spinCube(11);
            else if (x > 600 && x < 800 && theta[11] != 180) spinCube(12);
        }
        else
            if (y > 450 && y < 650)
            {
                if (x > 0 && x < 200 && theta[4] != 180) spinCube(5);
                else if (x > 200 && x < 400 && theta[5] != 180) spinCube(6);
                else if (x > 400 && x < 600 && theta[6] != 180) spinCube(7);
                else if (x > 600 && x < 800 && theta[7] != 180) spinCube(8);
            }
            else
                if (y > 650 && y < 850)
                {
                    if (x > 0 && x < 200 && theta[0] != 180) spinCube(1);
                    else if (x > 200 && x < 400 && theta[1] != 180) spinCube(2);
                    else if (x > 400 && x < 600 && theta[2] != 180) spinCube(3);
                    else if (x > 600 && x < 800 && theta[3] != 180) spinCube(4);
                }
}
//catch the mouse function
void mouse(int btn, int state, int x, int y)
{
    if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        ProcessSelection(x, y);
    }
}
//change the angle of certain cube to rotate the cube
void spinCube2()
{
    int i;
    for (i = 0; i < ELE_NUM; i++)
    {
        if (judge[i] > 0)
        {
            theta[i] += delta;
            if (theta[i] == 180) {
                judge[i] -= 1;
                if (rotate_buf != -1 && rotate_buf != i)
                {
                    judge[rotate_buf] += 1;
                    rotate_buf = -1;
                }
            }
            if (theta[i] > 360.0) {
                theta[i] -= 360.0;
                judge[i] -= 1;
            }
        }
    }
    glutPostRedisplay();
}
//main function
int main(int argc, char** argv)
{
    mkgroup();
    settime();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 850);
    glutCreateWindow("Flip Flop Match Game");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutIdleFunc(spinCube2);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
