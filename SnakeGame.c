#include <SDL2/SDL.h>
#include <emscripten.h> // For web UI remove it if you want to play it natively.
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <stdio.h>

#define TILE_SIZE 20
#define WIDTH 30
#define HEIGHT 20

typedef struct {
    int x, y;
} Point;

Point snake[WIDTH * HEIGHT];
int snake_len;
Point direction;
Point food;
int score;
int high_score = 0;
bool game_over;
Uint32 last_step_time = 0;
Uint32 game_speed = 150;

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

void update_web_title() {
    char js_code[128];
    snprintf(js_code, sizeof(js_code), "document.title = 'Snake Game | Score: %d | High Score: %d';", score, high_score);
    emscripten_run_script(js_code);
}

void setup() {
    game_over = false;
    score = 0;
    game_speed = 150;
    snake_len = 3;
    snake[0] = (Point){WIDTH / 2, HEIGHT / 2};
    snake[1] = (Point){(WIDTH / 2) - 1, HEIGHT / 2};
    snake[2] = (Point){(WIDTH / 2) - 2, HEIGHT / 2};
    direction = (Point){1, 0};
    food = (Point){rand() % WIDTH, rand() % HEIGHT};
    update_web_title();
}

void handle_input() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            emscripten_cancel_main_loop();
            return;
        } else if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                case SDLK_w:
                    if (direction.y != 1) direction = (Point){0, -1};
                    break;
                case SDLK_DOWN:
                case SDLK_s:
                    if (direction.y != -1) direction = (Point){0, 1};
                    break;
                case SDLK_LEFT:
                case SDLK_a:
                    if (direction.x != 1) direction = (Point){-1, 0};
                    break;
                case SDLK_RIGHT:
                case SDLK_d:
                    if (direction.x != -1) direction = (Point){1, 0};
                    break;
                case SDLK_r:
                    if (game_over) setup();
                    break;
            }
        }
    }
}

void logic() {
    Uint32 current_time = SDL_GetTicks();
    if (current_time - last_step_time < game_speed) {
        return;
    }
    last_step_time = current_time;

    Point tail = snake[snake_len - 1];

    for (int i = snake_len - 1; i > 0; i--) {
        snake[i] = snake[i - 1];
    }

    snake[0].x += direction.x;
    snake[0].y += direction.y;

    if (snake[0].x < 0) snake[0].x = WIDTH - 1;
    if (snake[0].x >= WIDTH) snake[0].x = 0;
    if (snake[0].y < 0) snake[0].y = HEIGHT - 1;
    if (snake[0].y >= HEIGHT) snake[0].y = 0;

    for (int i = 1; i < snake_len; i++) {
        if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
            game_over = true;
        }
    }

    if (snake[0].x == food.x && snake[0].y == food.y) {
        score += 10;
        if (score > high_score) {
            high_score = score;
        }
        update_web_title();
        
        if (game_speed > 50) {
            game_speed -= 5;
        }

        if (snake_len < WIDTH * HEIGHT) {
            snake[snake_len] = tail;
            snake_len++;
        }

        bool on_snake;
        do {
            on_snake = false;
            food = (Point){rand() % WIDTH, rand() % HEIGHT};
            for (int i = 0; i < snake_len; i++) {
                if (snake[i].x == food.x && snake[i].y == food.y) {
                    on_snake = true;
                    break;
                }
            }
        } while (on_snake);
    }
}

void draw() {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);

    if (!game_over) {
        SDL_Rect food_rect = {food.x * TILE_SIZE, food.y * TILE_SIZE, TILE_SIZE - 2, TILE_SIZE - 2};
        SDL_SetRenderDrawColor(renderer, 231, 76, 60, 255);
        SDL_RenderFillRect(renderer, &food_rect);

        for (int i = 0; i < snake_len; i++) {
            SDL_Rect segment = {snake[i].x * TILE_SIZE, snake[i].y * TILE_SIZE, TILE_SIZE - 2, TILE_SIZE - 2};
            if (i == 0) {
                SDL_SetRenderDrawColor(renderer, 46, 204, 113, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 39, 174, 96, 255);
            }
            SDL_RenderFillRect(renderer, &segment);
        }
    } else {
        SDL_SetRenderDrawColor(renderer, 150, 40, 40, 255);
        SDL_RenderClear(renderer);
    }

    SDL_RenderPresent(renderer);
}

void game_loop() {
    handle_input();
    if (!game_over) {
        logic();
    }
    draw();
}

int main() {
    srand(time(NULL));
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE, 0, &window, &renderer);
    setup();
    emscripten_set_main_loop(game_loop, 0, 1);
    return 0;
}
