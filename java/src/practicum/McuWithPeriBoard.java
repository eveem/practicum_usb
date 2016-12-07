package practicum;

import org.usb4java.Device;

public class McuWithPeriBoard extends McuBoard
{
	private static final byte RQ_EEPROM_UPDATE = 0;

    public McuWithPeriBoard(Device device) {
		super(device);
	}

    public void sentMessage(short index, short value) {
    	this.write(RQ_EEPROM_UPDATE, (short) index, (short) value);
    }
}
