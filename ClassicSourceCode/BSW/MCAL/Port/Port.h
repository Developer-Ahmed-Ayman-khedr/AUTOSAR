#ifndef PORT_H
#define PORT_H

#include "Std_Types.h"

typedef struct{

}Port_ConfigType; /*Type of the external data structure containing the initialization data for this module.*/

typedef uint32 Port_PinType; /*Data type for the symbolic name of a port pin.*/

typedef enum {
    PORT_PIN_IN     =   0x00, /*Sets port pin as input.*/
    PORT_PIN_OUT    =  0x01 /*Sets port pin as output.*/
} Port_PinDirectionType; /*Possible directions of a port pin.*/

typedef uint32 Port_PinModeType;

void Port_Init ( /*Initializes the Port Driver module.*/
const Port_ConfigType* ConfigPtr /*Pointer to configuration set.*/
);

void Port_SetPinDirection (/*Sets the port pin direction*/
Port_PinType Pin,/*Port Pin ID number*/
Port_PinDirectionType Direction/*Port Pin Direction*/
);

void Port_RefreshPortDirection ( /*Refreshes port direction.*/
void
);

void Port_GetVersionInfo ( /*Returns the version information of this module.*/
Std_VersionInfoType* versioninfo /*Pointer to where to store the version information of this module.*/
);

void Port_SetPinMode (/*Sets the port pin mode.*/
Port_PinType Pin, /*Port Pin ID number*/
Port_PinModeType Mode /*New Port Pin mode to be set on port pin.*/
);

#endif /*PORT_H*/