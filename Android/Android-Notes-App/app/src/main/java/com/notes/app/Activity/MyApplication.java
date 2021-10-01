package com.notes.app.Activity;

import android.app.Application;
import android.content.Context;
import android.os.StrictMode;

import androidx.multidex.MultiDex;

import com.facebook.ads.AudienceNetworkAds;
import com.google.android.gms.ads.MobileAds;
import com.onesignal.OneSignal;

import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.SharedPref.SharedPref;

public class MyApplication extends Application {

    private SharedPref sharedPref;

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        MultiDex.install(this);
    }

    @Override
    public void onCreate() {
        super.onCreate();
        sharedPref = new SharedPref(this);
        if (sharedPref.getNightMode()) {
            Setting.Dark_Mode = true;
        } else {
            Setting.Dark_Mode = false;
        }

        StrictMode.VmPolicy.Builder builder = new StrictMode.VmPolicy.Builder();
        StrictMode.setVmPolicy(builder.build());

        // Enable verbose OneSignal logging to debug issues if needed.
        OneSignal.setLogLevel(OneSignal.LOG_LEVEL.VERBOSE, OneSignal.LOG_LEVEL.NONE);

        // OneSignal Initialization
        OneSignal.initWithContext(getApplicationContext());
        OneSignal.setAppId(getApplicationContext().getString(R.string.ONESIGNAL_APP_ID));

        AudienceNetworkAds.initialize(this);
        MobileAds.initialize(getApplicationContext(), getApplicationContext().getString(R.string.admob_app_id));
    }

}