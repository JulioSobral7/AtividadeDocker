#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;

class BouncingBallApp : public App {
public:
    void setup() override;
    void update() override;
    void draw() override;

private:
    vec2 position;
    vec2 velocity;
    float radius;
    float gravity;
};

void BouncingBallApp::setup() {
    position = vec2(getWindowWidth() * 0.5f, getWindowHeight() * 0.5f); // Posiciona a bola no centro da janela
    velocity = vec2(5, -10); // Velocidade inicial da bola
    radius = 30; // Raio da bola
    gravity = 0.4f; // Força de gravidade
}

void BouncingBallApp::update() {
    // Atualiza a posição da bola
    position += velocity;

    // Aplica a gravidade
    velocity.y += gravity;

    // Verifica colisões com as bordas da janela
    if (position.x - radius < 0 || position.x + radius > getWindowWidth()) {
        velocity.x *= -1.0f; // Inverte a direção horizontal
    }
    if (position.y - radius < 0 || position.y + radius > getWindowHeight()) {
        velocity.y *= -0.8f; // Inverte a direção vertical e reduz a velocidade ao quicar
        position.y = std::min(getWindowHeight() - radius, position.y); // Mantém a bola dentro da janela
    }
}

void BouncingBallApp::draw() {
    gl::clear(Color(0, 0, 0)); // Limpa a tela com a cor preta
    gl::color(Color(1, 1, 1)); // Define a cor da bola como branca
    gl::drawSolidCircle(position, radius); // Desenha a bola
}

CINDER_APP(BouncingBallApp, RendererGl)
