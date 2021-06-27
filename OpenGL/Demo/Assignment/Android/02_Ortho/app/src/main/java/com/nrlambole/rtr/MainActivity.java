package com.nrlambole.rtr;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import android.content.pm.ActivityInfo;
import android.view.View;

public class MainActivity extends AppCompatActivity
{
	private MyView myView;
	
	@Override
	protected void onCreate(Bundle savedInstaceStates)
	{
		getWindow().getDecorView().setSystemUiVisibility(View.SYSTEM_UI_FLAG_IMMERSIVE | View.SYSTEM_UI_FLAG_LAYOUT_STABLE | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN | View.SYSTEM_UI_FLAG_NAVIGATION | View.SYSTEM_UI_FLAG_FULLSCREEN);
		
		super.OnCreate(savedInstanceState);
		
		setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDCAPE);
		myView = new MyView(this);
		
		// setContentView(R.layout.activity_main); 
		// commented by me for cutom view
		
	}
}
