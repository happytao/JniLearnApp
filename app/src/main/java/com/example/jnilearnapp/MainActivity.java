package com.example.jnilearnapp;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.hellojni.HelloJni;

public class MainActivity extends AppCompatActivity {
    private TextView mTextView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mTextView = findViewById(R.id.tv_text);
        mTextView.setText(HelloJni.stringFromJni());
        byte[] inputBytes = Util.hexString2Bytes("1234567890");
        byte[] outputBytes = HelloJni.getBytesFromJni(inputBytes);
        Log.e("xtxt","outputBytes = " + Util.byte2HexStr(outputBytes));
    }
}