/*
 * I2cCfg.h
 *
 * Created: 10/18/2022 12:01:06 PM
 *  Author: Moumen
 */


#ifndef I2CCFG_H_
#define I2CCFG_H_


/************************************_MACROS_**************************************/
// SELECT SLAVE ADRESS
#define SlAVE_ADDRESS  1
/*

//select general call enable disable
//OPTION 1 -> [1]  enable gen_call
//OPTION 2 -> [0]   disable gen_call

#define GENERAL_CALL 0




// select i2c mode
//OPTION 1 -> [I2C_MASTER]
//OPTION 2 -> [I2C_SLAVE]

#define I2CMODE    I2C_MASTER
*/


/********************************************_SELECT_TWI_MODE_*****************************************/
/*
//option 1 -> [ TWI_MASTER ]
//option 2 -> [ TWI_SLAVE  ]
#define TWI_MODE       TWI_MASTER
*/


/*
 * I2C_MODE OPTIONS : [ I2C_MASTER_MODE , I2C_SLAVE_MODE ]
 */
#define I2C_MODE        I2C_MASTER_MODE
/*
 * SELECT SLAVE ADDRESS OPTIONS : [ 1 -> 119 ]
 */
#define SLAVE_ADDRESS           1
/*
 * GENERAL_CALL_RESPONSE OPTIONS : [ 0 , 1 ]
 */
#define GENERAL_CALL_RESPONSE   0



#endif /* I2CCFG_H_ */
