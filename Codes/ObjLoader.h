/**
* @file         ObjLoader.h
* @brief        This header file contains various functions to load the .obj file and draw it.
* @detail       It contains functions for loading the .obj file and then extracting the information 
*               regarding vertices and faces of the figure. Then using draw functions, it draws the image on the screen.
*               This code only works for .obj files without tringulation.
* @author       Shreeya, Gunpreet and Sriram
* @include      freeglut libraries like <GL/glut.h> to implement OpenGL functions
*/
#include<GL/gl.h>
#include<GL/glut.h>
#include<stdio.h>
#include<bits/stdc++.h>
#include <glm/glm.hpp>
#include<string.h>
#include "ObjLoader.hpp"

using namespace std;
///Variable for drawing Carrot
GLuint Carrot;
///Variable for drawing Chilly
GLuint Chilly;
///Variable for drawing tree
GLuint Tree;
///Variable for drawing Popal Tree
GLuint PopTree;
///Variable for drawing Bottle
GLuint Bottle;

char ch='1';

/**
* @fn           drawRectangle()
* @brief        Function to draw rectangle from the given input points and to color it.
* @parameters   four points( x,y,z ) and the desired rgb values
* @return type  void
*/
void drawRectangle(float x1, float y1, float z1, float x2, float y2, float z2,
    float x3, float y3, float z3, float x4, float y4, float z4,float c1, float c2, float c3)
{
    glBegin(GL_QUADS);
    glColor3f(c1,c2,c3);
    glVertex3f(x1, y1, z1);
    glVertex3f(x2, y2, z2);
    glVertex3f(x3, y3, z3);
    glVertex3f(x4,y4,z4);
    glEnd();
}
/**
* @fn           loadCarrot()
* @brief        Function to load the .obj file for drawing carrot
* @parameters   pointer to the file location
* @return type  void
*/
void loadCarrot(char *fname)
{
    ///File 
    FILE *fp;
    ///Variable to give lines containing 'v'
    int read;
    ///vector to store the vertices
    std::vector< glm::vec3 > vertices;
    ///temporary variable
    char ch;
    Carrot=glGenLists(1);
    fp=fopen(fname,"r"); //opens file in read mode
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    
    glNewList(Carrot, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            glm::vec3 vertex;
            read=fscanf(fp,"%c %f %f %f",&ch,&vertex.x, &vertex.y, &vertex.z);
            if(read==4&&ch=='v')
            {   //if line with 'v' in the first position is encountered then it is stored in vertices vector
                    // and the point is plotted
            
                vertices.push_back(vertex);
                glVertex3f(vertex.x,vertex.y,vertex.z);

            }
           ///temporary variable
            char t;
            ///stores index of vertex 
            int vertexIndex[4];
            ///stores index of up vector
            int uvIndex[4];
            ///checks the number of matching elements
            int matches = fscanf(fp, "%c %d//%d %d//%d %d//%d %d//%d\n", &t, &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2],&vertexIndex[3], &uvIndex[3] );
          
            if(matches==9 && t=='f'){
                //if all matched then draws the face
                drawRectangle(vertices[vertexIndex[0]].x,vertices[vertexIndex[0]].y,vertices[vertexIndex[0]].z
                    ,vertices[vertexIndex[1]].x,vertices[vertexIndex[1]].y,vertices[vertexIndex[1]].z,
                    vertices[vertexIndex[2]].x,vertices[vertexIndex[2]].y,vertices[vertexIndex[2]].z,
                    vertices[vertexIndex[3]].x,vertices[vertexIndex[3]].y,vertices[vertexIndex[3]].z,1,0.5,0);
                
            }
                
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}
/**
* @fn           loadChilly()
* @brief        Function to load the .obj file for drawing red pepper
* @parameters   pointer to the file location
* @return type  void
*/

void loadChilly(char *fname)
{
    ///File 
    FILE *fp;
    ///Variable to give lines containing 'v'
    int read;
    ///vector to store the vertices
    std::vector< glm::vec3 > vertices;
    ///temporary variable
    char ch;
    Chilly=glGenLists(1);
    fp=fopen(fname,"r"); //opens file in read mode
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    
    glNewList(Chilly, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            glm::vec3 vertex;
            read=fscanf(fp,"%c %f %f %f",&ch,&vertex.x, &vertex.y, &vertex.z);
            if(read==4&&ch=='v')
            {   //if line with 'v' in the first position is encountered then it is stored in vertices vector
                    // and the point is plotted
            
                vertices.push_back(vertex);
                glVertex3f(vertex.x,vertex.y,vertex.z);

            }
           ///temporary variable
            char t;
            ///stores index of vertex 
            int vertexIndex[4];
            ///stores index of up vector
            int uvIndex[4];
            ///checks the number of matching elements
            int matches = fscanf(fp, "%c %d//%d %d//%d %d//%d %d//%d\n", &t, &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2],&vertexIndex[3], &uvIndex[3] );
          
            if(matches==9 && t=='f'){
                //if all matched then draws the face
                drawRectangle(vertices[vertexIndex[0]].x,vertices[vertexIndex[0]].y,vertices[vertexIndex[0]].z
                    ,vertices[vertexIndex[1]].x,vertices[vertexIndex[1]].y,vertices[vertexIndex[1]].z,
                    vertices[vertexIndex[2]].x,vertices[vertexIndex[2]].y,vertices[vertexIndex[2]].z,
                    vertices[vertexIndex[3]].x,vertices[vertexIndex[3]].y,vertices[vertexIndex[3]].z,1,0,0.1);
                
            }
                      
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}
/**
* @fn           loadTree()
* @brief        Function to load the .obj file for drawing Tree
* @parameters   pointer to the file location
* @return type  void
*/

void loadTree(char *fname)
{
    ///File 
    FILE *fp;
    ///Variable to give lines containing 'v'
    int read;
    ///vector to store the vertices
    std::vector< glm::vec3 > vertices;
    ///temporary variable
    char ch;
    Tree=glGenLists(1);
    fp=fopen(fname,"r"); //opens file in read mode
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    
    glNewList(Tree, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            glm::vec3 vertex;
            read=fscanf(fp,"%c %f %f %f",&ch,&vertex.x, &vertex.y, &vertex.z);
            if(read==4&&ch=='v')
            {   //if line with 'v' in the first position is encountered then it is stored in vertices vector
                    // and the point is plotted
            
                vertices.push_back(vertex);
                glVertex3f(vertex.x,vertex.y,vertex.z);

            }
           ///temporary variable
            char t;
            ///stores index of vertex 
            int vertexIndex[4];
            ///stores index of up vector
            int uvIndex[4];
            ///checks the number of matching elements
            int matches = fscanf(fp, "%c %d//%d %d//%d %d//%d %d//%d\n", &t, &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2],&vertexIndex[3], &uvIndex[3] );
          
            if(matches==9 && t=='f'){
                //if all matched then draws the face
                drawRectangle(vertices[vertexIndex[0]].x,vertices[vertexIndex[0]].y,vertices[vertexIndex[0]].z
                    ,vertices[vertexIndex[1]].x,vertices[vertexIndex[1]].y,vertices[vertexIndex[1]].z,
                    vertices[vertexIndex[2]].x,vertices[vertexIndex[2]].y,vertices[vertexIndex[2]].z,
                    vertices[vertexIndex[3]].x,vertices[vertexIndex[3]].y,vertices[vertexIndex[3]].z,0,0.5,0);
                
            }
           

            
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}

/**
* @fn           loadPopTree()
* @brief        Function to load the .obj file for drawing PopalTree
* @parameters   pointer to the file location
* @return type  void
*/

void loadPopTree(char *fname)
{
    ///File 
    FILE *fp;
    ///Variable to give lines containing 'v'
    int read;
    ///vector to store the vertices
    std::vector< glm::vec3 > vertices;
    ///temporary variable
    char ch;
    PopTree=glGenLists(1);
    fp=fopen(fname,"r"); //opens file in read mode
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    
    glNewList(PopTree, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            glm::vec3 vertex;
            read=fscanf(fp,"%c %f %f %f",&ch,&vertex.x, &vertex.y, &vertex.z);
            if(read==4&&ch=='v')
            {   //if line with 'v' in the first position is encountered then it is stored in vertices vector
                    // and the point is plotted
            
                vertices.push_back(vertex);
                glVertex3f(vertex.x,vertex.y,vertex.z);

            }
           ///temporary variable
            char t;
            ///stores index of vertex 
            int vertexIndex[4];
            ///stores index of up vector
            int uvIndex[4];
            ///checks the number of matching elements
            int matches = fscanf(fp, "%c %d//%d %d//%d %d//%d %d//%d\n", &t, &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2],&vertexIndex[3], &uvIndex[3] );
          
            if(matches==9 && t=='f'){
                //if all matched then draws the face
                drawRectangle(vertices[vertexIndex[0]].x,vertices[vertexIndex[0]].y,vertices[vertexIndex[0]].z
                    ,vertices[vertexIndex[1]].x,vertices[vertexIndex[1]].y,vertices[vertexIndex[1]].z,
                    vertices[vertexIndex[2]].x,vertices[vertexIndex[2]].y,vertices[vertexIndex[2]].z,
                    vertices[vertexIndex[3]].x,vertices[vertexIndex[3]].y,vertices[vertexIndex[3]].z,0,0.5,0);
                
            }
                       
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}
/**
* @fn           loadBottle()
* @brief        Function to load the .obj file for drawing Bottle
* @parameters   pointer to the file location
* @return type  void
*/

void loadBottle(char *fname)
{
    ///File 
    FILE *fp;
    ///Variable to give lines containing 'v'
    int read;
    ///vector to store the vertices
    std::vector< glm::vec3 > vertices;
    ///temporary variable
    char ch;
    Bottle=glGenLists(1);
    fp=fopen(fname,"r"); //opens file in read mode
    if (!fp)
    {
        printf("can't open file %s\n", fname);
        exit(1);
    }
    
    glNewList(Bottle, GL_COMPILE);
    {
        glPushMatrix();
        glBegin(GL_POINTS);
        while(!(feof(fp)))
        {
            glm::vec3 vertex;
            read=fscanf(fp,"%c %f %f %f",&ch,&vertex.x, &vertex.y, &vertex.z);
            if(read==4&&ch=='v')
            {   //if line with 'v' in the first position is encountered then it is stored in vertices vector
                    // and the point is plotted
            
                vertices.push_back(vertex);
                glVertex3f(vertex.x,vertex.y,vertex.z);

            }
           ///temporary variable
            char t;
            ///stores index of vertex 
            int vertexIndex[4];
            ///stores index of up vector
            int uvIndex[4];
            ///checks the number of matching elements
            int matches = fscanf(fp, "%c %d//%d %d//%d %d//%d %d//%d\n", &t, &vertexIndex[0], &uvIndex[0], &vertexIndex[1], &uvIndex[1], &vertexIndex[2], &uvIndex[2],&vertexIndex[3], &uvIndex[3] );
          
            if(matches==9 && t=='f'){
                //if all matched then draws the face
                drawRectangle(vertices[vertexIndex[0]].x,vertices[vertexIndex[0]].y,vertices[vertexIndex[0]].z
                    ,vertices[vertexIndex[1]].x,vertices[vertexIndex[1]].y,vertices[vertexIndex[1]].z,
                    vertices[vertexIndex[2]].x,vertices[vertexIndex[2]].y,vertices[vertexIndex[2]].z,
                    vertices[vertexIndex[3]].x,vertices[vertexIndex[3]].y,vertices[vertexIndex[3]].z,0,0.4,1);
                
            }
                     
        }
        glEnd();
    }
    glPopMatrix();
    glEndList();
    fclose(fp);
}

//wavefront .obj loader code ends here
/**
* @fn           reshape()
* @brief        Function to initialize and specify window parameters
* @parameters   width and height of viewport
* @return type  void
*/

void reshape(int w,int h)
{
    //specify viewport 
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    //load identity matrix
    glLoadIdentity();
    //specify perspective projection
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 0.1, 1000.0);
    //specify matrix mode
    glMatrixMode(GL_MODELVIEW);
}

/**
* @fn           drawCarrot()
* @brief        Function to draw carrot on the screen
* @parameters   void
* @return type  void
*/
void drawCarrot()
{
    glPushMatrix();
    glPointSize(1.0);
    glColor3f(0,0.5,0);
    glCallList(Carrot);
    glPopMatrix();
        
}

/**
* @fn           drawChilly()
* @brief        Function to draw red pepper on the screen
* @parameters   void
* @return type  void
*/
void drawChilly()
{
    glPushMatrix();
    glColor3f(1,0.2,0);
    glCallList(Chilly);
    glPopMatrix();

        
}
/**
* @fn           drawPoptree()
* @brief        Function to draw Popal tree on the screen
* @parameters   void
* @return type  void
*/
void drawPoptree()
{
    glPushMatrix();
    glColor3f(0,0.5,0);
    glCallList(PopTree);
    glPopMatrix();

        
}
/**
* @fn           drawtree()
* @brief        Function to draw tree on the screen
* @parameters   void
* @return type  void
*/
void drawTree()
{
    glPushMatrix();
    glPointSize(1.0);
    glColor3f(0,0.5,0);
    glCallList(Tree);
    glPopMatrix();      
}
/**
* @fn           drawbottle()
* @brief        Function to draw bottle on the screen
* @parameters   void
* @return type  void
*/
void drawbottle()
{
    glPushMatrix();
    glPointSize(1.0);
    glColor3f(0.2,0,1);
    glCallList(Bottle);
    glPopMatrix();

        
}

//--------------------------------------------------------------------------------------------------