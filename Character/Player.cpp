#include "Player.hpp"

void Player::update() {
	if (Input::trigger(Input::W)) {
		move(UP);
	}
	if (Input::trigger(Input::S)) {
		move(DOWN);
	}
	if (Input::trigger(Input::A)) {
		move(LEFT);
	}
	if (Input::trigger(Input::D)) {
		move(RIGHT);
	}
}
