//
// Created by Francesco on 22/10/2020.
//

#include "MeleeWeapon.h"

float MeleeWeapon::getRange() const {
    return range;
}

void MeleeWeapon::setRange(float range) {
    MeleeWeapon::range = range;
}

int MeleeWeapon::getPower() const {
    return power;
}

void MeleeWeapon::setPower(int power) {
    MeleeWeapon::power = power;
}

bool MeleeWeapon::isHit() const {
    return hit;
}

void MeleeWeapon::setHit(bool hit) {
    MeleeWeapon::hit = hit;
}

void MeleeWeapon::shoot() {

}
