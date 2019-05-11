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

#ifndef I2C_HELPERS_H_
#define I2C_HELPERS_H_

#define I2C_CB_H(i2cId, param) int on_set_i2c_## i2cId ##_## param( int value);
#define I2C_GETTER_H(param) int get_i2c_## param(int i2cId);
#define I2C_SETTER_H(param) void set_i2c_## param(int i2cId, int value);

I2C_CB_H(0, sda)
I2C_CB_H(0, sdc)
I2C_CB_H(0, enabled)
I2C_CB_H(1, sda)
I2C_CB_H(1, scl)
I2C_CB_H(1, enabled)

I2C_SETTER_H(sda)
I2C_GETTER_H(sda)
I2C_SETTER_H(scl)
I2C_GETTER_H(scl)
I2C_SETTER_H(enabled)
I2C_GETTER_H(enabled)

#endif
