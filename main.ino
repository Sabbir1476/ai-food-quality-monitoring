
#include <Arduino.h>
#include "edge-impulse-sdk/classifier/ei_run_classifier.h"

// Buffer for sensor data
#define SAMPLE_SIZE EI_CLASSIFIER_DSP_INPUT_FRAME_SIZE
float features[SAMPLE_SIZE];

// Dummy function (replace with real sensor readings)
void read_sensor_data() {
  for (int i = 0; i < SAMPLE_SIZE; i++) {
    features[i] = analogRead(A0);  // Example: gas sensor
    delay(5);
  }
}

// Signal structure required by Edge Impulse
static int raw_feature_get_data(size_t offset, size_t length, float *out_ptr) {
  memcpy(out_ptr, features + offset, length * sizeof(float));
  return 0;
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("🤖 AI Food Quality Monitoring Started");
}

void loop() {
  Serial.println("\nCollecting sensor data...");
  
  // Step 1: Read sensor data
  read_sensor_data();

  // Step 2: Prepare signal
  signal_t signal;
  signal.total_length = SAMPLE_SIZE;
  signal.get_data = &raw_feature_get_data;

  // Step 3: Run classifier
  ei_impulse_result_t result = {0};
  EI_IMPULSE_ERROR res = run_classifier(&signal, &result, false);

  if (res != EI_IMPULSE_OK) {
    Serial.print("Error running classifier: ");
    Serial.println(res);
    return;
  }

  // Step 4: Print predictions
  Serial.println("Prediction results:");

  for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++) {
    Serial.print(result.classification[ix].label);
    Serial.print(": ");
    Serial.println(result.classification[ix].value, 4);
  }

  Serial.println("-----------------------");

  delay(3000);
}
