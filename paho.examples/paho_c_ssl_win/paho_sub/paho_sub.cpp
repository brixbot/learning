#include "stdafx.h"
#include <iostream>
#include <windows.h> 
#include <string>
#include "MQTTAsync.h"

#define BRIXBOT_ADDRESS     "ssl://www.domain.com:8883"	// You have to change it to your broker
#define BRIXBOT_CLIENTID    "paho_c_ssl_win_sub"
#define BRIXBOT_TOPIC       "brixbot example"
#define BRIXBOT_QOS         2
#define BRIXBOT_TIMEOUT     10000L
#define BRIXBOT_USER	    "bot"		// You have to change it to a valid user name of your broker
#define BRIXBOT_PASSWORD    "password"	// You have to change it to the user's password

#define BRIXBOT_SERVER_CA_FILE	"../../ssl/ca.crt"
#define BRIXBOT_CLIENT_CRT_FILE	"../../ssl/client.crt"
#define BRIXBOT_CLIENT_KEY_FILE	"../../ssl/client.key"

void onSubscribeDone(void* context, MQTTAsync_successData* response)
{
    std::cout << "Subscribe succeeded" << std::endl;
}

void onSubscribeFailed(void* context, MQTTAsync_failureData* response)
{
    std::cout << "Failed to subscribe message. Error code: "
        << (response ? response->code : 0) << std::endl;
}

void onConnected(void* context, MQTTAsync_successData* response)
{
    std::cout << "Connected broker." << std::endl;

    MQTTAsync client = (MQTTAsync)context;
    MQTTAsync_responseOptions opts = MQTTAsync_responseOptions_initializer;

    std::cout << "Waiting message from topic \"" << BRIXBOT_TOPIC
        << "\"" << std::endl;

    opts.onSuccess = onSubscribeDone;
    opts.onFailure = onSubscribeFailed;

    int rc;
    if ((rc = MQTTAsync_subscribe(client, BRIXBOT_TOPIC, BRIXBOT_QOS, &opts))
        != MQTTASYNC_SUCCESS)
    {
        printf("Failed to start subscribe, return code %d\n", rc);
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
    std::cout << "Received a new message from topic \"" << topicName << "\"" << std::endl;
    std::cout << "  message: ";

    std::string strMsg((const char *)msg->payload, msg->payloadlen);

    std::cout << strMsg << std::endl;

    MQTTAsync_freeMessage(&msg);
    MQTTAsync_free(topicName);

    return 1;
}

int main()
{
    int rc;

    MQTTAsync client;
    if ((rc = MQTTAsync_create(&client, BRIXBOT_ADDRESS, BRIXBOT_CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTASYNC_SUCCESS)
    {
        std::cout << "Failed to create MQTT client, return code " << rc
            << std::endl;
        return rc;
    }

    if ((rc = MQTTAsync_setCallbacks(client, NULL, onConnectLost,
        onMessageArrived, onDeliveryComplete)) != MQTTASYNC_SUCCESS)
    {
        std::cout << "Failed to set callbacks, return code " << rc << std::endl;
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

