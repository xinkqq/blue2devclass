//
// Created by xinkq on 04/08/22.
//

#include "remote_device.h"


remote_device::remote_device(inquiry_info *dev_info,int device) {
    char device_address[20],device_name[255];
    ba2str(&(dev_info->bdaddr),device_address);
    this->public_addr = std :: string(device_address);
    if (hci_read_remote_name_with_clock_offset(
            device,&(dev_info->bdaddr),dev_info->pscan_rep_mode
            ,dev_info->clock_offset,sizeof(device_name), device_name,0) < 0)
    {
        strcpy(device_name, "[unknown]");
    }
    std :: bitset<8> _fs_eights (dev_info->dev_class[0]);    // 0-8 bits
    std :: bitset<8> _eights_sixt (dev_info->dev_class[1]);  // 8-16 bits
    std :: bitset<8> _sixt_twfr (dev_info->dev_class[2]);    // 16-24 bits
    std :: bitset<16> _fs_sixt = concatenate_bitsets(_fs_eights,_eights_sixt);
    this->dev_class = concatenate_bitsets(_fs_sixt,_sixt_twfr);
    this->public_name = std :: string(device_name);
    this->public_addr = std :: string(device_address);
}

remote_device::remote_device(const remote_device &dev) {
    this->dev_class = dev.dev_class;
    this->public_name = dev.public_name;
    this->public_addr = dev.public_addr;
    this->major_class = dev.major_class;
    this->dev_services = dev.dev_services;
}

void remote_device::set_service(MAJOR_SERVICE SERVICE) {
    switch(SERVICE){
        case LIMITED_DISCOVERABLE_MODE : ;
            {
                dev_services.discoverable_mode = true;
            }
            break;
        case LE_AUDIO : ;
            {
                dev_services.le_audio = true;
            }
            break;
        case POSITIONING : ;
            {
                dev_services.positioning = true;
            }
            break;
        case NETWORKING : ;
            {
                dev_services.networking = true;
            }
            break;
        case RENDERING : ;
            {
                dev_services.rendering = true;
            }
            break;
        case CAPTURING : ;
            {
                dev_services.capturing = true;
            }
            break;
        case OBJECT_TRANSFER : ;
            {
                dev_services.object_transfer = true;
            }
            break;
        case AUDIO : ;
            {
                dev_services.audio = true;
            }
            break;
        case TELEPHONY: ;
            {
                dev_services.telephony = true;
            }
            break;
        case INFORMATION: ;
            {
                dev_services.information = true;
            }
            break;
        default : ;
            {

            }
            break;
    }
}

void remote_device::set_major_class(MAJOR_DEVICE CLASS) {
    this->major_class = CLASS;
}

std::string remote_device::major_class_str() {
    switch(major_class){
        case COMPUTER : ;
            {
                return "Computer, notebook";
            }
            break;
        case PHONE : ;
            {
                return "Phone device";
            }
            break;
        case AUDIO_VIDEO : ;
            {
                return "Audio/Video device";
            }
            break;
        case PERIPHERAL : ;
            {
                return "Peripheral device";
            }
            break;
        case MISCELANNEOUS: ;
            {
                return "Miscelanneous";
            }
            break;
        default : ;
            {
                return "Unrecognized";
            }
            break;
    }
    return "Unrecognized";
}


std::string remote_device::minor_class_str() {
    switch(major_class){
        case COMPUTER : ;
            {
                switch(minor_class.minor_comp_class){
                    case UNCATEGORIZED_COMP: ;
                        {
                            return "Uncategorized computer";
                        }
                        break;
                    case DESKTOP_WORKSTATION: ;
                        {
                            return "Desktop workstation";
                        }
                        break;
                    case SERVER_CLASS_COMPUTER: ;
                        {
                            return "Server computer";
                        }
                        break;
                    case LAPTOP: ;
                        {
                            return "Laptop";
                        }
                        break;
                    case HANDHELD_PC_PDA: ;
                        {
                            return "Handheld PC PDA";
                        }
                        break;
                    case PALM_SIZE_PC_PDA: ;
                        {
                            return "Palm suze PC PDA";
                        }
                        break;
                    case WEARABLE_COMPUTER: ;
                        {
                            return "Wearable computer";
                        }
                        break;
                    case TABLET: ;
                        {
                            return "Tablet";
                        }
                        break;
                    default: ;
                        {
                            return "Uncategorized major class";
                        }
                    break;
                }
            }
            break;
        case PHONE : ;
            {
                switch(minor_class.minor_phone_class){
                    case UNCATEGORIZED_PHONE: ;
                        {
                            return "Uncategorized phone";
                        }
                        break;
                    case CELLULAR : ;
                        {
                            return "Cellular";
                        }
                        break;
                    case CORDLESS: ;
                        {
                            return "Cordless";
                        }
                        break;
                    case SMARTPHONE: ;
                        {
                            return "Smartphone";
                        }
                        break;
                    case WIRED_MODEM : ;
                        {
                            return "Wired modem";
                        }
                        break;
                    case COMMON_ISDN_ACCESS: ;
                        {
                            return "Common ISDN access";
                        }
                        break;
                    default: ;
                        {
                            return "Uncategorized major class";
                        }
                        break;
                }
            }
            break;
        case AUDIO_VIDEO : ;
            {
                switch(minor_class.minor_a_video_class){
                    case WEARABLE_A_V: ;
                        {
                            return "Wearable audio/video";
                        }
                        break;
                    case HANDS_FREE: ;
                        {
                            return "Hands free";
                        }
                        break;
                    case MICROPHONE: ;
                        {
                            return "Microphone";
                        }
                        break;
                    case LOUDSPEAKER: ;
                        {
                            return "Loudspeaker";
                        }
                        break;
                    case HEADPHONES: ;
                        {
                            return "Headphones";
                        }
                        break;
                    case CAR_AUDIO: ;
                        {
                            return "Car audio";
                        }
                        break;
                    case SET_TOP_BOX: ;
                        {
                            return "Set top box";
                        }
                        break;
                    case HIFI_AUDIO: ;
                        {
                            return "HIFI audio";
                        }
                        break;
                    case VCR: ;
                        {
                            return "VCR";
                        }
                        break;
                    case VIDEO_CAMERA: ;
                        {
                            return "Video camera";
                        }
                        break;
                    case CAMCORDER: ;
                        {
                            return "Camcorder";
                        }
                        break;
                    case VIDEO_MONITOR: ;
                        {
                            return "Video monitor";
                        }
                        break;
                    case VIDEO_DISPLAY_LOUDSPEAKER: ;
                        {
                            return "Video display loudspeaker";
                        }
                        break;
                    case VIDEO_CONFERENCING: ;
                        {
                            return "Video conferencing";
                        }
                        break;
                    case GAMING_TOY: ;
                        {
                            return "Gaming toy";
                        }
                        break;
                }
            }
            break;
        case PERIPHERAL : ;
            {
                switch(minor_class.minor_peripheral_class){
                    case UNCATEGORIZED_PERIPHERAL: ;
                        {
                            return "Uncategorized";
                        }
                        break;
                    case JOYSTICK: ;
                        {
                            return "Joystick";
                        }
                        break;
                    case GAMEPAD: ;
                        {
                            return "Gamepad";
                        }
                        break;
                    case REMOTE_CONTROL: ;
                        {
                            return "Remote control";
                        }
                        break;
                    case SENSING: ;
                        {
                            return "Sensing";
                        }
                        break;
                    case DIGITIZER_TABLET: ;
                        {
                            return "Digitizer tablet";
                        }
                        break;
                    case CARD_READER: ;
                        {
                            return "Card reader";
                        }
                        break;
                    case DIGITAL_PEN: ;
                        {
                            return "Digital pen";
                        }
                        break;
                    case RFID: ;
                        {
                            return "RFID";
                        }
                        break;
                    case INPUT_HANDHELD: ;
                        {
                            return "Input handheld";
                        }
                        break;
                    case KEYBOARD: ;
                        {
                            return "Keyboard";
                        }
                        break;
                    case POINTING_DEV: ;
                        {
                            return "Pointing device";
                        }
                        break;
                    case KEYBOARD_AND_POINTING: ;
                        {
                            return "Keyboard and pointing";
                        }
                        break;
                    default : ;
                        {
                            return "Uncategorized major class";
                        }
                        break;

                }
            }
            break;
        default : ;
            {
                return "Unrecognized major device class";
            }
            break;
    }
    return "Unrecognized";
}


void remote_device::set_minor_class(minor_cl minor_cl) {
    this->minor_class = minor_cl;
}

std::vector<std::string> remote_device::str_services() {
    std :: vector<std :: string> str_serv;
    str_serv.reserve(10);
    if(dev_services.discoverable_mode){
        str_serv.emplace_back("Discoverable mode");
    }
    if(dev_services.le_audio){
        str_serv.emplace_back("LE Audio");
    }
    if(dev_services.positioning){
        str_serv.emplace_back("Positioning");
    }
    if(dev_services.networking){
        str_serv.emplace_back("Networking");
    }
    if(dev_services.rendering){
        str_serv.emplace_back("Rendering");
    }
    if(dev_services.capturing){
        str_serv.emplace_back("Capturing");
    }
    if(dev_services.object_transfer){
        str_serv.emplace_back("Object transfer");
    }
    if(dev_services.audio){
        str_serv.emplace_back("Audio");
    }
    if(dev_services.telephony){
        str_serv.emplace_back("Telephony");
    }
    if(dev_services.le_audio) {
        str_serv.emplace_back("Information");
    }
    return str_serv;
}