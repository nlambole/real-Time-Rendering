package com.helloworld.rtr;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import androidx.appcompat.widget.AppCompatTextView;
import android.graphics.Color;
import android.view.Gravity;

public class MainActivity extends AppCompatActivity 
{

    @Override
    protected void onCreate(Bundle savedInstanceState)
	{
        super.onCreate(savedInstanceState);
		getWindow().getDecorView().setBackgroundColor(Color.rgb(0, 0, 0)); // Object Chaining
		
		AppCompatTextView myTextView = new AppCompatTextView(this);
		myTextView.setText("Hello World !!!");
		myTextView.setTextSize(64);
		myTextView.setTextColor(Color.rgb(0, 255, 0));
		myTextView.setGravity(Gravity.CENTER);
		myTextView.setBackgroundColor(Color.rgb(0, 0, 0));
		
        setContentView(myTextView);
		
	   System.out.println("Hello Nandlal, How can I help you ?");
    }
}