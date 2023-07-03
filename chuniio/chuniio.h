#pragma once
#ifndef WINVER
#define WINVER 0x0602
#endif
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0602
#endif
#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0410
#endif
#ifndef _WIN32_IE
#define _WIN32_IE 0x0700
#endif

#include <windows.h>
#include <windowsx.h>
#include <winuser.h>
#include <stdbool.h>
#include <stdint.h>
#define D2D_USE_C_DEFINITIONS
#ifdef __MINGW32__
#include <d2d1.h>
#else
#ifdef _MSC_VER
#include "3rdparty/d2d1.h"
#else
#error "don't know what to do with d2d1."
#endif
#endif
#pragma comment(lib, "d2d1.lib")

typedef void (*chuni_io_slider_callback_t)(const uint8_t *state);
uint16_t chuni_io_get_api_version(void);
HRESULT chuni_io_jvs_init(void);
void chuni_io_jvs_poll(uint8_t *opbtn, uint8_t *beams);
void chuni_io_jvs_read_coin_counter(uint16_t *total);
void chuni_io_jvs_set_coin_blocker(bool open);
HRESULT chuni_io_led_init(void);
void chuni_io_led_set_colors(void);
HRESULT chuni_io_slider_init(void);
void chuni_io_slider_start(chuni_io_slider_callback_t callback);
void chuni_io_slider_set_leds(const uint8_t *rgb);
void chuni_io_slider_stop(void);
