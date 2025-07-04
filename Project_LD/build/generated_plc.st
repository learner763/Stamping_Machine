PROGRAM program0
  VAR
    S1 : BOOL;
    x : BOOL;
    Reset : BOOL;
    Actual_Input_Signal : BOOL;
    Cylinder_2 : BOOL;
    B7 : BOOL;
    Cylinder_1 : BOOL;
    B2 : BOOL;
    y : BOOL;
    B3 : BOOL;
    B4 : BOOL;
    B5 : BOOL;
    B6 : BOOL;
    Cylinder_3 : BOOL;
    CTU0 : CTU;
    CTU1 : CTU;
    TOF0 : TOF;
    CTU2 : CTU;
    TON1 : TON;
    TON0 : TON;
    _TMP_XOR60_OUT : BOOL;
    _TMP_NOT67_OUT : BOOL;
    _TMP_AND61_OUT : BOOL;
    R_TRIG1 : R_TRIG;
    _TMP_GT30_OUT : BOOL;
    _TMP_NOT25_OUT : BOOL;
    R_TRIG2 : R_TRIG;
    _TMP_GT37_OUT : BOOL;
    _TMP_AND39_OUT : BOOL;
    _TMP_SUB38_OUT : INT;
    _TMP_EQ33_OUT : BOOL;
    _TMP_AND40_OUT : BOOL;
    _TMP_NOT41_OUT : BOOL;
    _TMP_EQ49_OUT : BOOL;
    R_TRIG3 : R_TRIG;
    _TMP_XOR57_OUT : BOOL;
  END_VAR

  Cylinder_1 := NOT(y) AND B7 AND Actual_Input_Signal;
  Actual_Input_Signal := S1 OR Actual_Input_Signal AND NOT(Reset);
  TON0(IN := B2, PT := T#4s);
  _TMP_XOR60_OUT := XOR(B2, TON0.Q);
  _TMP_NOT67_OUT := NOT(_TMP_XOR60_OUT);
  _TMP_AND61_OUT := AND(_TMP_NOT67_OUT, TON0.Q, NOT(B6));
  R_TRIG1(CLK := _TMP_AND61_OUT);
  CTU0(CU := R_TRIG1.Q, R := S1, PV := 10);
  _TMP_GT30_OUT := GT(CTU0.CV, 0);
  _TMP_NOT25_OUT := NOT(_TMP_AND61_OUT);
  R_TRIG2(CLK := _TMP_NOT25_OUT);
  CTU1(CU := R_TRIG2.Q, R := S1, PV := 10);
  _TMP_GT37_OUT := GT(CTU1.CV, 0);
  _TMP_AND39_OUT := AND(_TMP_GT30_OUT, _TMP_GT37_OUT);
  _TMP_SUB38_OUT := SUB(CTU0.CV, CTU1.CV);
  _TMP_EQ33_OUT := EQ(_TMP_SUB38_OUT, 0);
  _TMP_AND40_OUT := AND(_TMP_AND39_OUT, _TMP_EQ33_OUT);
  _TMP_NOT41_OUT := NOT(_TMP_AND40_OUT);
  TOF0(IN := _TMP_NOT41_OUT, PT := T#2s);
  _TMP_EQ49_OUT := EQ(TOF0.Q, _TMP_AND40_OUT);
  y := _TMP_EQ49_OUT;
  R_TRIG3(CLK := _TMP_EQ49_OUT);
  CTU2(CU := R_TRIG3.Q, PV := 10);
  x := CTU2.Q;
  TON1(IN := x, PT := T#30s);
  _TMP_XOR57_OUT := XOR(x, TON1.Q);
  Reset := _TMP_XOR57_OUT;
  Cylinder_2 := _TMP_XOR60_OUT;
  Cylinder_3 := _TMP_AND61_OUT;
END_PROGRAM


CONFIGURATION Config0

  RESOURCE Res0 ON PLC
    TASK task0(INTERVAL := T#20ms,PRIORITY := 0);
    PROGRAM instance0 WITH task0 : program0;
  END_RESOURCE
END_CONFIGURATION
