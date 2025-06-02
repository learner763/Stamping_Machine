void LOGGER_init__(LOGGER *data__, BOOL retain) {
  __INIT_VAR(data__->EN,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->ENO,__BOOL_LITERAL(TRUE),retain)
  __INIT_VAR(data__->TRIG,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->MSG,__STRING_LITERAL(0,""),retain)
  __INIT_VAR(data__->LEVEL,LOGLEVEL__INFO,retain)
  __INIT_VAR(data__->TRIG0,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void LOGGER_body__(LOGGER *data__) {
  // Control execution
  if (!__GET_VAR(data__->EN)) {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(FALSE));
    return;
  }
  else {
    __SET_VAR(data__->,ENO,,__BOOL_LITERAL(TRUE));
  }
  // Initialise TEMP variables

  if ((__GET_VAR(data__->TRIG,) && !(__GET_VAR(data__->TRIG0,)))) {
    #define GetFbVar(var,...) __GET_VAR(data__->var,__VA_ARGS__)
    #define SetFbVar(var,val,...) __SET_VAR(data__->,var,__VA_ARGS__,val)

   LogMessage(GetFbVar(LEVEL),(char*)GetFbVar(MSG, .body),GetFbVar(MSG, .len));
  
    #undef GetFbVar
    #undef SetFbVar
;
  };
  __SET_VAR(data__->,TRIG0,,__GET_VAR(data__->TRIG,));

  goto __end;

__end:
  return;
} // LOGGER_body__() 





void PROGRAM0_init__(PROGRAM0 *data__, BOOL retain) {
  __INIT_VAR(data__->S1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->X,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->RESET,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->ACTUAL_INPUT_SIGNAL,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CYLINDER_2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B7,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CYLINDER_1,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B2,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->Y,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B3,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B4,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B5,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->B6,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->CYLINDER_3,__BOOL_LITERAL(FALSE),retain)
  CTU_init__(&data__->CTU0,retain);
  CTU_init__(&data__->CTU1,retain);
  TOF_init__(&data__->TOF0,retain);
  CTU_init__(&data__->CTU2,retain);
  TON_init__(&data__->TON1,retain);
  TON_init__(&data__->TON0,retain);
  __INIT_VAR(data__->_TMP_XOR60_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT67_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND61_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG1,retain);
  __INIT_VAR(data__->_TMP_GT30_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT25_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG2,retain);
  __INIT_VAR(data__->_TMP_GT37_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND39_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_SUB38_OUT,0,retain)
  __INIT_VAR(data__->_TMP_EQ33_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_AND40_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_NOT41_OUT,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->_TMP_EQ49_OUT,__BOOL_LITERAL(FALSE),retain)
  R_TRIG_init__(&data__->R_TRIG3,retain);
  __INIT_VAR(data__->_TMP_XOR57_OUT,__BOOL_LITERAL(FALSE),retain)
}

// Code part
void PROGRAM0_body__(PROGRAM0 *data__) {
  // Initialise TEMP variables

  __SET_VAR(data__->,CYLINDER_1,,((!(__GET_VAR(data__->Y,)) && __GET_VAR(data__->B7,)) && __GET_VAR(data__->ACTUAL_INPUT_SIGNAL,)));
  __SET_VAR(data__->,ACTUAL_INPUT_SIGNAL,,(__GET_VAR(data__->S1,) || (__GET_VAR(data__->ACTUAL_INPUT_SIGNAL,) && !(__GET_VAR(data__->RESET,)))));
  __SET_VAR(data__->TON0.,IN,,__GET_VAR(data__->B2,));
  __SET_VAR(data__->TON0.,PT,,__time_to_timespec(1, 0, 4, 0, 0, 0));
  TON_body__(&data__->TON0);
  __SET_VAR(data__->,_TMP_XOR60_OUT,,XOR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->B2,),
    (BOOL)__GET_VAR(data__->TON0.Q,)));
  __SET_VAR(data__->,_TMP_NOT67_OUT,,!(__GET_VAR(data__->_TMP_XOR60_OUT,)));
  __SET_VAR(data__->,_TMP_AND61_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)3,
    (BOOL)__GET_VAR(data__->_TMP_NOT67_OUT,),
    (BOOL)__GET_VAR(data__->TON0.Q,),
    (BOOL)!(__GET_VAR(data__->B6,))));
  __SET_VAR(data__->R_TRIG1.,CLK,,__GET_VAR(data__->_TMP_AND61_OUT,));
  R_TRIG_body__(&data__->R_TRIG1);
  __SET_VAR(data__->CTU0.,CU,,__GET_VAR(data__->R_TRIG1.Q,));
  __SET_VAR(data__->CTU0.,R,,__GET_VAR(data__->S1,));
  __SET_VAR(data__->CTU0.,PV,,10);
  CTU_body__(&data__->CTU0);
  __SET_VAR(data__->,_TMP_GT30_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTU0.CV,),
    (INT)0));
  __SET_VAR(data__->,_TMP_NOT25_OUT,,!(__GET_VAR(data__->_TMP_AND61_OUT,)));
  __SET_VAR(data__->R_TRIG2.,CLK,,__GET_VAR(data__->_TMP_NOT25_OUT,));
  R_TRIG_body__(&data__->R_TRIG2);
  __SET_VAR(data__->CTU1.,CU,,__GET_VAR(data__->R_TRIG2.Q,));
  __SET_VAR(data__->CTU1.,R,,__GET_VAR(data__->S1,));
  __SET_VAR(data__->CTU1.,PV,,10);
  CTU_body__(&data__->CTU1);
  __SET_VAR(data__->,_TMP_GT37_OUT,,GT__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->CTU1.CV,),
    (INT)0));
  __SET_VAR(data__->,_TMP_AND39_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_GT30_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_GT37_OUT,)));
  __SET_VAR(data__->,_TMP_SUB38_OUT,,SUB__INT__INT__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (INT)__GET_VAR(data__->CTU0.CV,),
    (INT)__GET_VAR(data__->CTU1.CV,)));
  __SET_VAR(data__->,_TMP_EQ33_OUT,,EQ__BOOL__INT(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (INT)__GET_VAR(data__->_TMP_SUB38_OUT,),
    (INT)0));
  __SET_VAR(data__->,_TMP_AND40_OUT,,AND__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->_TMP_AND39_OUT,),
    (BOOL)__GET_VAR(data__->_TMP_EQ33_OUT,)));
  __SET_VAR(data__->,_TMP_NOT41_OUT,,!(__GET_VAR(data__->_TMP_AND40_OUT,)));
  __SET_VAR(data__->TOF0.,IN,,__GET_VAR(data__->_TMP_NOT41_OUT,));
  __SET_VAR(data__->TOF0.,PT,,__time_to_timespec(1, 0, 2, 0, 0, 0));
  TOF_body__(&data__->TOF0);
  __SET_VAR(data__->,_TMP_EQ49_OUT,,EQ__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->TOF0.Q,),
    (BOOL)__GET_VAR(data__->_TMP_AND40_OUT,)));
  __SET_VAR(data__->,Y,,__GET_VAR(data__->_TMP_EQ49_OUT,));
  __SET_VAR(data__->R_TRIG3.,CLK,,__GET_VAR(data__->_TMP_EQ49_OUT,));
  R_TRIG_body__(&data__->R_TRIG3);
  __SET_VAR(data__->CTU2.,CU,,__GET_VAR(data__->R_TRIG3.Q,));
  __SET_VAR(data__->CTU2.,PV,,10);
  CTU_body__(&data__->CTU2);
  __SET_VAR(data__->,X,,__GET_VAR(data__->CTU2.Q,));
  __SET_VAR(data__->TON1.,IN,,__GET_VAR(data__->X,));
  __SET_VAR(data__->TON1.,PT,,__time_to_timespec(1, 0, 30, 0, 0, 0));
  TON_body__(&data__->TON1);
  __SET_VAR(data__->,_TMP_XOR57_OUT,,XOR__BOOL__BOOL(
    (BOOL)__BOOL_LITERAL(TRUE),
    NULL,
    (UINT)2,
    (BOOL)__GET_VAR(data__->X,),
    (BOOL)__GET_VAR(data__->TON1.Q,)));
  __SET_VAR(data__->,RESET,,__GET_VAR(data__->_TMP_XOR57_OUT,));
  __SET_VAR(data__->,CYLINDER_2,,__GET_VAR(data__->_TMP_XOR60_OUT,));
  __SET_VAR(data__->,CYLINDER_3,,__GET_VAR(data__->_TMP_AND61_OUT,));

  goto __end;

__end:
  return;
} // PROGRAM0_body__() 





