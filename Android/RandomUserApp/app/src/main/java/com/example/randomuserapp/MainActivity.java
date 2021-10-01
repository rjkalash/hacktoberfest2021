package com.example.randomuserapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.android.volley.AuthFailureError;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonArrayRequest;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;
import com.bumptech.glide.Glide;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

public class MainActivity extends AppCompatActivity {
    ImageView imageView;
    TextView name;
    TextView gender;
    TextView email;
    TextView phone;
    TextView address;
    Button refesh;
//    private SwipeRefreshLayout swipe_refresh;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        name=findViewById(R.id.name);
        imageView=findViewById(R.id.image);
        gender=findViewById(R.id.gender);
        email=findViewById(R.id.email);
        phone=findViewById(R.id.phone);
        address=findViewById(R.id.address);
        refesh=findViewById(R.id.refresh);
//        swipe_refresh=findViewById(R.id.swipe_refresh);
        fetchData();
        refesh.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                fetchData();
            }
        });





    }
    public void fetchData(){
        RequestQueue  requestQueue;
        requestQueue= Volley.newRequestQueue(MainActivity.this);

        JsonObjectRequest jsonObjectRequest=new JsonObjectRequest(Request.Method.GET,"https://randomuser.me/api/"/*?gender=female*/, null,
                new Response.Listener<JSONObject>() {
                    @Override
                    public void onResponse(JSONObject response) {
                        try {

                            JSONArray userJsonArray=response.getJSONArray("results");

                            JSONObject userJsonObject=userJsonArray.getJSONObject(0);
                            gender.setText(userJsonObject.getString("gender"));
                            JSONObject Name=userJsonObject.getJSONObject("name");
                            String title=Name.getString("title");
                            String first=Name.getString("first");
                            String last=Name.getString("last");
                            name.setText(title+" "+first+" "+last);
                            email.setText(userJsonObject.getString("email"));
                            phone.setText(userJsonObject.getString("phone"));
                            JSONObject location=userJsonObject.getJSONObject("location");
                            JSONObject street =location.getJSONObject("street");
                            String Add1=street.getString("number")+","+street.getString("name");
                            String Add2=location.getString("city")+","+location.getString("state")+","+location.getString("country")+","+location.getString("postcode");
                            address.setText(Add1+","+Add2);
                            JSONObject picture=userJsonObject.getJSONObject("picture");
                            String longImgUrl=picture.getString("large");
                            Glide.with(MainActivity.this).load(longImgUrl).into(imageView);


                        } catch (JSONException e) {
                            e.printStackTrace();
                        }
                    }
                }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {

                Toast.makeText(MainActivity.this, error.toString()+"ewwkmvfmdvmklrxjngrnjgjr", Toast.LENGTH_SHORT).show();

            }
        });
        requestQueue.add(jsonObjectRequest);


    }

}