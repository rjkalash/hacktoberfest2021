package com.notes.app.Activity;

import android.os.Bundle;
import android.view.View;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.widget.ProgressBar;

import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.notes.app.Constant.Constant;
import com.notes.app.R;
import com.notes.app.SharedPref.Setting;


public class PrivacyPolicyActivity extends AppCompatActivity {

    private Toolbar toolbar;
    private WebView privacy_policy;
    private ProgressBar progressBar_policy;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if (Setting.Dark_Mode ) {
            setTheme(R.style.AppTheme2);
        } else {
            setTheme(R.style.AppTheme);
        }
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_privacy_policy);

        toolbar = this.findViewById(R.id.toolbar);
        toolbar.setTitle(getString(R.string.privacy_policy));
        this.setSupportActionBar(toolbar);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        toolbar.setNavigationOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                onBackPressed();
            }
        });

        if (Setting.Dark_Mode) {
            getSupportActionBar().setHomeAsUpIndicator(R.drawable.ic_keyboard_backspace_black_24dp);
        } else {
            getSupportActionBar().setHomeAsUpIndicator(R.drawable.ic_keyboard_backspace_black_24dp2);
        }

        progressBar_policy = findViewById(R.id.progressBar_policy);

        privacy_policy = findViewById(R.id.privacy_policy);
        privacy_policy.setWebChromeClient(new WebChromeClient() {
            public void onProgressChanged(WebView view, int progress) {
                //Make the bar disappear after URL is loaded, and changes string to Loading...
                toolbar.setTitle("Loading...");
                setProgress(progress * 100); //Make the bar disappear after URL is loaded

                // Return the app name after finish loading
                if(progress == 100){
                    toolbar.setTitle(R.string.privacy_policy);
                    progressBar_policy.setVisibility(View.GONE);
                }
            }
        });
        privacy_policy.getSettings().setJavaScriptEnabled(true);
        privacy_policy.loadUrl(Constant.privacyPolicy);
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();
    }
}