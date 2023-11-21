#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MACROS
#define SERVER_IP "127.0.0.1"
#define LOCAL_HOST "127.0.0.1"
#define SERVER_PORT_TO 5002
#define CLIENT_PORT 6001
#define SERVER_PORT 6002
#define CLIENT_PORT_TO 5001
#define PAYLOAD_SIZE 1190
#define WINDOW_SIZE 5
#define TIMEOUT 0.2
#define MAX_SEQUENCE 1190

// Packet Layout
// You may change this if you want to
struct packet {
    packet(uint16_t seqnum, uint16_t acknum, uint8_t last, uint8_t ack, uint32_t length, const char* payload) {
        this->seqnum = seqnum;
        this->seqnum = seqnum;
        this->acknum = acknum;
        this->ack = ack;
        this->last = last;
        this->length = length;
        memcpy(this->payload, payload, length);
    }

    uint16_t seqnum;
    uint16_t acknum; 
    uint8_t ack;
    uint8_t last;
    uint32_t length;
    char payload[PAYLOAD_SIZE];
};

// Utility function to print a packet
void printRecv(packet* pkt) {
    printf("RECV %d %d%s%s\n", pkt->seqnum, pkt->acknum, pkt->last ? " LAST": "", (pkt->ack) ? " ACK": "");
}

void printSend(packet* pkt, int resend) {
    if (resend)
        printf("RESEND %d %d%s%s\n", pkt->seqnum, pkt->acknum, pkt->last ? " LAST": "", pkt->ack ? " ACK": "");
    else
        printf("SEND %d %d%s%s\n", pkt->seqnum, pkt->acknum, pkt->last ? " LAST": "", pkt->ack ? " ACK": "");
}

#endif