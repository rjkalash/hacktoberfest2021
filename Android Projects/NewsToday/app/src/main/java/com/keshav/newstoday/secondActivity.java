package com.keshav.newstoday;

import android.content.Intent;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.ProgressBar;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.keshav.newstoday.schema.Data;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;

public class secondActivity extends AppCompatActivity {

    String API_KEY = "7b6d5c82373041aa843ff18b8e2c0a37";
    ListView listNews;

    ArrayList<HashMap<String, String>> dataList = new ArrayList<HashMap<String, String>>();
    static final String KEY_AUTHOR = "author";
    static final String KEY_TITLE = "title";
    static final String KEY_DESCRIPTION = "description";
    static final String KEY_URL = "url";
    static final String KEY_URLTOIMAGE = "urlToImage";
    static final String KEY_PUBLISHEDAT = "publishedAt";


    public String category = "all";

    public HorizontalListView horizontalListView;
    public HorizontalAdapter customeAdapter;
    public ArrayList<Model> imageModelArrayList;
    public int[] myImageList = new int[]{R.drawable.sports, R.drawable.entertainment, R.drawable.tech,R.drawable.politics,
            R.drawable.business, R.drawable.health};

    public String[] myImageNameList = new String[]{"Sports","Entertainment","Technology","politics","Business","Health"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_second);

        listNews = (ListView) findViewById(R.id.listNews);

        LinearLayoutManager layoutManager = new LinearLayoutManager(this);
        layoutManager.setOrientation(LinearLayoutManager.HORIZONTAL);


        final DownloadNews newsTask = new DownloadNews();
        newsTask.execute();


        horizontalListView = (HorizontalListView) findViewById(R.id.HorizontalListView);

        imageModelArrayList = populateData();
        Log.d("hjhjh",imageModelArrayList.size()+"");
        customeAdapter = new HorizontalAdapter(this,imageModelArrayList);
        horizontalListView.setAdapter(customeAdapter);

        horizontalListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {

                dataList.clear();

                category = "sports";
                DownloadNews newsTask = new DownloadNews();
                newsTask.execute();
            }
        });
    }


    class DownloadNews extends AsyncTask<String, Void, String> {
        @Override
        protected void onPreExecute() {
            super.onPreExecute();

        }
        protected String doInBackground(String... args) {
            String xml = "";

            String urlParameters = "";
            xml = Function.excuteGet("https://newsapi.org/v2/everything?q="+category+"&language=en&pageSize=10&apiKey="+API_KEY, urlParameters);
            return  xml;
        }
        @Override
        protected void onPostExecute(String xml) {

            if(xml.length()>10){ // Just checking if not empty

                try {
                    JSONObject jsonResponse = new JSONObject(xml);
                    JSONArray jsonArray = jsonResponse.optJSONArray("articles");

                    for (int i = 0; i < jsonArray.length(); i++) {
                        JSONObject jsonObject = jsonArray.getJSONObject(i);
                        HashMap<String, String> map = new HashMap<String, String>();
                        map.put(KEY_AUTHOR, jsonObject.optString(KEY_AUTHOR).toString());
                        map.put(KEY_TITLE, jsonObject.optString(KEY_TITLE).toString());
                        map.put(KEY_DESCRIPTION, jsonObject.optString(KEY_DESCRIPTION).toString());
                        map.put(KEY_URL, jsonObject.optString(KEY_URL).toString());
                        map.put(KEY_URLTOIMAGE, jsonObject.optString(KEY_URLTOIMAGE).toString());
                        map.put(KEY_PUBLISHEDAT, jsonObject.optString(KEY_PUBLISHEDAT).toString());
                        dataList.add(map);
                    }
                } catch (JSONException e) {
                    Toast.makeText(getApplicationContext(), "Unexpected error", Toast.LENGTH_SHORT).show();
                }

                ListNewsAdapter adapter = new ListNewsAdapter(secondActivity.this, dataList);
                listNews.setAdapter(adapter);

                listNews.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                    public void onItemClick(AdapterView<?> parent, View view, int position, long id) {

                        Intent i = new Intent(secondActivity.this, DetailsActivity.class);
                        i.putExtra("url", dataList.get(+position).get(KEY_URL));
                        startActivity(i);
                    }
                });

            }else{
                Toast.makeText(getApplicationContext(), "No news found", Toast.LENGTH_SHORT).show();
            }
        }

    }


    private ArrayList<Model> populateData(){

        ArrayList<Model> list = new ArrayList<>();

        for(int i = 0; i < myImageNameList.length; i++){

            Model imageModel = new Model();
            imageModel.setName(myImageNameList[i]);
            imageModel.setImage_drawable(myImageList[i]);
            list.add(imageModel);
        }

        return list;
    }

}