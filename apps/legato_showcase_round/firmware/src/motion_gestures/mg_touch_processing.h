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

#ifndef _MG_TOUCH_PROCESSING_H    /* Guard against multiple inclusion */
#define _MG_TOUCH_PROCESSING_H

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif
    
#define SGRE_FLOAT_FIXED int32_t
#define SGRE_FIX32
    
#if defined(SGRE_FIX32)
typedef SGRE_FLOAT_FIXED SGRE_FLOAT;
#elif defined(SGRE_DOUBLE)
typedef double SGRE_FLOAT;
#else
typedef float SGRE_FLOAT;
#endif
typedef int8_t SGRE_CHAR;
typedef int32_t SGRE_LINT;
typedef int16_t SGRE_SINT;
typedef uint32_t SGRE_ULINT;
typedef uint16_t SGRE_USINT;
typedef bool SGRE_BOOL;
#define SGRE_TRUE true
#define SGRE_FALSE false


typedef enum SGRE_touch_gesture_status_e
{       
    SGRE_TOUCH_GESTURE_ACCEPTED,
    SGRE_TOUCH_GESTURE_REJECTED,
    SGRE_TOUCH_GESTURE_NONE
} SGRE_touch_gesture_status_t;
    

typedef struct SGRE_touch_predict_result_s SGRE_touch_predict_result;


struct SGRE_touch_predict_result_s{
    SGRE_USINT label;
    SGRE_FLOAT confidence;
    SGRE_touch_gesture_status_t status;
};   


/*
 * Collects the touch coordinates
 */
void collect_coordinates(uint16_t x,uint16_t y);
   

/*
 * Collects the touch coordinates
 */
void clear_coordinates(void);
  

/*
 * Processes touch gesture results 
 */
SGRE_touch_predict_result process_touch_gesture_result(void);
    

/*
 * Predict touch gesture from provided gesture points. 
 * @param input Array of SGRE_FLOAT[] coordinates of the gesture. The array 
 * must have an allocated memory of of 2 * capacity * sizeof(SGRE_FLOAT). 
 * The X values are stored at the start of the array (starting at index 0) with 
 * the length of "length" while the Y values are stored starting at index 
 * "capacity" with the length of "length".
 * @param capacity The capacity of the array
 * @param length The number of points
 * @param temp1 Temporary array, of "capacity" size
 * @param temp2 Temporary array, of "capacity" size
 * @param predict_result The returned result
 */    
void touch_predict(void *input, SGRE_USINT capacity, SGRE_USINT length, 
        SGRE_FLOAT temp1[], SGRE_FLOAT temp2[], 
        SGRE_touch_predict_result *predict_result);


/*
 * Convert a unint16_t to a SGRE_FLOAT
 * @param number The number to convert
 * @return The SGRE_FLOAT result
 */
SGRE_FLOAT convert_to_float(uint16_t number);


/*
 * Calculate the distance between two points
 * @param x1 The X coordinate of the first point
 * @param y1 The Y coordinate of the first point
 * @param x2 The X coordinate of the second point
 * @param y2 The Y coordinate of the second point
 * @return 
 */
SGRE_FLOAT calculate_distance(SGRE_FLOAT x1, SGRE_FLOAT y1, SGRE_FLOAT x2, SGRE_FLOAT y2);


/* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _MG_TOUCH_PROCESSING_H */

/* *****************************************************************************
 End of File
 */
