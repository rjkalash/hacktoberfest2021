package com.keshav.newstoday;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

public class HorizontalAdapter extends BaseAdapter {

    private Context context;
    private ArrayList<Model> imageModelArrayList;

    public HorizontalAdapter(Context context, ArrayList<Model> imageModelArrayList) {

        this.context = context;
        this.imageModelArrayList = imageModelArrayList;
    }

    @Override
    public int getViewTypeCount() {
        return getCount();
    }
    @Override
    public int getItemViewType(int position) {

        return position;
    }

    @Override
    public int getCount() {
        return imageModelArrayList.size();
    }

    @Override
    public Object getItem(int position) {
        return imageModelArrayList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder holder;

        if (convertView == null) {
            holder = new ViewHolder();
            LayoutInflater inflater = (LayoutInflater) context
                    .getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.lv_row, null, true);

            holder.tvname = (TextView) convertView.findViewById(R.id.name);
            holder.iv = (ImageView) convertView.findViewById(R.id.imgView);

            convertView.setTag(holder);
        }else {
            // the getTag returns the viewHolder object set as a tag to the view
            holder = (ViewHolder)convertView.getTag();
        }

        holder.tvname.setText(imageModelArrayList.get(position).getName());
        holder.iv.setImageResource(imageModelArrayList.get(position).getImage_drawable());

        return convertView;
    }

    private class ViewHolder {

        protected TextView tvname;
        private ImageView iv;

    }

}
