package com.innovativedesign.jcardio;

import android.app.ListActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MenuList extends ListActivity{

	String classes[] = {"Setup Account", "Connect to WiFi", "Connect to Bluetooth", "Heart Rate Monitor", "Fitness Tracker",
			"Food Diary", "Personal Trainer"};
	
	String jclasses[] = {"SetupAccount", "WiFiDirectActivity", "ConnectToBluetooth", "HeartRateMonitor", "FitnessTracker",
			"FoodDiary", "PersonalTrainer"};
	
	@Override
	protected void onListItemClick(ListView l, View v, int position, long id) {
		// TODO Auto-generated method stub		
		super.onListItemClick(l, v, position, id);
		String nextclass = classes[position];
		
		switch (position){
		case 0:
		try {
		Class ourClass = Class.forName("com.innovativedesign.jcardio." +jclasses[0]);
		Intent ourIntent = new Intent(MenuList.this, ourClass);
		startActivity(ourIntent);
		} catch (ClassNotFoundException e){
			e.printStackTrace();
		}
		break;
		
		case 1:
			try {
			Class ourClass = Class.forName("com.innovativedesign.jcardio." +jclasses[1]);
			Intent ourIntent = new Intent(MenuList.this, ourClass);
			startActivity(ourIntent);
			} catch (ClassNotFoundException e){
				e.printStackTrace();
			}
			break;
			
		case 2:
			try {
			Class ourClass = Class.forName("com.innovativedesign.jcardio." +jclasses[2]);
			Intent ourIntent = new Intent(MenuList.this, ourClass);
			startActivity(ourIntent);
			} catch (ClassNotFoundException e){
				e.printStackTrace();
			}
			break;
			
		case 3:
			try {
			Class ourClass = Class.forName("com.innovativedesign.jcardio." +jclasses[3]);
			Intent ourIntent = new Intent(MenuList.this, ourClass);
			startActivity(ourIntent);
			} catch (ClassNotFoundException e){
				e.printStackTrace();
			}
			break;
			
		case 4:
			try {
			Class ourClass = Class.forName("com.innovativedesign.jcardio." +jclasses[4]);
			Intent ourIntent = new Intent(MenuList.this, ourClass);
			startActivity(ourIntent);
			} catch (ClassNotFoundException e){
				e.printStackTrace();
			}
			break;
			
		case 5:
			try {
			Class ourClass = Class.forName("com.innovativedesign.jcardio." +jclasses[5]);
			Intent ourIntent = new Intent(MenuList.this, ourClass);
			startActivity(ourIntent);
			} catch (ClassNotFoundException e){
				e.printStackTrace();
			}
			break;
			
		case 6:
			try {
			Class ourClass = Class.forName("com.innovativedesign.jcardio." +jclasses[6]);
			Intent ourIntent = new Intent(MenuList.this, ourClass);
			startActivity(ourIntent);
			} catch (ClassNotFoundException e){
				e.printStackTrace();
			}
			break;
		};
	}

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setListAdapter(new ArrayAdapter<String>(MenuList.this, android.R.layout.simple_list_item_1, classes));
	}

}
