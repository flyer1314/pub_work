

void rtsp_network_adaptive(int type, int diff_frame, int ch)
{
	static int cur_bitrate = 3000;
	static int times = 0;
	int bitrate = 0;

//	printf("Rtsp Time=%d \n", times);
	if(type == 0)
	{
		times = 0;
		bitrate = diff_frame * 50;
		bitrate = cur_bitrate - bitrate;
		if(bitrate < 800)
		{
			bitrate = 800;
			if(cur_bitrate <= 800)
			{
				return;
			}
		}
	}
	else
	{
		times++;
		if(times >= 25)
		{
			times = 0;
			bitrate = cur_bitrate + 200;
			if(bitrate > 3000)
			{
				bitrate = 3000;
				if(cur_bitrate >= 3000)
				{
					return;
				}
			}
		}
		else
			return;
	}

	if(ch != 0 && cur_bitrate != bitrate)
	{
		GK_Set_Venc_BitRate(ch, bitrate);
//		Printf("Network Adaptive, %s bitrate [%d] to [%d]\n", type == 1 ? "Up" : "Down", cur_bitrate, bitrate);
	}

	cur_bitrate = bitrate;
	return;
}