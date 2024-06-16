#include <stdlib.h>
#include <conio.h>
#include "fujinet-fuji.h"

static AdapterConfigExtended adapterConfig;
char buf[3];

void cputs_cr(char *s) {
	cputs(s);
	cputs("\r\n");
}

void main() {
	if (fuji_get_adapter_config_extended(&adapterConfig)) {
		cputs("           SSID: "); cputs_cr(adapterConfig.ssid);
		cputs("       Hostname: "); cputs_cr(adapterConfig.hostname);
		cputs("     IP Address: "); cputs_cr(adapterConfig.sLocalIP);
		cputs("Gateway Address: "); cputs_cr(adapterConfig.sGateway);
		cputs("    DNS Address: "); cputs_cr(adapterConfig.sDnsIP);
		cputs("        Netmask: "); cputs_cr(adapterConfig.sNetmask);
		cputs("    MAC Address: "); cputs_cr(adapterConfig.sMacAddress);
		cputs("          BSSID: "); cputs_cr(adapterConfig.sBssid);
		cputs("FCONFIG Version: "); cputs_cr(VERSION_STRING);
		cputs("  Fuji Firmware: "); cputs_cr(adapterConfig.fn_version);
	} else {
		itoa(_fuji_status.value.error, &buf[0], 16);
		cputs("err: "); cputs_cr(buf);
		itoa(_fuji_status.value.cmd, &buf[0], 16);
		cputs("cmd: "); cputs_cr(buf);
		cputs("msg: "); cputs_cr(_fuji_status.value.msg);
	}
}