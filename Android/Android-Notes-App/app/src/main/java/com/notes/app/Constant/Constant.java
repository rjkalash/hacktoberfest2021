package com.notes.app.Constant;

import java.io.Serializable;

public class Constant implements Serializable {
    private static final long serialVersionUID = 1L;

    public static String company = "Harsha";
    public static String email = "maramsaiharsha128@gmail.com";
    public static String website = "https://www.maramsaiharsha.netlify.com/";
    public static String contact = "+91 8897579068";
    public static String privacyPolicy = "http://maramsaiharsha.netlify.com/privacy";

    //--------------------Admob ads----------------- //
    public static Boolean isAdmobBannerAd = true;
    public static Boolean  isAdmobInterAd = true;
    public static int adShow = 5;

    //--------------------Fb ads----------------- //
    public static Boolean isFBBannerAd = false;
    public static Boolean  isFBInterAd = false;
    public static int adShowFB = 5;


}