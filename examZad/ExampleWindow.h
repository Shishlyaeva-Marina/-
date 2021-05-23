/*
 * ExampleWindow.h
 *
 *  Created on: 19 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

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
 * setup() - начальная настройка
 * handle_logic() - логика движения камеры
 */

class ExampleWindow: public Window
{
	public:
		static constexpr int DEFAULT_WIDTH = 1920;
		static constexpr int DEFAULT_HEIGHT = 1080;

	protected:
		double _angle;
		double _eye_level;

	public:
		ExampleWindow(
				int width = DEFAULT_WIDTH,
				int height = DEFAULT_HEIGHT);

		virtual ~ExampleWindow() = default;

		virtual void setup() override;

		virtual void render() override;

		virtual void handle_logic() override;
};




#endif /* EXAMPLEWINDOW_H_ */
