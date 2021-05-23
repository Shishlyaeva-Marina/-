/*
 * ExampleWindow.cc
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#include <cmath>

static constexpr double Pi = acos(-1.);

#include "mywindow.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>


MyWindow::MyWindow(int width, int height)
: Window(800, 600)
{
    _angle = 0.;
    _eye_level = 0.;
}

/*
 *	Цвета
 */
static const float s_material_red[4]     { 1.f, 0.f, 0.f, 1.f };
static const float s_material_green[4]   { 0.f, 1.f, 0.f, 1.f };
static const float s_material_blue[4]    { 0.f, 0.f, 1.f, 1.f };
static const float s_material_cyan[4]    { 0.f, 1.f, 1.f, 1.f };
static const float s_material_magenta[4] { 1.f, 0.f, 1.f, 1.f };
static const float s_materialyellow[4]  { 1.f, 1.f, 0.f, 1.f };

/************************************************************
 *
 * glClearColor - очищает и устанавливает цвет по умолчанию
 * glMatrixMode - режим матрицы видового преобразования
 * gluPerspective - перспективное проецирование
 *
 ************************************************************/
void MyWindow::setup()
{
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glClearColor(0.15f, 0.15f, 0.4f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45., double(width()) / double(height()), 0.01, 20.0);
    glMatrixMode(GL_MODELVIEW);
}


/***********************************************************
 * gluLookAt - координаты, вектор, ось Y камеры
 * glRotated - поворачивает камеру
 * glBegin - начинает отрисовку
 * glEnd - заканчивает отрисовку
 ***********************************************************/
void MyWindow::render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    gluLookAt(
            5., 5., 5. * _eye_level,
            0., 0., 0.,
            0., 0., 1.);

    glRotated(_angle, 1., 0., 1.);

    glBegin(GL_QUADS);


    glNormal3d(  0.,  1.,  0.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
    glVertex3d( -1.,  1. + y,  1. + z);
    glVertex3d(  1. + x,  1. + y,  1. + z);
    glVertex3d(  1. + x,  1. + y, -1.);
    glVertex3d( -1.,  1. + y, -1.);

    glNormal3d(  0., -1.,  0.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
    glVertex3d(  1. + x, -1.,  1. + z);
    glVertex3d( -1., -1.,  1. + z);
    glVertex3d( -1., -1., -1.);
    glVertex3d(  1. + x, -1., -1.);

    glNormal3d(  0.,  0.,  1.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
    glVertex3d( -1.,  1. + y,  1. + z);
    glVertex3d(  1. + x,  1. + y,  1. + z);
    glVertex3d(  1. + x, -1.,  1. + z);
    glVertex3d( -1., -1.,  1. + z);

    glNormal3d(  0.,  0., -1.);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_green);
    glVertex3d(  1. + x,  1. + y, -1);
    glVertex3d( -1.,  1. + y, -1.);
    glVertex3d( -1., -1., -1.);
    glVertex3d(  1. + x, -1., -1.);

    glEnd();

    glBegin(GL_QUADS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, s_material_cyan);
    glVertex3d( -1.,  1. + y,  1. + z);
    glVertex3d(  1. + x,  1. + y,  1. + z);
    glVertex3d(  1. + x,  0.,  2. + z);
    glVertex3d( -1.,  0.,  2. + z);

    glVertex3d(  1. + x,  0., 2. + z);
    glVertex3d( -1.,  0., 2. + z);
    glVertex3d( -1., -1., 1. + z);
    glVertex3d(  1. + x, -1., 1. + z);

    glEnd();



}

void MyWindow::handle_keys(const Uint8 *keys)
{
    if(keys[SDL_SCANCODE_Q]) _angle+=1; // поворот
    if(keys[SDL_SCANCODE_E]) _angle-=1; // поворот
    if(keys[SDL_SCANCODE_1]) x += 0.1;  //Увеличить X
    if(keys[SDL_SCANCODE_3]) y += 0.1;  //Увеличить Y
    if(keys[SDL_SCANCODE_5]) z += 0.1;  //Увеличить Z
    if(keys[SDL_SCANCODE_2]) x -= 0.1;  //Уменьшить X
    if(keys[SDL_SCANCODE_4]) y -= 0.1;  //Уменьшить Y
    if(keys[SDL_SCANCODE_6]) z -= 0.1;  //Уменьшить Z

}
/*
 * handle_logic - для поворота камеры
 */
void MyWindow::handle_logic()
{
    //_angle += 1.;
    if (_angle >= 360.)
        _angle -= 360.;

    _eye_level = cos(_angle / 180. * Pi);
}
