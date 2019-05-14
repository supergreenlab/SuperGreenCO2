/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include "solenoid.h"

#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#include "../core/kv/kv.h"
#include "../core/log/log.h"

#define GPIO_OUTPUT_SOLENOID    18
#define GPIO_OUTPUT_SOLENOID_SEL  (1ULL<<GPIO_OUTPUT_SOLENOID)

static void solenoid_task(void *param);

void init_solenoid() {
  ESP_LOGI(SGO_LOG_EVENT, "@SOLENOID Initializing solenoid module");

	gpio_config_t io_conf;
	io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
	io_conf.mode = GPIO_MODE_OUTPUT;
	io_conf.pin_bit_mask = GPIO_OUTPUT_SOLENOID_SEL;
	io_conf.pull_down_en = 1;
	io_conf.pull_up_en = 0;
	gpio_config(&io_conf);

  xTaskCreate(solenoid_task, "SOLENOID", 4096, NULL, 10, NULL);
}

static bool is_on() {
  int on_hour = get_on_hour();
  int on_min = get_on_min();
  int off_hour = get_off_hour();
  int off_min = get_off_min();

  time_t now;
  struct tm tm_now;
  time(&now);
  localtime_r(&now, &tm_now); 

  double on_sec = on_hour * 3600 + on_min * 60;
  double off_sec = off_hour * 3600 + off_min * 60;
  double cur_sec = tm_now.tm_hour * 3600 + tm_now.tm_min * 60;

  if (on_sec == off_sec) return true;

  return (on_sec < off_sec && on_sec < cur_sec && off_sec > cur_sec) || (on_sec > off_sec && (on_sec < cur_sec || cur_sec < off_sec));
}

static void solenoid_task(void *param) {
  int i = 0;
  while (true) {
    if (get_pause() || !is_on()) {
      set_solenoid(0);
      gpio_set_level(GPIO_OUTPUT_SOLENOID, 0);
      vTaskDelay(10 * 1000 / portTICK_PERIOD_MS);
      continue;
    }
    int co2 = get_co2();
    if (!get_solenoid() && co2 < get_co2_min()) {
      set_solenoid(1);
      i = 0;
    } else if (get_solenoid() && co2 > get_co2_max()) {
      set_solenoid(0);
    }
    gpio_set_level(GPIO_OUTPUT_SOLENOID, get_solenoid() && !(i % get_cycle_div()));
    vTaskDelay(1.0f * (double)get_cycle_div_duration() / portTICK_PERIOD_MS);
    ++i;
  }
}
