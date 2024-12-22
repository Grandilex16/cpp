#include "speedywagon.h"

namespace speedywagon {

// Enter your code below:

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int> *data_array) {
  double avg{};
  for (auto element : *data_array) {
    avg += element;
  }
  avg /= data_array->size();
  int uv_index{};
  for (auto element : *data_array) {
    if (element > avg)
      ++uv_index;
  }
  return uv_index;
}

bool connection_check(pillar_men_sensor *sensor) {

  if (sensor != nullptr) {
    return true;
  }
  return false;
}
int activity_counter(pillar_men_sensor sensor_arr[], int num) {

  int counter = 0;
  for (int i = 0; i < num; i++) {

    counter += sensor_arr[i].activity;
  }
  return counter;
}
bool alarm_control(pillar_men_sensor *alarm_sensor) {

  if (alarm_sensor == nullptr) {
    return false;
  }
  if (alarm_sensor->activity > 0) {
    return true;
  } else {
    return false;
  }
}
bool uv_alarm(pillar_men_sensor *alarm) {

  if (alarm == nullptr) {
    return false;
  }
  if (uv_light_heuristic(&alarm->data) > alarm->activity) {
    return true;
  } else {
    return false;
  }
}

} // namespace speedywagon
