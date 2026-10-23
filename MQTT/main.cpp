#include <iostream>
#include <cstdlib>
#include <cstring>
#include <mqtt/async_client.h>
using namespace std;

string SERVER_ADDRESS{"tcp://broker.emqx.io:1883"};
string CLIENT_ID{"cpp_mqtt_publisher_sample"};
string TOPIC{"test/cpp_topic"};

int main()
{
    //  Instantiate the MQTT client
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);

    //  set connection configuration options
    mqtt::connect_options connOpts;
    connOpts.set_keep_alive_interval(20);
    connOpts.set_clean_session(true);

    try
    {
        cout << "Connection to the MQTT broker..." << endl;
        client.connect(connOpts)->wait();
        cout << "connected successfully" << endl;

        string payload = "Hello from modern C++";
        auto msg = mqtt::make_message(TOPIC, payload);
        msg->set_qos(1);

        cout << "Publishing message to topic" << TOPIC << endl;
        client.publish(msg)->wait();
        cout << "Message published" << endl;

        //  Disconnect clean
        client.disconnect()->wait();
        cout << "Disconnected securely" << endl;
    }
    catch (const mqtt::exception &exc)
    {
        cerr << "MQTT Error: " << exc.what() << "[" << exc.get_reason_code() << "]" << endl;
        return 1;
    }

    return 0;
}