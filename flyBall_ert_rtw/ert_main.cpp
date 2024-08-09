// 
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// 
// File: ert_main.cpp
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



            #include <stdio.h> /* This example main program uses printf/fflush */
    #include "flyBall.h" /* Model header file */



    


    


    


    


    


    


    


    


    


    


        
                
        
        static flyBall flyBall_Obj;  /* Instance of model class */






    


    


    


    


        
void rt_OneStep(void);
void rt_OneStep(void)
    {

                static boolean_T OverrunFlag{ false };


        /* Disable interrupts here */

        /* Check for overrun */
        if (OverrunFlag) {
                                rtmSetErrorStatus(flyBall_Obj.getRTM(), "Overrun");

            return;
        }
        OverrunFlag = true;

        /* Save FPU context here (if necessary) */
        /* Re-enable timer or interrupt here */
        /* Set model inputs here */
        
        /* Step the model */
            



         flyBall_Obj.step();
    /* Get model outputs here */

        



        /* Indicate task complete */
        OverrunFlag = false;

        /* Disable interrupts here */
        /* Restore FPU context here (if necessary) */
        /* Enable interrupts here */

    }

    

    
    int_T main(int_T argc, const char *argv[])
    {


            /* Unused arguments */
            (void)(argc);
            (void)(argv);


        




                
    /* Initialize model */
        flyBall_Obj.initialize();

    

    


        
        


        

            /* Simulating the model step behavior (in non real-time) to
            *  simulate model behavior at stop time.
            */
        while ((rtmGetErrorStatus(flyBall_Obj.getRTM()) == (nullptr)) && !rtmGetStopRequested(flyBall_Obj.getRTM())) {
            rt_OneStep();
        }






                        /* Terminate model */
            flyBall_Obj.terminate();


        


        return 0;
    }



    


    


    


    


// 
// File trailer for generated code.
// 
// [EOF]
// 

