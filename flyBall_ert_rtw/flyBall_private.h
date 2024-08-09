// 
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// 
// File: flyBall_private.h
//  
// Code generated for Simulink model 'flyBall'.
// 
// Model version                  : 1.4
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Sun Aug  4 14:55:12 2024
// 
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives: Unspecified
// Validation result: Not run
// 



  #ifndef RTW_HEADER_flyBall_private_h_
  #define RTW_HEADER_flyBall_private_h_

                #include "rtwtypes.h"


#include "flyBall_types.h"



    


    


    


                /* Private macros used by the generated code to access rtModel */
            

        #ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm) (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm) (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val) ((rtm)->Timing.t = (val))
#endif


    




    


    


    


    


    


    


    


    


        /* private model entry point functions */
        extern void     flyBall_derivatives();
    


    


    


    


    


    


    


    


  #endif /* RTW_HEADER_flyBall_private_h_ */

// 
// File trailer for generated code.
// 
// [EOF]
// 

