//
// Created by xinkq on 03/08/22.
//

#ifndef BLUE2DEVCLASS_DEV_CLASS_H
#define BLUE2DEVCLASS_DEV_CLASS_H

#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <bitset>
#include <spdlog/spdlog.h>
#include <iostream>
#include <unistd.h>

enum MAJOR_SERVICE{                        // Bitset of services (look "Assigned Numbers – Bluetooth Baseband” document)
    LIMITED_DISCOVERABLE_MODE = 1 << 13,
    LE_AUDIO                  = 1 << 14,
    RESERVED                  = 1 << 15,    // Reserved for future devices
    POSITIONING               = 1 << 16,    // Location identification
    NETWORKING                = 1 << 17,    // LAN, Ad hoc, ...
    RENDERING                 = 1 << 18,    // Printing, Speakers, ...
    CAPTURING                 = 1 << 19,    // Scanner, Microphone, ...
    OBJECT_TRANSFER           = 1 << 20,    // v-Inbox, v-Folder, ...
    AUDIO                     = 1 << 21,    // Speaker, Microphone, Headset service, ...
    TELEPHONY                 = 1 << 22,    // Cordless telephony, Modem, Headset service, ...
    INFORMATION               = 1 << 23,    // Web-server,WAP-server
};

enum MAJOR_DEVICE{                         // Bitset of major devices
    MISCELANNEOUS             =  0x00,
    COMPUTER                  =  1 << 8,                                                     // Desktop, notebook, PDA, organizer, ...
    PHONE                     =  1 << 9,                                                     // Cellular, cordless, pay phone, modem, ...
    LAN_NETWORK_ACCESS_POINT  = (1 << 8) | (1 << 9),
    AUDIO_VIDEO               =  1 << 10,                                                    // Headset, speaker, stereo, video display, VCR, ...
    PERIPHERAL                = (1 << 10) | (1 << 8),                                        // Mouse, joystick, keyboard, ...
    IMAGING                   = (1 << 10) | (1 << 9),                                        // Printer, scanner, camera, display, ...
    WEARABLE                  = (1 << 10) | (1 << 9) | (1 << 8),
    TOY                       = (1 << 11),
    HEALTH                    = (1 << 11) | (1 << 8),
    UNCATEGORIZED             = (1 << 12) | (1 << 11) | (1 << 10) | (1 << 9) | (1 << 8),     // Device code not specified
};

enum MINOR_COMPUTER{                       // Bitset of minor computer classes
    UNCATEGORIZED_COMP        =  0x00,
    DESKTOP_WORKSTATION       =  1 << 2,
    SERVER_CLASS_COMPUTER     =  1 << 3,
    LAPTOP                    = (1 << 2) | (1 << 3),
    HANDHELD_PC_PDA           =  1 << 4,
    PALM_SIZE_PC_PDA          = (1 << 2) | (1 << 4),
    WEARABLE_COMPUTER         = (1 << 3) | (1 << 4),
    TABLET                    = (1 << 2) | (1 << 3) | (1 << 4),
};

enum MINOR_PHONE{                         // Bitset of minor phone classes
    UNCATEGORIZED_PHONE       =  0x00,
    CELLULAR                  =  1 << 2,
    CORDLESS                  =  1 << 3,
    SMARTPHONE                = (1 << 3) | (1 << 4),
    WIRED_MODEM               =  1 << 4,
    COMMON_ISDN_ACCESS        = (1 << 2) | (1 << 4),
};

enum MINOR_AUDIO_VIDEO{                   // Bitset of minor audio/video classes
    UNCATEGORIZED_A_VIDEO     =  0x00,
    WEARABLE_A_V              =  1 << 2,
    HANDS_FREE                =  1 << 3,
    MICROPHONE                =  1 << 4,
    LOUDSPEAKER               = (1 << 2) | (1 << 4),
    HEADPHONES                = (1 << 3) | (1 << 4),
    PORTABLE_AUDIO            = (1 << 2) | (1 << 3) | (1 << 4),
    CAR_AUDIO                 =  1 << 5,
    SET_TOP_BOX               = (1 << 2) | (1 << 5),
    HIFI_AUDIO                = (1 << 3) | (1 << 5),
    VCR                       = (1 << 2) | (1 << 3) | (1 << 5),
    VIDEO_CAMERA              = (1 << 4) | (1 << 5),
    CAMCORDER                 = (1 << 2) | (1 << 4) | (1 << 5),
    VIDEO_MONITOR             = (1 << 3) | (1 << 4) | (1 << 5),
    VIDEO_DISPLAY_LOUDSPEAKER = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5),
    VIDEO_CONFERENCING        =  1 << 6,
    GAMING_TOY                = (1 << 3) | (1 << 6),
};

enum MINOR_PERIPHERAL{
    UNCATEGORIZED_PERIPHERAL  =  0x00,
    JOYSTICK                  =  1 << 2,
    GAMEPAD                   =  1 << 3,
    REMOTE_CONTROL            = (1 << 2) | (1 << 3),
    SENSING                   =  1 << 4,
    DIGITIZER_TABLET          = (1 << 2) | (1 << 4),
    CARD_READER               = (1 << 3) | (1 << 4),
    DIGITAL_PEN               = (1 << 2) | (1 << 3) | (1 << 4),
    RFID                      =  1 << 5,
    INPUT_HANDHELD            = (1 << 2) | (1 << 5),
    KEYBOARD                  = (1 << 6),
    POINTING_DEV              = (1 << 7),
    KEYBOARD_AND_POINTING     =  KEYBOARD | POINTING_DEV,
};


//other devices minor recognition would be later

enum HCI_ERRS{
    HCI_DEVICE_NOT_FOUND      = 24,
    HCI_SOCK_FAILED           = 32,
    HCI_INQUIRY_FAILED        = 64,
};

enum PARSING{
    PARSED                    = 79,
    PARSE_ERR                 = 86
};

typedef struct minor_cl{                     // Struct with minor device class, if class != UNCATEGORIZED
    MINOR_COMPUTER    minor_comp_class       = UNCATEGORIZED_COMP;
    MINOR_PHONE       minor_phone_class      = UNCATEGORIZED_PHONE;
    MINOR_AUDIO_VIDEO minor_a_video_class    = UNCATEGORIZED_A_VIDEO;
    MINOR_PERIPHERAL  minor_peripheral_class = UNCATEGORIZED_PERIPHERAL;
}minor_cl;



#endif //BLUE2DEVCLASS_DEV_CLASS_H
