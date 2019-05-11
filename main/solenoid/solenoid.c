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

static void solenoid_task(void *param) {
  while (true) {
    int co2 = get_co2();
    if (!get_solenoid() && co2 < 1000) {
      gpio_set_level(GPIO_OUTPUT_SOLENOID, 1);
      set_solenoid(1);
    } else if (get_solenoid() && co2 > 1500) {
      gpio_set_level(GPIO_OUTPUT_SOLENOID, 0);
      set_solenoid(0);
    }
    vTaskDelay(1 * 1000 / portTICK_PERIOD_MS);
  }
}
