//
// Created by xinkq on 04/08/22.
//

#include "dev_class.h"
#include "remote_device.h"

//Parsing services and major class
int parse_s_major_bitmask(std :: vector<remote_device> &devices){
    for(auto &i : devices) {
        spdlog::info("Parsing {} {}", i.get_name(), i.get_addr());
        std::bitset<24> dev_bitmask = i.get_class();
        //Parsing device services
        {
            if ((dev_bitmask & std::bitset<24>(LIMITED_DISCOVERABLE_MODE)) != 0) {
                i.set_service(LIMITED_DISCOVERABLE_MODE);
            }
            if ((dev_bitmask & std::bitset<24>(LE_AUDIO)) != 0) {
                i.set_service(LE_AUDIO);
            }
            if ((dev_bitmask & std::bitset<24>(POSITIONING)) != 0) {
                i.set_service(POSITIONING);
            }
            if ((dev_bitmask & std::bitset<24>(NETWORKING)) != 0) {
                i.set_service(NETWORKING);
            }
            if ((dev_bitmask & std::bitset<24>(RENDERING)) != 0) {
                i.set_service(RENDERING);
            }
            if ((dev_bitmask & std::bitset<24>(CAPTURING)) != 0) {
                i.set_service(CAPTURING);

            }
            if ((dev_bitmask & std::bitset<24>(OBJECT_TRANSFER)) != 0) {
                i.set_service(OBJECT_TRANSFER);;
            }
            if ((dev_bitmask & std::bitset<24>(AUDIO)) != 0) {
                i.set_service(AUDIO);
            }
            if ((dev_bitmask & std::bitset<24>(TELEPHONY)) != 0) {
                i.set_service(TELEPHONY);
            }
            if ((dev_bitmask & std::bitset<24>(INFORMATION)) != 0) {
                i.set_service(INFORMATION);
            }
        }
        //Parsing device major class
        {
            if((dev_bitmask & std :: bitset<24>(UNCATEGORIZED)) == std :: bitset<24>(UNCATEGORIZED)){
                i.set_major_class(UNCATEGORIZED);
            }
            else if((dev_bitmask & std :: bitset<24>(COMPUTER)) == std :: bitset<24>(COMPUTER)){
                spdlog :: info("Computer class");
                i.set_major_class(COMPUTER);
            }
            else if((dev_bitmask & std :: bitset<24>(PHONE)) == std :: bitset<24>(PHONE)){
                spdlog :: info("Phone class");
                i.set_major_class(PHONE);
            }
            else if((dev_bitmask & std :: bitset<24>(LAN_NETWORK_ACCESS_POINT)) == std :: bitset<24>(LAN_NETWORK_ACCESS_POINT)){
                spdlog :: info("LAN/Network access point class");
                i.set_major_class(LAN_NETWORK_ACCESS_POINT);
            }
            else if((dev_bitmask & std :: bitset<24>(AUDIO_VIDEO)) == std :: bitset<24>(AUDIO_VIDEO)){
                spdlog :: info("Audio/Video class");
                i.set_major_class(AUDIO_VIDEO);
            }
            else if((dev_bitmask & std :: bitset<24>(PERIPHERAL)) == std :: bitset<24>(PERIPHERAL)){
                spdlog :: info("Peripheral class");
                i.set_major_class(PERIPHERAL);
            }
            else if((dev_bitmask & std :: bitset<24>(IMAGING)) == std :: bitset<24>(IMAGING)){
                spdlog :: info("Imaging class");
                i.set_major_class(IMAGING);
            }
            else if((dev_bitmask & std :: bitset<24>(WEARABLE)) == std :: bitset<24>(WEARABLE)){
                spdlog :: info("Wearable class");
                i.set_major_class(WEARABLE);
            }
            else if((dev_bitmask & std :: bitset<24>(TOY)) == std :: bitset<24>(TOY)){
                spdlog :: info("Toy class");
                i.set_major_class(TOY);
            }
            else if((dev_bitmask & std :: bitset<24>(HEALTH)) == std :: bitset<24>(HEALTH)){
                spdlog :: info("Health class");
                i.set_major_class(HEALTH);
            }
        }
    }
    return 0;
}

int parse_minor_bitmask(std :: vector<remote_device> &devices){
    for(auto &i : devices){
        spdlog :: info("Parsing minor function of device {} {}, class of device: {}",i.get_name(),i.get_addr(),i.major_class_str());
        std :: bitset<24> dev_bitmask = i.get_class();
        switch(i.get_major_dev()){
            case COMPUTER : ;
                {
                    if((dev_bitmask & std :: bitset<24>(DESKTOP_WORKSTATION)) == std :: bitset<24>(DESKTOP_WORKSTATION)){
                        minor_cl minor_class;
                        minor_class.minor_comp_class = DESKTOP_WORKSTATION;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(SERVER_CLASS_COMPUTER)) == std :: bitset<24>(SERVER_CLASS_COMPUTER)){
                        minor_cl minor_class;
                        minor_class.minor_comp_class = SERVER_CLASS_COMPUTER;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(LAPTOP)) == std :: bitset<24>(LAPTOP)){
                        minor_cl minor_class;
                        minor_class.minor_comp_class = LAPTOP;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(HANDHELD_PC_PDA)) == std :: bitset<24>(HANDHELD_PC_PDA)){
                        minor_cl minor_class;
                        minor_class.minor_comp_class = HANDHELD_PC_PDA;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(PALM_SIZE_PC_PDA)) == std :: bitset<24>(PALM_SIZE_PC_PDA)){
                        minor_cl minor_class;
                        minor_class.minor_comp_class = PALM_SIZE_PC_PDA;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(WEARABLE_COMPUTER)) == std :: bitset<24>(WEARABLE_COMPUTER)){
                        minor_cl minor_class;
                        minor_class.minor_comp_class = WEARABLE_COMPUTER;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(TABLET)) == std :: bitset<24>(TABLET)){
                        minor_cl minor_class;
                        minor_class.minor_comp_class = TABLET;
                        i.set_minor_class(minor_class);
                    }
                }
                break;
            case PHONE : ;
                {
                    if((dev_bitmask & std :: bitset<24>(SMARTPHONE)) == std :: bitset<24>(SMARTPHONE)){
                        minor_cl minor_class;
                        minor_class.minor_phone_class = SMARTPHONE;
                        i.set_minor_class(minor_class);
                    }
                    else if((dev_bitmask & std :: bitset<24>(COMMON_ISDN_ACCESS)) == std :: bitset<24>(COMMON_ISDN_ACCESS)){
                        minor_cl minor_class;
                        minor_class.minor_phone_class = COMMON_ISDN_ACCESS;
                        i.set_minor_class(minor_class);
                    }
                    else if((dev_bitmask & std :: bitset<24>(CELLULAR)) == std :: bitset<24>(CELLULAR)){
                        minor_cl minor_class;
                        minor_class.minor_phone_class = CELLULAR;
                        i.set_minor_class(minor_class);
                    }
                    else if((dev_bitmask & std :: bitset<24>(CORDLESS)) == std :: bitset<24>(CORDLESS)){
                        minor_cl minor_class;
                        minor_class.minor_phone_class = CORDLESS;
                        i.set_minor_class(minor_class);
                    }
                    else if((dev_bitmask & std :: bitset<24>(WIRED_MODEM)) == std :: bitset<24>(WIRED_MODEM)){
                        minor_cl minor_class;
                        minor_class.minor_phone_class = WIRED_MODEM;
                        i.set_minor_class(minor_class);
                    }
                    else{
                        spdlog :: info("Minor class:unrecognized\n");
                    }
                }
                break;
            case PERIPHERAL : ;
                {
                    if((dev_bitmask & std :: bitset<24>(JOYSTICK)) == std :: bitset<24>(JOYSTICK)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = JOYSTICK;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(GAMEPAD)) == std :: bitset<24>(GAMEPAD)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = GAMEPAD;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(REMOTE_CONTROL)) == std :: bitset<24>(REMOTE_CONTROL)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = REMOTE_CONTROL;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(SENSING)) == std :: bitset<24>(SENSING)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = SENSING;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(DIGITIZER_TABLET)) == std :: bitset<24>(DIGITIZER_TABLET)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = DIGITIZER_TABLET;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(CARD_READER)) == std :: bitset<24>(CARD_READER)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = CARD_READER;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(DIGITAL_PEN)) == std :: bitset<24>(DIGITAL_PEN)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = DIGITAL_PEN;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(RFID)) == std :: bitset<24>(RFID)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = RFID;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(INPUT_HANDHELD)) == std :: bitset<24>(INPUT_HANDHELD)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = INPUT_HANDHELD;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(KEYBOARD)) == std :: bitset<24>(KEYBOARD)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = KEYBOARD;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(POINTING_DEV)) == std :: bitset<24>(POINTING_DEV)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = POINTING_DEV;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(KEYBOARD_AND_POINTING)) == std :: bitset<24>(KEYBOARD_AND_POINTING)){
                        minor_cl minor_class;
                        minor_class.minor_peripheral_class = KEYBOARD_AND_POINTING;
                        i.set_minor_class(minor_class);
                    }
                }
                break;
            case AUDIO_VIDEO: ;
                {
                    if((dev_bitmask & std :: bitset<24>(VIDEO_DISPLAY_LOUDSPEAKER)) == std :: bitset<24>(VIDEO_DISPLAY_LOUDSPEAKER)){
                        spdlog :: info("Minor class :video display loudspeaker\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = VIDEO_DISPLAY_LOUDSPEAKER;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(WEARABLE_A_V)) == std :: bitset<24>(WEARABLE_A_V)){
                        spdlog :: info("Minor class :wearable\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = WEARABLE_A_V;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(MICROPHONE)) == std :: bitset<24>(MICROPHONE)){
                        spdlog :: info("Minor class :microphone\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = MICROPHONE;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(LOUDSPEAKER)) == std :: bitset<24>(LOUDSPEAKER)){
                        spdlog :: info("Minor loudspeaker :wearable\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = LOUDSPEAKER;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(HEADPHONES)) == std :: bitset<24>(HEADPHONES)){
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = HEADPHONES;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(PORTABLE_AUDIO)) == std :: bitset<24>(PORTABLE_AUDIO)){
                        spdlog :: info("Minor class :portable audio\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = PORTABLE_AUDIO;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(CAR_AUDIO)) == std :: bitset<24>(CAR_AUDIO)){
                        spdlog :: info("Minor class :car audio\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = CAR_AUDIO;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(SET_TOP_BOX)) == std :: bitset<24>(SET_TOP_BOX)){
                        spdlog :: info("Minor class :set top box\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = SET_TOP_BOX;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(HIFI_AUDIO)) == std :: bitset<24>(HIFI_AUDIO)){
                        spdlog :: info("Minor class :hifi audio\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = HIFI_AUDIO;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(VCR)) == std :: bitset<24>(VCR)){
                        spdlog :: info("Minor class :video cassette recorder\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = VCR;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(VIDEO_CAMERA)) == std :: bitset<24>(VIDEO_CAMERA)){
                        spdlog :: info("Minor class :video camera\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = VIDEO_CAMERA;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(CAMCORDER)) == std :: bitset<24>(CAMCORDER)){
                        spdlog :: info("Minor class :camcorder\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = CAMCORDER;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(VIDEO_MONITOR)) == std :: bitset<24>(VIDEO_MONITOR)){
                        spdlog :: info("Minor class :video monitor\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = VIDEO_MONITOR;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(VIDEO_CONFERENCING)) == std :: bitset<24>(VIDEO_CONFERENCING)){
                        spdlog :: info("Minor class :video conferencing\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = VIDEO_CONFERENCING;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(GAMING_TOY)) == std :: bitset<24>(GAMING_TOY)){
                        spdlog :: info("Minor class :gaming toy\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = GAMING_TOY;
                        i.set_minor_class(minor_class);
                    }
                    if((dev_bitmask & std :: bitset<24>(HANDS_FREE)) == std :: bitset<24>(HANDS_FREE)){
                        spdlog :: info("Minor class :hands free\n");
                        minor_cl minor_class;
                        minor_class.minor_a_video_class = HANDS_FREE;
                        i.set_minor_class(minor_class);
                    }
                }
                break;
            case UNCATEGORIZED : ;
                {
                    spdlog :: error("Parsing minor device class,can't recognize device major class");
                }
                break;
            default : ;
                {
                    return PARSE_ERR;
                }
                break;
        }
    }
    return PARSED;
}