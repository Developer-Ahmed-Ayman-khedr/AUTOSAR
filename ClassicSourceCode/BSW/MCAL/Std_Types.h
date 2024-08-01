#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Contents of file */

//////////////////////////////////

typedef unsigned char uint8;

typedef unsigned long uint16;

typedef unsigned int uint32;

/////////

typedef signed char sint8;

typedef signed long sint16;

typedef signed int sint32;

//////////////////////////////////

/*This type can be used as standard API return type which is shared between the RTE and the BSW modules.*/
typedef uint8 Std_ReturnType;

#define E_OK                    (Std_ReturnType)0

#define E_NOT_OK                (Std_ReturnType)1

//////////////////////////////////

typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;

}Std_VersionInfoType; /*This type shall be used to request the version of a BSW module using the <Module name>_GetVersionInfo() function.*/

//////////////////////////////////

typedef uint8 Std_TransformerErrorCode; /*The values are specified for each transformer class in ASWS_TransformerGeneral.*/

//////////////////////////////////

typedef enum
{
    STD_TRANSFORMER_UNSPECIFIED = 0x00, /*Transformer of a unspecified transformer class.*/

    STD_TRANSFORMER_SERIALIZER = 0x01, /*Transformer of a serializer class.*/

    STD_TRANSFORMER_SAFETY = 0x02, /*Transformer of a safety class.*/

    STD_TRANSFORMER_SECURITY = 0x03, /*Transformer of a security class.*/

    STD_TRANSFORMER_CUSTOM = 0xFF /*Transformer of a custom class not standardized by AUTOSAR.*/

}Std_TransformerClass;

//////////////////////////////////

typedef struct 
{
    Std_TransformerErrorCode errorCode;

    Std_TransformerClass transformerClass; /*The specific meaning of the values of Std_TransformerErrorCode is to be seen for the specific transformer chain for which the data type represents the transformer error.*/

}Std_TransformerError; /*Std_TransformerError represents a transformer error in the context of a certain transformer chain.*/

//////////////////////////////////

typedef uint8 Std_TransformerForwardCode;

#define E_SAFETY_INVALID_REP        (Std_TransformerForwardCode)0x01 /*Repeat the last used sequence number.*/

#define E_SAFETY_INVALID_CRC        (Std_TransformerForwardCode)0x03 /*Generate a deliberately wrong CRC.*/

#define E_SAFETY_INVALID_SEQ        (Std_TransformerForwardCode)0x02 /*Use a wrong sequence number.*/

//////////////////////////////////

typedef uint8 Std_MessageTypeType; /*This type is used to encode the different type of messages. - Currently this encoding is limited to
the distinction between requests and responses in C/S communication.*/

#define STD_MESSAGETYPE_REQUEST     (Std_MessageTypeType)0x00 /*Message type for a request message*/

#define STD_MESSAGETYPE_RESPONSE    (Std_MessageTypeType)0x01 /*Message type for a response message*/

//////////////////////////////////

typedef uint8 Std_MessageResultType; /*This type is used to encode different types of results for response messages. - Currently this
encoding is limited to the distinction between OK and ERROR responses.*/

#define STD_MESSAGERESULT_OK        (Std_MessageResultType)0x00 /*STD_MESSAGERESULT_OK*/
#define STD_MESSAGERESULT_ERROR     (Std_MessageResultType)0x01 /*Messageresult for an ERROR response*/

/*Type for the function pointer to extract the relevant protocol header fields of the message and the type of the message result of a transformer.*/
Std_ReturnType (*Std_ExtractProtocolHeaderFieldsType) (
const uint8* buffer, /*Buffer allocated by the RTE, where the transformed data has to be stored by the transformer*/
uint32 bufferLength, /*Length of the buffer*/
Std_MessageTypeType* messageType, /*Canonical representation of the message type (extracted from the transformers protocol header).*/
Std_MessageResultType* messageResult /*Canonical representation of the message result type (extracted from the transformers protocol header).*/
);

//////////////////////////////////

/*Because E_OK is already defined within OSEK, the symbol E_OK has to be shared.
To avoid name clashes and redefinition problems, the symbols have to be defined in the following way
(approved within implementation):*/
#ifndef STATUSTYPEDEFINED

#define STATUSTYPEDEFINED

#define E_OK 0x00u

typedef unsigned char StatusType; /* OSEK compliance */

#endif

#define E_NOT_OK 0x01u

//////////////////////////////////

#define STD_HIGH 0x01u /* Physical state 5V or 3.3V */

#define STD_LOW 0x00u /* Physical state 0V */

//////////////////////////////////

#define STD_ACTIVE 0x01u /* Logical state active */

#define STD_IDLE 0x00u /* Logical state idle */

//////////////////////////////////

#define STD_ON 0x01u

#define STD_OFF 0x00u

//////////////////////////////////

#define NULL_PTR ((void *)0)

//////////////////////////////////

#endif /* STD_TYPES_H */