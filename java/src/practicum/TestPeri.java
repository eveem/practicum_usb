package practicum;

import org.usb4java.Device;

public class TestPeri
{
    public static void main(String[] args) throws Exception
    {
        McuBoard.initUsb();

        try
        {
        	Device[] devices = McuBoard.findBoards();
        	
        	if (devices.length == 0) {
                System.out.format("** Practicum board not found **\n");
                return;
        	}
        	else {
                System.out.format("** Found %d practicum board(s) **\n", devices.length);
        	}
            McuWithPeriBoard peri = new McuWithPeriBoard(devices[0]);

            System.out.format("** Practicum board found **\n");
            System.out.format("** Manufacturer: %s\n", peri.getManufacturer());
            System.out.format("** Product: %s\n", peri.getProduct());
            
            while (true)
            {
            	for (int i = 0; i < 8; i++)
            	{
//            		peri.setGreenLed(i, 0);
            		Thread.sleep(500);
            	}
//            	peri.setGreenLed(4, 1);
            	Thread.sleep(500);
//            	for (int i = 0; i < 8; i++)
//            	{
//            		peri.setGreenLed(i, 1);
//            		Thread.sleep(500);	
//            	}             
            }
        }
        catch (Exception e)
        {
            System.out.println(e);
        }

        McuBoard.cleanupUsb();
    }
}
