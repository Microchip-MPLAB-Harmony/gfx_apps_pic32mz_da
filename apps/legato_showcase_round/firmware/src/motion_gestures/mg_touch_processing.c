/**
 * This software is provided for demo purposes only. You may use this software, 
 * and any derivatives, exclusively for demonstration purposes with Microchip 
 * Technology Inc's (Microchip) products. Motion Gestures retains all ownership 
 * and intellectual property rights in the accompanying software and in all 
 * derivatives hereto. You agree not to remove from view this notice appearing 
 * on the software. You further agree not to adapt, translate, deconstruct, 
 * reverse engineer, decompile, or otherwise derive the source code for the 
 * software. 
 * SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, 
 * APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
 * MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL 
 * MOTION GESTURES BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR 
 * CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO 
 * THE SOFTWARE, HOWEVER CAUSED, EVEN IF MOTION GESTURES HAS BEEN ADVISED OF THE 
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY 
 * LAW, MOTION GESTURE?S TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE 
 * WILL NOT EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MOTION GESTURES
 * FOR THIS SOFTWARE.
 */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "mg_touch_processing.h"
#include "definitions.h"


/*
 * The maximum number of gesture points we are ready to recognize
 */
#define POINTS_DEFAULT_CAPACITY 500


/*
 * input: The array of SGRE_FLOAT that we use to store x and y coordinates. 
 * X coordinates are stored at the beginning of the array, while Y coordinates
 * are store at position+points_capacity
 */
static SGRE_FLOAT input[2*POINTS_DEFAULT_CAPACITY];
static SGRE_FLOAT temp1[POINTS_DEFAULT_CAPACITY];
static SGRE_FLOAT temp2[POINTS_DEFAULT_CAPACITY];


/*
 * The points capacity
 */
static int points_capacity =  POINTS_DEFAULT_CAPACITY;


/*
 * The number of coordinates stored
 */
static int points_length = 0;


/*
 * The minimum distance that a point has to be from another point
 * for us to consider it.
 */
static uint16_t distanceThreshold = 3;


/*
 * Collect Touch Coordinates
 */
void collect_coordinates(uint16_t x,uint16_t y)
{
    //do not collect more points that we have room for
    if(points_length>=points_capacity-1) {
        return;
    }
        
    SGRE_FLOAT xf = convert_to_float(x);
    SGRE_FLOAT yf = convert_to_float(y);

    if(points_length == 0)
    {
        input[points_length] = xf;
        input[points_length+points_capacity] = yf;
        points_length++;
    } 
    else 
    {
        SGRE_FLOAT d = calculate_distance(xf,yf,input[points_length-1],input[points_length+points_capacity-1]);
        if(d > convert_to_float(distanceThreshold))
        {
            input[points_length] = xf;
            input[points_length+points_capacity] = yf;
            points_length++;
        }
    }
}


/*
 * Clear Coordinates
 */
void clear_coordinates(void){
    points_length = 0;
}


/*
 * Initialize Memory Labels to Names
 */
const char init_mem_label2name[16][14] = {
"2",                //0
"Check",            //1
"",                 //2
"",                 //3
"Alpha",            //4
"S",                //5
"",                 //6
"",                 //7
"Star",             //8
"Dummy-M",          //9
"Dummy-S",          //A
"Dummy-S-2",        //B
"Dummy-Check-1",    //C
"Dummy-Check-2",    //D
"Dummy-Alpha",      //E
"M",                //F
};
const char* project_name="Motion_Gestures_Touch_Demo";


/*
 * Process Touch Gesture Result
 */

SGRE_touch_predict_result process_touch_gesture_result(void)
{         
    SGRE_touch_predict_result predict_result;
    
    predict_result.status = SGRE_TOUCH_GESTURE_REJECTED;
    
    //ignore calls with less than 10 points
    if(points_length >= 10)
    {
        touch_predict(input,  points_capacity, points_length, temp1, temp2, &predict_result);
    }

    clear_coordinates();
    
    return predict_result;
}

/* *****************************************************************************
 End of File
 */