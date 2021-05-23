/*
 * ExampleWindow.h
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef MYWINDOW_H_
#define MYWINDOW_H_

#include "Window.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <GL/gl.h>
#include <GL/glu.h>

/*
 * Класс ExampleWindow потомок Window
 * _angle - угол поворота модели
 * _eye_level - высота для просмотра
 *
 * ExampleWindow - конструктор класса
 * ~ExampleWindow - деструктор класса
 * setup() - начальная настройка окна
 * handle_logic() - логика движения
 */

class MyWindow: public Window
{
    public:
        static constexpr int DEFAULT_WIDTH = 1920;
        static constexpr int DEFAULT_HEIGHT = 1080;

    protected:
        double _angle;
        double _eye_level;
        double x = 0;
        double y = 0;
        double z = 0;
        bool nazh = false;
    public:
        MyWindow(
                int width = DEFAULT_WIDTH,
                int height = DEFAULT_HEIGHT);

        virtual ~MyWindow() = default;

        virtual void setup() override;

        virtual void render() override;

        void handle_logic();

        virtual void handle_keys(const Uint8 *keys) override;

        //virtual void handle_event(const SDL_Event &event) override;
};




#endif /* MYWINDOW_H_ */
