package com.example.randomuserapp;

public class UserDetails {
    String name;
    String gender;
    String email;
    String street;
    String city;
    String phone;

    public String getPhone() {
        return phone;
    }

    public String getName() {
        return name;
    }

    public String getGender() {
        return gender;
    }

    public String getEmail() {
        return email;
    }

    public String getStreet() {
        return street;
    }

    public String getCity() {
        return city;
    }

    public String getState() {
        return State;
    }

    public String getImg_url() {
        return img_url;
    }

    String State;
    String img_url;

    public UserDetails(String name, String gender, String email, String street, String city, String state,String phone) {
        this.name = name;
        this.gender = gender;
        this.email = email;
        this.street = street;
        this.city = city;
        this. State = state;
        this.phone=phone;
    }
}
