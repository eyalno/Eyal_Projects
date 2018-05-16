

// Traffic Light

// cpu interrup
enum interrupt{
	INACTIVE = -1,
	ACTIVE
};


///.. to work with char???

bit for each light
enum states {
	CLEAR,
	RED = 1,
	YELLOW = 2,
	FLICKER = 3,
	GREEN = 4 
	
	
};

states eFlicker = CLEAR;
states eState = RED;
interrupt eInterrupt = 0;

Active()
{
	int begin;

	while (1)
	{
		switch (eState)
		{
		case RED:
			eState = YELLOW;
			
			set RED;
		
			begin = time();
			while (time() - begin < 35)
			{
				if (eInterrupt == INACTIVE)
				{
					eState = FLICKER;
					break;
				}
			}
				
			break;

		case YELLOW:
			eState = GREEN;
			set YELLOW;

			begin = time();
			while (time() - begin < 5)
			{
				if (eInterrupt == INACTIVE)
				{
					eState = FLICKER;
					break;
				}
			}
				
			break;

		case GREEN:
			eState = RED;
			set GREEN;

			begin = time();
			while (time() - begin < 5)
			{
				if (eInterrupt == INACTIVE)
				{
					eState = FLICKER;
					break;
				}
			}
			
			break;

		case FLICKER:

			while (eInterrupt == INACTIVE)
			{
				set eFlicker;
				
				begin = time();
				while (time() - begin < 1)
				{
					if (eInterrupt == ACTIVE)
					{
						eState = RED;
						break;
					}
				}
				
				if (eFlicker == CLEAR)
					eFlicker = YELLOW;
				else
					eFlicker = CLEAR;
			}
			break;
		}

	}
}


InterruptFunc()
{
	~eInterrupt;
}




