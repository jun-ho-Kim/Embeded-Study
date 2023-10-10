package com.jhexample.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    static MainHandler mainHandler;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        ClientThread clientThread;
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mainHandler = new MainHandler();

        clientThread = new ClientThread();
        clientThread.start();


    }
    public void onButtonClicked(View v) {
        Toast.makeText(this, "확인1 버튼이 눌렸어요.", Toast.LENGTH_SHORT).show();
    }

    public void onButton2Clicked(View v)
    {
        Intent myIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("http://m.naver.com"));
        startActivity(myIntent);
    }

    public void onButton3Clicked(View v)
    {
        Intent myIntent = new Intent(Intent.ACTION_VIEW, Uri.parse("tel:010-6283-5049"));
        startActivity(myIntent);
    }
    class MainHandler extends Handler {
        @Override
        public void handleMessage(Message msg)
        {
            super.handleMessage(msg);
            Bundle bundle = msg.getData();
            String data = bundle.getString("msg");
            Log.d("MainHandler", data);
        }
    }
}