#include "Plane.h"


void Plane::HB1_uart_test(uint8_t msg_id)
{
    switch (msg_id) {
        case 1:
            HB1_uart_test_msg1();
            break;
        case 2:
            HB1_uart_test_msg2();
            break;
        case 3:
            HB1_uart_test_msg3();
            break;
        default:
            break;
    }
}

void Plane::HB1_uart_test_msg1(){
    HB1_mission2apm_v1 &tmp_msg = HB1_uart_mission.get_msg_mission2apm_v1();
    tmp_msg._msg_1.updated = true;
    tmp_msg._msg_1.need_send = true;
    tmp_msg._msg_1.content.msg.header.head_1 = HB1_mission2apm_v1::PREAMBLE1;
    tmp_msg._msg_1.content.msg.header.head_2 = HB1_mission2apm_v1::PREAMBLE2;
    tmp_msg._msg_1.content.msg.header.index = HB1_mission2apm_v1::INDEX1;

    tmp_msg._msg_1.content.msg.console_type = tmp_msg._msg_1.length;
    tmp_msg._msg_1.content.msg.remote_index = 1;
    tmp_msg._msg_1.content.msg.remote_cmd.cmd_wp.line_index = 23;
    tmp_msg._msg_1.content.msg.remote_cmd.cmd_wp.point_index = 33;
    tmp_msg._msg_1.content.msg.remote_cmd.cmd_wp.longitude = 123456;
    tmp_msg._msg_1.content.msg.remote_cmd.cmd_wp.latitude = 654321;
    tmp_msg._msg_1.content.msg.remote_cmd.cmd_wp.alt = 250;
    tmp_msg._msg_1.content.msg.unused[0] = 0;
    tmp_msg._msg_1.content.msg.unused[1] = 0;
    tmp_msg._msg_1.content.msg.unused[2] = 0;
    tmp_msg._msg_1.content.msg.unused[3] = 0;
    tmp_msg._msg_1.content.msg.sum_check = 0;
    
    for (int8_t i = 2; i < tmp_msg._msg_1.length - 1; i++) {
        tmp_msg._msg_1.content.msg.sum_check += tmp_msg._msg_1.content.data[i];
    }
}

void Plane::HB1_uart_test_msg2(){
    HB1_mission2cam &tmp_msg = HB1_uart_mission.get_msg_mission2cam();
    tmp_msg._msg_1.updated = true;
    tmp_msg._msg_1.need_send = true;
    tmp_msg._msg_1.content.msg.header.head_1 = HB1_mission2cam::PREAMBLE1;
    tmp_msg._msg_1.content.msg.header.head_2 = HB1_mission2cam::PREAMBLE2;
    for (int8_t i = 2; i < tmp_msg._msg_1.length - 1; i++) {
        tmp_msg._msg_1.content.data[i] = i;
    }
    tmp_msg._msg_1.content.msg.sum_check = 0;
    
    for (int8_t i = 2; i < tmp_msg._msg_1.length - 1; i++) {
        tmp_msg._msg_1.content.msg.sum_check += tmp_msg._msg_1.content.data[i];
    }
}

void Plane::HB1_uart_test_msg3(){
/*    HB1_UART::YANGUART_MSG_1 tmp_msg = HB1_uart.get_msg_1();
    tmp_msg.updated = true;
    tmp_msg.content.msg.header.head_1 = HB1_UART::PREAMBLE1;
    tmp_msg.content.msg.header.head_2 = HB1_UART::PREAMBLE2;
    tmp_msg.content.msg.header.index = HB1_UART::INDEX1;

    tmp_msg.content.msg.console_type = tmp_msg.length;
    tmp_msg.content.msg.remote_index = 1;
    tmp_msg.content.msg.remote_cmd.cmd_1.p1 = 23;
    tmp_msg.content.msg.remote_cmd.cmd_1.p2 = 33;
    tmp_msg.content.msg.remote_cmd.cmd_1.longitude = 123456;
    tmp_msg.content.msg.remote_cmd.cmd_1.latitude = 654321;
    tmp_msg.content.msg.remote_cmd.cmd_1.alt = 250;
    tmp_msg.content.msg.unused[0] = 0;
    tmp_msg.content.msg.unused[1] = 0;
    tmp_msg.content.msg.unused[2] = 0;
    tmp_msg.content.msg.unused[3] = 0;
    tmp_msg.content.msg.sum_check = 0;
    
    for (int8_t i = 2; i < tmp_msg.length - 1; i++) {
        tmp_msg.content.msg.sum_check += tmp_msg.content.data[i];
    }*/
}