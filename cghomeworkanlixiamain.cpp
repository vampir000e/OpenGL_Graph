 #include <GL/gl.h>
 #include <GL/glut.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include"cghomeworkanlixia.h"
#include<windows.h>

//���������
int main(int argc, char *argv[])
{
    glutInitWindowSize(WW,WH);//���ô��ڴ�С
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("HomeworkALX");

    //ָ����ǰ����  ����͸��ͶӰ
    glMatrixMode(GL_PROJECTION);
    //ָ����Ļ�������귶Χ,�������½�(0,0)
    gluOrtho2D(0, WW, 0, WH);

    //glLoadIdentity(); //��Ϊ��λ����

    glutDisplayFunc(display);//��ʾ�ص�

    glutSpecialFunc(specialKey);//���������
    glutMouseFunc(mouseDown);     // ���ص�
    glutPassiveMotionFunc(passiveMouseMove);  //ָ������ƶ���Ӧ����

    cout<<"�Ҽ�ѡ��˵�"<<endl<<endl;
    //�����Ӳ˵�1
    submenu1=glutCreateMenu(subMenu1);
    glutAddMenuEntry("ֱ��",1);
    glutAddMenuEntry("Բ",2);
    glutAddMenuEntry("��Բ",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //�����Ӳ˵�2
    submenu2=glutCreateMenu(subMenu2);
    glutAddMenuEntry("����ͼ��",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //�����Ӳ˵�3
    submenu3=glutCreateMenu(subMenu3);
    glutAddMenuEntry("ֱ�߶βü�",1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //�����Ӳ˵�4
    submenu4=glutCreateMenu(subMenu4);
    glutAddMenuEntry("ƽ��+��ת+����:������ ",1);
    glutAddMenuEntry("ƽ��+��ת+���ţ�����",2);
    glutAddMenuEntry("��άͼ�α任",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    //�������˵��������Ӳ˵�
    menu=glutCreateMenu(mainMenu);
    glutAddSubMenu("ͼ������",submenu1);
    glutAddSubMenu("ͼ�����",submenu2);
    glutAddSubMenu("ͼ�βü�",submenu3);
    glutAddSubMenu("ͼ�α任",submenu4);
    //glutAddSubMenu("�˳�",submenu5);
    glutAttachMenu(GLUT_RIGHT_BUTTON);


    glutReshapeFunc(changeSize);  //ָ�����ڵ�������

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // ������Ⱦ״̬

    glutMainLoop();

    return EXIT_SUCCESS;
}

//���˵�
void mainMenu(GLint option)
{
    //�Ȼ�ȡ��ǰ�˵�
    //getMenu();
    switch(option)
    {
        case 1: cout<<"ͼ������"<<endl; break;
        case 2: cout<<"ͼ�����"<<endl; break;
        case 3: cout<<"ͼ�βü�"<<endl; break;
        case 4: cout<<"ͼ�α任"<<endl; break;
        case 5: cout<<"�˳�"<<endl; break;
    }
}

//�Ӳ˵�1
void subMenu1(GLint option)
{
    switch(option)
    {
        case 1:
            type=1;
            count=0;
            cout<<endl<<"-------����ֱ��-------"<<endl;
            cout<<endl<<"�������������������ȡɫ"<<endl;
            break;
        case 2:
            type=2;
            count=0;
            cout<<endl<<"--------����Բ--------"<<endl;
            cout<<endl<<"�������������������ȡɫ"<<endl;
            break;
        case 3:
            type=3;
            count=0;
            cout<<endl<<"-------������Բ--------"<<endl;
            cout<<endl<<"�������������������ȡɫ"<<endl;
            break;
    }
    glutPostRedisplay();
}

//�Ӳ˵�2
void subMenu2(GLint option)
{
    switch(option)
    {
    case 1:
        type=4;
        cout<<endl<<"-------���ͼ��-------"<<endl;
        cout<<endl<<"�������������������ȡɫ"<<endl;
        break;
    /*
    case 2:
        type=9;
        count=0;
        cout<<endl<<"--------��Ƥ�����--------"<<endl;
        break;
    */
    }
    glutPostRedisplay();
}

/*
    ƽ�Ʊ任
    �����任���ֲ������任����������任��
    ��ת�任����x�ᡢy�ᡢz�ᡢ�����ᣩ
    �ԳƱ任����������ƽ�桢������ȣ�
    ͶӰ��ƽ��ͶӰ��͸��ͶӰ��
*/

//�Ӳ˵�3
void subMenu3(GLint option)
{
    if(option==1)
    {
        type=8;
        iPositionNum=0;
        count=0;
        XL=XR=YT=YB=0;

        cout<<endl<<"-------�߶βü�-------"<<endl;
        cout<<endl<<"��������������������Ƥ�����"<<endl;
        cout<<endl<<"��������м���ֱ��"<<endl;
    }
    glutPostRedisplay();
}

//�Ӳ˵�4
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

        //��ʼ��
        xt=0;
        yt=0;
        alphat=0;
        multit=0;

        cout<<endl<<"-------ƽ��+��ת+����-------"<<endl;
        cout<<endl<<"��ʹ���������ҷ��������ƽ��"<<endl;
        cout<<"F1˳ʱ����ת  F2��ʱ����ת"<<endl;
        cout<<"F3�������Ŵ�  F4��������С"<<endl;
        cout<<endl<<"ʹ��F9 F10 F11 F12������������λ��"<<endl;
        break;
    case 2:
        type=10;

        //��ʼ��
        xx=0;
        yy=0;
        alpha=0;
        multi=0;

        cout<<endl<<"-------ƽ��+��ת+����-------"<<endl;
        cout<<endl<<"��ʹ���������ҷ��������ƽ��"<<endl;
        cout<<"F1˳ʱ����ת  F2��ʱ����ת"<<endl;
        cout<<"F3�������Ŵ�  F4��������С"<<endl;
        break;

    case 3:
        cout<<"-------��άͼ�α任-------"<<endl;
        cout<<endl<<"ʹ���������ҷ��������ƽ��"<<endl;
        cout<<endl<<"F1,F2��������"<<endl;
        cout<<endl<<"F3:��z����ת  F4:��x��  F5:��y��"<<endl;

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

        glEnable(GL_DEPTH_TEST);//���ر���
        glViewport(0,0,WW,WH);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(-2.0,2.0,-2.0*(GLfloat)WH/(GLfloat)WW,2.0*(GLfloat)WH/(GLfloat)WW,-10.0,10.0);
        glMatrixMode(GL_MODELVIEW);

        break;
    }
    glutPostRedisplay();

}

//�Ӳ˵�5
void subMenu5()
{
    exit(0);
}


//���������
void specialKey(GLint key,GLint x,GLint y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        if(type==5) //ͼ�α任:������
        {
            //cout<<"yt"<<yt<<endl;
            if(yt<=WH-450)
            {
                yt+=20;
            }
            else
            {
                cout<<"���߽��ˣ�����"<<endl;
            }
        }
        else if(type==10) ////ͼ�α任:����
        {
            yy+=20;
        }
        else if(type==11) //��άͼ�α任
        {
            //��άͼ��ƽ��
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
                cout<<"���߽��ˣ�����"<<endl;
            }
        }
        else if(type==10)
        {
            yy-=20;
        }
        else if(type==11)
        {
            //cout<<"down"<<endl;
            //��άͼ��ƽ��
            //ddy-=0.1;
            //��������󻭳�ƽ�ƺ����άͼ��
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
                cout<<"���߽��ˣ�����"<<endl;
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

            //��������󻭳�ƽ�ƺ����άͼ��
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
                cout<<"���߽��ˣ�����"<<endl;
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
            //��������󻭳�ƽ�ƺ����άͼ��
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
            //��������󻭳���С�����άͼ��
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
            //��������󻭳��Ŵ�����άͼ��
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
     case GLUT_KEY_F9:  //�ƶ�������
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

//���ڵ���
void changeSize(GLint newWW,GLint newWH)
{
	glViewport(0,0,newWW,newWH); //ָ��������ʾ����
	glMatrixMode(GL_PROJECTION);//ָ������ͶӰ����
	glLoadIdentity();//���õ�λ����ȥ����ǰ��ͶӰ��������

	gluOrtho2D(0.0,GLfloat(newWW),0.0,GLfloat(newWH));//����ͶӰ����
	display();
	glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    //��ȡɫ��
    if(type==1||type==2||type==3||type==4)
    {
        //ȡɫ������
        glBegin(GL_TRIANGLES);
        glColor3f(1.0f,0.0f,0.0f);
        glVertex2f(450,500);
        glColor3f(0.0f,1.0f,0.0f);
        glVertex2f(550,500);
        glColor3f(0.0f,0.0f,1.0f);
        glVertex2f(500,600);
        glEnd();
    }

    //ͼ�����
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

        //��һ������
        GLfloat graph4[4][3]={{165,380,1},{240,380,1},{240,320,1},{165,320,1}};
        drawLineLoop(graph4,4,boarderColor);

        //��һ������
        GLfloat graph[4][3]={{400,350,1},{600,350,1},{600,150,1},{400,150,1}};
        drawLineLoop(graph,4,boarderColor);

        //������Բ
        Point pl;
        pl.x=460;
        pl.y=290;
        midPointEllipse(pl, 50, 30,boarderColor);

        //������Բ
        Point pr;
        pr.x=540;
        pr.y=290;
        midPointEllipse(pr, 50, 30,boarderColor);

        //��һ��������
        GLfloat graph6[6][3]={{450,150,1},{550,150,1},{580,200,1},{550,250,1},{450,250,1},{420,200,1}};
        drawLineLoop(graph6,6,boarderColor);
    }

    //ͼ�α任
    if(type==5)
    {
        //��������
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1,0x00FF);

        glColor3f(1,1,1);
        glBegin(GL_LINES);
        glVertex2i(coordinate.xaxis.p0.x,coordinate.xaxis.p0.y);
        glVertex2i(coordinate.xaxis.p1.x,coordinate.xaxis.p1.y);

        glVertex2i(coordinate.yaxis.p0.x,coordinate.yaxis.p0.y);
        glVertex2i(coordinate.yaxis.p1.x,coordinate.yaxis.p1.y);
        glEnd();

        //�ر��Զ�������
        glDisable(GL_LINE_STIPPLE);

        Color color={0.3,0.4,0.6};//ƽ��ͼ����ɫ
        Color color1={0.9,0.0,0.9};//��תͼ����ɫ
        Color color2={0.9,0.9,0.0};//����ͼ����ɫ

        //��������󻭳�ƽ�ƺ��ͼ��
        Translate(triangle,3,xt,yt,color);

        //��������󻭳���ת���ͼ��
        Rotate(triangle,3,alphat,color1);

        //����ԭͼ��
        drawLineLoop(triangle,3,boarderColor);

        //��������󻭳����ź��ͼ��
        Scale(triangle,3,multit,multit,color2);
    }

    //ͼ�α任  ����
    if(type==10)
    {
        //��ʼ������ζ��� ����άͼ�Σ�
        GLfloat points[4][3]={{50,50,1},{50,100,1},{200,100,1},{200,50,1}};

        //����ԭͼ
        drawGraphic(points,4);

        //���������ԭͼ��ƽ��
        Translate(points,4,xx,yy,boarderColor);//ƽ��

        for(GLint i=0;i<4;i++)
        {
            points[i][0]+=xx;
            points[i][1]+=yy;
        }

        //��������󻭳���ת���ͼ��
        Rotate(points,4,alpha,boarderColor);
        //��������󻭳��������ź��ͼ��
        Scale(points,4,multi,multi,boarderColor);
    }

    //�߶βü�
    if(type==8)
    {
        //cout<<"here"<<endl;
        GLfloat region[4][3]={{XL,YB,1},{XR,YB,1},{XR,YT,1},{XL,YT,1}};

        //��������  ��Ƥ��
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
        //�Ȼ���ԭ�߶Σ��ٽ��вü�
        drawLine(p1.x,p1.y,p2.x,p2.y);
        CS_LineClip(p1,p2);

        p1.x=80;
        p1.y=330;
        p2.x=230;
        p2.y=490;
        glColor3f (1.0, 0.7, 1.0);
        //�Ȼ���ԭ�߶Σ��ٽ��вü�
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

//���߿�ͼ��
//�������壺��һ��������ͼ�ζ������飬�ڶ��������Ƕ����������������������ɫ
void drawLineLoop(GLfloat a[][3],GLint n,Color color)
{
    glLineWidth(2.0f);//�����߿�
    glBegin(GL_LINE_LOOP);
    glColor3f(color[0],color[1],color[2]);
    for(int i=0;i<n;i++)
    {
        glVertex2f(a[i][0],a[i][1]);
    }
    glEnd();
    glFlush();
}

//����ɫͼ��
//�������壺��һ������a��ָͼ�ζ������飬�ڶ���������ͼ�ζ������
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


// ���Ƶ�
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

// ���Ƶ�
void drawPoint(GLint x,GLint y)
{
    glPointSize(1.0f);
    //glColor3f(fillColor[0], fillColor[1], fillColor[2]);
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

//��ֱ��
void drawLine(GLint x1, GLint y1, GLint x2, GLint y2)
{
    //����ֱ��
    glBegin(GL_LINES);
    //glColor3f(0.0,0.0,1.0);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
    glFlush();
}


//ƽ��(��ά��
//�������壺��һ��������ͼ�ζ������飬�ڶ���������������ͼ�ζ��������������������������ӳͼ��ά�������ĸ�������x����ƽ���������ĸ�������y����ƽ����
void Translate(GLfloat graph[][3],GLint n,GLint dx,GLint dy,Color color)
{
    /*  x����ƽ��X,y����ƽ��Y
    1 0 0
    0 1 0
    X Y 1
    */
    //����ƽ�Ʊ任����
    GLfloat translate[3][3] = {{1,0,0},{0,1,0},{dx,dy,1}};
    GLfloat result[n][3];
    matrixMulti(result,graph,translate,n,3);

    if(n==4)
    {
        drawGraphic(result,n); //ƽ�Ʋ��ı���״
    }
    else
    {
        drawLineLoop(result,3,color);
    }

}

//��ת(��ά��
//�������壺��һ��������ͼ�ζ������飬�ڶ���������ͼ�ζ��������������������ת�Ƕ�
void Rotate(GLfloat graph[][3],GLint n,GLfloat alpha,Color color)
{
    //������������
    GLfloat result1[n][3],result2[n][3],result3[n][3];

    if(n==3)
    {
        drawLine(graph[0][0],graph[0][1],coordinate.yaxis.p0.x,coordinate.xaxis.p0.y);
        //���Ƚ�����ε�һ������ƽ�Ƶ�ԭ��
        GLfloat matrix1[3][3]={{1,0,0},{0,1,0},{-coordinate.yaxis.p0.x,-coordinate.xaxis.p0.y,1}};
        // ����˷�
        matrixMulti(result1,graph,matrix1,n,3);

        /*  ��תalpha�Ƕ�
         cos(alpha)  sin(alpha) 0
        -sin(alpha)  cos(alpha) 0
            0           0       1
        */
        //������ת�任����
        GLfloat rotate[3][3]={{cos(alpha),sin(alpha),0},{-sin(alpha),cos(alpha),0},{0,0,1}};
        //����˷�
        matrixMulti(result2,result1,rotate,n,3);

        //������εĶ���ƽ�ƻ�ԭ��
        GLfloat matrix2[3][3]={{1,0,0},{0,1,0},{coordinate.yaxis.p0.x,coordinate.xaxis.p0.y,1}};
        // ���о���˷�ʵ����ת
        matrixMulti(result3,result2,matrix2,n,3);

        drawLine(result3[0][0],result3[0][1],coordinate.yaxis.p0.x,coordinate.xaxis.p0.y);
        drawLineLoop(result3,n,color);
    }
    else
    {
        GLfloat matrix1[3][3]={{1,0,0},{0,1,0},{-graph[0][0],-graph[0][1],1}};
        // ����˷�
        matrixMulti(result1,graph,matrix1,n,3);

        /*  ��תalpha�Ƕ�
         cos(alpha)  sin(alpha) 0
        -sin(alpha)  cos(alpha) 0
            0           0       1
        */
        //������ת�任����
        GLfloat rotate[3][3]={{cos(alpha),sin(alpha),0},{-sin(alpha),cos(alpha),0},{0,0,1}};

        //����˷�
        matrixMulti(result2,result1,rotate,n,3);

        //������εĶ���ƽ�ƻ�ԭ��
        GLfloat matrix2[3][3]={{1,0,0},{0,1,0},{graph[0][0],graph[0][1],1}};
        // ���о���˷�ʵ����ת
        matrixMulti(result3,result2,matrix2,n,3);

        //������ת֮���ͼ��
        drawGraphic(result3,n);
    }

}

//���ţ���ά��
//�������壺��һ��������ͼ�ζ������飬�ڶ���������ͼ�ζ��������������������x����Ŵ��������ĸ�������y����Ŵ���
void Scale(GLfloat graph[][3],GLint n,GLfloat dx,GLfloat dy,Color color)
{
    GLfloat result1[n][3],result2[n][3],result3[n][3];

    //���Ƚ�����ε�һ������ƽ�Ƶ�ԭ��
    GLfloat matrix1[3][3]={{1,0,0},{0,1,0},{-graph[0][0],-graph[0][1],1}};
    //����˷�
    matrixMulti(result1,graph,matrix1,n,3);

    /*  x�����Ϊԭ����X��,y�����Ϊԭ����Y��
    X 0 0
    0 Y 0
    0 0 1
    */
    GLfloat scale[3][3]={{dx,0,0},{0,dy,0},{0,0,1}};
    matrixMulti(result2,result1,scale,n,3);

    //��ͼ���ƻ�ԭ��λ��
    GLfloat matrix2[3][3]={{1,0,0},{0,1,0},{graph[0][0],graph[0][1],1}};
    //����˷�ʵ��ƽ��
    matrixMulti(result3,result2,matrix2,n,3);

    if(n==4)
    {
        //��������֮���ͼ��
        drawGraphic(result3,n);
    }
    else
    {
        drawLineLoop(result3,n,color);
    }

}

//����˷�����(��ά��
//�������壺aMatrix�Ǿ���bMatrix�;���cMatrix�˷�����Ľ��
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

//����˷�����(��ά��
//�������壺aMatrix�Ǿ���bMatrix�;���cMatrix�˷�����Ľ��
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

//ƽ�ƣ���ά��
//�������壺��һ��������ͼ�ζ������飬�ڶ���������������ͼ�ζ��������������������������ӳͼ��ά�������ĸ�������x����ƽ���������ĸ�������y����ƽ����
void Translate3D(GLfloat graph[][4],GLint n,GLfloat dx,GLfloat dy,GLfloat dz)
{
    /*  x����ƽ��X,y����ƽ��Y,z����ƽ��Z
    1 0 0 0
    0 1 0 0
    0 0 1 0
    X Y Z 1
    */
    //����ƽ�Ʊ任����
    GLfloat translate[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{dx,dy,dz,1}};

    matrixMulti3D(vertices,graph,translate,n,4);

}

//���ţ���ά��
//�������壺��һ��������ͼ�ζ������飬�ڶ���������ͼ�ζ��������������������x����Ŵ��������ĸ�������y����Ŵ���
void Scale3D(GLfloat graph[][4],GLint n,GLfloat dx,GLfloat dy,GLfloat dz)
{
    GLfloat result1[n][4],result2[n][4];

    /*  x�����Ϊԭ����X��,y�����Ϊԭ����Y��
    X 0 0 0
    0 Y 0 0
    0 0 Z 0
    0 0 0 1
    */
    GLfloat scale[4][4]={ {dx,0,0,0}, {0,dy,0,0}, {0,0,dz,0}, {0,0,0,1}};

    matrixMulti3D(vertices,graph,scale,n,4);
}


//��ת(��ά��
//�������壺��һ��������ͼ�ζ������飬�ڶ���������ͼ�ζ��������������������ת�Ƕ�
void Rotate3D(GLfloat graph[][4],GLint n,GLfloat alpha,GLfloat beta,GLfloat gema)
{
    //������������
    GLfloat result1[n][4],result2[n][4],result3[n][4],result4[n][4];

    //���Ƚ�����ε�һ������ƽ�Ƶ�ԭ��
    GLfloat matrix1[8][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    // ����˷�
    matrixMulti3D(result1,graph,matrix1,n,4);

    /*  ��תalpha�Ƕ�
    cos(alpha)  sin(alpha) 0  0
    -sin(alpha) cos(alpha) 0  0
        0           0      1  0
        0           0      0  1
    */
    //������ת�任����
    GLfloat rotate1[4][4]={{cos(alpha),sin(alpha),0,0},{-sin(alpha),cos(alpha),0,0},{0,0,1,0},{0,0,0,1}};
    GLfloat rotate2[4][4]={{1,0,0,0},{0,cos(beta),sin(beta),0},{0,-sin(beta),cos(beta),0},{0,0,0,1}};
    GLfloat rotate3[4][4]={{cos(gema),0,-sin(gema),0},{0,1,0,0},{sin(gema),0,cos(gema),0},{0,0,0,1}};
    //����˷�
    matrixMulti3D(result2,result1,rotate1,n,4);

    matrixMulti3D(result3,result2,rotate2,n,4);

    matrixMulti3D(result4,result3,rotate3,n,4);

    //������εĶ���ƽ�ƻ�ԭ��
    GLfloat matrix2[8][4]={{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    // ���о���˷�ʵ����ת
    matrixMulti3D(vertices,result4,matrix2,n,4);
}

//�ж��Ƿ��ڴ����ڲ�
bool isInside(GLint x,GLint y)
{
    if(x>=0 && y>=0 && x<=WW &&y<=WH)
    {
        return true;
    }
    else
    {
        cout<<"���磡"<<endl;
        return false;
    }
}

// ���������
void mouseDown(GLint btn,GLint state,GLint x,GLint y)
{
    Point point;
    point.x=x;
    point.y=WH-y;

    //����ֱ�߶˵���
    if (type==1 && state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y))
    {
        //ȡɫ
        if(count==0)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"����������ȡɫ������"<<endl;
            }
            else
            {
                cout<<endl<<"�������������ֱ�������˵�"<<endl;
                count++;
            }
        }
        //�����һ���㲻����
        else if(count==1)
        {
            drawPoint(point,color);
            //�洢�õ�
            startPoint=point;
            count++;
        }
        //����ֱ��
        else
        {
            drawPoint(point,color);
            endPoint=point;
            //glClear(GL_COLOR_BUFFER_BIT);
            Bresenham(startPoint,endPoint,color);
            count=0;
        }
    }

    //����Բ�ļ�Բ�ϵ�ĵ��
    //����һ��Բ ��ָ��Բ��Ϊ�����λ��
    Circle circle;
    if (type==2&&state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y))
    {
        //ȡɫ
        if(count==0)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"����������ȡɫ������"<<endl;
            }
            else
            {
                 cout<<endl<<"��������м����Բ�ļ�Բ�߽���һ��λ��"<<endl;
                count++;
            }
        }
        else if(count==1)
        {
            //�洢Բ��
            startPoint = point;
            //����
            drawPoint(startPoint,color);
            count++;
        }
        else if(count==2)
        {
            //cout<<"2"<<endl;
            //�洢�յ�
            endPoint = point;
            drawPoint(endPoint,color);

            circle.pm=startPoint; //Բ��
            circle.r=sqrt( (endPoint.x-startPoint.x)*(endPoint.x-startPoint.x)+(endPoint.y-startPoint.y)*(endPoint.y-startPoint.y) );//�뾶

            //glClear(GL_COLOR_BUFFER_BIT);
            //cout<<circle.pm.x<<" "<<circle.pm.y<<" "<<circle.r<<endl;;
            //�е㻭Բ������Բ
            midPointCircle(circle,color);
            //Bresenham(startPoint,endPoint,color);
            count=0;
        }
    }

    //��Բ����
    if (type==3&& state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y))
    {
        if(count==0)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"����������ȡɫ������"<<endl;
            }
            else
            {
                cout<<endl<<"����������Բ����λ��"<<endl;
                count++;
            }
        }
        else if(count==1)
        {
            //�洢Բ��
            startPoint = point;
            //����
            drawPoint(startPoint,color);
            //glClear(GL_COLOR_BUFFER_BIT);
            midPointEllipse(point, 120, 100, color);
            count=0;
        }
    }

    //�������Բ�ĵ��
    if(type==4 && state == GLUT_DOWN && btn == GLUT_LEFT_BUTTON&&isInside(x,y) )
    {
        if (isFirst)
        {
            getpixel(x,WH-y,color);
            //cout<<color[0]<<" "<<color[1]<<" "<<color[2]<<endl;
            if(isSameColor(color,backgroundColor)==1)
            {
                cout<<endl<<"����������ȡɫ������"<<endl;
            }
            else
            {
                 cout<<endl<<"��ѡ��Ҫ����ͼ��"<<endl;
                 isFirst = false;
            }
        }
        else
        {
            //cout<<"xy"<<x<<" "<<WH-y<<endl;
            if(isLeagle(x,WH-y)==true)
            {
                FloodFill4(x,WH-y,backgroundColor,color); //����������꼰��ɫ
                //ScanLineFill(x,WH-y,boarderColor);
                isFirst=true;
            }
            else
            {
                cout<<"���λ���޿����ͼ�Σ�����"<<endl;
            }
        }
    }

    //�����߶βü�ʱ�ĵ��
    if(type==8)
    {
        if(state == GLUT_DOWN && btn == GLUT_MIDDLE_BUTTON&&isInside(x,y) )
        {
            drawPoint(point,boarderColor);
            //�����һ���㲻����
            if (count==0)
            {
                //�洢�õ�
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
    //��άͼ�α任
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
    //��Բ��
    if( sqrt( (cfill.pm.x-x)*(cfill.pm.x-x)+(cfill.pm.y-y)*(cfill.pm.y-y) ) <= cfill.r )
    {
        cout<<"��Բ��"<<endl;
        return true;
    }
    //�ھ�����
    if( x>=400&&x<=600&&y>=150&&y<=350 )
    {
        cout<<"�ھ�����"<<endl;
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

//ֱ�������㷨
void Bresenham(Point p1,Point p2,Color color)
{
    //Ԥ����
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

//�е㻭Բ��
void midPointCircle(Circle circle,Color color)
{
    GLint x,y;
    GLint e;
    x = 0;
    y = circle.r;
    e = 1 - circle.r;

    //circle.pm��Բ��
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

//Point p��Բ��
void circlePoint(Point p,GLint x,GLint y,Color color)
{
    glPointSize(2.0f);
    glColor3f(color[0],color[1],color[2]);
    glBegin(GL_POINTS);
    //glColor3f(1.0f,0.0f,0.0f);   //��ɫ
    glVertex2f(x+p.x, y+p.y);
    //glColor3f(0.5f,1.0f,0.0f);   //��ɫ
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

//��Բ�����㷨
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

//��ȡ���ص����ɫ
void getpixel(GLint x, GLint y, Color color)
{
    //glCopyPixels(x,y,1,1,GL_RGB);
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

//��drawpoint�ظ�
//���㺯��
void setpixel(GLint x, GLint y,Color c)
{

    glColor3f(c[0],c[1],c[2]);

    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glEnd();
    glFlush();
}

//�Ƚ���ɫ�Ƿ���ͬ
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

//�򵥵���������㷨���ڵ��ʾ��
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

//CohenSutherland�ü��㷨
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

//�Զ˵����
GLint encode(Point p)
{
	GLint c = 0;
	if(p.x < XL) c|=LEFT;
	if(p.x > XR) c|=RIGHT;
	if(p.y < YB) c|=BOTTOM;
	if(p.y > YT) c|=TOP;
	return c;
}

//ɨ������������㷨
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

        while( (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)<=cfill.r*cfill.r )//�������
        {
            drawPoint(x,y);
            x++;
        }
        xr = x - 1;
        x = pt.x - 1;
        while( (x-cfill.pm.x)*(x-cfill.pm.x)+(y-cfill.pm.y)*(y-cfill.pm.y)<=cfill.r*cfill.r )//�������
        {
            drawPoint(x,y);
            x--;
        }
        xl = x + 1;

        //��������һ��ɨ����
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

        //��������һ��ɨ����
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

//���Ʋ�ɫ��������
void colorCube(GLfloat graph[][4])
{
    //cout<<"��������"<<endl;
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

//���ƶ�������ñ������б�
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

//��ת������
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


