package com.keshav.newstoday;

import androidx.appcompat.app.AppCompatActivity;

import android.animation.Animator;
import android.content.Intent;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.TextView;

import com.daimajia.androidanimations.library.Techniques;
import com.daimajia.androidanimations.library.YoYo;

public class MainActivity extends AppCompatActivity {

    ImageView image;
    TextView text, quote;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        image = findViewById(R.id.image);
        text = findViewById(R.id.qu);
        quote = findViewById(R.id.quote);

        YoYo.with(Techniques.ZoomIn).duration(1500).withListener(new Animator.AnimatorListener() {
            @Override
            public void onAnimationStart(Animator animator) {
                YoYo.with(Techniques.FadeOut).duration(1200).playOn(text);
                YoYo.with(Techniques.FadeOut).duration(1).playOn(quote);
            }

            @Override
            public void onAnimationEnd(Animator animator) {
                YoYo.with(Techniques.FadeIn).duration(1000).playOn(text);
                YoYo.with(Techniques.FadeIn).duration(1200).playOn(quote);
            }

            @Override
            public void onAnimationCancel(Animator animator) {
            }

            @Override
            public void onAnimationRepeat(Animator animator) {
            }
        }).playOn(image);

        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    Thread.sleep(3000);

                    startActivity(new Intent(MainActivity.this,secondActivity.class));

                    finish();

                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }
}
