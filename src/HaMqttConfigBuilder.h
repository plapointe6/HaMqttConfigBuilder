#include "Arduino.h"

// An helper class to generate a json Key/Value config payload for Home Assistant
class HaMqttConfigBuilder {

private:
  struct Elem {
    String key;
    String str;
    double num;
  };
  std::vector<Elem> elements;

public:
  // Add an element to the config paylaod
  HaMqttConfigBuilder& add(const String& key, const String& str) {
    elements.push_back({key, str, 0});
    return *this;
  }
  HaMqttConfigBuilder& add(const String& key, const double num) {
    elements.push_back({key, "", num});
    return *this;
  }

  // Clear all elements
  void clear() { elements.clear(); };

  // Generate the json key/value payload for home assistant
  String generatePayload() {
    String str = "{";

    for(Elem elem : elements) {
      str.concat('"');
      str.concat(elem.key);
      str.concat("\":");
      
      if (elem.str.length() > 0) {
        str.concat('"');
        str.concat(elem.str);
        str.concat('"');
      } else {
        str.concat(elem.num);
      }
      str.concat(',');
    }

    if (str.endsWith(","))
      str.setCharAt(str.length()-1, '}');
    else
      str.concat('}');

    return str;
  }
};