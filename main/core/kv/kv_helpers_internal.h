/*
 * Copyright (C) 2019  SuperGreenLab <towelie@supergreenlab.com>
 * Author: Constantin Clauzel <constantin.clauzel@gmail.com>
 *
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

#ifndef KV_HELPERS_INTERNAL_H_
#define KV_HELPERS_INTERNAL_H_

/*
 * [GENERATED]
 */

void internal_set_wifi_status(int value);
void internal_set_wifi_ssid(const char *value);
void internal_set_wifi_password(const char *value);
void internal_set_wifi_ap_ssid(const char *value);
void internal_set_wifi_ap_password(const char *value);
void internal_set_mdns_domain(const char *value);
void internal_set_wifi_ip(const char *value);
void internal_set_time(int value);
void internal_set_n_restarts(int value);
void internal_set_ota_timestamp(int value);
void internal_set_ota_server_ip(const char *value);
void internal_set_ota_server_hostname(const char *value);
void internal_set_ota_server_port(const char *value);
void internal_set_ota_basedir(const char *value);
void internal_set_ota_status(int value);
void internal_set_broker_url(const char *value);
void internal_set_broker_channel(const char *value);
void internal_set_broker_clientid(const char *value);
void internal_set_i2c_0_sda(int value);
void internal_set_i2c_0_scl(int value);
void internal_set_i2c_0_enabled(int value);
void internal_set_i2c_1_sda(int value);
void internal_set_i2c_1_scl(int value);
void internal_set_i2c_1_enabled(int value);
void internal_set_reboot(int value);
void internal_set_co2(int value);
void internal_set_solenoid(int value);
void internal_set_co2_min(int value);
void internal_set_co2_max(int value);
void internal_set_cycle_div(int value);
void internal_set_cycle_div_duration(int value);
void internal_set_on_hour(int value);
void internal_set_on_min(int value);
void internal_set_off_hour(int value);
void internal_set_off_min(int value);
void internal_set_pause(int value);

/*
 * [/GENERATED]
 */

#endif
