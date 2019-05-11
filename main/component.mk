# Core modules
COMPONENT_SRCDIRS := . core core/wifi core/ble core/kv core/ota core/httpd core/stat_dump core/time core/mqtt core/i2c core/reboot

# Custom modules
COMPONENT_SRCDIRS += solenoid

# I2C devices
COMPONENT_SRCDIRS += arduino_co2
