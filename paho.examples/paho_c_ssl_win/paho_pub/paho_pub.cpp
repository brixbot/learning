#include "stdafx.h"
#include <iostream>
#include <windows.h> 
#include "MQTTAsync.h"

#define BRIXBOT_ADDRESS     "ssl://www.domain.com:8883"	// You have to change it to your broker
#define BRIXBOT_CLIENTID    "paho_c_ssl_win_pub"
#define BRIXBOT_TOPIC       "brixbot example"
#define BRIXBOT_PAYLOAD     "Hello brixbot!"
#define BRIXBOT_QOS         2
#define BRIXBOT_TIMEOUT     10000L
#define BRIXBOT_USER	    "bot"		// You have to change it to a valid user name of your broker
#define BRIXBOT_PASSWORD    "password"	// You have to change it to the user's password

#define BRIXBOT_SERVER_CA_FILE	"../../ssl/ca.crt"
#define BRIXBOT_CLIENT_CRT_FILE	"../../ssl/client.crt"
#define BRIXBOT_CLIENT_KEY_FILE	"../../ssl/client.key"

void onSendDone(void* context, MQTTAsync_successData* response)
{
    std::cout << "Message with token " << response->token
        << " has been delivered.(from response callback)" << std::endl;
}

void onSendFailed(void* context, MQTTAsync_failureData* response)
{
    std::cout << "Failed to send message with token " << response->token
        << ". Error code: " << response->code << std::endl;
}

void onConnected(void* context, MQTTAsync_successData* response)
{
    std::cout << "Connected broker." << std::endl;

    MQTTAsync client = (MQTTAsync)context;
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;
    MQTTAsync_message msg = MQTTAsync_message_initializer;

    opts.onSuccess = onSendDone;
    opts.onFailure = onSendFailed;

    msg.payload = BRIXBOT_PAYLOAD;
    msg.payloadlen = (int)strlen(BRIXBOT_PAYLOAD);
    msg.qos = BRIXBOT_QOS;
    msg.retained = 0;

    std::cout << "Sending message..." << std::endl;

    int rc;
    if ((rc = MQTTAsync_sendMessage(client, BRIXBOT_TOPIC, &msg, &opts))
        != MQTTASYNC_SUCCESS)
    {
        std::cout << "Failed to start sendMessage, return code " << rc << std::endl;
    }
}

void onConnectFailure(void* context, MQTTAsync_failureData* response)
{
    std::cout << "Failed to connect broker!" << std::endl;
}

void onConnectLost(void *context, char *cause)
{
    std::cout << "Broker connection lost!" << std::endl;
}

void onDeliveryComplete(void* context, MQTTAsync_token token)
{
    std::cout << "Message with token " << token
        << " has been delivered.(from global callback)" << std::endl;
}

int onMessageArrived(void* context, char* topicName, int topicLen,
    MQTTAsync_message* msg)
{
    std::cout << "Received a new message" << std::endl;
    return 1;
}

int main()
{
    int rc;

    MQTTAsync client;
    if ((rc = MQTTAsync_create(&client, BRIXBOT_ADDRESS, BRIXBOT_CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTASYNC_SUCCESS)
    {
        std::cout << "Failed to create MQTT client, return code "
            << rc << std::endl;
        return rc;
    }

    if ((rc = MQTTAsync_setCallbacks(client, NULL, onConnectLost,
        onMessageArrived, onDeliveryComplete)) != MQTTASYNC_SUCCESS)
    {
        std::cout << "Failed to set callbacks, return code "
            << rc << std::endl;
        return rc;
    }

    MQTTAsync_SSLOptions sslOpts = MQTTAsync_SSLOptions_initializer;
    sslOpts.trustStore = BRIXBOT_SERVER_CA_FILE;
    sslOpts.keyStore = BRIXBOT_CLIENT_CRT_FILE;
    sslOpts.privateKey = BRIXBOT_CLIENT_KEY_FILE;
    sslOpts.verify = 1;

    MQTTAsync_connectOptions connOpts = MQTTAsync_connectOptions_initializer;
    connOpts.keepAliveInterval = 20;
    connOpts.cleansession = 1;
    connOpts.username = BRIXBOT_USER;
    connOpts.password = BRIXBOT_PASSWORD;
    connOpts.onSuccess = onConnected;
    connOpts.onFailure = onConnectFailure;
    connOpts.context = (void *)client;
    connOpts.ssl = &sslOpts;

    std::cout << "Connecting " << BRIXBOT_ADDRESS << std::endl;
    if ((rc = MQTTAsync_connect(client, &connOpts)) != MQTTASYNC_SUCCESS)
    {
        std::cout << "Failed to start connect, return code " << rc << std::endl;
        return rc;
    }

    std::cout << "Press anykey to exit.\n";
    std::cin.get();

    MQTTAsync_destroy(&client);

    return 0;
}

