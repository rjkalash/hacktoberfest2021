package com.notes.app.Methods;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;
import android.widget.LinearLayout;
import android.widget.Toast;

import com.facebook.ads.AdError;
import com.facebook.ads.InterstitialAdListener;
import com.google.ads.consent.ConsentInformation;
import com.google.ads.consent.ConsentStatus;
import com.google.ads.mediation.admob.AdMobAdapter;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.InterstitialAd;

import es.dmoral.toasty.Toasty;
import com.notes.app.Constant.Constant;
import com.notes.app.R;
import com.notes.app.SharedPref.Setting;
import com.notes.app.entities.Note;
import com.notes.app.listeners.InterAdListener;


public class Methods {

    private Context context;
    private InterAdListener interAdListener;
    private InterstitialAd interstitialAd;
    private com.facebook.ads.InterstitialAd interstitialAdFB;

    public Methods(Context context) {
        this.context = context;
    }

    public Methods(Context context, InterAdListener interAdListener) {
        this.context = context;
        this.interAdListener = interAdListener;
        loadad();
    }

    public void showSnackBar(String message, String type) {
        if (type.equals("success")){
            Toasty.success(context, message, Toast.LENGTH_SHORT, true).show();
        }else {
            Toasty.error(context, message, Toast.LENGTH_SHORT, true).show();
        }
    }


    public boolean isNetworkAvailable() {
        ConnectivityManager connectivityManager = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo activeNetworkInfo = connectivityManager.getActiveNetworkInfo();
        return activeNetworkInfo != null && activeNetworkInfo.isConnected();
    }


    private void loadad() {
        if (Constant.isAdmobInterAd) {
            interstitialAd = new InterstitialAd(context);
            AdRequest adRequest;
            if (ConsentInformation.getInstance(context).getConsentStatus() == ConsentStatus.PERSONALIZED) {
                adRequest = new AdRequest.Builder()
                        .build();
            } else {
                Bundle extras = new Bundle();
                extras.putString("npa", "1");
                adRequest = new AdRequest.Builder()
                        .addNetworkExtrasBundle(AdMobAdapter.class, extras)
                        .build();
            }
            interstitialAd.setAdUnitId(context.getString(R.string.interstitia_ad_unit_id));
            interstitialAd.loadAd(adRequest);
        } else if (Constant.isFBInterAd) {
            interstitialAdFB = new com.facebook.ads.InterstitialAd(context, context.getString(R.string.fb_ad_interstitia_id));
            interstitialAdFB.loadAd();
        }
    }


    public void showInter(final int pos, final Note note, final String type) {
        if (Constant.isAdmobInterAd) {
            Setting.adCount = Setting.adCount + 1;
            if (Setting.adCount % Constant.adShow == 0) {
                interstitialAd.setAdListener(new com.google.android.gms.ads.AdListener() {
                    @Override
                    public void onAdClosed() {
                        interAdListener.onClick(pos, note, type);
                        super.onAdClosed();
                    }
                });
                if (interstitialAd.isLoaded()) {
                    interstitialAd.show();
                } else {
                    interAdListener.onClick(pos, note, type);
                }
                loadad();
            } else {
                interAdListener.onClick(pos, note, type);
            }
        } else if (Constant.isFBInterAd) {
            Setting.adCount = Setting.adCount + 1;
            if (Setting.adCount % Constant.adShowFB == 0) {
                interstitialAdFB.loadAd(interstitialAdFB.buildLoadAdConfig().withAdListener(new InterstitialAdListener() {
                    @Override
                    public void onError(com.facebook.ads.Ad ad, AdError adError) {

                    }

                    @Override
                    public void onAdLoaded(com.facebook.ads.Ad ad) {

                    }

                    @Override
                    public void onAdClicked(com.facebook.ads.Ad ad) {

                    }

                    @Override
                    public void onLoggingImpression(com.facebook.ads.Ad ad) {

                    }

                    @Override
                    public void onInterstitialDisplayed(com.facebook.ads.Ad ad) {

                    }

                    @Override
                    public void onInterstitialDismissed(com.facebook.ads.Ad ad) {
                        interAdListener.onClick(pos, note, type);
                    }
                }).build());
                if (interstitialAdFB.isAdLoaded()) {
                    interstitialAdFB.show();
                } else {
                    interAdListener.onClick(pos, note, type);
                }
                loadad();
            } else {
                interAdListener.onClick(pos, note, type);
            }
        } else {
            interAdListener.onClick(pos, note, type);
        }
    }

    public void showBannerAd(LinearLayout linearLayout) {
        if (isNetworkAvailable() && linearLayout != null) {
            if (ConsentInformation.getInstance(context).getConsentStatus() == ConsentStatus.NON_PERSONALIZED) {
                showNonPersonalizedAds(linearLayout);
            } else {
                showPersonalizedAds(linearLayout);
            }
        }
    }


    private void showPersonalizedAds(LinearLayout linearLayout) {
        if (Constant.isAdmobBannerAd) {
            AdView adView = new AdView(context);
            AdRequest adRequest = new AdRequest.Builder().addTestDevice("0336997DCA346E1612B610471A578EEB").build();
            adView.setAdUnitId(context.getString(R.string.banner_ad_unit_id));
            adView.setAdSize(AdSize.SMART_BANNER);
            linearLayout.addView(adView);
            adView.loadAd(adRequest);
        } else if (Constant.isFBBannerAd) {
            com.facebook.ads.AdView adView;
            adView = new com.facebook.ads.AdView(context, context.getString(R.string.fb_ad_banner_id), com.facebook.ads.AdSize.BANNER_HEIGHT_90);
            adView.loadAd();
            linearLayout.addView(adView);
        }
    }

    private void showNonPersonalizedAds(LinearLayout linearLayout) {
        if (Constant.isAdmobBannerAd) {
            Bundle extras = new Bundle();
            extras.putString("npa", "1");
            AdView adView = new AdView(context);
            AdRequest adRequest = new AdRequest.Builder()
                    .addNetworkExtrasBundle(AdMobAdapter.class, extras)
                    .build();
            adView.setAdUnitId(context.getString(R.string.banner_ad_unit_id));
            adView.setAdSize(AdSize.SMART_BANNER);
            linearLayout.addView(adView);
            adView.loadAd(adRequest);
        } else if (Constant.isFBBannerAd) {
            com.facebook.ads.AdView adView;
            adView = new com.facebook.ads.AdView(context, context.getString(R.string.fb_ad_banner_id), com.facebook.ads.AdSize.BANNER_HEIGHT_90);
            adView.loadAd();
            linearLayout.addView(adView);
        }
    }

}