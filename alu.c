#include "alu.h"
#include <stdio.h>

void add(op_size size, byte register_in1, byte register_in2, byte register_out) {

    if (size == BYTE) {
        registers[register_out] = (registers[register_out] & 0xFF00) + registers[register_in1] + registers[register_in2];
    }
    else {
        registers[register_out] = registers[register_in1] + registers[register_in2];
    }
}

void sub(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
      registers[register_out] = (registers[register_out] & 0xFF00) + registers[register_in1] - registers[register_in2];
    }
    else {
        registers[register_out] = registers[register_in1] - registers[register_in2];
    }
}

void and(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
        registers[register_out] = (registers[register_out] & 0b1111111100000000) + (registers[register_in1] & registers[register_in2] & 0b0000000011111111);
    }
    else {
        registers[register_out] = registers[register_in1] & registers[register_in2];
    }
}

void or(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
        registers[register_out] = (registers[register_out] & 0xFF00) + registers[register_in1] | registers[register_in2];
    }
    else {
        registers[register_out] = registers[register_in1] | registers[register_in2];
    }
}

void sal(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
        registers[register_out] = (registers[register_out] & 0xFF00) + registers[register_in1] << registers[register_in2];
    }
    else {
        registers[register_out] = registers[register_in1] << registers[register_in2];
    }
}

void sar(op_size size, byte register_in1, byte register_in2, byte register_out) {
    if (size == BYTE) {
       registers[register_out] = (registers[register_out] & 0xFF00) + (signed short) registers[register_in1] >> registers[register_in2];
    }
    else {
        registers[register_out] = (signed short) registers[register_in1] >> registers[register_in2];
    }
}

void neg(op_size size, byte register_in, byte register_out) {
    if (size == BYTE) {
        registers[register_out] = (registers[register_out] & 0xFF00) + -registers[register_in];
    }
    else {
        registers[register_out] = -registers[register_in];
    }
}


void not(op_size size, byte register_in, byte register_out) {
    if (size == BYTE) {
        
      registers[register_out] = (registers[register_out] & 0xFF00) +  ~registers[register_in];
    }
    else {
        registers[register_out] = ~registers[register_in];

    }
}