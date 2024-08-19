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

///////////////////////////////////////////////////

typedef uint8 Dio_LevelType; /*is the type for the possible levels that a DIO channel can have (input or output)*/

#define STD_LOW     (Dio_LevelType)0x00
#define STD_HIGH    (Dio_LevelType)0x01

typedef uint Dio_PortLevelType; /*is the type for the value of a DIO port.*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Function definitions*/

Dio_LevelType Dio_ReadChannel ( /*Returns the value of the specified DIO channel.*/
Dio_ChannelType ChannelId /*ID of DIO channel*/
);

/* returns
STD_HIGH The physical level of the corresponding Pin is
STD_HIGH
STD_LOW The physical level of the corresponding Pin is STD_LOW*/

///////////////////////////////////////////////////

void Dio_WriteChannel ( /*Service to set a level of a channel.*/
Dio_ChannelType ChannelId, /*ID of DIO channel*/
Dio_LevelType Level /*Value to be written*/
);

/* returns
None
*/

///////////////////////////////////////////////////

Dio_PortLevelType Dio_ReadPort ( /*Returns the level of all channels of that port.*/
Dio_PortType PortId /*ID of DIO Port*/
);

/* returns
Dio_PortLevelType Level of all channels of that port
*/

///////////////////////////////////////////////////

void Dio_WritePort ( /*Service to set a value of the port.*/
Dio_PortType PortId, /*ID of DIO Port*/
Dio_PortLevelType Level /*Value to be written*/
);

/* returns
None
*/

///////////////////////////////////////////////////

Dio_PortLevelType Dio_ReadChannelGroup ( /*This Service reads a subset of the adjoining bits of a port.*/
const Dio_ChannelGroupType* ChannelGroupIdPtr /*Pointer to ChannelGroup*/
);

/* returns
Dio_PortLevelType Level of a subset of the adjoining bits of a port
*/

///////////////////////////////////////////////////

void Dio_WriteChannelGroup ( /*Service to set a subset of the adjoining bits of a port to a specified level.*/
const Dio_ChannelGroupType* ChannelGroupIdPtr, /*Pointer to ChannelGroup*/
Dio_PortLevelType Level /*Value to be written*/
);

/* returns
None
*/

///////////////////////////////////////////////////

void Dio_GetVersionInfo ( /*Service to get the version information of this module.*/
Std_VersionInfoType* VersionInfo /*Pointer to where to store the version information of this module.*/
);

/* returns
None
*/

///////////////////////////////////////////////////

Dio_LevelType Dio_FlipChannel ( /*Service to flip (change from 1 to 0 or from 0 to 1) the level of a channel and return the level of
the channel after flip.*/
Dio_ChannelType ChannelId /*ID of DIO channel*/
);

/* returns
STD_HIGH: The physical level of the corresponding Pin is STD_HIGH.
STD_LOW: The physical level of the corresponding Pin is STD_LOW. 
*/

///////////////////////////////////////////////////

void Dio_MaskedWritePort ( /*Service to set the value of a given port with required mask.*/
Dio_PortType PortId, /*ID of DIO Port*/
Dio_PortLevelType Level, /*Value to be written*/
Dio_PortLevelType Mask /*Channels to be masked in the port*/
);

/* returns
None
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif /*DIO_H*/