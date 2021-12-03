 #include <GL/gl.h>
 #include <GL/glut.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include"cghomeworkanlixia.h"
#include<windows.h>

//主程序入口
int main(int argc, char *argv[])
{
    glutInitWindowSize(WW,WH);//设置窗口大小
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("HomeworkALX");

    //指定当前矩阵  设置透视投影
    glMatrixMode(GL_PROJECTION);
    //指定屏幕区域坐标范围,设置左下角(0,0)
    gluOrtho2D(0, WW, 0, WH);

    //glLoadIdentity(); //改为单位坐标

    glutDisplayFunc(display);//显示回调

    glutSpecialFunc(specialKey);//处理特殊键
    glutMouseFunc(mouseDown);     // 鼠标回调
    glutPassiveMotionFunc(passiveMouseMove);  //指定鼠标移动相应函数

    cout<<"右键选择菜单"<<endl<<endl;
    //创建子菜单1
    submenu1=glutCreateMenu(subMenu1);
    glutAddMenuEntry("直线",1);
    glutAddMenuEntry("圆",2);
    glutAddMenuEntry("椭圆",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //创建子菜单2
    submenu2=glutCreateMenu(subMenu2);
    glutAddMenuEntry("各种图形",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //创建子菜单3
    submenu3=glutCreateMenu(subMenu3);
    glutAddMenuEntry("直线段裁剪",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //创建子菜单4
    submenu4=glutCreateMenu(subMenu4);
    glutAddMenuEntry("平移+旋转+缩放:三角形 ",1);
    glutAddMenuEntry("平移+旋转+缩放：矩形",2);
    glutAddMenuEntry("三维图形变换",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //创建主菜单并加入子菜单
    menu=glutCreateMenu(mainMenu);
    glutAddSubMenu("图形生成",submenu1);
    glutAddSubMenu("图形填充",submenu2);
    glutAddSubMenu("图形裁剪",submenu3);
    glutAddSubMenu("图形变换",submenu4);
    //glutAddSubMenu("退出",submenu5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    glutReshapeFunc(changeSize);  //指定窗口调整函数

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // 设置渲染状态

    glutMainLoop();

    return EXIT_SUCCESS;
}

//主菜单
void mainMenu(GLint option)
{
    //先获取当前菜单
    //getMenu();
    switch(option)
    {
        case 1: cout<<"图形生成"<<endl; break;
        case 2: cout<<"图形填充"<<endl; break;
        case 3: cout<<"图形裁剪"<<endl; break;
        case 4: cout<<"图形变换"<<endl; break;
        case 5: cout<<"退出"<<endl; break;
    }
}

//子菜单1
void subMenu1(GLint option)
{
    switch(option)
    {
        case 1:
            type=1;
            count=0;
            cout<<endl<<"-------生成直线-------"<<endl;
            cout<<endl<<"请用鼠标左键点击三角形取色"<<endl;
            break;
        case 2:
            type=2;
            count=0;
            cout<<endl<<"--------生成圆--------"<<endl;
            cout<<endl<<"请用鼠标左键点击三角形取色"<<endl;
            break;
        case 3:
            type=3;
            count=0;
            cout<<endl<<"-------生成椭圆--------"<<endl;
            cout<<endl<<"请用鼠标左键点击三角形取色"<<endl;
            break;
    }
    glutPostRedisplay();
}

//子菜单2
void subMenu2(GLint option)
{
    switch(option)
    {
    case 1:
        type=4;
        cout<<endl<<"-------填充图形-------"<<endl;
        cout<<endl<<"请用鼠标左键点击三角形取色"<<endl;
        break;
    /*
    case 2:
        type=9;
        count=0;
        cout<<endl<<"--------橡皮筋画矩形--------"<<endl;
        break;
    */
    }
    glutPostRedisplay();
}

/*
    平移变换
    比例变换（局部比例变换、整体比例变换）
    旋转变换（绕x轴、y轴、z轴、任意轴）
    对称变换（关于坐标平面、坐标轴等）
    投影（平行投影、透视投影）
*/

//子菜单3
void subMenu3(GLint option)
{
    if(option==1)
    {
        type=8;
        iPositionNum=0;
        count=0;
        XL=XR=YT=YB=0;

        cout<<endl<<"-------线段裁剪-------"<<endl;
        cout<<endl<<"请用鼠标左键绘制区域（橡皮筋技术）"<<endl;
        cout<<endl<<"请用鼠标中键画直线"<<endl;
    }
    glutPostRedisplay();
}

//子菜单4
void subMenu4(GLint option)
{
    switch(option)
    {
    case 1:
        type=5;

        Point p1,p2,p3,p4;
        p3.x=350;
        p3.y=20;
        p4.x=350;
        p4.y=580;

        p1.x=20;
        p1.y=300;
        p2.x=680;
        p2.y=300;

        coordinate.xaxis.p0=p1;
        coordinate.xaxis.p1=p2;
        coordinate.yaxis.p0=p3;
        coordinate.yaxis.p1=p4;

        //初始化
        xt=0;
        yt=0;
        alphat=0;
        multit=0;

        cout<<endl<<"-------平移+旋转+缩放-------"<<endl;
        cout<<endl<<"请使用上下左右方向键控制平移"<<endl;
        cout<<"F1顺时针旋转  F2逆时针旋转"<<endl;
        cout<<"F3按比例放大  F4按比例缩小"<<endl;
        cout<<endl<<"使用F9 F10 F11 F12键控制坐标轴位置"<<endl;
        break;
    case 2:
        type=10;

        //初始化
        xx=0;
        yy=0;
        alpha=0;
        multi=0;

        cout<<endl<<"-------平移+旋转+缩放-------"<<endl;
        cout<<endl<<"请使用上下左右方向键控制平移"<<endl;
        cout<<"F1顺时针旋转  F2逆时针旋转"<<endl;
        cout<<"F3按比例放大  F4按比例缩小"<<endl;
        break;

    case 3:
        cout<<"-------三维图形变换-------"<<endl;
        cout<<endl<<"使用上下左右方向键控制平移"<<endl;
        cout<<endl<<"F1,F2控制缩放"<<endl;
        cout<<endl<<"F3:绕z轴旋转  F4:绕x轴  F5:绕y轴"<<endl;

        for(GLint i=0;i<8;i++)
        {
            vertices[i][0]= verticescopy[i][0];
            vertices[i][1]= verticescopy[i][1];
            vertices[i][2]= verticescopy[i][2];
            vertices[i][3]= verticescopy[i][3];
        }

        ddx=ddy=ddz=0;
        multix=multiy=multiz=1;
        alpha3D=0;

        type=11;

        glEnable(GL_DEPTH_TEST);//隐藏表面
        glViewport(0,0,WW,WH);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-2.0,2.0,-2.0*(GLfloat)WH/(GLfloat)WW,2.0*(GLfloat)WH/(GLfloat)WW,-10.0,10.0);
        glMatrixMode(GL_MODELVIEW);

        break;
    }
    glutPostRedisplay();

}

//子菜单5
void subMenu5()
{
    exit(0);
}


//处理特殊键
void specialKey(GLint key,GLint x,GLint y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(type==5) //图形变换:三角形
        {
            //cout<<"yt"<<yt<<endl;
            if(yt<=WH-450)
            {
                yt+=20;
            }
            else
            {
                cout<<"到边界了！！！"<<endl;
            }
        }
        else if(type==10) ////图形变换:矩形
        {
            yy+=20;
        }
        else if(type==11) //三维图形变换
        {
            //三维图形平移
            //ddy+=0.1;
            Translate3D(vertices,8,0,0.1,0);
        }
        break;
    case GLUT_KEY_DOWN:
        if(type==5)
        {
            if(yt>=-200)
            {
                yt-=20;
            }
            else
            {
                cout<<"到边界了！！！"<<endl;
            }
        }
        else if(type==10)
        {
            yy-=20;
        }
        else if(type==11)
        {
            //cout<<"down"<<endl;
            //三维图形平移
            //ddy-=0.1;
            //矩阵运算后画出平移后的三维图形
            Translate3D(vertices,8,0,-0.1,0);
        }
        break;
    case GLUT_KEY_LEFT:
        if(type==5)
        {
            if(xt>=-350)
            {
                xt-=20;
            }
            else
            {
                cout<<"到边界了！！！"<<endl;
            }
        }
        else if(type==10)
        {
            xx-=20;
        }
        else if(type==11)
        {
            //cout<<"left"<<endl;
            //ddx-=0.1;

            //矩阵运算后画出平移后的三维图形
            Translate3D(vertices,8,-0.1,0,0);
        }
        break;
    case GLUT_KEY_RIGHT:
        if(type==5)
        {
            if(xt<=WW-520)
            {
                xt+=20;
            }
            else
            {
                cout<<"到边界了！！！"<<endl;
            }
        }
        else if(type==10)
        {
            xx+=20;
        }
        else if(type==11)
        {
            //cout<<"right"<<endl;
            //ddx+=0.1;
            //矩阵运算后画出平移后的三维图形
            Translate3D(vertices,8,0.1,0,0);
        }
        break;
    case GLUT_KEY_F1:
        if(type==5)
        {
            alphat-=0.1;
        }
        else if(type==10)
        {
            alpha-=0.1;
        }
        else if(type==11)
        {
            multix=multiy=multiz=0.9;
            //矩阵运算后画出缩小后的三维图形
            Scale3D(vertices,8,multix,multiy,multiz);
        }
        break;
    case GLUT_KEY_F2:
        if(type==5)
        {
            alphat+=0.1;
        }
        else if(type==10)
        {
            alpha+=0.1;
        }
        else if(type==11)
        {
            multix=multiy=multiz=1.1;
            //矩阵运算后画出放大后的三维图形
            Scale3D(vertices,8,multix,multiy,multiz);
        }
        break;
    case GLUT_KEY_F3:
        if(type==5)
        {
            multit+=0.3;
        }
        else if(type==10)
        {
            multi+=0.3;
        }
        else if(type==11)
        {
            Rotate3D(vertices,8,0.1,0,0);
        }
        break;
    case GLUT_KEY_F4:
        if(type==5)
        {
            multit-=0.3;
        }
        else if(type==10)
        {
            multi-=0.3;
        }
        else if(type==11)
        {
            Rotate3D(vertices,8,0,0.1,0);
        }
        break;
    case GLUT_KEY_F5:
        if(type==11)
        {
            Rotate3D(vertices,8,0,0,0.1);
        }
        break;
     case GLUT_KEY_F9:  //移动坐标轴
        coordinate.xaxis.p0.y-=10;
        coordinate.xaxis.p1.y-=10;
        break;
    case GLUT_KEY_F10:
        coordinate.xaxis.p0.y+=10;
        coordinate.xaxis.p1.y+=10;
        break;
    case GLUT_KEY_F11:
        coordinate.yaxis.p0.x-=10;
        coordinate.yaxis.p1.x-=10;
        break;
    case GLUT_KEY_F12:
        coordinate.yaxis.p0.x+=10;
        coordinate.yaxis.p1.x+=10;
        break;
    }
    glutPostRedisplay();
}

//窗口调整
void changeSize(GLint newWW,GLint newWH)
{
	glViewport(0,0,newWW,newWH); //指定窗口显示区域
	glMatrixMode(GL_PROJECTION);//指定窗口投影参数
	glLoadIdentity();//调用单位矩阵，去掉以前的投影参数设置

	gluOrtho2D(0.0,GLfloat(newWW),0.0,GLfloat(newWH));//设置投影参数
	display();
	glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //画取色板
    if(type==1||type==2||type==3||type==4)
    {
        //取色三角形
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(450,500);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(550,500);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(500,600);
        glEnd();
    }

    //图形填充
    if(type==4)
    {
        cfill.pm.x=200;
        cfill.pm.y=400;
        cfill.r=120;
        midPointCircle(cfill,boarderColor);

        Circle eyel;
        eyel.pm.x=145;
        eyel.pm.y=445;
        eyel.r=30;
        midPointEllipse(eyel.pm, 50, 30,boarderColor);
        midPointCircle(eyel,boarderColor);

        Circle eyer;
        eyer.pm.x=255;
        eyer.pm.y=445;
        eyer.r=30;
        //midPointEllipse(eyer.pm, 50, 30,boarderColor);
        midPointCircle(eyer,boarderColor);

        //画一个矩形
        GLfloat graph4[4][3]={{165,380,1},{240,380,1},{240,320,1},{165,320,1}};
        drawLineLoop(graph4,4,boarderColor);

        //画一个矩形
        GLfloat graph[4][3]={{400,350,1},{600,350,1},{600,150,1},{400,150,1}};
        drawLineLoop(graph,4,boarderColor);

        //生成椭圆
        Point pl;
        pl.x=460;
        pl.y=290;
        midPointEllipse(pl, 50, 30,boarderColor);

        //生成椭圆
        Point pr;
        pr.x=540;
        pr.y=290;
        midPointEllipse(pr, 50, 30,boarderColor);

        //画一个六边形
        GLfloat graph6[6][3]={{450,150,1},{550,150,1},{580,200,1},{550,250,1},{450,250,1},{420,200,1}};
        drawLineLoop(graph6,6,boarderColor);
    }

    //图形变换
    if(type==5)
    {
        //启动线型
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1,0x00FF);

        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2i(coordinate.xaxis.p0.x,coordinate.xaxis.p0.y);
        glVertex2i(coordinate.xaxis.p1.x,coordinate.xaxis.p1.y);

        glVertex2i(coordinate.yaxis.p0.x,coordinate.yaxis.p0.y);
        glVertex2i(coordinate.yaxis.p1.x,coordinate.yaxis.p1.y);
        glEnd();

        //关闭自定义线型
        glDisable(GL_LINE_STIPPLE);

        Color color={0.3,0.4,0.6};//平移图形颜色
        Color color1={0.9,0.0,0.9};//旋转图形颜色
        Color color2={0.9,0.9,0.0};//缩放图形颜色

        //矩阵运算后画出平移后的图形
        Translate(triangle,3,xt,yt,color);

        //矩阵运算后画出旋转后的图形
        Rotate(triangle,3,alphat,color1);

        //画出原图形
        drawLineLoop(triangle,3,boarderColor);

        //矩阵运算后画出缩放后的图形
        Scale(triangle,3,multit,multit,color2);
    }

    //图形变换  矩形
    if(type==10)
    {
        //初始化多边形顶点 （二维图形）
        GLfloat points[4][3]={{50,50,1},{50,100,1},{200,100,1},{200,50,1}};

        //画出原图
        drawGraphic(points,4);

        //矩阵运算后将原图形平移
        Translate(points,4,xx,yy,boarderColor);//平移

        for(GLint i=0;i<4;i++)
        {
            points[i][0]+=xx;
            points[i][1]+=yy;
        }

        //矩阵运算后画出旋转后的图形
        Rotate(points,4,alpha,boarderColor);
        //矩阵运算后画出比例缩放后的图形
        Scale(points,4,multi,multi,boarderColor);
    }

    //线段裁剪
    if(type==8)
    {
        //cout<<"here"<<endl;
        GLfloat region[4][3]={{XL,YB,1},{XR,YB,1},{XR,YT,1},{XL,YT,1}};

        //绘制区域  橡皮筋
        if(iPositionNum>=1)
        {
            Color color={0,0.1,1};
            drawLineLoop(region,4,color);
        }

        Point p1,p2;
        p1.x=100;
        p1.y=30;
        p2.x=500;
        p2.y=450;
        glColor3f (1.0, 0.7, 1.0);
        //先画出原线段，再进行裁剪
        drawLine(p1.x,p1.y,p2.x,p2.y);
        CS_LineClip(p1,p2);

        p1.x=80;
        p1.y=330;
        p2.x=230;
        p2.y=490;
        glColor3f (1.0, 0.7, 1.0);
        //先画出原线段，再进行裁剪
        drawLine(p1.x,p1.y,p2.x,p2.y);
        CS_LineClip(p1,p2);
    }

    if(type==11)
    {
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        //Translate3D(vertices,8,ddx,ddy,0);
        //Scale3D(vertices,8,multix,multiy,multiz);
        colorCube(vertices);

        glFlush();
        glutSwapBuffers();
    }

    glFlush();
    //glutSwapBuffers();

}

//画线框图形
//参数意义：第一个参数是图形顶点数组，第二个参数是顶点个数，第三个参数是颜色
void drawLineLoop(GLfloat a[][3],GLint n,Color color)
{
    glLineWidth(2.0f);//设置线宽
    glBegin(GL_LINE_LOOP);
    glColor3f(color[0],color[1],color[2]);
    for(int i=0;i<n;i++)
    {
        glVertex2f(a[i][0],a[i][1]);
    }
    glEnd();
    glFlush();
}

//画填色图形
//参数意义：第一个参数a是指图形顶点数组，第二个参数是图形顶点个数
void drawGraphic(GLfloat a[][3],GLint n)
{
    glShadeModel(GL_SMOOTH);

    drawLine(a[0][0],a[0][1],a[1][0],a[1][1]);
    drawLine(a[0][0],a[0][1],a[3][0],a[3][1]);

    drawLine(a[3][0]+1,a[3][1],a[2][0]+1,a[2][1]);
    drawLine(a[2][0],a[2][1]+1,a[1][0],a[1][1]+1);

    glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
    {
        glColor3f(0.3+0.1*i,0.5+0.1*i,0.6+0.1*i);
        glVertex2f(a[i][0],a[i][1]);
    }
    glEnd();
    glFlush();
}


// 绘制点
void drawPoint(Point p,Color color)
{
    glPointSize(2.0f);
    glColor3f(color[0], color[1], color[2]);
    //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
    glBegin(GL_POINTS);
    glVertex2i(p.x, p.y);
    glEnd();
    glFlush();
}

// 绘制点
void drawPoint(GLint x,GLint y)
{
    glPointSize(1.0f);
    //glColor3f(fillColor[0], fillColor[1], fillColor[2]);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

//画直线
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{
    //绘制直线
    glBegin(GL_LINES);
    //glColor3f(0.0,0.0,1.0);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}


//平移(二维）
//参数意义：第一个参数是图形顶点数组，第二个参数是行数即图形顶点个数，第三个参数是列数反映图形维数，第四个参数是x方向平移量，第四个参数是y方向平移量
void Translate(GLfloat graph[][3],GLint n,GLint dx,GLint dy,Color color)
{
    /*  x方向平移X,y方向平移Y
    1 0 0
    0 1 0
    X Y 1
    */
    //定义平移变换矩阵
    GLfloat translate[3][3] = {{1,0,0},{0,1,0},{dx,dy,1}};
    GLfloat result[n][3];
    matrixMulti(result,graph,translate,n,3);

    if(n==4)
    {
        drawGraphic(result,n); //平移不改变形状
    }
    else
    {
        drawLineLoop(result,3,color);
    }

}

//旋转(二维）
//参数意义：第一个参数是图形顶点数组，第二个参数是图形顶点个数，第三个参数旋转角度
void Rotate(GLfloat graph[][3],GLint n,GLfloat alpha,Color color)
{
    //定义三个矩阵
    GLfloat result1[n][3],result2[n][3],result3[n][3];

    if(n==3)
    {
        drawLine(graph[0][0],graph[0][1],coordinate.yaxis.p0.x,coordinate.xaxis.p0.y);
        //首先将多边形的一个顶点平移到原点
        GLfloat matrix1[3][3]={{1,0,0},{0,1,0},{-coordinate.yaxis.p0.x,-coordinate.xaxis.p0.y,1}};
        // 矩阵乘法
        matrixMulti(result1,graph,matrix1,n,3);

        /*  旋转alpha角度
         cos(alpha)  sin(alpha) 0
        -sin(alpha)  cos(alpha) 0
            0           0       1
        */
        //定义旋转变换矩阵
        GLfloat rotate[3][3]={{cos(alpha),sin(alpha),0},{-sin(alpha),cos(alpha),0},{0,0,1}};
        //矩阵乘法
        matrixMulti(result2,result1,rotate,n,3);

        //将多边形的顶点平移回原处
        GLfloat matrix2[3][3]={{1,0,0},{0,1,0},{coordinate.yaxis.p0.x,coordinate.xaxis.p0.y,1}};
        // 运行矩阵乘法实现旋转
        matrixMulti(result3,result2,matrix2,n,3);

        drawLine(result3[0][0],result3[0][1],coordinate.yaxis.p0.x,coordinate.xaxis.p0.y);
        drawLineLoop(result3,n,color);
    }
    else
    {
        GLfloat matrix1[3][3]={{1,0,0},{0,1,0},{-graph[0][0],-graph[0][1],1}};
        // 矩阵乘法
        matrixMulti(result1,graph,matrix1,n,3);

        /*  旋转alpha角度
         cos(alpha)  sin(alpha) 0
        -sin(alpha)  cos(alpha) 0
            0           0       1
        */
        //定义旋转变换矩阵
        GLfloat rotate[3][3]={{cos(alpha),sin(alpha),0},{-sin(alpha),cos(alpha),0},{0,0,1}};

        //矩阵乘法
        matrixMulti(result2,result1,rotate,n,3);

        //将多边形的顶点平移回原处
        GLfloat matrix2[3][3]={{1,0,0},{0,1,0},{graph[0][0],graph[0][1],1}};
        // 运行矩阵乘法实现旋转
        matrixMulti(result3,result2,matrix2,n,3);

        //画出旋转之后的图形
        drawGraphic(result3,n);
    }

}

//缩放（二维）
//参数意义：第一个参数是图形顶点数组，第二个参数是图形顶点个数，第三个参数是x方向放大倍数，第四个参数是y方向放大倍数
void Scale(GLfloat graph[][3],GLint n,GLfloat dx,GLfloat dy,Color color)
{
    GLfloat result1[n][3],result2[n][3],result3[n][3];

    //首先将多边形的一个顶点平移到原点
    GLfloat matrix1[3][3]={{1,0,0},{0,1,0},{-graph[0][0],-graph[0][1],1}};
    //矩阵乘法
    matrixMulti(result1,graph,matrix1,n,3);

    /*  x方向变为原来的X倍,y方向变为原来的Y倍
    X 0 0
    0 Y 0
    0 0 1
    */
    GLfloat scale[3][3]={{dx,0,0},{0,dy,0},{0,0,1}};
    matrixMulti(result2,result1,scale,n,3);

    //将图形移回原来位置
    GLfloat matrix2[3][3]={{1,0,0},{0,1,0},{graph[0][0],graph[0][1],1}};
    //矩阵乘法实现平移
    matrixMulti(result3,result2,matrix2,n,3);

    if(n==4)
    {
        //画出缩放之后的图形
        drawGraphic(result3,n);
    }
    else
    {
        drawLineLoop(result3,n,color);
    }

}

//矩阵乘法运算(二维）
//参数意义：aMatrix是矩阵bMatrix和矩阵cMatrix乘法运算的结果
void matrixMulti(GLfloat aMatrix[][3],GLfloat bMatrix[][3],GLfloat cMatrix[][3],GLint row,GLint col)
{
    GLint i,j,k;
    GLint tmp;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            tmp = 0;
            for(k=0;k<col;k++)
            {
                tmp += bMatrix[i][k]*cMatrix[k][j];
            }
            aMatrix[i][j] = tmp;
        }
    }
}

//矩阵乘法运算(三维）
//参数意义：aMatrix是矩阵bMatrix和矩阵cMatrix乘法运算的结果
void matrixMulti3D(GLfloat aMatrix[][4],GLfloat bMatrix[][4],GLfloat cMatrix[][4],GLint row,GLint col)
{
    GLint i,j,k;
    GLfloat tmp;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            tmp = 0;
            for(k=0;k<col;k++)
            {
                tmp += bMatrix[i][k]*cMatrix[k][j];
            }
            aMatrix[i][j] = tmp;
        }
    }
}

//平移（三维）
//参数意义：第一个参数是图形顶点数组，第二个参数是行数即图形顶点个数，第三个参数是列数反映图形维数，第四个参数是x方向平移量，第四个参数是y方向平移量
void Translate3D(GLfloat graph[][4],GLint n,GLfloat dx,GLfloat dy,GLfloat dz)
{
    /*  x方向平移X,y方向平移Y,z方向平移Z
    1 0 0 0
    0 1 0 0
    0 0 1 0
    X Y Z 1
    */
    //定义平移变换矩阵
    GLfloat translate[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{dx,dy,dz,1}};

    matrixMulti3D(vertices,graph,translate,n,4);

}

//缩放（三维）
//参数意义：第一个参数是图形顶点数组，第二个参数是图形顶点个数，第三个参数是x方向放大倍数，第四个参数是y方向放大倍数
void Scale3D(GLfloat graph[][4],GLint n,GLfloat dx,GLfloat dy,GLfloat dz)
{
    GLfloat result1[n][4],result2[n][4];

    /*  x方向变为原来的X倍,y方向变为原来的Y倍
    X 0 0 0
    0 Y 0 0
    0 0 Z 0
    0 0 0 1
    */
    GLfloat scale[4][4]={ {dx,0,0,0}, {0,dy,0,0}, {0,0,dz,0}, {0,0,0,1}};

    matrixMulti3D(vertices,graph,scale,n,4);
}


//旋转(三维）
//参数意义：第一个参数是图形顶点数组，第二个参数是图形顶点个数，第三个参数旋转角度
void Rotate3D(GLfloat graph[][4],GLint n,GLfloat alpha,GLfloat beta,GLfloat gema)
{
    //定义三个矩阵
    GLfloat result1[n][4],result2[n][4],result3[n][4],result4[n][4];

    //首先将多边形的一个顶点平移到原点
    GLfloat matrix1[8][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    // 矩阵乘法
    matrixMulti3D(result1,graph,matrix1,n,4);

    /*  旋转alpha角度
    cos(alpha)  sin(alpha) 0  0
    -sin(alpha) cos(alpha) 0  0
        0           0      1  0
        0           0      0  1
    */
    //定义旋转变换矩阵
    GLfloat rotate1[4][4]={{cos(alpha),sin(alpha),0,0},{-sin(alpha),cos(alpha),0,0},{0,0,1,0},{0,0,0,1}};
    GLfloat rotate2[4][4]={{1,0,0,0},{0,cos(beta),sin(beta),0},{0,-sin(beta),cos(beta),0},{0,0,0,1}};
    GLfloat rotate3[4][4]={{cos(gema),0,-sin(gema),0},{0,1,0,0},{sin(gema),0,cos(gema),0},{0,0,0,1}};
    //矩阵乘法
    matrixMulti3D(result2,result1,rotate1,n,4);

    matrixMulti3D(result3,result2,rotate2,n,4);

    matrixMulti3D(result4,result3,rotate3,n,4);

    //将多边形的顶点平移回原处
    GLfloat matrix2[8][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    // 运行矩阵乘法实现旋转
    matrixMulti3D(vertices,result4,matrix2,n,4);
}

//判断是否在窗口内部
bool isInside(GLint x,GLint y)
{
    if(x>=0 && y>=0 && x<=WW &&y<=WH)
    {
        return true;
    }
    else
    {
        cout<<"出界！"<<endl;
        return false;
    }
}

// 处理鼠标点击
void mouseDown(GLint btn,GLint state,GLint x,GLint y)
{
    Point point;
    point.x=x;
    point.y=WH-y;

    //处理直线端点点击
    if (type==1 && state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y))
    {
        //取色
        if(count==0)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"请点击三角形取色！！！"<<endl;
            }
            else
            {
                cout<<endl<<"请用鼠标左键点击直线两个端点"<<endl;
                count++;
            }
        }
        //点击第一个点不画线
        else if(count==1)
        {
            drawPoint(point,color);
            //存储该点
            startPoint=point;
            count++;
        }
        //生成直线
        else
        {
            drawPoint(point,color);
            endPoint=point;
            //glClear(GL_COLOR_BUFFER_BIT);
            Bresenham(startPoint,endPoint,color);
            count=0;
        }
    }

    //处理圆心及圆上点的点击
    //定义一个圆 并指定圆心为鼠标点击位置
    Circle circle;
    if (type==2&&state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y))
    {
        //取色
        if(count==0)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"请点击三角形取色！！！"<<endl;
            }
            else
            {
                 cout<<endl<<"请用鼠标中键点击圆心及圆边界上一点位置"<<endl;
                count++;
            }
        }
        else if(count==1)
        {
            //存储圆心
            startPoint = point;
            //画点
            drawPoint(startPoint,color);
            count++;
        }
        else if(count==2)
        {
            //cout<<"2"<<endl;
            //存储终点
            endPoint = point;
            drawPoint(endPoint,color);

            circle.pm=startPoint; //圆心
            circle.r=sqrt( (endPoint.x-startPoint.x)*(endPoint.x-startPoint.x)+(endPoint.y-startPoint.y)*(endPoint.y-startPoint.y) );//半径

            //glClear(GL_COLOR_BUFFER_BIT);
            //cout<<circle.pm.x<<" "<<circle.pm.y<<" "<<circle.r<<endl;;
            //中点画圆法生成圆
            midPointCircle(circle,color);
            //Bresenham(startPoint,endPoint,color);
            count=0;
        }
    }

    //椭圆生成
    if (type==3&& state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y))
    {
        if(count==0)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"请点击三角形取色！！！"<<endl;
            }
            else
            {
                cout<<endl<<"请左键点击椭圆中心位置"<<endl;
                count++;
            }
        }
        else if(count==1)
        {
            //存储圆心
            startPoint = point;
            //画点
            drawPoint(startPoint,color);
            //glClear(GL_COLOR_BUFFER_BIT);
            midPointEllipse(point, 120, 100, color);
            count=0;
        }
    }

    //处理填充圆的点击
    if(type==4 && state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y) )
    {
        if (isFirst)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"请点击三角形取色！！！"<<endl;
            }
            else
            {
                 cout<<endl<<"请选择要填充的图形"<<endl;
                 isFirst = false;
            }
        }
        else
        {
            //cout<<"xy"<<x<<" "<<WH-y<<endl;
            if(isLeagle(x,WH-y)==true)
            {
                FloodFill4(x,WH-y,backgroundColor,color); //设置起点坐标及颜色
                //ScanLineFill(x,WH-y,boarderColor);
                isFirst=true;
            }
            else
            {
                cout<<"点击位置无可填充图形！！！"<<endl;
            }
        }
    }

    //处理线段裁剪时的点击
    if(type==8)
    {
        if(state == GLUT_DOWN && btn == GLUT_MIDDLE_BUTTON&&isInside(x,y) )
        {
            drawPoint(point,boarderColor);
            //点击第一个点不画线
            if (count==0)
            {
                //存储该点
                startPoint=point;
                count++;
            }
            else
            {
                endPoint=point;
                //glClear(GL_COLOR_BUFFER_BIT);
                Bresenham(startPoint,endPoint,boarderColor);
                CS_LineClip(startPoint,endPoint);
                count=0;
            }
        }
        else if(state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON && isInside(x,y))
        {
            if(iPositionNum==0||iPositionNum==2)
            {
                iPositionNum = 1;
                XL = x;
                YT = WH - y;
            }
            else if(iPositionNum==1)
            {
                XR = x;
                YB = WH - y;
                iPositionNum = 2;
            }
        }
    }


    /*
    //三维图形变换
    if(type==11)
    {
        if(state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON)
        {
            //axis = 2;
            //alpha3D+=1;
            Rotate3D(vertices,8,0.1,0,0);

        }
        if(state == GLUT_DOWN && btn == GLUT_MIDDLE_BUTTON)
        {
             //axis = 0;
             Rotate3D(vertices,8,0,0.1,0);
        }
        if(state == GLUT_DOWN && btn == GLUT_RIGHT_BUTTON)
        {
            //axis = 1;
        }
        Display3(axis);
    }
    */

}

bool isLeagle(GLint x,GLint y)
{
    //在圆内
    if( sqrt( (cfill.pm.x-x)*(cfill.pm.x-x)+(cfill.pm.y-y)*(cfill.pm.y-y) ) <= cfill.r )
    {
        cout<<"在圆内"<<endl;
        return true;
    }
    //在矩形内
    if( x>=400&&x<=600&&y>=150&&y<=350 )
    {
        cout<<"在矩形内"<<endl;
        return true;
    }
    return false;
}

void passiveMouseMove(GLint xMouse,GLint yMouse)
{
    if(iPositionNum==1)
    {
        XR = xMouse;
        YB = WH - yMouse;
        glutPostRedisplay();
    }
}

//直线生成算法
void Bresenham(Point p1,Point p2,Color color)
{
    //预处理
    if(p1.x>p2.x)
    {
        Point p;
        p=p1;
        p1=p2;
        p2=p;
    }
    else{}

    if( p2.x-p1.x>=p2.y-p1.y && p2.y-p1.y>=0 )  //0<=k<=1
    {
        //cout<<endl<<"0<=k<=1"<<endl;
        bresenham1(p1,p2,color);
    }
    else if( p2.x-p1.x<p2.y-p1.y && p2.x-p1.x>=0  )  //k>1
    {
        //cout<<endl<<"k>1"<<endl;
        bresenham2(p1,p2,color);
    }
    else if( p2.x-p1.x>=p1.y-p2.y && p1.y-p2.y>0 ) //-1<=k<0
    {
        //cout<<endl<<"-1<=k<0"<<endl;
        bresenham3(p1,p2,color);
    }
    else if( p2.x-p1.x<p1.y-p2.y && p1.y-p2.y>0 ) //k<-1
    {
        //cout<<endl<<"k<-1"<<endl;
        bresenham4(p1,p2,color);
    }
}

//0<=k<=1
void bresenham1(Point p1,Point p2,Color color)
{
    GLint dx,dy,e,i;
    Point p;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    e = 2*dy - dx;
    p=p1;

    //cout<<endl<<"x"<<" "<<"y"<<" "<<"e"<<endl;
    for(i=0;i<=dx;i++)
    {
        //cout<<x<<" "<<y<<" "<<e<<endl;
        drawPoint(p,color);

        p.x++;
        if(e>=0)
        {
            p.y++;
            e = e + 2*dy - 2*dx;
        }
        else
        {
            e = e + 2*dy;
        }
    }
}


//k>1
void bresenham2(Point p1,Point p2,Color color)
{
    GLint dx,dy,e,i;
    Point p;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    e = 2*dx - dy;
    p=p1;

    for(i=0;i<=dy;i++)
    {
        drawPoint(p,color);

        p.y++;
        if(e>=0)
        {
            p.x++;
            e = e + 2*dx - 2*dy;
        }
        else
        {
            e = e + 2*dx;
        }
    }
}

//-1<=k<0
void bresenham3(Point p1,Point p2,Color color)
{
    GLint dx,dy,e,i;
    Point p;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    e = 2*dy + dx;
    p=p1;

    for(i=0;i<=dx;i++)
    {
        drawPoint(p,color);

        p.x++;
        if(e>=0)
        {
            e = e + 2*dy;
        }
        else
        {
            p.y--;
            e = e + 2*dy + 2*dx;
        }
    }
}

//k<-1
void bresenham4(Point p1,Point p2,Color color )
{
    GLint dx,dy,e,i;
    Point p;
    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    e = 2*dx + dy;
    p=p1;

    for(i=0;i<=-dy;i++)
    {
        drawPoint(p,color);

        p.y--;
        if(e>=0)
        {
            p.x++;
            e = e + 2*dx + 2*dy;
        }
        else
        {
            e = e + 2*dx;
        }
    }
}

//中点画圆法
void midPointCircle(Circle circle,Color color)
{
    GLint x,y;
    GLint e;
    x = 0;
    y = circle.r;
    e = 1 - circle.r;

    //circle.pm是圆心
    circlePoint(circle.pm,x,y,color);

    while(x<=y)
    {
        if(e<0)
        {
            e += 2*x + 3;
        }
        else
        {
            e += 2*(x-y) + 5;
            y--;
        }
        x++;
        circlePoint(circle.pm,x,y,color);
    }
}

//Point p是圆心
void circlePoint(Point p,GLint x,GLint y,Color color)
{
    glPointSize(2.0f);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POINTS);
    //glColor3f(1.0f,0.0f,0.0f);   //红色
    glVertex2f(x+p.x, y+p.y);
    //glColor3f(0.5f,1.0f,0.0f);   //绿色
    glVertex2f(-x+p.x, y+p.y);
    //glColor3f(0.0f,1.0f,0.0f);
    glVertex2f(x+p.x, p.y-y);
    //glColor3f(1.0f,0.5f,1.0f);
    glVertex2f(-x+p.x, p.y-y);
    //glColor3f(0.0f,1.0f,1.0f);
    glVertex2f(y+p.x, x+p.y);
    //glColor3f(1.0f,0.5f,0.5f);
    glVertex2f(-y+p.x, x+p.y);
    //glColor3f(0.5f,0.5f,1.0f);
    glVertex2f(y+p.x, p.y-x);
    //glColor3f(1.0f,1.0f,0.5f);
    glVertex2f(-y+p.x, p.y-x);
    glEnd();
    glFlush();
}

//椭圆生成算法
void midPointEllipse(Point pc,GLint a,GLint b,Color color)
{
    GLint aa=a*a,bb=b*b;
    GLint twoaa=2*aa,twobb=22*bb;
    GLint x=0,y=b;
    GLint d;
    GLint dx=0;
    GLint dy=twoaa*y;
    d=GLint(bb+aa*(-b+0.25)+0.5);
    setpixel(pc.x+x,pc.y+y,color);
    setpixel(pc.x+x,pc.y-y,color);
    setpixel(pc.x-x,pc.y+y,color);
    setpixel(pc.x-x,pc.y-y,color);
    while(dx<dy)
    {
        x++;
        dx+=twobb;
        if(d<0)
        {
            d+=bb+dx;
        }
        else
        {
            dy-=twoaa;
            d+=bb+dx-dy;
            y--;
        }

        setpixel(pc.x+x,pc.y+y,color);
        setpixel(pc.x+x,pc.y-y,color);
        setpixel(pc.x-x,pc.y+y,color);
        setpixel(pc.x-x,pc.y-y,color);
    }
    d=GLint(bb*(x+0.5)+(x+0.5)+aa*(y-1)*(y-1)-aa*bb+0.5);

    while(y>0)
    {
        y--;
        dy-=twoaa;
        if(d>0)
        {
            d+=aa-dy;
        }
        else
        {
            x++;
            dx+=twobb;
            d+=aa-dy+dx;
        }
        setpixel(pc.x+x,pc.y+y,color);
        setpixel(pc.x+x,pc.y-y,color);
        setpixel(pc.x-x,pc.y+y,color);
        setpixel(pc.x-x,pc.y-y,color);
    }

}

//获取像素点的颜色
void getpixel(GLint x, GLint y, Color color)
{
    //glCopyPixels(x,y,1,1,GL_RGB);
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

//与drawpoint重复
//画点函数
void setpixel(GLint x, GLint y,Color c)
{

    glColor3f(c[0],c[1],c[2]);

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

//比较颜色是否相同
GLint isSameColor(Color color1, Color color2)
{
    if (color1[0] != color2[0] || color1[1] != color2[1] || color1[2] != color2[2])
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

//简单的种子填充算法（内点表示）
void FloodFill4(GLint x, GLint y,Color oldcolor,Color newcolor)
{
    Color interiorColor;
    getpixel(x,y,interiorColor);

    if( isSameColor(interiorColor,oldcolor)==1 && isSameColor(interiorColor,boarderColor)==0)
    {

        setpixel(x,y,newcolor);

        FloodFill4(x + 1, y, interiorColor, newcolor);
        FloodFill4(x, y + 1, interiorColor, newcolor);
        FloodFill4(x - 2, y, interiorColor, newcolor );
        FloodFill4(x, y - 2, interiorColor, newcolor);
    }
}

//CohenSutherland裁剪算法
void CS_LineClip(Point p1,Point p2)
{
	GLint code1,code2,code;
	Point p;
	code1=encode(p1);
	code2=encode(p2);
	//cout<<code1<<" "<<code2<<endl;
	while(code1 != 0||code2 != 0)
    {
		if((code1&code2) != 0) return;

		if(code1 != 0) code=code1;
		else code=code2;

		if((LEFT&code) != 0)
        {
			p.x=XL;
			p.y=p1.y+(p2.y-p1.y)*(XL-p1.x)/(p2.x-p1.x);
		}
		else if((RIGHT&code)!=0)
        {
			p.x=XR;
			p.y=p1.y+(p2.y-p1.y)*(XR-p1.x)/(p2.x-p1.x);
		}
		else if((BOTTOM & code)!=0)
        {
			p.y=YB;
			p.x=p1.x+(p2.x-p1.x)*(YB-p1.y)/(p2.y-p1.y);
		}
		else if((TOP & code)!=0)
        {
			p.y=YT;
			p.x=p1.x+(p2.x-p1.x)*(YT-p1.y)/(p2.y-p1.y);
		}
		if(code==code1)
        {
			p1.x=p.x;
			p1.y=p.y;
			code1=encode(p);
		}
		else
        {
			p2.x=p.x;
			p2.y=p.y;
			code2=encode(p);
		}
	}

	//glColor3f (0.3, 0.2, 0.4);
	glColor3f (1.0, 0.0, 0.0);
    glBegin (GL_LINES);
        glVertex2i (p1.x, p1.y);
        glVertex2i (p2.x, p2.y);
    glEnd ( );
    glFlush();
}

//对端点编码
GLint encode(Point p)
{
	GLint c = 0;
	if(p.x < XL) c|=LEFT;
	if(p.x > XR) c|=RIGHT;
	if(p.y < YB) c|=BOTTOM;
	if(p.y > YT) c|=TOP;
	return c;
}

//扫描线种子填充算法
void ScanLineFill(GLint x,GLint y,Color color)
{
    GLint xl;
    GLint xr;
    Point pt;
    bool spanNeedFill;
    stack<Point> stackPoint;
    stackPoint.empty();
    pt.x = x;
    pt.y = y;
    stackPoint.push(pt);
    while(!stackPoint.empty())
    {
        pt = stackPoint.top();
        stackPoint.pop();
        x = pt.x;
        y = pt.y;

        glColor3fv(color);

        while( (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)<=cfill.r*cfill.r )//向右填充
        {
            drawPoint(x,y);
            x++;
        }
        xr = x - 1;
        x = pt.x - 1;
        while( (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)<=cfill.r*cfill.r )//向左填充
        {
            drawPoint(x,y);
            x--;
        }
        xl = x + 1;

        //处理上面一条扫描线
        x = xl;
        y = y + 1;
        while(x<xr)
        {
            spanNeedFill = false;
            while(  (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)<=cfill.r*cfill.r  )
            {
                spanNeedFill = true;
                x++;
            }
            if(spanNeedFill)
            {
                pt.x = x - 1;
                pt.y = y;
                stackPoint.push(pt);
                spanNeedFill = false;
            }
            while(  (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)>cfill.r*cfill.r  && x<xr  )
            {
                x++;
            }
        }

        //处理下面一条扫描线
        x = xl;
        y = y - 2;
        while(x<xr)
        {
            spanNeedFill = false;
            while( (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)<=cfill.r*cfill.r )
            {
                spanNeedFill = true;
                x++;
            }
            if(spanNeedFill)
            {
                pt.x = x - 1;
                pt.y = y;
                stackPoint.push(pt);
                spanNeedFill = false;
            }
            while(  (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)>cfill.r*cfill.r  && x<xr )
            {
                x++;
            }
        }
    }
}


void Display3(GLint axis)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    theta[axis]+=2.0;
    if(theta[axis]>360.0)
    {
        theta[axis]-=360.0;
    }

    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
    glRotatef(theta[2],0.0,0.0,1.0);


    colorCube(vertices);
    glFlush();
    glutSwapBuffers();
}

//绘制彩色的立方体
void colorCube(GLfloat graph[][4])
{
    //cout<<"画立方体"<<endl;
    polygon(graph,0,3,2,1);
    polygon(graph,2,3,7,6);
    polygon(graph,0,4,7,3);
    polygon(graph,1,2,6,5);
    polygon(graph,4,5,6,7);
    polygon(graph,0,1,5,4);

/*
    glColor3f(1.0,0.0,1.0);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glVertex3f(graph[0][0],graph[0][1],graph[0][2]);
    glVertex3f(graph[1][0],graph[1][1],graph[1][2]);

    glVertex3f(graph[0][0],graph[0][1],graph[0][2]);
    glVertex3f(graph[3][0],graph[3][1],graph[3][2]);

    glVertex3f(graph[0][0],graph[0][1],graph[0][2]);
    glVertex3f(graph[4][0],graph[4][1],graph[4][2]);

    glVertex3f(graph[1][0],graph[1][1],graph[1][2]);
    glVertex3f(graph[2][0],graph[2][1],graph[2][2]);

    glVertex3f(graph[2][0],graph[2][1],graph[2][2]);
    glVertex3f(graph[3][0],graph[3][1],graph[3][2]);

    glVertex3f(graph[2][0],graph[2][1],graph[2][2]);
    glVertex3f(graph[6][0],graph[6][1],graph[6][2]);

    glVertex3f(graph[3][0],graph[3][1],graph[3][2]);
    glVertex3f(graph[7][0],graph[7][1],graph[7][2]);

    glVertex3f(graph[5][0],graph[5][1],graph[5][2]);
    glVertex3f(graph[4][0],graph[4][1],graph[4][2]);

    glVertex3f(graph[5][0],graph[5][1],graph[5][2]);
    glVertex3f(graph[6][0],graph[6][1],graph[6][2]);

    glVertex3f(graph[4][0],graph[4][1],graph[4][2]);
    glVertex3f(graph[7][0],graph[7][1],graph[7][2]);

    glVertex3f(graph[7][0],graph[7][1],graph[7][2]);
    glVertex3f(graph[6][0],graph[6][1],graph[6][2]);

    glVertex3f(graph[1][0],graph[1][1],graph[1][2]);
    glVertex3f(graph[5][0],graph[5][1],graph[5][2]);
    glEnd();
*/
    glutSwapBuffers();
}

//绘制多边形所用变量的列表
void polygon(GLfloat graph[][4],int a,int b,int c,int d)
{
    glBegin(GL_POLYGON);
    glColor3fv(colors[a]);
    glVertex3fv(graph[a]);
    glColor3fv(colors[b]);
    glVertex3fv(graph[b]);
    glColor3fv(colors[c]);
    glVertex3fv(graph[c]);
    glColor3fv(colors[d]);
    glVertex3fv(graph[d]);
    glEnd();
}

//旋转立方体
void spinCube()
{
    if(type==11)
    {
        theta[axis]+=2.0;
        if(theta[axis]>360.0)
        {
            theta[axis]-=360.0;
        }
        //glutPostRedisplay();
        Display3(0);
    }
}


