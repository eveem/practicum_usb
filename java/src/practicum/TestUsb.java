package practicum;

import org.usb4java.Device;

public class TestUsb {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		McuBoard.initUsb();
		Device[] devs = McuBoard.findBoards();
		McuBoard b = new McuBoard(devs[0]);

		//write function : first parameter is number of request
		//write function : second parameter is led [0 = red, 1 = yellow, 2 = green]
		//write function : third parameter is set on/off led [0 = off, 1 = on]
		b.write((byte)0, (short)0, (short)1);
		b.write((byte)0, (short)1, (short)1);
		b.write((byte)0, (short)2, (short)0);
		
		byte[] ret = b.read((byte)2, (short)0, (short)0);
		System.out.println(ret[0]);
		McuBoard.cleanupUsb();
	}

}
