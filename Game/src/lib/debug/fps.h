#pragma once


class CFps {
private:
	static double m_frameRate;			//フレームレート

	static int m_count;					//フレーム数カウント	

	static int m_updateFrameRateTime;	//フレームレート更新時間

	static int m_currentTime;			//現在のPC時間

	static int m_lastTime;				//1フレーム前のPC時間

public:
	static void Init();

	static bool CheckNext();

	static void Calc();

	static void PrintFps();

};
