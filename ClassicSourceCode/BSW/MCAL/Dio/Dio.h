#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"

/* Contents of file */

typedef uint Dio_ChannelType; /*Numeric ID of a DIO channel.*/

typedef uint Dio_PortType; /*Numeric ID of a DIO port.*/

typedef struct 
{
    uint8 mask; /*This element mask which defines the positions of the channel group.*/
    uint8 offset; /*This element shall be the position of the Channel Group on the port, counted from the LSB.*/
    Dio_PortType port; /*This shall be the port on which the Channel group is defined.*/
}Dio_ChannelGroupType; /*Type for the definition of a channel group, which consists of several adjoining channels within a port.*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef uint8 Dio_LevelType; /*is the type for the possible levels that a DIO channel can have (input or output)*/

#define STD_LOW     (Dio_LevelType)0x00
#define STD_HIGH    (Dio_LevelType)0x01

typedef uint Dio_PortLevelType; /*is the type for the value of a DIO port.*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Function definitions*/

#endif /*DIO_H*/