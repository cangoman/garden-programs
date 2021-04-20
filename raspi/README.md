Raspberry pi is configured. Installed Raspbian lite (headless). 

Will be using MQTT for communication.

Installation of MQTT and mosquitto client:

Update mosquitto packages
```
sudo wget https://repo.mosquitto.org/debian/mosquitto-repo.gpg.key
sudo apt-key add mosquitto-repo.gpg.key
cd /etc/apt/sources.list.d/
sudo wget http://repo.mosquitto.org/debian/mosquitto-buster.list
sudo apt-get update
```


Install mosquitto (MQTT broker) and mosquitto clients:

```
sudo apt-get install mosquitto mosquitto-clients
```


Install pip (if not yet installed) to manage python packages:

```
sudo apt-get install python-pip
```

and use it to install maho-mqtt (python library for mqtt)

```
sudo pip install paho-mqtt
```



To configure the mosquitto server:

open the file `/etc/mosquitto.conf`, and edit it to this:

```
# Place your local configuration in /etc/mosquitto/conf.d/
#
# A full description of the configuration file is at
# /usr/share/doc/mosquitto/examples/mosquitto.conf.example

pid_file /var/run/mosquitto.pid

persistence true
persistence_location /var/lib/mosquitto/

log_dest topic


log_type error
log_type warning
log_type notice
log_type information

connection_messages true
log_timestamp true

include_dir /etc/mosquitto/conf.d
```


Then start the server with `sudo /etc/init.d/mosquitto start`





I followed [this guide](https://www.switchdoc.com/2018/02/tutorial-installing-and-testing-mosquitto-mqtt-on-raspberry-pi/). I'm keeping it here as a reference in case it is taken down.
