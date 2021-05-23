/*
 * Window.h
 *
 *  Created on: 14 окт. 2020 г.
 *      Author: unyuu
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>
#include <GL/gl.h>
#include <GL/glu.h>


class Window
{
public:
    // Размеры окна
	static constexpr int DEFAULT_WIDTH = 1920;
	static constexpr int DEFAULT_HEIGHT = 1080;
protected:
    // Указатель на окно
	std::shared_ptr<SDL_Window> _window;
	// Указатель на контекст OpenGL
	std::shared_ptr<void> _gl_context;

    // Переменные для ширины и высоты окна
	int _width, _height;
public:
    // Конструктор класса Window с установкой ширины/высоты по умолчанию
    Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
    // Дескриптор класса Window
	virtual ~Window() = default;

    // Возвращает размеры окна
	int width() const { return _width; }
	int height() const { return _height; }

	// 	Основной цикл
	void main_loop();

    // Настройка окна
	virtual void setup() { }

    // Рендер
	virtual void render() { }

    // Метод обработки событий
	virtual void handle_event(SDL_Event &event) { }

    // Метод обработки клавиатуры
	virtual void handle_keys(const Uint8 * keys) { }

	// Метод обработки логики
	virtual void handle_logic() { }
};


#endif /* WINDOW_H_ */
