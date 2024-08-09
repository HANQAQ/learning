// 
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// 
// File: flyBall.cpp
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



    
#include "flyBall.h"

#include "rtwtypes.h"

#include "flyBall_private.h"



    


    


    


    


    


    


    


    


    


    


    


    


    


    


    


    








    
        void flyBall::rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
    {
        

            time_T    t    { rtsiGetT(si) };
            time_T    tnew { rtsiGetSolverStopTime(si) };
            time_T    h    { rtsiGetStepSize(si) };
            real_T    *x   { rtsiGetContStates(si) };
            ODE4_IntgData  *id  { static_cast<ODE4_IntgData *>(rtsiGetSolverData(si)) };
            real_T    *y   { id->y };
            real_T    *f0  { id->f[0] };
            real_T    *f1  { id->f[1] };
            real_T    *f2  { id->f[2] };
            real_T    *f3  { id->f[3] };
            real_T    temp;
            int_T     i;
            int_T     nXc  { 2 };

            rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
            

            /* Save the state values at time t in y, we'll use x as ynew. */
            (void) std::memcpy(y, x,
static_cast<uint_T>(nXc)*sizeof(real_T));

            /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
            /* f0 = f(t,y) */
            rtsiSetdX(si, f0);
                        flyBall_derivatives();

            /* f1 = f(t + (h/2), y + (h/2)*f0) */
            temp = 0.5 * h;
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (temp*f0[i]);
            }
            rtsiSetT(si, t + temp);
            rtsiSetdX(si, f1);
            
            


            this->step();


                        flyBall_derivatives();

            
            /* f2 = f(t + (h/2), y + (h/2)*f1) */
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (temp*f1[i]);
            }
            rtsiSetdX(si, f2);
            
            


            this->step();


                        flyBall_derivatives();

            
            /* f3 = f(t + h, y + h*f2) */
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + (h*f2[i]);
            }
            rtsiSetT(si, tnew);
            rtsiSetdX(si, f3);
            
            


            this->step();


                        flyBall_derivatives();

            
            /* tnew = t + h
            ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
            temp = h / 6.0;
            for (i = 0; i < nXc; i++) {
                x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
            }





            rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
            

    }
    

    
    

                

    

                        




        
        
                    
        void flyBall::step() 
        {
            


        

                
        
            
real_T rtb_Clock;
real_T rtb_Gain;
real_T rtb_Square1;
real_T rtb_Square2;
boolean_T OR;

            
            



        

        




                
            

            if (rtmIsMajorTimeStep((&flyBall_M))) {
        
            /* set solver stop time */
        rtsiSetSolverStopTime(&(&flyBall_M)->solverInfo,(((&flyBall_M)->Timing.clockTick0+1)*(&flyBall_M)->Timing.stepSize0));


    

        } /* end MajorTimeStep */
        /* Update absolute time of base rate at minor time step */
        if (rtmIsMinorTimeStep((&flyBall_M))) {
            (&flyBall_M)->Timing.t[0] = rtsiGetT(&(&flyBall_M)->solverInfo);
        }
        





        




                                                    
                
                                    /*@>1b26*/rtb_Clock/*@>7cd*/ = /*@[2f9a*/(&flyBall_M)->Timing.t[0]/*@]*/;
/*@>1b13*/OR/*@>3d0*/ = ((/*@>1b52*/rtb_Clock/*@>10a0*/ >= /*@>1b66*/10.0)/*@>3cf*/ || (/*@>2d9d*/flyBall_X./*@>30e0*/y_CSTATE/*@>10a5*/ <= /*@>1b67*/0.0));
/*@>91c*/if (rtmIsMajorTimeStep((&flyBall_M))/*@>2fc2*/ && /*@>1b28*/OR) {
    /*@[2fa0*/rtmSetStopRequested((&flyBall_M), 1)/*@]*/;
}
/*@>2d16*/flyBall_B./*@>30b3*/y/*@>4b3*/ = /*@>2da3*/flyBall_X./*@>30e3*/y_CSTATE;
/*@>2d1c*/flyBall_B./*@>30b6*/vy_m/*@>808*/ = /*@>2da9*/flyBall_X./*@>30e6*/vy_CSTATE;
/*@>2d22*/flyBall_B./*@>30b9*/vy/*@>568*/ = /*@>2d28*/flyBall_B./*@>30bc*/vy_m;
/*@>820*/if (/*@>1b30*/OR) {
    /*@>1b4e*/rtb_Gain/*@>932*/ = /*@>2d34*/flyBall_B./*@>30c2*/vy/*@>92f*/ - /*@>2d76*/flyBall_P./*@>30d4*/target_vy;
    /*@>1b3e*/rtb_Square2/*@>83c*/ = /*@>1b3c*/rtb_Gain/*@>1baf*/ * /*@>1b3a*/rtb_Gain;
    /*@>1b40*/rtb_Gain/*@>849*/ = (/*@>2d3a*/flyBall_B./*@>30c5*/y/*@>10b0*/ - /*@>2d7c*/flyBall_P./*@>30d7*/target_y)/*@>1bab*/ * /*@>1b69*/0.33333333333333331;
    /*@>1b46*/rtb_Square1/*@>84e*/ = /*@>1b44*/rtb_Gain/*@>1ba7*/ * /*@>1b42*/rtb_Gain;
    /*@>1b48*/rtb_Gain/*@>85b*/ = (/*@>1b5a*/rtb_Clock/*@>10bb*/ - /*@>2d88*/flyBall_P./*@>30dd*/target_t)/*@>1ba3*/ * /*@>1b6a*/10.0;
    /*@>2d52*/flyBall_B./*@>30d1*/reward/*@>81b*/ = ((/*@>1b62*/rtb_Gain/*@>1b9f*/ * /*@>1b64*/rtb_Gain/*@>111a*/ + /*@>1b5e*/rtb_Square1)/*@>1119*/ + /*@>1b60*/rtb_Square2)/*@>1b9b*/ * /*@>1b6b*/-0.01/*@>10d9*/ + /*@>1b6c*/0.5;
} else {
    /*@>2d2e*/flyBall_B./*@>30bf*/reward/*@>81e*/ = /*@>1b68*/-0.001;
}
if (rtmIsMajorTimeStep((&flyBall_M))) {
    /*@>2d40*/flyBall_B./*@>30c8*/ay_c/*@>92d*/ = /*@>2d82*/flyBall_P./*@>30da*/control/*@>1965*/ - 9.8;
    /*@>2d46*/flyBall_B./*@>30cb*/ay/*@>652*/ = /*@>2d4c*/flyBall_B./*@>30ce*/ay_c;
}






        



                




                    

        if (rtmIsMajorTimeStep((&flyBall_M))) {


        
                rt_ertODEUpdateContinuousStates(&(&flyBall_M)->solverInfo);

                        /* Update absolute time for base rate */
                        /* The "clockTick0" counts the number of times the code of this task has
        * been executed. The absolute time is the multiplication of "clockTick0"
        * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
        * overflow during the application lifespan selected.
        */

        ++(&flyBall_M)->Timing.clockTick0; 
  (&flyBall_M)->Timing.t[0] = rtsiGetSolverStopTime(&(&flyBall_M)->solverInfo);


                {
            /* Update absolute timer for sample time: [0.1s, 0.0s] */
                        /* The "clockTick1" counts the number of times the code of this task has
        * been executed. The resolution of this integer timer is 0.1, which is the step size
        * of the task. Size of "clockTick1" ensures timer will not overflow during the
        * application lifespan selected.
        */

        (&flyBall_M)->Timing.clockTick1++;

        }

            





        

    } /* end MajorTimeStep */




        
                    


            




                


        } 
        
                                    
                
        void flyBall::flyBall_derivatives()
        {

            

            
    
flyBall::XDot_flyBall_T *_rtXdot;

    




                                
        
    




                                                
                                    _rtXdot = ((XDot_flyBall_T *) (&flyBall_M)->derivs);
/*@>2dcf*/_rtXdot->/*@>312e*/y_CSTATE/*@>8ab*/ = /*@>2d58*/flyBall_B./*@>3128*/vy_m;
/*@>2dd6*/_rtXdot->/*@>3131*/vy_CSTATE/*@>8b7*/ = /*@>2d5e*/flyBall_B./*@>312b*/ay_c;





    




                
        
                }
        




















    
    
            void flyBall::initialize()
    {
            


    




    
        

        



            /* Registration code */
                
    
        





            
            
        {
            /* Setup solver object */

                rtsiSetSimTimeStepPtr(&(&flyBall_M)->solverInfo, &(&flyBall_M)->Timing.simTimeStep);
            rtsiSetTPtr(&(&flyBall_M)->solverInfo, &rtmGetTPtr((&flyBall_M)));
                rtsiSetStepSizePtr(&(&flyBall_M)->solverInfo, &(&flyBall_M)->Timing.stepSize0);
                rtsiSetdXPtr(&(&flyBall_M)->solverInfo, &(&flyBall_M)->derivs);
                rtsiSetContStatesPtr(&(&flyBall_M)->solverInfo, (real_T **) &(&flyBall_M)->contStates);
                rtsiSetNumContStatesPtr(&(&flyBall_M)->solverInfo, &(&flyBall_M)->Sizes.numContStates);
                    rtsiSetNumPeriodicContStatesPtr(&(&flyBall_M)->solverInfo, &(&flyBall_M)->Sizes.numPeriodicContStates);
                    rtsiSetPeriodicContStateIndicesPtr(&(&flyBall_M)->solverInfo, &(&flyBall_M)->periodicContStateIndices);
                    rtsiSetPeriodicContStateRangesPtr(&(&flyBall_M)->solverInfo, &(&flyBall_M)->periodicContStateRanges);


            rtsiSetErrorStatusPtr(&(&flyBall_M)->solverInfo, (&rtmGetErrorStatus((&flyBall_M))));


            rtsiSetRTModelPtr(&(&flyBall_M)->solverInfo, (&flyBall_M));
        }
            rtsiSetSimTimeStep(&(&flyBall_M)->solverInfo, MAJOR_TIME_STEP);
                    (&flyBall_M)->intgData.y = (&flyBall_M)->odeY;
                    (&flyBall_M)->intgData.f[0] = (&flyBall_M)->odeF[0];
                    (&flyBall_M)->intgData.f[1] = (&flyBall_M)->odeF[1];
                    (&flyBall_M)->intgData.f[2] = (&flyBall_M)->odeF[2];
                    (&flyBall_M)->intgData.f[3] = (&flyBall_M)->odeF[3];
                
                (&flyBall_M)->contStates = ((X_flyBall_T *) &flyBall_X);



                rtsiSetSolverData(&(&flyBall_M)->solverInfo, static_cast<void *>(&(&flyBall_M)->intgData));
                rtsiSetIsMinorTimeStepWithModeChange(&(&flyBall_M)->solverInfo, false);
        rtsiSetSolverName(&(&flyBall_M)->solverInfo,"ode4");





            rtmSetTPtr((&flyBall_M), &(&flyBall_M)->Timing.tArray[0]);







                                (&flyBall_M)->Timing.stepSize0  = 0.1;


                    












        









                



















        















        

    
            
    
        











                                            
                                    

        

                

        

                

        

                

/*@>2daf*/flyBall_X./*@>3197*/y_CSTATE/*@>90c*/ = /*@>1b97*/100.0;
/*@>2db5*/flyBall_X./*@>319a*/vy_CSTATE/*@>919*/ = /*@>1b98*/0.0;













    





                



        
    }        






        




        
        
                    void flyBall::terminate()

        {
            
            /* (no terminate code required) */



                                



                        }
            





    




    

    

     flyBall::flyBall()    :

        flyBall_B(),
flyBall_X(),

            flyBall_M()

    {
            /* Currently there is no constructor body generated.*/
    }


        
            /* Currently there is no destructor body generated.*/
             flyBall::~flyBall() = default;
                    
                    flyBall::RT_MODEL_flyBall_T * flyBall::getRTM() {
                        return (&flyBall_M);
                    }





    


    


    


    


// 
// File trailer for generated code.
// 
// [EOF]
// 

