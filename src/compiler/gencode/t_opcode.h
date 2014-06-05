#ifndef T_OPCODE_H
#define T_OPCODE_H

enum t_opcode
{
  JUMP, // 0
  EMPC, // 1
  EMPS, // 2
  EMPL, // 3
  EMPG, // 4
  DEPL, // 5
  EMPT, // 6
  DEPT, // 7
  ADD, // 8
  SUB, // 9
  MUL, // 10
  DIV, // 11
  INF, // 12
  INFEQUAL, // 13
  SUP, // 14
  SUPEQUAL, // 15
  CALL, // 16
  PILE, // 17
  FUNCTION, // 18
  INSTRUCTIONS, // 19
  RETURN, // 20
  EXIT, // 21
  PRINT, // 22
  SHOWTAC, // 23
  HIDETAC, // 24
  SHOWCODE, // 25
  HIDECODE, // 26
  SHOWSTATEVM, // 27
  HIDESTATEVM, // 28
  READPOL, // 29
  END, // 30
  EMPTIME, // 31
  IFFALSE, // 32
  CLASS // 32

};

#endif
