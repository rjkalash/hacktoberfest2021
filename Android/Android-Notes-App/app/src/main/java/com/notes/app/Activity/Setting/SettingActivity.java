package com.notes.app.Activity.Setting;

import android.annotation.SuppressLint;
import android.app.ProgressDialog;
import android.content.Intent;
import android.graphics.drawable.ColorDrawable;
import android.os.AsyncTask;
import android.os.Build;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;

import com.notes.app.Activity.PrivacyPolicyActivity;
import com.notes.app.view.SwitchButton.SwitchButton;

import org.apache.commons.io.FileUtils;

import java.io.File;
import java.text.DecimalFormat;

import com.notes.app.Activity.About.AboutActivity;
import com.notes.app.Activity.LockScreen.LockRemoveActivity;
import com.notes.app.Activity.LockScreen.LockScreenActivity;
import com.notes.app.Activity.MainActivity;
import com.notes.app.Methods.Methods;
import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.SharedPref.SharedPref;

public class SettingActivity extends AppCompatActivity {

    private Methods methods;
    private SharedPref sharedPref;
    private SwitchButton switch_dark;
    private LinearLayout about, lockScreen, ll_clearcache, ll_privacy;
    private TextView tv_cachesize;
    private AlertDialog dialogDeletNote;
    private ProgressDialog progressDialog;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        sharedPref = new SharedPref(this);
        if (sharedPref.getNightMode()) {
            setTheme(R.style.AppTheme2);
            Setting.Dark_Mode = true;
        } else {
            setTheme(R.style.AppTheme);
            Setting.Dark_Mode = false;
        }

        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_setting);

        methods = new Methods(this);

        Toolbar toolbar = findViewById(R.id.toolbar_setting);
        setSupportActionBar(toolbar);

        this.setSupportActionBar(toolbar);
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);

        Dark_mode();

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            if (Setting.Dark_Mode){
                progressDialog = new ProgressDialog(SettingActivity.this, R.style.ThemeDialog2);
            }else {
                progressDialog = new ProgressDialog(SettingActivity.this, R.style.ThemeDialog);
            }
        } else {
            progressDialog = new ProgressDialog(SettingActivity.this);
        }
        progressDialog.setMessage(getString(R.string.clearing_cache));
        progressDialog.setCancelable(false);
        progressDialog.setCanceledOnTouchOutside(false);


        ll_clearcache = findViewById(R.id.ll_cache);
        tv_cachesize = findViewById(R.id.tv_cachesize);

        about= findViewById(R.id.nav_about);
        about.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent player = new Intent(SettingActivity.this, AboutActivity.class);
                startActivity(player);
            }
        });


        lockScreen= findViewById(R.id.lockScreen);
        lockScreen.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (Setting.in_code){
                    showDeletNoteDialog();
                }else {
                    Intent main = new Intent(SettingActivity.this, LockScreenActivity.class);
                    startActivity(main);
                }
            }
        });

        ll_privacy  = findViewById(R.id.ll_privacy);
        ll_privacy.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(SettingActivity.this, PrivacyPolicyActivity.class));
            }
        });

        ll_clearcache.setOnClickListener(new View.OnClickListener() {
            @Override
            @SuppressLint("StaticFieldLeak")
            public void onClick(View v) {
                new AsyncTask<String, String, String>() {
                    @Override
                    protected void onPreExecute() {
                        progressDialog.show();
                        super.onPreExecute();
                    }

                    @Override
                    protected String doInBackground(String... strings) {
                        try {
                            FileUtils.deleteQuietly(getCacheDir());
                            FileUtils.deleteQuietly(getExternalCacheDir());
                        } catch (Exception e) {
                            e.printStackTrace();
                        }
                        return null;
                    }

                    @Override
                    protected void onPostExecute(String s) {
                        progressDialog.dismiss();
                        methods.showSnackBar(getString(R.string.cache_cleared),"success");
                        tv_cachesize.setText("0 MB");
                        super.onPostExecute(s);
                    }
                }.execute();

            }
        });

        initializeCache();

    }

    private void Dark_mode() {
        switch_dark = findViewById(R.id.switch_dark);
        if (sharedPref.getNightMode()) {
            switch_dark.setChecked(true);
        } else {
            switch_dark.setChecked(false);
        }
        switch_dark.setOnCheckedChangeListener(new SwitchButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(SwitchButton view, boolean isChecked) {
                sharedPref.setNightMode(isChecked);
                Apps_recreate();
            }
        });
    }

    private void Apps_recreate() {
        recreate();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem menuItem) {
        switch (menuItem.getItemId()) {
            case android.R.id.home:
                overridePendingTransition(0, 0);
                overridePendingTransition(0, 0);
                startActivity(new Intent(SettingActivity.this, MainActivity.class));
                finish();
                break;

            default:
                return super.onOptionsItemSelected(menuItem);
        }
        return true;
    }

    @Override
    public void onBackPressed() {
        overridePendingTransition(0, 0);
        overridePendingTransition(0, 0);
        startActivity(new Intent(SettingActivity.this, MainActivity.class));
        finish();
    }

    private void showDeletNoteDialog() {
        if (dialogDeletNote == null) {
            AlertDialog.Builder builder = new AlertDialog.Builder(SettingActivity.this);
            View view = LayoutInflater.from(this).inflate(
                    R.layout.layout_delete_lock, (ViewGroup) findViewById(R.id.layoutDeleteNoteContainer)
            );
            builder.setView(view);
            dialogDeletNote = builder.create();
            if (dialogDeletNote.getWindow() != null){
                dialogDeletNote.getWindow().setBackgroundDrawable(new ColorDrawable(0));
            }
            view.findViewById(R.id.textDeleteNote).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Intent main = new Intent(SettingActivity.this, LockRemoveActivity.class);
                    startActivity(main);
                    dialogDeletNote.dismiss();
                }
            });

            view.findViewById(R.id.textCancel).setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    dialogDeletNote.dismiss();
                }
            });
        }

        dialogDeletNote.show();
    }

    private void initializeCache() {
        long size = 0;
        size += getDirSize(this.getCacheDir());
        size += getDirSize(this.getExternalCacheDir());
        tv_cachesize.setText(readableFileSize(size));
    }

    public long getDirSize(File dir) {
        long size = 0;
        for (File file : dir.listFiles()) {
            if (file != null && file.isDirectory()) {
                size += getDirSize(file);
            } else if (file != null && file.isFile()) {
                size += file.length();
            }
        }
        return size;
    }

    public static String readableFileSize(long size) {
        if (size <= 0) return "0 Bytes";
        final String[] units = new String[]{"Bytes", "kB", "MB", "GB", "TB"};
        int digitGroups = (int) (Math.log10(size) / Math.log10(1024));
        return new DecimalFormat("#,##0.#").format(size / Math.pow(1024, digitGroups)) + " " + units[digitGroups];
    }
}