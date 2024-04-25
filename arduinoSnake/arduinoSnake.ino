#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

#ifndef PSTR
#define PSTR
#endif

#define MATRIX_WIDTH 8
#define MATRIX_HEIGHT 8
#define PIN 12

#define GAME_MOV_DELAY 300

#define B1 2
#define B2 3
#define B3 4
#define B4 5

#define UP 1
#define LEFT 4
#define RIGHT 2
#define DOWN 3

#define APPLE_COLOR matrix.Color(255, 0, 0)//roja

#define SNAKE_HEAD matrix.Color(0, 0, 255)//azul
#define SNAKE_BODY matrix.Color(255, 128, 0)//naranja

#define INITIAL_X 4
#define INITIAL_Y 4

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(MATRIX_WIDTH, MATRIX_HEIGHT, PIN, NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT + NEO_MATRIX_ROWS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

int direction = 0;

/*
  1
4   2
  3
*/

int apple[2] = {0, 0};

int snake_head[2] = {INITIAL_X, INITIAL_Y};
int snakeBody[MATRIX_WIDTH * MATRIX_HEIGHT][2] = {};
int bodyLength = 1;

bool isAlive = true;

void setup()
{
  matrix.begin();
  matrix.setBrightness(20);


  pinMode(B1, INPUT_PULLUP);
  pinMode(B2, INPUT_PULLUP);
  pinMode(B3, INPUT_PULLUP);
  pinMode(B4, INPUT_PULLUP);

  randomSeed(analogRead(A0));

  spawnApple();

  matrix.show();
}

void drawSomething(int something[2], uint32_t color)
{
  matrix.drawPixel(something[0], something[1], color);
}

void spawnApple()
{
  do {

  apple[0] = random(0, MATRIX_WIDTH);
  apple[1] = random(0, MATRIX_HEIGHT);
  } while (onSnakeBody(apple));
}

void delay_movement(int t_ms)
{
  long t_i = millis();
  long t_f = t_i + t_ms;

  while (millis() < t_f)
  {
    if (digitalRead(B1) == HIGH && direction != DOWN)
    {
      direction = UP;
    }
    else if (digitalRead(B2) == HIGH && direction != LEFT)
    {
      direction = RIGHT;
    }
    else if (digitalRead(B3) == HIGH && direction != UP)
    {
      direction = DOWN;
    }
    else if (digitalRead(B4) == HIGH && direction != RIGHT)
    {
      direction = LEFT;
    }
  }
}

bool snakeCollide()
{
  for (int i = 1; i < bodyLength; i++)
  {
    if (snake_head[0] == snakeBody[i][0] && snake_head[1] == snakeBody[i][1])
      return true;
  }
  return false;
}

bool onSnakeBody(int something[2])
{
  for (int i = 0; i < bodyLength; i++)
  {
    if (snakeBody[i][0] == something[0] && snakeBody[i][1] == something[1])
      return true;
  }
  return false;
}

void resetGame()
{
  direction = 0;
  bodyLength = 1;
  snake_head[0] = INITIAL_X;
  snake_head[1] = INITIAL_Y;
  spawnApple();
  isAlive = true;
}

void updateSnakeBody()
{
  for(int i = bodyLength - 1; i > 0; i--)
    {
      snakeBody[i][0] = snakeBody[i - 1][0];
      snakeBody[i][1] = snakeBody[i - 1][1];
    }
    snakeBody[0][0] = snake_head[0];
    snakeBody[0][1] = snake_head[1];
}

void drawSnake()
{
  for(int i = 0; i < bodyLength; i++)
  {
   drawSomething(snakeBody[i], SNAKE_BODY); 
  }
  drawSomething(snake_head, SNAKE_HEAD);
}

void displayEndGame()
{
  matrix.fillScreen(matrix.Color(255, 0, 0));
  matrix.show();

  delay(1000);

  matrix.clear();

  for (int i = 4; i > -10; i--)
  {
    matrix.setCursor(i, 1);

    matrix.print(bodyLength - 1);

    matrix.show();
    matrix.clear();

    delay(200);
  }
}


void loop()
{

  while (isAlive)
  {
    delay_movement(GAME_MOV_DELAY);
    matrix.clear();

    switch (direction)
    {
      case UP:
        if (snake_head[1] == 0)
          isAlive = false;
        snake_head[1]--;
        break;
      case RIGHT:
        if (snake_head[0] == MATRIX_WIDTH - 1)
          isAlive = false;
        snake_head[0]++;
        break;
      case DOWN:
        if (snake_head[1] == MATRIX_HEIGHT - 1)
          isAlive = false;
        snake_head[1]++;
        break;
      case LEFT:
        if (snake_head[0] == 0)
          isAlive = false;
        snake_head[0]--;
        break;
    }

    updateSnakeBody();
    drawSnake();

    if (snakeCollide())
    {
      isAlive = false;
    }

    if (snake_head[0] == apple[0] && snake_head[1] == apple[1])
    {
      bodyLength++;
      //snakeBody[apple[0][apple[1] = {};
      spawnApple();
    }
    //spawnApple();
    drawSomething(apple, APPLE_COLOR);
    matrix.show();
  }

  displayEndGame();

  resetGame();

}
