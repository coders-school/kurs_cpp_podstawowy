#pragma once

int NWD(int lhs, int rhs) {

    if (lhs < 0) { // switch to positive num
    lhs *= -1;

    }

    if (rhs < 0) { // switch to positive num
    rhs *= -1;

    }

    if (lhs == rhs) {
    return lhs;

    }

    if (lhs == 0) {
    return rhs;

    }

    if (rhs == 0) {
    return lhs;

    }


    int biggerArg = 0;
    int lesserArg = 0;
    int howManyTimes = 0;
    int lastRest = 0;
    int rest = 0;

    lhs > rhs ? biggerArg = lhs : biggerArg = rhs; // set bigger and lesser argument
    lhs > rhs ? lesserArg = rhs : lesserArg = lhs;



    if (!(biggerArg % lesserArg)) { // if greatest common divisor is lesser argument
    return lesserArg;

    }

    do {
    lastRest = rest;

    howManyTimes = biggerArg / lesserArg;

    rest = biggerArg - (lesserArg * howManyTimes);

    biggerArg = lesserArg;
    lesserArg = rest;

    } while (rest != 0);


    return lastRest;

}

int NWW(int lhs, int rhs) {

    return 0;

}
