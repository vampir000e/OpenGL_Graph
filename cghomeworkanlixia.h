#ifndef CGHOMEWORKANLIXIA_H_INCLUDED
#define CGHOMEWORKANLIXIA_H_INCLUDED

//#define _STDCALL_SUPPORTED
//#define _M_IX86
//#define GLUT_DISABLE_ATEXIT_HACK
//#define GLUT_NO_WARNING_DISABLE

#include <stdlib.h>
#include <windows.h>
#include<iostream>
#include<math.h>
#include<stack>

using namespace std;

GLsizei WH = 600;
GLsizei WW = 700;

#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

/*
GLint XL=200;
GLint XR=450;
GLint YB=200;
GLint YT=400;
*/
GLint XL;
GLint XR;
GLint YB;
GLint YT;

// 定义判定标志，第一次画点不连线
bool isFirst = true;

//计数
GLint count=0;

//指定鼠标点击事件类型
GLint type;

GLint xx,yy;
GLfloat alpha;
GLfloat multi;

GLint xt,yt;
GLfloat alphat;
GLfloat multit;

GLfloat ddx,ddy,ddz;
GLfloat multix,multiy,multiz;
GLfloat alpha3D;


GLint iPositionNum = 0;   //已经确定的点数
GLint x11=0,y11=0,x22=0,y22=0;

struct Point
{
    int x;
    int y;
};

struct Circle
{
    Point pm; //圆心
    int r; //半径
};

//坐标轴
struct Axis
{
    //轴的两端点
    Point p0;
    Point p1;
};

//坐标系
struct Coordinate
{
    //Point p; //坐标原点
    Axis xaxis; //x轴
    Axis yaxis; //y轴
};

//坐标轴
Coordinate coordinate;

typedef float Color[3];

Color color={0,0,0};

Color boarderColor = {0.0, 1.0, 0.0};//边界颜色 绿色
Color backgroundColor={0,0,0};

//定义起始点、终点
Point startPoint;
Point endPoint;

Circle cfill;

//三角形顶点数组
GLfloat triangle[3][3]={{350,300,1},{450,200,1},{500,450,1} };;

//旋转角度和轴
static GLfloat theta[] = {0.0,0.0,0.0};
static GLint axis=1;

//绘制立方体所需要的8个顶点
GLfloat vertices[8][4] = {{-0.5,-0.5,-0.5,1.0},{0.5,-0.5,-0.5,1.0},{0.5,0.5,-0.5,1.0},{-0.5,0.5,-0.5,1.0},{-0.5,-0.5,0.5,1.0},{0.5,-0.5,0.5,1.0},{0.5,0.5,0.5,1.0},{-0.5,0.5,0.5,1.0}};
GLfloat verticescopy[8][4] = {{-0.5,-0.5,-0.5,1.0},{0.5,-0.5,-0.5,1.0},{0.5,0.5,-0.5,1.0},  {-0.5,0.5,-0.5,1.0},{-0.5,-0.5,0.5,1.0},{0.5,-0.5,0.5,1.0},{0.5,0.5,0.5,1.0},{-0.5,0.5,0.5,1.0}};
//绘制立方体所需要的不同颜色
GLfloat colors[][3] = {{0.0,0.6,0.0},{1.0,0.0,0.0},{1.0,1.0,0.7},{0.3,1.0,0.0},{0.0,0.5,1.0},{0.6,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};

GLfloat rtri = 0;

GLint menu,submenu1,submenu2,submenu3,submenu4;
bool isInside(int x,int y);

void getpixel(GLint x, GLint y, Color color);
void setpixel(GLint x, GLint y,Color color);
GLint isSameColor(Color color1, Color color2);

void Display3(GLint a);
void colorCube(GLfloat graph[][4]);
void polygon(GLfloat graph[][4],int a,int b,int c,int d);

void matrixMulti3D(GLfloat aMatrix[][4],GLfloat bMatrix[][4],GLfloat cMatrix[][4],GLint row,GLint col);
void Translate3D(GLfloat graph[][4],GLint n,GLfloat dx,GLfloat dy,GLfloat dz);
void Scale3D(GLfloat graph[][4],GLint n,GLfloat dx,GLfloat dy,GLfloat dz);
void Rotate3D(GLfloat graph[][4],GLint n,GLfloat alpha,GLfloat beta,GLfloat gema);

void display();

void drawLineLoop(float a[][3],int n,Color color);

void changeSize(int w,int h);

void createMenu();

void mainMenu(int option);
void subMenu1(int option);
void subMenu2(int option);
void subMenu3(int option);
void subMenu4(int option);

bool isLeagle(GLint x,GLint y);

void Bresenham(Point p1,Point p2,Color color);//
void bresenham1(Point p1,Point p2,Color color); //0<k<1
void bresenham2(Point p1,Point p2,Color color);
void bresenham3(Point p1,Point p2,Color color);
void bresenham4(Point p1,Point p2,Color color);

void midPointCircle(Circle circle,Color color);
void circlePoint(Point p,int x,int y,Color color);
void midPointEllipse(Point p, int a, int b,Color color);

void drawPoint(Point p);
void drawPoint(int x,int y);
void drawLine(int x1, int y1, int x2, int y2);

void FloodFill4(GLint x, GLint y,Color oldcolor,Color newcolor);
void ScanLineFill(int x,int y, Color color);

GLint encode(Point p);
void CS_LineClip(Point p1,Point p2);

void mouseDown(GLint btn,GLint state,GLint x,GLint y);
void passiveMouseMove(GLint xMouse,GLint yMouse);

void specialKey(int key,int x,int y);
void keyBoard(unsigned char key,GLint x,GLint y);

void drawGraphic(float a[][3],int n);
void Translate(float graph[][3],int n,int dx,int dy,Color color);
void Rotate(float graph[][3],int n,float alpha,Color color);
void Scale(float graph[][3],int n,float dx,float dy,Color color);

void matrixMulti(float aMatrix[][3],float bMatrix[][3],float cMatrix[][3],int row,int col);

void spinCube();

#endif // CGHOMEWORKANLIXIA_H_INCLUDED
