package com.notes.app.Activity.LockScreen;

import android.os.Bundle;
import android.os.Handler;
import android.view.View;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.Observer;

import com.notes.app.view.pflockscreen.PFFLockScreenConfiguration;
import com.notes.app.view.pflockscreen.fragments.PFLockScreenFragment;
import com.notes.app.view.pflockscreen.security.PFResult;
import com.notes.app.view.pflockscreen.security.PFSecurityManager;
import com.notes.app.view.pflockscreen.security.callbacks.PFPinCodeHelperCallback;
import com.notes.app.view.pflockscreen.viewmodels.PFPinCodeViewModel;

import com.notes.app.Methods.Methods;
import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.SharedPref.SharedPref;


public class LockRemoveActivity extends AppCompatActivity {

    private SharedPref sharedPre;
    private Methods methods;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.lockscreen);

        sharedPre = new SharedPref(this);
        methods = new Methods(this);

        showLockScreenFragment();

    }

    private final PFLockScreenFragment.OnPFLockScreenCodeCreateListener mCodeCreateListener = new PFLockScreenFragment.OnPFLockScreenCodeCreateListener() {
                @Override
                public void onCodeCreated(String encodedCode) {
                    methods.showSnackBar("Code created","success");
                }

                @Override
                public void onNewCodeValidationFailed() {
                    methods.showSnackBar("Code validation error","error");
                }
            };

    private final PFLockScreenFragment.OnPFLockScreenLoginListener mLoginListener = new PFLockScreenFragment.OnPFLockScreenLoginListener() {

                @Override
                public void onCodeInputSuccessful() {
                    methods.showSnackBar("Code successfull","success");
                    showMainFragment();
                }

                @Override
                public void onFingerprintSuccessful() {
                    methods.showSnackBar("Fingerprint successfull","success");
                    showMainFragment();
                }

                @Override
                public void onPinLoginFailed() {
                    methods.showSnackBar("Pin failed","error");
                }

                @Override
                public void onFingerprintLoginFailed() {
                    methods.showSnackBar("Fingerprint failed","error");
                }
            };

    private void showMainFragment() {
        sharedPre.saveToPref("", false);
        Setting.in_code = false;
        PFSecurityManager.getInstance().getPinCodeHelper().delete(new PFPinCodeHelperCallback<Boolean>() {
            @Override
            public void onResult(PFResult<Boolean> result) {
                if (result == null) {
                    return;
                }
                if (result.getError() != null) {
                    methods.showSnackBar("Can not get pin code info","error");
                    return;
                }
            }
        });

        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                onBackPressed();
            }
        },500);
    }

    private void showLockScreenFragment() {
        new PFPinCodeViewModel().isPinCodeEncryptionKeyExist().observe(
                this,
                new Observer<PFResult<Boolean>>() {
                    @Override
                    public void onChanged(@Nullable PFResult<Boolean> result) {
                        if (result == null) {
                            return;
                        }
                        if (result.getError() != null) {
                            methods.showSnackBar("Can not get pin code info","error");
                            return;
                        }
                        showLockScreenFragment(result.getResult());
                    }
                }
        );
    }

    private void showLockScreenFragment(boolean isPinExist) {
        final PFFLockScreenConfiguration.Builder builder = new PFFLockScreenConfiguration.Builder(this)
                .setTitle(isPinExist ? "Delete with your pin code or fingerprint" : "Create Code")
                .setCodeLength(4)
                .setLeftButton("Can't remeber")
                .setNewCodeValidation(true)
                .setNewCodeValidationTitle("Please input code again")
                .setUseFingerprint(true);
        final PFLockScreenFragment fragment = new PFLockScreenFragment();

        fragment.setOnLeftButtonClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                methods.showSnackBar("Left button pressed","success");
            }
        });

        builder.setMode(isPinExist
                ? PFFLockScreenConfiguration.MODE_AUTH
                : PFFLockScreenConfiguration.MODE_CREATE);
        if (isPinExist) {
            fragment.setEncodedPinCode(sharedPre.getCode());
            fragment.setLoginListener(mLoginListener);
        }

        fragment.setConfiguration(builder.build());
        fragment.setCodeCreateListener(mCodeCreateListener);
        getSupportFragmentManager().beginTransaction()
                .replace(R.id.container_view, fragment).commit();

    }
}
