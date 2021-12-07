#include "Arduino.h"
#include "HaMqttConfigBuilder.h"

String generateDeviceConfig() {
  return HaMqttConfigBuilder()
    .add("~", "homeassistant/light/my_light")
    .add("unique_id", "my_light")
    .add("name", "My test light")
    .add("json_attr_t", "~/attr")
    .add("stat_t", "~/state")
    .add("cmd_t", "~/cmd")
    .add("bri_stat_t", "~/br/state")
    .add("bri_cmd_t", "~/br/cmd")
    .add("bri_scl", "100")
    .generatePayload();
}
String generateDeviceAttributes() {
  return HaMqttConfigBuilder()
    .add("IP", "192.168.0.100")
    .generatePayload();
}

void setup() {
  Serial.begin(115200);
  Serial.println(generateDeviceConfig());
  Serial.println(generateDeviceAttributes());
}

void loop() {
}
