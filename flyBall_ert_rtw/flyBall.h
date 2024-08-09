// 
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// 
// File: flyBall.h
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



  #ifndef RTW_HEADER_flyBall_h_
  #define RTW_HEADER_flyBall_h_

                        #include "rtwtypes.h"
        #include "rtw_continuous.h"
        #include "rtw_solver.h"




#include "flyBall_types.h"

#include <cstring>



    


    


    


    
            /* Macros for accessing real-time model data structure */
            

        #ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm) ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm) (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm) (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm) ((rtm)->Timing.t)
#endif


    







    


    


    


    


                    #ifndef ODE4_INTG
        #define ODE4_INTG
        /* ODE4 Integration Data */
        struct ODE4_IntgData {
        real_T *y; /* output */
        real_T *f[4]; /* derivatives */
        };
        #endif



    


    


    


    


    


    

    
    
    




    /* Class declaration for model flyBall */
        class flyBall final 
{
  /* public data and function members */
public:
            
                /* Block signals (default storage) */
                    
        struct B_flyBall_T {
        /*@[31a7*/




                    
                    


                        



                            /*@[319b*/
                            /*@[319c*/
                                   real_T y; /* '<Root>/Gain2' */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[319d*/
                            /*@[319e*/
                                   real_T vy_m; /* '<Root>/vy' */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[319f*/
                            /*@[31a0*/
                                   real_T vy; /* '<Root>/Gain1' */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[31a1*/
                            /*@[31a2*/
                                   real_T reward; /* '<S3>/Switch' */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[31a3*/
                            /*@[31a4*/
                                   real_T ay_c; /* '<Root>/ay' */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[31a5*/
                            /*@[31a6*/
                                   real_T ay; /* '<Root>/Gain' */

                        
                        /*@]*/
                        /*@]*/


                    



/*@]*/
        };

                    
                /* Continuous states (default storage) */
                    struct X_flyBall_T {
                            /*@[31a8*/
                        real_T y_CSTATE; /* '<Root>/y' */
                    /*@]*/
                    /*@[31a9*/
                        real_T vy_CSTATE; /* '<Root>/vy' */
                    /*@]*/
    
        };
            
                                /* State derivatives (default storage) */
                            struct XDot_flyBall_T {
                                /*@[31aa*/
                        real_T y_CSTATE; /* '<Root>/y' */
                    /*@]*/
                    /*@[31ab*/
                        real_T vy_CSTATE; /* '<Root>/vy' */
                    /*@]*/
                };                        
                /* State disabled  */
                    struct XDis_flyBall_T {                            /*@[31ac*/
                        boolean_T y_CSTATE; /* '<Root>/y' */
                    /*@]*/
                    /*@[31ad*/
                        boolean_T vy_CSTATE; /* '<Root>/vy' */
                    /*@]*/
            };            

                        /* Parameters (default storage) */
                struct P_flyBall_T {
                    /*@[31b6*/




                    
                    


                        



                            /*@[31ae*/
                            /*@[31af*/
                                   real_T control; /* Variable: control
  * Referenced by: '<Root>/u'
   */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[31b0*/
                            /*@[31b1*/
                                   real_T target_t; /* Variable: target_t
  * Referenced by: '<S3>/Constant1'
   */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[31b2*/
                            /*@[31b3*/
                                   real_T target_vy; /* Variable: target_vy
  * Referenced by: '<S3>/Constant3'
   */

                        
                        /*@]*/
                        /*@]*/


                    






                    
                    


                        



                            /*@[31b4*/
                            /*@[31b5*/
                                   real_T target_y; /* Variable: target_y
  * Referenced by: '<S3>/Constant2'
   */

                        
                        /*@]*/
                        /*@]*/


                    



/*@]*/
                };

        


            /* Real-time Model Data Structure */
            
    struct RT_MODEL_flyBall_T {
                    const char_T *errorStatus;
                    RTWSolverInfo solverInfo;
        X_flyBall_T *contStates;
                    int_T *periodicContStateIndices;
                    real_T *periodicContStateRanges;
                    real_T *derivs;
                    XDis_flyBall_T *contStateDisabled;
        boolean_T zCCacheNeedsReset;
                    boolean_T derivCacheNeedsReset;
                    boolean_T CTOutputIncnstWithState;
                    real_T odeY[2];
                    real_T odeF[4][2];
                    ODE4_IntgData intgData;

                        /*
        * Sizes:
                * The following substructure contains sizes information
        * for many of the model attributes such as inputs, outputs,
        * dwork, sample times, etc.
         */
 
    struct  {
                    int_T numContStates;
                    int_T numPeriodicContStates;
                    int_T numSampTimes;
            


    } Sizes;

                        /*
        * Timing:
                * The following substructure contains information regarding
        * the timing information for the model.
         */
 
    struct  {
                    uint32_T clockTick0;
                    time_T stepSize0;
                    uint32_T clockTick1;
                    SimTimeStep simTimeStep;
        boolean_T stopRequestedFlag;
                    time_T *t;
                    time_T tArray[2];
            


    } Timing;



            
    };



                /* Copy Constructor */
            flyBall(flyBall const&) = delete;

                /* Assignment Operator */
            flyBall& operator=(flyBall const&) & = delete;

    
    /* Move Constructor */
    flyBall(flyBall &&) = delete;

    /* Move Assignment Operator */
    flyBall& operator=(flyBall &&) = delete;


/* Real-Time Model get method */
flyBall::RT_MODEL_flyBall_T * getRTM();

    void initialize();
    void step();
static     void terminate();
    flyBall();
    ~flyBall();
  /* private data and function members */
private:
    B_flyBall_T flyBall_B;
    static P_flyBall_T flyBall_P;
    X_flyBall_T flyBall_X;
        

    

        /* Continuous states update member function*/
        void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si );





        /* Derivatives member function */
        void flyBall_derivatives();





    /* Real-Time Model */RT_MODEL_flyBall_T flyBall_M;

};



        





    


    


    


    


    


  #endif /* RTW_HEADER_flyBall_h_ */

// 
// File trailer for generated code.
// 
// [EOF]
// 

