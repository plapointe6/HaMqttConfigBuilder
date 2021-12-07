# Config payloads generation for Home Assistant MQTT discovery

A tiny library that will let you generate config payloads for Home Assistant MQTT discovery. These payload ar JSON key/value pairs.

This is intended to replace [plapointe6/HAMqttDevice](https://github.com/plapointe6/HAMqttDevice) in my future iot devices.


## Exemple

```c++
#include "Arduino.h"
#include "HaMqttConfigBuilder.h"

String generateConfig() {
  return HaMqttConfigBuilder()
    .add("~", "homeassistant/light/my_light")
    .add("unique_id", "my_light")
    .add("name", "My test light")
    .add("stat_t", "~/state")
    .add("cmd_t", "~/cmd")
    .generatePayload();
}

void setup() {
  Serial.begin(115200);
  Serial.println(generateConfig());
}

void loop() {
}
```

Output:
```
{"~":"homeassistant/light/my_light","unique_id":"my_light","name":"My test light","stat_t":"~/state","cmd_t":"~/cmd"}
```
