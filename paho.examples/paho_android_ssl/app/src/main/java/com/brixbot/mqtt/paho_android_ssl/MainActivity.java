package com.brixbot.mqtt.paho_android_ssl;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import org.eclipse.paho.android.service.MqttAndroidClient;
import org.eclipse.paho.client.mqttv3.DisconnectedBufferOptions;
import org.eclipse.paho.client.mqttv3.IMqttActionListener;
import org.eclipse.paho.client.mqttv3.IMqttDeliveryToken;
import org.eclipse.paho.client.mqttv3.IMqttMessageListener;
import org.eclipse.paho.client.mqttv3.IMqttToken;
import org.eclipse.paho.client.mqttv3.MqttCallbackExtended;
import org.eclipse.paho.client.mqttv3.MqttConnectOptions;
import org.eclipse.paho.client.mqttv3.MqttException;
import org.eclipse.paho.client.mqttv3.MqttMessage;

import java.io.IOException;
import java.security.KeyManagementException;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.security.UnrecoverableKeyException;
import java.security.cert.CertificateException;

public class MainActivity extends AppCompatActivity {
    MqttAndroidClient mqttClient;

    final String serverUri = "ssl://www.domain.com:8883"; // You have to change it to your broker
    final String topic = "brixbot example";
    final String publishMessage = "Hello brixbot from android!";
    String clientId = "paho_android_ssl_client";
    final String userName = "bot";          // You have to change it to a valid user name of your broker
    final String password = "password";    // You have to change it to the user's password

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        clientId = clientId + System.currentTimeMillis();
        mqttClient = new MqttAndroidClient(getApplicationContext(), serverUri, clientId);
        mqttClient.setCallback(new MqttCallbackExtended() {
            @Override
            public void connectComplete(boolean reconnect, String serverURI) {
                Log.i("MQTT", "Connected broker.");
            }

            @Override
            public void connectionLost(Throwable cause) {
                Log.e("MQTT", "Broker connection lost!");
            }

            @Override
            public void messageArrived(String topic, MqttMessage message) throws Exception {
                Log.i("MQTT", "Received a new message.");
            }

            @Override
            public void deliveryComplete(IMqttDeliveryToken token) {
                Log.i("MQTT", "Message was delivered");
            }
        });

        MqttConnectOptions opts = new MqttConnectOptions();
        opts.setAutomaticReconnect(true);
        opts.setCleanSession(false);
        opts.setKeepAliveInterval(20);
        opts.setUserName(userName);
        opts.setPassword(password.toCharArray());

        SocketFactory.SocketFactoryOptions socketOpts = new SocketFactory.SocketFactoryOptions();
        try {
            socketOpts.withCaInputStream(this.getResources().openRawResource(R.raw.ca)).
                    withClientP12InputStream(this.getResources().openRawResource(R.raw.client)).
                    withClientP12Password("YourP12FilePassword");
            opts.setSocketFactory(new SocketFactory(socketOpts));
        } catch (IOException | NoSuchAlgorithmException | KeyStoreException | CertificateException | KeyManagementException | UnrecoverableKeyException e) {
            e.printStackTrace();
        }

        try {
            mqttClient.connect(opts, null, new IMqttActionListener() {
                @Override
                public void onSuccess(IMqttToken asyncActionToken) {
                    Log.i("MQTT", "Connected broker.");

                    DisconnectedBufferOptions disconnectedBufferOptions = new DisconnectedBufferOptions();
                    disconnectedBufferOptions.setBufferEnabled(true);
                    disconnectedBufferOptions.setBufferSize(100);
                    disconnectedBufferOptions.setPersistBuffer(false);
                    disconnectedBufferOptions.setDeleteOldestMessages(false);
                    mqttClient.setBufferOpts(disconnectedBufferOptions);

                    subscribeToTopic();
                    publishMessage();
                }

                @Override
                public void onFailure(IMqttToken asyncActionToken, Throwable exception) {
                    Log.e("MQTT", "Failed to connect broker!");
                }
            });
        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

    public void publishMessage() {
        MqttMessage message = new MqttMessage();
        message.setPayload(publishMessage.getBytes());

        Log.i("MQTT", "Sending message...");

        try {
            mqttClient.publish(topic, message);
        } catch (MqttException e) {
            e.printStackTrace();
        }
    }

    public void subscribeToTopic(){
        try {
            mqttClient.subscribe(topic, 0, null, new IMqttActionListener() {
                @Override
                public void onSuccess(IMqttToken asyncActionToken) {
                    Log.i("MQTT", "Subscribe succeeded");
                }

                @Override
                public void onFailure(IMqttToken asyncActionToken, Throwable exception) {
                    Log.i("MQTT", "Subscribe failed");
                }
            });

            // THIS DOES NOT WORK!
            mqttClient.subscribe(topic, 0, new IMqttMessageListener() {
                @Override
                public void messageArrived(String topic, MqttMessage message) throws Exception {
                    // message Arrived!
                    Log.i("MQTT", "Received a new message from topic \"" + topic + "\"");
                    Log.i("MQTT", "  message: " + new String(message.getPayload()));
                }
            });

        } catch (MqttException ex){
            System.err.println("Exception whilst subscribing");
            ex.printStackTrace();
        }
    }
}
